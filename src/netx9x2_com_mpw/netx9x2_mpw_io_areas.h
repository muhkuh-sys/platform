#ifndef __NETX9X2_MPW_COM_IO_AREAS_H__
#define __NETX9X2_MPW_COM_IO_AREAS_H__

#include "../netx9x2_common/regdef_netx9x2_mpw.h"

// TODO: Define MMIOs if the chip has some.
//#include "netx9x2_mmio.h"


#define NX9X2_MPW_DEF_ptComUart0Area NX9X2_MPW_UART_AREA_T * const ptComUart0Area = (NX9X2_MPW_UART_AREA_T * const)(Addr_NX9X2_MPW_com_uart0);
#define NX9X2_MPW_DEF_ptComXspiArea NX9X2_MPW_XSPI_AREA_T * const ptComXspiArea = (NX9X2_MPW_XSPI_AREA_T * const)(Addr_NX9X2_MPW_com_xspi);
#define NX9X2_MPW_DEF_ptComAdaRamCtrlArea NX9X2_MPW_GEN_RAM_CTRL_ADA_0_AREA_T * const ptComAdaRamCtrlArea = (NX9X2_MPW_GEN_RAM_CTRL_ADA_0_AREA_T * const)(Addr_NX9X2_MPW_com_ada_ram_ctrl);
#define NX9X2_MPW_DEF_ptComAdaConfigArea NX9X2_MPW_EH2_CONFIG_AREA_T * const ptComAdaConfigArea = (NX9X2_MPW_EH2_CONFIG_AREA_T * const)(Addr_NX9X2_MPW_com_ada_config);
#define NX9X2_MPW_DEF_ptComAdaTimerArea NX9X2_MPW_RV_TIMER_AREA_T * const ptComAdaTimerArea = (NX9X2_MPW_RV_TIMER_AREA_T * const)(Addr_NX9X2_MPW_com_ada_timer);

#define NX9X2_MPW_DEF_ptSqiArea NX9X2_MPW_SQI_AREA_T * const ptSqiArea = (NX9X2_MPW_SQI_AREA_T * const)(Addr_NX9X2_MPW_sqi);
#define NX9X2_MPW_DEF_ptGlobalAsicCtrlArea NX9X2_MPW_GLOBAL_ASIC_CTRL_AREA_T * const ptGlobalAsicCtrlArea = (NX9X2_MPW_GLOBAL_ASIC_CTRL_AREA_T * const)(Addr_NX9X2_MPW_global_asic_ctrl);
#define NX9X2_MPW_DEF_ptGlobalIoextenderArea NX9X2_MPW_IOEXTENDER_AREA_T * const ptGlobalIoextenderArea = (NX9X2_MPW_IOEXTENDER_AREA_T * const)(Addr_NX9X2_MPW_global_ioextender);
#define NX9X2_MPW_DEF_ptCrgArea NX9X2_MPW_CRG_AREA_T * const ptCrgArea = (NX9X2_MPW_CRG_AREA_T * const)(Addr_NX9X2_MPW_crg);
#define NX9X2_MPW_DEF_ptAsicCtrlArea NX9X2_MPW_COM_ASIC_CTRL_AREA_T * const ptAsicCtrlArea = (NX9X2_MPW_COM_ASIC_CTRL_AREA_T * const)(Addr_NX9X2_MPW_com_asic_ctrl);

#define NX9X2_MPW_DEF_ptDpmRamCtrlArea NX9X2_MPW_GEN_RAM_CTRL_NETX22XX_0_AREA_T * const ptDpmRamCtrlArea = (NX9X2_MPW_GEN_RAM_CTRL_NETX22XX_0_AREA_T * const)(Addr_NX9X2_MPW_dpm_ram_ctrl);

#endif  /* __NETX9X2_MPW_COM_IO_AREAS_H__ */
