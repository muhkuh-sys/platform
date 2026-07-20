#include <stddef.h>


#ifndef __PAD_CTRL_H__
#define __PAD_CTRL_H__


#if ASIC_TYP==ASIC_TYP_NETX9X2_COM_MPW
typedef enum NETX9X2_MPW_PAD_PS_ENUM
{
	NETX9X2_MPW_PAD_PS_PULLDOWN = 0,
	NETX9X2_MPW_PAD_PS_PULLUP = 1
} NETX9X2_MPW_PAD_PS_T;


typedef struct NETX9X2_MPW_PAD_CTRL_ENTRY_STRUCT
{
	size_t sizRegisterOffset;
	unsigned long ulValue;
} NETX9X2_MPW_PAD_CTRL_ENTRY_T;

#       define PADCTRL_DO_CONCAT2(a,b) a##_##b
#       define PADCTRL_CONCAT2(a,b) PADCTRL_DO_CONCAT2(a,b)

#       define PADCTRL_DO_CONCAT4(a,b,c,d) a##_##b##_##c##_##d
#       define PADCTRL_CONCAT4(a,b,c,d) PADCTRL_DO_CONCAT4(a,b,c,d)

#       define PADCTRL_DO_CONCAT5(a,b,c,d,e) a##_##b##_##c##_##d##_##e
#       define PADCTRL_CONCAT5(a,b,c,d,e) PADCTRL_DO_CONCAT5(a,b,c,d,e)

#       define NETX9X2_MPW_PAD_CTRL_ENTRY(ID, DS, PE, PS, SL, ST, IE) { \
	.sizRegisterOffset = offsetof(NX9X2_MPW_PAD_CTRL_AREA_T, PADCTRL_CONCAT2(ulPad_ctrl, ID))/sizeof(unsigned long), \
	.ulValue = DS << PADCTRL_CONCAT5(SRT, HOST, pad_ctrl, ID, ds) | \
	           PE << PADCTRL_CONCAT5(SRT, HOST, pad_ctrl, ID, pe) | \
	           PS << PADCTRL_CONCAT5(SRT, HOST, pad_ctrl, ID, ps) | \
	           SL << PADCTRL_CONCAT5(SRT, HOST, pad_ctrl, ID, sl) | \
	           ST << PADCTRL_CONCAT5(SRT, HOST, pad_ctrl, ID, st) | \
	           IE << PADCTRL_CONCAT5(SRT, HOST, pad_ctrl, ID, ie) | \
	           PADCTRL_CONCAT4(PW_VAL, HOST, pad_ctrl, ID) \
}

#       define NETX9X2_MPW_PAD_CTRL_DEFAULT(ID) { \
	.sizRegisterOffset = offsetof(NX9X2_MPW_PAD_CTRL_AREA_T, PADCTRL_CONCAT2(ulPad_ctrl, ID))/sizeof(unsigned long), \
	.ulValue = PADCTRL_CONCAT4(DFLT_VAL, HOST, pad_ctrl, ID) \
}

void padctrl_apply(const NETX9X2_MPW_PAD_CTRL_ENTRY_T *ptPadCtrl, size_t sizPadCtrl);
#endif


#endif  /* __PAD_CTRL_H__ */
