/***************************************************************************
 *   Copyright (C) 2012 by Christoph Thelen                                *
 *   doc_bacardi@users.sourceforge.net                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "systime.h"
#include "netx_io_areas.h"

#if ASIC_TYP==ASIC_TYP_NETIOL
unsigned long ulSystime_ms = 0;
/*
The netIOL only has 24 bit timers that count clock cycles.
At 100 MHz, the timer runs over after 160ms.
At 8 MHz, it runs over after 2 seconds.
The systime functions currently assume that the system is running at 8MHz.
The timer is run in single-shot mode. Every time systime_get_ms() is called and the
timer has run out, 2000 ms are added to ulSystime_ms.
This means that, unless systime_get_ms() is called periodically at least 2 seconds, it will miss time.
*/
#endif

/* ASIC */
#define DEV_FREQUENCY 100000000

/* For netx 4000 FPGA */
//#define DEV_FREQUENCY 10000000

#if ASIC_TYP==ASIC_TYP_NETX9X2_COM_MPW
	/* The netX9x2 COM ADA timer seems to run with 500MHz. */
#       define TIMER_CLOCK 500000000U
#endif


void systime_init(void)
{
#if ASIC_TYP==ASIC_TYP_NETX4000_RELAXED || ASIC_TYP==ASIC_TYP_NETX4000
	HOSTDEF(ptSystimeUcArea);

	/* Set the systime border to 1ms. */
	ptSystimeUcArea->ulSystime_border = (DEV_FREQUENCY/100U)-1U;
	ptSystimeUcArea->ulSystime_count_value = 10U<<28U;
#elif ASIC_TYP==ASIC_TYP_NETX9X2_COM_MPW
	HOSTDEF(ptComAdaTimerArea);


	/* Stop the timer. */
	ptComAdaTimerArea->ulRv_timer_ctrl = 0U;

	/* Count ticks. */
	ptComAdaTimerArea->ulRv_timer_cfg = 1U << HOSTSRT(rv_timer_cfg_step);

	/* Reset the lower and upper timer to 0. */
	ptComAdaTimerArea->ulRv_timer_lower = 0U;
	ptComAdaTimerArea->ulRv_timer_upper = 0U;

	/* Deactivate all IRQs. */
	ptComAdaTimerArea->ulRv_timer_intr_0_enable = 0U;
	ptComAdaTimerArea->ulRv_timer_intr_1_enable = 0U;
	ptComAdaTimerArea->ulRv_timer_intr_2_enable = 0U;
	ptComAdaTimerArea->ulRv_timer_intr_3_enable = 0U;
	ptComAdaTimerArea->ulRv_timer_intr_4_enable = 0U;
	ptComAdaTimerArea->ulRv_timer_intr_5_enable = 0U;
	ptComAdaTimerArea->ulRv_timer_intr_6_enable = 0U;
	ptComAdaTimerArea->ulRv_timer_intr_7_enable = 0U;

	/* Start the timer. */
	ptComAdaTimerArea->ulRv_timer_ctrl = HOSTMSK(rv_timer_ctrl_active);

#elif ASIC_TYP==ASIC_TYP_NETX90_MPW || ASIC_TYP==ASIC_TYP_NETX90
	HOSTDEF(ptSystimeUcComArea);

	/* Set the systime border to 1ms. */
	ptSystimeUcComArea->ulSystime_border = (DEV_FREQUENCY/100U)-1U;
	ptSystimeUcComArea->ulSystime_count_value = 10U<<28U;
#elif ASIC_TYP==ASIC_TYP_NETX90_MPW_APP || ASIC_TYP==ASIC_TYP_NETX90_APP
	HOSTDEF(ptSystimeAppArea);

	/* Set the systime border to 1ms. */
	ptSystimeAppArea->ulSystime_border = (DEV_FREQUENCY/100U)-1U;
	ptSystimeAppArea->ulSystime_count_value = 10U<<28U;
#elif ASIC_TYP==ASIC_TYP_NETIOL

	/* Set the reload value to 16 Mio.
	When the system is running at 8 MHz, the timer overflows after 2 sec. */
	HOSTDEF(ptSwTimerArea);
	ptSwTimerArea->ulSw_timer_en_mode_clr = MSK_NIOL_sw_timer_en_mode_t0_en | MSK_NIOL_sw_timer_en_mode_t0_mode;
	ptSwTimerArea->asSw_timer_timer[0].ulUpper = 0;
	ptSwTimerArea->asSw_timer_timer[0].ulLower = 0;
	#define NETIOL_SWTIMER_RELOAD_VAL 16000000UL
	ptSwTimerArea->asSw_timer_timer[0].ulUpper_rld = NETIOL_SWTIMER_RELOAD_VAL >> 16;
	ptSwTimerArea->asSw_timer_timer[0].ulLower_rld = NETIOL_SWTIMER_RELOAD_VAL & 0xFFFFUL;

	ptSwTimerArea->ulSw_timer_en_mode_set = MSK_NIOL_sw_timer_en_mode_t0_en;

#else
	HOSTDEF(ptSystimeArea);

	/* Set the systime border to 1ms. */
	ptSystimeArea->ulSystime_border = (DEV_FREQUENCY/100U)-1U;
	ptSystimeArea->ulSystime_count_value = 10U<<28U;

#       if ASIC_TYP==ASIC_TYP_NETX50
	/* Disable systime compare. */
	ptSystimeArea->ulSystime_s_compare_enable = 0;

	/* Reset any pending systime IRQs. */
	ptSystimeArea->ulSystime_s_compare_irq = 1;
#       endif
#endif
}



