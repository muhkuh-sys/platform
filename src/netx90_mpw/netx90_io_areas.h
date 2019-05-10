/***************************************************************************
 *   Copyright (C) 2016 by Hilscher GmbH                                   *
 *                                                                         *
 *   Author: Christoph Thelen (cthelen@hilscher.com)                       *
 *                                                                         *
 *   Redistribution or unauthorized use without expressed written          *
 *   agreement from the Hilscher GmbH is forbidden.                        *
 ***************************************************************************/

#ifndef __NETX90_IO_AREAS_H__
#define __NETX90_IO_AREAS_H__


#include "netx90_regdef.h"
#include "netx90_mmio.h"


#define NX90MPW_DEF_ptCm4MiscAsicCtrlArea NX90MPW_CM4_MISC_CTRL_AREA_T * const ptCm4MiscAsicCtrlArea = (NX90MPW_CM4_MISC_CTRL_AREA_T * const)Addr_NX90MPW_cm4_misc_ctrl;

#define NX90MPW_DEF_ptDmacComCh0Area NX90MPW_DMAC_CH_AREA_T * const ptDmacComCh0Area = (NX90MPW_DMAC_CH_AREA_T * const)Addr_NX90MPW_dmac_com_ch0;
#define NX90MPW_DEF_ptDmacComCh1Area NX90MPW_DMAC_CH_AREA_T * const ptDmacComCh1Area = (NX90MPW_DMAC_CH_AREA_T * const)Addr_NX90MPW_dmac_com_ch1;
#define NX90MPW_DEF_ptDmacComCh2Area NX90MPW_DMAC_CH_AREA_T * const ptDmacComCh2Area = (NX90MPW_DMAC_CH_AREA_T * const)Addr_NX90MPW_dmac_com_ch2;
#define NX90MPW_DEF_ptDmacAppCh0Area NX90MPW_DMAC_CH_AREA_T * const ptDmacAppCh0Area = (NX90MPW_DMAC_CH_AREA_T * const)Addr_NX90MPW_dmac_app_ch0;
#define NX90MPW_DEF_ptDmacAppCh1Area NX90MPW_DMAC_CH_AREA_T * const ptDmacAppCh1Area = (NX90MPW_DMAC_CH_AREA_T * const)Addr_NX90MPW_dmac_app_ch1;
#define NX90MPW_DEF_ptDmacAppCh2Area NX90MPW_DMAC_CH_AREA_T * const ptDmacAppCh2Area = (NX90MPW_DMAC_CH_AREA_T * const)Addr_NX90MPW_dmac_app_ch2;

#define NX90MPW_DEF_ptDmacComRegArea NX90MPW_DMAC_REG_AREA_T * const ptDmacComRegArea = (NX90MPW_DMAC_REG_AREA_T * const)Addr_NX90MPW_dmac_com_reg;
#define NX90MPW_DEF_ptDmacAppRegArea NX90MPW_DMAC_REG_AREA_T * const ptDmacAppRegArea = (NX90MPW_DMAC_REG_AREA_T * const)Addr_NX90MPW_dmac_app_reg;

#define NX90MPW_DEF_ptUartComArea NX90MPW_UART_AREA_T * const ptUartComArea = (NX90MPW_UART_AREA_T * const)Addr_NX90MPW_uart_com;
#define NX90MPW_DEF_ptUartAppArea NX90MPW_UART_AREA_T * const ptUartAppArea = (NX90MPW_UART_AREA_T * const)Addr_NX90MPW_uart_app;
#define NX90MPW_DEF_ptUartXpicAppArea NX90MPW_UART_AREA_T * const ptUartXpicAppArea = (NX90MPW_UART_AREA_T * const)Addr_NX90MPW_uart_xpic_app;

#define NX90MPW_DEF_ptI2c0ComArea NX90MPW_I2C_AREA_T * const ptI2cArea = (NX90MPW_I2C_AREA_T * const)Addr_NX90MPW_i2c0_com;
#define NX90MPW_DEF_ptI2c1ComArea NX90MPW_I2C_AREA_T * const ptI2cArea = (NX90MPW_I2C_AREA_T * const)Addr_NX90MPW_i2c1_com;
#define NX90MPW_DEF_ptI2cAppArea NX90MPW_I2C_AREA_T * const ptI2cArea = (NX90MPW_I2C_AREA_T * const)Addr_NX90MPW_i2c_app;
#define NX90MPW_DEF_ptI2cXpicAppArea NX90MPW_I2C_AREA_T * const ptI2cArea = (NX90MPW_I2C_AREA_T * const)Addr_NX90MPW_i2c_xpic_app;

