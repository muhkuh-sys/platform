#ifndef __NETX9X2_MPW_IO_AREAS_H__
#define __NETX9X2_MPW_IO_AREAS_H__

#include "../netx9x2_common/regdef_netx9x2_mpw.h"

// TODO: Define MMIOs if the chip has some.
//#include "netx9x2_mmio.h"


/* Define offsets for the areas mapped by firewall settings.
 * NOTE: There are different firewall settings around. The build-in settings of the netX9x2 MPW ROM code seem to be
 *       obsolete. They are superseeded by the "SERT" settings, which are also used here.
 */
/* | 1      | 0x6000_0000 | 0x6000_0000 | 0x0000_0000 - | first 512MByte of the global address map         |
 * |        |             |             | 0x1FFF_FFFF   |                                                  |
 */
#define NX9X2_MPW_FGHG_OFFSET 0x60000000U

/* | 2      | 0x8000_0000 | 0x4000_0000 | 0x4000_0000 - | 256MByte for HPERI and MOT                       |
 * |        |             |             | 0x4FFF_FFFF   |                                                  |
 */
#define NX9X2_MPW_HPERI_OFFSET 0x40000000U

/* | 3      | 0x9000_0000 | 0x3000_0000 | 0x6000_0000 - | 256MByte for SMS and ...                         |
 * |        |             |             | 0x6FFF_FFFF   |                                                  |
 */
#define NX9X2_MPW_SMS_OFFSET 0x30000000U


#define NX9X2_MPW_DEF_ptSecencUartArea NX9X2_MPW_UART_PL011_AREA_T * const ptSecencUartArea = (NX9X2_MPW_UART_PL011_AREA_T * const)Addr_NX9X2_MPW_secenc_uart;

#define NX9X2_MPW_DEF_ptSecencTimer0 NX9X2_MPW_CMSDK_TIMER_AREA_T * const ptSecencTimer0 = (NX9X2_MPW_CMSDK_TIMER_AREA_T * const)Addr_NX9X2_MPW_secenc_timer0;

#define NX9X2_MPW_DEF_ptAsicCtrlArea NX9X2_MPW_COM_ASIC_CTRL_AREA_T * const ptAsicCtrlArea = (NX9X2_MPW_COM_ASIC_CTRL_AREA_T * const)(Addr_NX9X2_MPW_com_asic_ctrl+NX9X2_MPW_HPERI_OFFSET);

#define NX9X2_MPW_DEF_ptIntram0RamCtrlArea NX9X2_MPW_GEN_RAM_CTRL_NETX22XX_1_AREA_T * const ptIntram0RamCtrlArea = (NX9X2_MPW_GEN_RAM_CTRL_NETX22XX_1_AREA_T * const)(Addr_NX9X2_MPW_intram0_ram_ctrl+NX9X2_MPW_SMS_OFFSET);
#define NX9X2_MPW_DEF_ptIntram1RamCtrlArea NX9X2_MPW_GEN_RAM_CTRL_NETX22XX_2_AREA_T * const ptIntram1RamCtrlArea = (NX9X2_MPW_GEN_RAM_CTRL_NETX22XX_2_AREA_T * const)(Addr_NX9X2_MPW_intram1_ram_ctrl+NX9X2_MPW_SMS_OFFSET);
#define NX9X2_MPW_DEF_ptIntram2RamCtrlArea NX9X2_MPW_GEN_RAM_CTRL_NETX22XX_3_AREA_T * const ptIntram2RamCtrlArea = (NX9X2_MPW_GEN_RAM_CTRL_NETX22XX_3_AREA_T * const)(Addr_NX9X2_MPW_intram2_ram_ctrl+NX9X2_MPW_SMS_OFFSET);

#define NX9X2_MPW_DEF_ptHostBaseSysCtrlArea NX9X2_MPW_HOST_BASE_SYS_CTRL_AREA_T * const ptHostBaseSysCtrlArea = (NX9X2_MPW_HOST_BASE_SYS_CTRL_AREA_T * const)(Addr_NX9X2_MPW_host_base_sys_ctrl+NX9X2_MPW_FGHG_OFFSET);


#endif  /* __NETX9X2_MPW_IO_AREAS_H__ */
