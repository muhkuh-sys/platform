#ifndef __NETX9X2_MPW_ADA_IO_AREAS_H__
#define __NETX9X2_MPW_ADA_IO_AREAS_H__

#include "../netx9x2_common/regdef_netx9x2_mpw.h"

// TODO: Define MMIOs if the chip has some.
//#include "netx9x2_mmio.h"


#define NX9X2_MPW_DEF_ptComUart0Area NX9X2_MPW_UART_AREA_T * const ptComUart0Area = (NX9X2_MPW_UART_AREA_T * const)(Addr_NX9X2_MPW_com_uart0);
#define NX9X2_MPW_DEF_ptComAdaRamCtrlArea NX9X2_MPW_GEN_RAM_CTRL_ADA_0_AREA_T * const ptComAdaRamCtrlArea = (NX9X2_MPW_GEN_RAM_CTRL_ADA_0_AREA_T * const)(Addr_NX9X2_MPW_com_ada_ram_ctrl);
#define NX9X2_MPW_DEF_ptComAdaConfigArea NX9X2_MPW_EH2_CONFIG_AREA_T * const ptComAdaConfigArea = (NX9X2_MPW_EH2_CONFIG_AREA_T * const)(Addr_NX9X2_MPW_com_ada_config);
#define NX9X2_MPW_DEF_ptAdaTimerArea NX9X2_MPW_RV_TIMER_AREA_T * const ptAdaTimerArea = (NX9X2_MPW_RV_TIMER_AREA_T * const)(Addr_NX9X2_MPW_ada_timer);

#define NX9X2_MPW_DEF_ptAsicCtrlArea NX9X2_MPW_COM_ASIC_CTRL_AREA_T * const ptAsicCtrlArea = (NX9X2_MPW_COM_ASIC_CTRL_AREA_T * const)(Addr_NX9X2_MPW_com_asic_ctrl);


#endif  /* __NETX9X2_MPW_ADA_IO_AREAS_H__ */