#define NX90MPW_DEF_ptMledCtrlComArea NX90MPW_MLED_CTRL_AREA_T * const ptMledCtrlComArea = (NX90MPW_MLED_CTRL_AREA_T * const)Addr_NX90MPW_mled_ctrl_com;
#define NX90MPW_DEF_ptMledCtrlAppArea NX90MPW_MLED_CTRL_AREA_T * const ptMledCtrlAppArea = (NX90MPW_MLED_CTRL_AREA_T * const)Addr_NX90MPW_mled_ctrl_app;

#define NX90MPW_DEF_ptEccCtrlComArea NX90MPW_ECC_CTRL_AREA_T * const ptEccCtrlComArea = (NX90MPW_ECC_CTRL_AREA_T * const)Addr_NX90MPW_ecc_ctrl_com;
#define NX90MPW_DEF_ptEccCtrlAppArea NX90MPW_ECC_CTRL_AREA_T * const ptEccCtrlAppArea = (NX90MPW_ECC_CTRL_AREA_T * const)Addr_NX90MPW_ecc_ctrl_app;

#define NX90MPW_DEF_ptGpioArea NX90MPW_GPIO_AREA_T * const ptGpioArea = (NX90MPW_GPIO_AREA_T * const)Addr_NX90MPW_gpio_com;

#define NX90MPW_DEF_ptBlinkArea NX90MPW_BLINK_AREA_T * const ptBlinkArea = (NX90MPW_BLINK_AREA_T * const)Addr_NX90MPW_blink_com;

#define NX90MPW_DEF_ptIntlogicSystimeLtComArea NX90MPW_INTLOGIC_SYSTIME_LT_AREA_T * const ptIntlogicSystimeLtComArea = (NX90MPW_INTLOGIC_SYSTIME_LT_AREA_T * const)Addr_NX90MPW_systime_lt_com;
#define NX90MPW_DEF_ptIntlogicSystimeLtAppArea NX90MPW_INTLOGIC_SYSTIME_LT_AREA_T * const ptIntlogicSystimeLtAppArea = (NX90MPW_INTLOGIC_SYSTIME_LT_AREA_T * const)Addr_NX90MPW_systime_lt_app;
#define NX90MPW_DEF_ptIntlogicSystimeLtXpicComArea NX90MPW_INTLOGIC_SYSTIME_LT_AREA_T * const ptIntlogicSystimeLtXpicComArea = (NX90MPW_INTLOGIC_SYSTIME_LT_AREA_T * const)Addr_NX90MPW_systime_lt_xpic_com;
#define NX90MPW_DEF_ptIntlogicSystimeLtXpicAppArea NX90MPW_INTLOGIC_SYSTIME_LT_AREA_T * const ptIntlogicSystimeLtXpicAppArea = (NX90MPW_INTLOGIC_SYSTIME_LT_AREA_T * const)Addr_NX90MPW_systime_lt_xpic_app;

#define NX90MPW_DEF_ptArmTimerComArea NX90MPW_ARM_TIMER_AREA_T * const ptArmTimerComArea = (NX90MPW_ARM_TIMER_AREA_T * const)Addr_NX90MPW_timer_com;
#define NX90MPW_DEF_ptArmTimerAppArea NX90MPW_ARM_TIMER_AREA_T * const ptArmTimerAppArea = (NX90MPW_ARM_TIMER_AREA_T * const)Addr_NX90MPW_timer_app;
#define NX90MPW_DEF_ptArmTimerXpicComArea NX90MPW_ARM_TIMER_AREA_T * const ptArmTimerXpicComArea = (NX90MPW_ARM_TIMER_AREA_T * const)Addr_NX90MPW_timer_xpic_com;
#define NX90MPW_DEF_ptArmTimerXpicAppArea NX90MPW_ARM_TIMER_AREA_T * const ptArmTimerXpicAppArea = (NX90MPW_ARM_TIMER_AREA_T * const)Addr_NX90MPW_timer_xpic_app;