unsigned long systime_get_ms(void)
{
#if ASIC_TYP==ASIC_TYP_NETX4000_RELAXED || ASIC_TYP==ASIC_TYP_NETX4000
	HOSTDEF(ptSystimeUcArea);

	return ptSystimeUcArea->ulSystime_s;
#elif ASIC_TYP==ASIC_TYP_NETX9X2_COM_MPW
	HOSTDEF(ptComAdaTimerArea);
	uint32_t ulTimerLo;
	uint32_t ulTimerHi;
	uint64_t ullTimerNs;
	uint64_t ullTimerMs;
	uint32_t ulTimerMs;


	/* First read the lower timer, then the upper timer.
	 * I hope that reading the lower register will latch the upper one.
	 */
	ulTimerLo = ptComAdaTimerArea->ulRv_timer_lower;
	ulTimerHi = ptComAdaTimerArea->ulRv_timer_upper;
	/* Combine the lower and upper timer part to one value. */
	ullTimerNs = ((uint64_t)ulTimerLo) | ((uint64_t)ulTimerHi)<<32U;
	/* The timer counts ticks. Divide the value by 1000000 to get miliseconds. */
	ullTimerMs = ullTimerNs / (TIMER_CLOCK/1000);
	/* The result is a 32 bit value. */
	ulTimerMs = (uint32_t)(ullTimerMs & 0x00000000ffffffffU);

	return ulTimerMs;

#elif ASIC_TYP==ASIC_TYP_NETX90_MPW || ASIC_TYP==ASIC_TYP_NETX90
	HOSTDEF(ptSystimeUcComArea);

	return ptSystimeUcComArea->ulSystime_s;
#elif ASIC_TYP==ASIC_TYP_NETX90_MPW_APP || ASIC_TYP==ASIC_TYP_NETX90_APP
	HOSTDEF(ptSystimeAppArea);

	return ptSystimeAppArea->ulSystime_s;
#elif ASIC_TYP==ASIC_TYP_NETIOL
	HOSTDEF(ptSwTimerArea)
	unsigned long ulTimerVal;
	unsigned long ulTimer_ms;

	/* This approach requires that get_ms is called every 2 seconds to keep countin correctly. */
	if (0 == (ptSwTimerArea->ulSw_timer_en_mode & MSK_NIOL_sw_timer_en_mode_t0_en))
	{
		/* Timer has stopped: more than 2 sec. passed. Increase systime_ms by 2000 and restart timer. */
		ptSwTimerArea->ulSw_timer_en_mode_set = MSK_NIOL_sw_timer_en_mode_t0_en;
		ulSystime_ms += 2000;
		ulTimer_ms = ulSystime_ms;
	}
	else
	{
		/* Timer still running. Less than 2 sec. passed. */
		ptSwTimerArea->ulSw_timer_en_mode_clr = MSK_NIOL_sw_timer_en_mode_t0_en;
		ulTimerVal = ptSwTimerArea->asSw_timer_timer[0].ulUpper_rld << 16 | ptSwTimerArea-> asSw_timer_timer[0].ulLower_rld;
		ptSwTimerArea->ulSw_timer_en_mode_set = MSK_NIOL_sw_timer_en_mode_t0_en;
		ulTimer_ms = ulSystime_ms + (NETIOL_SWTIMER_RELOAD_VAL - ulTimerVal) / 8000UL;
	}

	return ulTimer_ms;

#else
	HOSTDEF(ptSystimeArea)


	return ptSystimeArea->ulSystime_s;
#endif
}

