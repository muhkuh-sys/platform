#ifndef __NETX9X2_MPW_COM_IO_AREAS_H__
#define __NETX9X2_MPW_COM_IO_AREAS_H__

#include "../netx9x2_common/regdef_netx9x2_mpw.h"

// TODO: Define MMIOs if the chip has some.
//#include "netx9x2_mmio.h"


#define NX9X2_MPW_DEF_ptAsicCtrlArea NX9X2_MPW_COM_ASIC_CTRL_AREA_T * const ptAsicCtrlArea = (NX9X2_MPW_COM_ASIC_CTRL_AREA_T * const)(Addr_NX9X2_MPW_com_asic_ctrl);
#define NX9X2_MPW_DEF_ptGlobalAsicCtrlArea NX9X2_MPW_GLOBAL_ASIC_CTRL_AREA_T * const ptGlobalAsicCtrlArea = (NX9X2_MPW_GLOBAL_ASIC_CTRL_AREA_T * const)(Addr_NX9X2_MPW_global_asic_ctrl);
#define NX9X2_MPW_DEF_ptComAdaTimerArea NX9X2_MPW_RV_TIMER_AREA_T * const ptComAdaTimerArea = (NX9X2_MPW_RV_TIMER_AREA_T * const)(Addr_NX9X2_MPW_com_ada_timer);


#endif  /* __NETX9X2_MPW_COM_IO_AREAS_H__ */