#define NX90MPW_DEF_ptSystimeComArea NX90MPW_SYSTIME_AREA_T * const ptSystimeComArea = (NX90MPW_SYSTIME_AREA_T * const)Addr_NX90MPW_systime_com;
#define NX90MPW_DEF_ptSystimeUcComArea NX90MPW_SYSTIME_AREA_T * const ptSystimeUcComArea = (NX90MPW_SYSTIME_AREA_T * const)Addr_NX90MPW_systime_uc_com;
#define NX90MPW_DEF_ptSystimeAppArea NX90MPW_SYSTIME_AREA_T * const ptSystimeAppArea = (NX90MPW_SYSTIME_AREA_T * const)Addr_NX90MPW_systime_app;

#define NX90MPW_DEF_ptHsIrqRegComArea NX90MPW_HS_IRQ_REG_AREA_T * const ptHsIrqRegComArea = (NX90MPW_HS_IRQ_REG_AREA_T * const)Addr_NX90MPW_mpc_com;
#define NX90MPW_DEF_ptHsIrqRegAppArea NX90MPW_HS_IRQ_REG_AREA_T * const ptHsIrqRegAppArea = (NX90MPW_HS_IRQ_REG_AREA_T * const)Addr_NX90MPW_mpc_app;
#define NX90MPW_DEF_ptHsIrqRegXpicComArea NX90MPW_HS_IRQ_REG_AREA_T * const ptHsIrqRegXpicComArea = (NX90MPW_HS_IRQ_REG_AREA_T * const)Addr_NX90MPW_mpc_xpic_com;
#define NX90MPW_DEF_ptHsIrqRegXpicAppArea NX90MPW_HS_IRQ_REG_AREA_T * const ptHsIrqRegXpicAppArea = (NX90MPW_HS_IRQ_REG_AREA_T * const)Addr_NX90MPW_mpc_xpic_app;

#define NX90MPW_DEF_ptWatchdogComArea NX90MPW_WATCHDOG_AREA_T * const ptWatchdogComArea = (NX90MPW_WATCHDOG_AREA_T * const)Addr_NX90MPW_wdg_com;
#define NX90MPW_DEF_ptWatchdogAppArea NX90MPW_WATCHDOG_AREA_T * const ptWatchdogAppArea = (NX90MPW_WATCHDOG_AREA_T * const)Addr_NX90MPW_wdg_app;

#define NX90MPW_DEF_ptIntPhyCfgComArea NX90MPW_INT_PHY_CFG_AREA_T * const ptIntPhyCfgComArea = (NX90MPW_INT_PHY_CFG_AREA_T * const)Addr_NX90MPW_int_phy_cfg_com;

#define NX90MPW_DEF_ptAsicCtrlComArea NX90MPW_ASIC_CTRL_COM_AREA_T * const ptAsicCtrlComArea = (NX90MPW_ASIC_CTRL_COM_AREA_T * const)Addr_NX90MPW_asic_ctrl_com;

#define NX90MPW_DEF_ptLvds2mii0ComArea NX90MPW_LVDS2MII_AREA_T * const ptLvds2mii0ComArea = (NX90MPW_LVDS2MII_AREA_T * const)Addr_NX90MPW_lvds2mii0_com;
#define NX90MPW_DEF_ptLvds2mii1ComArea NX90MPW_LVDS2MII_AREA_T * const ptLvds2mii1ComArea = (NX90MPW_LVDS2MII_AREA_T * const)Addr_NX90MPW_lvds2mii1_com;

#define NX90MPW_DEF_ptDpm0ComArea NX90MPW_DPM_AREA_T * const ptDpm0ComArea = (NX90MPW_DPM_AREA_T * const)Addr_NX90MPW_dpm0_com;
#define NX90MPW_DEF_ptDpm1ComArea NX90MPW_DPM_AREA_T * const ptDpm1ComArea = (NX90MPW_DPM_AREA_T * const)Addr_NX90MPW_dpm1_com;

#define NX90MPW_DEF_ptIdpmComArea NX90MPW_IDPM_AREA_T * const ptIdpmComArea = (NX90MPW_IDPM_AREA_T * const)Addr_NX90MPW_idpm_com;

