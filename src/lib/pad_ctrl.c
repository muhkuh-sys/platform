#include "pad_ctrl.h"

#include "netx_io_areas.h"


void padctrl_apply(const NETX9X2_MPW_PAD_CTRL_ENTRY_T *ptPadCtrl, size_t sizPadCtrl)
{
	unsigned long * const pulGlobalPadCtrl = (unsigned long * const)(Addr_NX9X2_MPW_global_pad_ctrl);
	const NETX9X2_MPW_PAD_CTRL_ENTRY_T *ptCnt;
	const NETX9X2_MPW_PAD_CTRL_ENTRY_T *ptEnd;


	ptCnt = ptPadCtrl;
	ptEnd = ptPadCtrl + sizPadCtrl;
	while( ptCnt<ptEnd )
	{
		pulGlobalPadCtrl[ptCnt->sizRegisterOffset] = ptCnt->ulValue;
		++ptCnt;
	}
}