int systime_elapsed(unsigned long ulStart, unsigned long ulDuration)
{
#if ASIC_TYP==ASIC_TYP_NETX4000_RELAXED || ASIC_TYP==ASIC_TYP_NETX4000
	HOSTDEF(ptSystimeUcArea)
	unsigned long ulDiff;


	/* get the time difference */
	ulDiff = ptSystimeUcArea->ulSystime_s - ulStart;

	return (ulDiff>=ulDuration);
#elif ASIC_TYP==ASIC_TYP_NETX9X2_COM_MPW
	uint32_t ulDiff;
	int iIsElapsed;


	/* Get the duration from the start time to the current time. */
	ulDiff = systime_get_ms() - ulStart;

	/* The time elapsed if the current duration is equal to or larget than
	 * the requested duration.
	 */
	iIsElapsed = (ulDiff>=ulDuration);
	return iIsElapsed;

#elif ASIC_TYP==ASIC_TYP_NETX90_MPW || ASIC_TYP==ASIC_TYP_NETX90
	HOSTDEF(ptSystimeUcComArea);

	unsigned long ulDiff;


	/* get the time difference */
	ulDiff = ptSystimeUcComArea->ulSystime_s - ulStart;

	return (ulDiff>=ulDuration);
#elif ASIC_TYP==ASIC_TYP_NETX90_MPW_APP || ASIC_TYP==ASIC_TYP_NETX90_APP
	HOSTDEF(ptSystimeAppArea);

	unsigned long ulDiff;


	/* get the time difference */
	ulDiff = ptSystimeAppArea->ulSystime_s - ulStart;

	return (ulDiff>=ulDuration);
#elif ASIC_TYP==ASIC_TYP_NETIOL
	unsigned long ulDiff;

	/* get the time difference */
	ulDiff = systime_get_ms() - ulStart;

	return (ulDiff>=ulDuration);

#else
	HOSTDEF(ptSystimeArea)
	unsigned long ulDiff;


	/* get the time difference */
	ulDiff = ptSystimeArea->ulSystime_s - ulStart;

	return (ulDiff>=ulDuration);
#endif
}



void systime_delay_ms(unsigned long ulDuration)
{
	unsigned long ulStart;
	int iElapsed;


	ulStart = systime_get_ms();
	do
	{
		iElapsed = systime_elapsed(ulStart, ulDuration);
	} while( iElapsed==0 );
}



void systime_handle_start_ms(TIMER_HANDLE_T *ptHandle, unsigned long ulDuration)
{
	ptHandle->ulStart = systime_get_ms();
	ptHandle->ulDuration = ulDuration;
}



int systime_handle_is_elapsed(TIMER_HANDLE_T *ptHandle)
{
	return systime_elapsed(ptHandle->ulStart, ptHandle->ulDuration);
}