#define NX90MPW_DEF_ptIflashCfg0ComArea NX90MPW_IFLASH_CFG_AREA_T * const ptIflashCfg0ComArea = (NX90MPW_IFLASH_CFG_AREA_T * const)Addr_NX90MPW_iflash_cfg0_com;
#define NX90MPW_DEF_ptIflashCfg1ComArea NX90MPW_IFLASH_CFG_AREA_T * const ptIflashCfg1ComArea = (NX90MPW_IFLASH_CFG_AREA_T * const)Addr_NX90MPW_iflash_cfg1_com;
#define NX90MPW_DEF_ptIflashCfg2Area NX90MPW_IFLASH_CFG_AREA_T * const ptIflashCfg2Area = (NX90MPW_IFLASH_CFG_AREA_T * const)Addr_NX90MPW_iflash_cfg2;

#define NX90MPW_DEF_ptHandshakeCtrlComArea NX90MPW_HANDSHAKE_CTRL_AREA_T * const ptHandshakeCtrlComArea = (NX90MPW_HANDSHAKE_CTRL_AREA_T * const)Addr_NX90MPW_handshake_ctrl_com;

#define NX90MPW_DEF_ptBistCtrlComArea NX90MPW_BIST_CTRL_AREA_T * const ptBistCtrlComArea = (NX90MPW_BIST_CTRL_AREA_T * const)Addr_NX90MPW_bist_ctrl_com;

#define NX90MPW_DEF_ptCrcComArea NX90MPW_CRC_AREA_T * const ptCrcComArea = (NX90MPW_CRC_AREA_T * const)Addr_NX90MPW_crc_com;

#define NX90MPW_DEF_ptIflashGlobalTimingsArea NX90MPW_IFLASH_GLOBAL_TIMINGS_AREA_T * const ptIflashGlobalTimingsArea = (NX90MPW_IFLASH_GLOBAL_TIMINGS_AREA_T * const)Addr_NX90MPW_flash_global_timings_com;

#define NX90MPW_DEF_ptHashArea NX90MPW_HASH_AREA_T * const ptHashArea = (NX90MPW_HASH_AREA_T * const)Addr_NX90MPW_hash;

#define NX90MPW_DEF_ptAesArea NX90MPW_AES_AREA_T * const ptAesArea = (NX90MPW_AES_AREA_T * const)Addr_NX90MPW_aes;

#define NX90MPW_DEF_ptRandomArea NX90MPW_RANDOM_AREA_T * const ptRandomArea = (NX90MPW_RANDOM_AREA_T * const)Addr_NX90MPW_random;

#define NX90MPW_DEF_ptMtgyArea NX90MPW_MTGY_AREA_T * const ptMtgyArea = (NX90MPW_MTGY_AREA_T * const)Addr_NX90MPW_mtgy;

#define NX90MPW_DEF_ptXpecArea NX90MPW_XPEC_AREA_T * const ptXpecArea = (NX90MPW_XPEC_AREA_T * const)Adr_NX90MPW_;

#define NX90MPW_DEF_ptXc0Xmac0RegsArea NX90MPW_XMAC_AREA_T * const ptXc0Xmac0RegsArea = (NX90MPW_XMAC_AREA_T * const)Addr_NX90MPW_xc0_xmac0_regs;
#define NX90MPW_DEF_ptXc0Xmac1RegsArea NX90MPW_XMAC_AREA_T * const ptXc0Xmac1RegsArea = (NX90MPW_XMAC_AREA_T * const)Addr_NX90MPW_xc0_xmac1_regs;

#define NX90MPW_DEF_ptPointerFifoArea NX90MPW_POINTER_FIFO_AREA_T * const ptPointerFifoArea = (NX90MPW_POINTER_FIFO_AREA_T * const)Addr_NX90MPW_xc0_pointer_fifo;
#define NX90MPW_DEF_ptFmmusmArea NX90MPW_FMMUSM_AREA_T * const ptFmmusmArea = (NX90MPW_FMMUSM_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptTriggerSampleUnitArea NX90MPW_TRIGGER_SAMPLE_UNIT_AREA_T * const ptTriggerSampleUnitArea = (NX90MPW_TRIGGER_SAMPLE_UNIT_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXcExternalConfigArea NX90MPW_XC_EXTERNAL_CONFIG_AREA_T * const ptXcExternalConfigArea = (NX90MPW_XC_EXTERNAL_CONFIG_AREA_T * const)Addr_NX90MPW_xc_external_config;
#define NX90MPW_DEF_ptBufManArea NX90MPW_BUF_MAN_AREA_T * const ptBufManArea = (NX90MPW_BUF_MAN_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXpecIrqRegistersArea NX90MPW_XPEC_IRQ_REGISTERS_AREA_T * const ptXpecIrqRegistersArea = (NX90MPW_XPEC_IRQ_REGISTERS_AREA_T * const)Addr_NX90MPW_xc_xpec_irq_registers;
#define NX90MPW_DEF_ptXcDebugArea NX90MPW_XC_DEBUG_AREA_T * const ptXcDebugArea = (NX90MPW_XC_DEBUG_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXcStartStopArea NX90MPW_XC_START_STOP_AREA_T * const ptXcStartStopArea = (NX90MPW_XC_START_STOP_AREA_T * const)Addr_NX90MPW_xc_start_stop;
#define NX90MPW_DEF_ptXc0PhyCtrl0Area NX90MPW_PHY_CTRL_AREA_T * const ptXc0PhyCtrl0Area = (NX90MPW_PHY_CTRL_AREA_T * const)Addr_NX90MPW_xc0_phy_ctrl0;
#define NX90MPW_DEF_ptXc0PhyCtrl1Area NX90MPW_PHY_CTRL_AREA_T * const ptXc0PhyCtrl1Area = (NX90MPW_PHY_CTRL_AREA_T * const)Addr_NX90MPW_xc0_phy_ctrl1;
#define NX90MPW_DEF_ptXcSystimeConfigArea NX90MPW_XC_SYSTIME_CONFIG_AREA_T * const ptXcSystimeConfigArea = (NX90MPW_XC_SYSTIME_CONFIG_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXpicArea NX90MPW_XPIC_AREA_T * const ptXpicArea = (NX90MPW_XPIC_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXpicDebugArea NX90MPW_XPIC_DEBUG_AREA_T * const ptXpicDebugArea = (NX90MPW_XPIC_DEBUG_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXpicVicArea NX90MPW_XPIC_VIC_AREA_T * const ptXpicVicArea = (NX90MPW_XPIC_VIC_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXpicWgdArea NX90MPW_XPIC_WDG_AREA_T * const ptXpicWgdArea = (NX90MPW_XPIC_WDG_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptSrArea NX90MPW_SR_AREA_T * const ptSrArea = (NX90MPW_SR_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXcStatcfgSharedArea NX90MPW_XC_STATCFG_SHARED_AREA_T * const ptXcStatcfgSharedArea = (NX90MPW_XC_STATCFG_SHARED_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptNfifoArea NX90MPW_NFIFO_AREA_T * const ptNfifoArea = (NX90MPW_NFIFO_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptPadCtrlArea NX90MPW_PAD_CTRL_AREA_T * const ptPadCtrlArea = (NX90MPW_PAD_CTRL_AREA_T * const)Addr_NX90MPW_pad_ctrl;

#define NX90MPW_DEF_ptAsicCtrlArea NX90MPW_ASIC_CTRL_AREA_T * const ptAsicCtrlArea = (NX90MPW_ASIC_CTRL_AREA_T * const)Addr_NX90MPW_asic_ctrl;

#define NX90MPW_DEF_ptMmioCtrlArea NX90MPW_MMIO_CTRL_AREA_T * const ptMmioCtrlArea = (NX90MPW_MMIO_CTRL_AREA_T * const)Addr_NX90MPW_mmio_ctrl;
#define NX90MPW_DEF_ptGlobalBufManArea NX90MPW_GLOBAL_BUF_MAN_AREA_T * const ptGlobalBufManArea = (NX90MPW_GLOBAL_BUF_MAN_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptHifIoCtrlArea NX90MPW_HIF_IO_CTRL_AREA_T * const ptHifIoCtrlArea = (NX90MPW_HIF_IO_CTRL_AREA_T * const)Addr_NX90MPW_hif_io_ctrl;
#define NX90MPW_DEF_ptHifAsyncmemCtrlArea NX90MPW_EXT_ASYNCMEM_CTRL_AREA_T * const ptHifAsyncmemCtrlArea = (NX90MPW_EXT_ASYNCMEM_CTRL_AREA_T * const)Addr_NX90MPW_hif_asyncmem_ctrl;
#define NX90MPW_DEF_ptHifSdramCtrlArea NX90MPW_EXT_SDRAM_CTRL_AREA_T * const ptHifSdramCtrlArea = (NX90MPW_EXT_SDRAM_CTRL_AREA_T * const)Addr_NX90MPW_hif_sdram_ctrl;
#define NX90MPW_DEF_ptHifmemPriorityCtrlArea NX90MPW_EXTMEM_PRIORITY_CTRL_AREA_T * const ptHifmemPriorityCtrlArea = (NX90MPW_EXTMEM_PRIORITY_CTRL_AREA_T * const)Addr_NX90MPW_hifmem_priority_ctrl;

#define NX90MPW_DEF_ptSqiArea NX90MPW_SQI_AREA_T * const ptSqiArea = (NX90MPW_SQI_AREA_T * const)Addr_NX90MPW_sqi;

#define NX90MPW_DEF_ptSampleAtPornStatArea NX90MPW_SAMPLE_AT_PORN_STAT_AREA_T * const ptSampleAtPornStatArea = (NX90MPW_SAMPLE_AT_PORN_STAT_AREA_T * const)Addr_NX90MPW_sample_at_porn_stat;
#define NX90MPW_DEF_ptAdcSeqArea NX90MPW_ADC_SEQ_AREA_T * const ptAdcSeqArea = (NX90MPW_ADC_SEQ_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptMiimuArea NX90MPW_MIIMU_AREA_T * const ptMiimuArea = (NX90MPW_MIIMU_AREA_T * const)Addr_NX90MPW_miimu;
#define NX90MPW_DEF_ptEthArea NX90MPW_ETH_AREA_T * const ptEthArea = (NX90MPW_ETH_AREA_T * const)Addr_NX90MPW_eth;
#define NX90MPW_DEF_ptDmacMuxArea NX90MPW_DMAC_MUX_AREA_T * const ptDmacMuxArea = (NX90MPW_DMAC_MUX_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptGpioAppArea NX90MPW_GPIO_APP_AREA_T * const ptGpioAppArea = (NX90MPW_GPIO_APP_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptEndatArea NX90MPW_ENDAT_AREA_T * const ptEndatArea = (NX90MPW_ENDAT_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptEndatCtrlArea NX90MPW_ENDAT_CTRL_AREA_T * const ptEndatCtrlArea = (NX90MPW_ENDAT_CTRL_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptCanctrlArea NX90MPW_CANCTRL_AREA_T * const ptCanctrlArea = (NX90MPW_CANCTRL_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptSpiArea NX90MPW_SPI_AREA_T * const ptSpiArea = (NX90MPW_SPI_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptPioArea NX90MPW_PIO_AREA_T * const ptPioArea = (NX90MPW_PIO_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptBissArea NX90MPW_BISS_AREA_T * const ptBissArea = (NX90MPW_BISS_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptBissCtrlArea NX90MPW_BISS_CTRL_AREA_T * const ptBissCtrlArea = (NX90MPW_BISS_CTRL_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXlinkArea NX90MPW_XLINK_AREA_T * const ptXlinkArea = (NX90MPW_XLINK_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptIoLinkIeqArea NX90MPW_IO_LINK_IRQ_AREA_T * const ptIoLinkIeqArea = (NX90MPW_IO_LINK_IRQ_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptXcExtbusSelArea NX90MPW_XC_EXTBUS_SEL_AREA_T * const ptXcExtbusSelArea = (NX90MPW_XC_EXTBUS_SEL_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptParityArea NX90MPW_PARITY_AREA_T * const ptParityArea = (NX90MPW_PARITY_AREA_T * const)Adr_NX90MPW_;
#define NX90MPW_DEF_ptArmBootVectorArea NX90MPW_ARM_BOOT_VECTOR_AREA_T * const ptArmBootVectorArea = (NX90MPW_ARM_BOOT_VECTOR_AREA_T * const)Adr_NX90MPW_;


#endif  /* __NETX90_IO_AREAS_H__ */

