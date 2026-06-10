#ifndef __NX9X2_MPW_MMIO_CTRL_H__
#define __NX9X2_MPW_MMIO_CTRL_H__


#define NX9X2_MPW_MMIO_SEL_PIO                      0x00
#define NX9X2_MPW_MMIO_SEL_com_spi0_clk             0x01
#define NX9X2_MPW_MMIO_SEL_com_spi0_miso            0x02
#define NX9X2_MPW_MMIO_SEL_com_spi0_mosi            0x03
#define NX9X2_MPW_MMIO_SEL_com_spi0_cs0n            0x04
#define NX9X2_MPW_MMIO_SEL_com_spi1_clk             0x05
#define NX9X2_MPW_MMIO_SEL_com_spi1_miso            0x06
#define NX9X2_MPW_MMIO_SEL_com_spi1_mosi            0x07
#define NX9X2_MPW_MMIO_SEL_com_spi1_cs0n            0x08
#define NX9X2_MPW_MMIO_SEL_com_i2c0_scl             0x09
#define NX9X2_MPW_MMIO_SEL_com_i2c0_sda             0x0a
#define NX9X2_MPW_MMIO_SEL_com_i2c1_scl             0x0b
#define NX9X2_MPW_MMIO_SEL_com_i2c1_sda             0x0c
#define NX9X2_MPW_MMIO_SEL_com_uart0_tx             0x0d
#define NX9X2_MPW_MMIO_SEL_com_uart0_rx             0x0e
#define NX9X2_MPW_MMIO_SEL_com_uart0_rtsn           0x0f
#define NX9X2_MPW_MMIO_SEL_com_uart0_ctsn           0x10
#define NX9X2_MPW_MMIO_SEL_com_uart1_tx             0x11
#define NX9X2_MPW_MMIO_SEL_com_uart1_rx             0x12
#define NX9X2_MPW_MMIO_SEL_com_uart1_rtsn           0x13
#define NX9X2_MPW_MMIO_SEL_com_uart1_ctsn           0x14
#define NX9X2_MPW_MMIO_SEL_com_iol_clkref           0x15
#define NX9X2_MPW_MMIO_SEL_com_iol_spi_cs1n         0x16
#define NX9X2_MPW_MMIO_SEL_com_iol_spi_cs2n         0x17
#define NX9X2_MPW_MMIO_SEL_com_mii0_txer            0x18
#define NX9X2_MPW_MMIO_SEL_com_mii1_txer            0x19
#define NX9X2_MPW_MMIO_SEL_com_gpio0                0x1a
#define NX9X2_MPW_MMIO_SEL_com_gpio1                0x1b
#define NX9X2_MPW_MMIO_SEL_com_gpio2                0x1c
#define NX9X2_MPW_MMIO_SEL_com_gpio3                0x1d
#define NX9X2_MPW_MMIO_SEL_com_gxc_sample_global0   0x1e
#define NX9X2_MPW_MMIO_SEL_com_gxc_sample_global1   0x1f
#define NX9X2_MPW_MMIO_SEL_com_gxc_trigger_global0  0x20
#define NX9X2_MPW_MMIO_SEL_com_gxc_trigger_global1  0x21
#define NX9X2_MPW_MMIO_SEL_com_wdg_active           0x22


typedef enum {
	NX9X2_MPW_MMIO_CFG_PIO                      = 0x00,
	NX9X2_MPW_MMIO_CFG_com_spi0_clk             = 0x01,
	NX9X2_MPW_MMIO_CFG_com_spi0_miso            = 0x02,
	NX9X2_MPW_MMIO_CFG_com_spi0_mosi            = 0x03,
	NX9X2_MPW_MMIO_CFG_com_spi0_cs0n            = 0x04,
	NX9X2_MPW_MMIO_CFG_com_spi1_clk             = 0x05,
	NX9X2_MPW_MMIO_CFG_com_spi1_miso            = 0x06,
	NX9X2_MPW_MMIO_CFG_com_spi1_mosi            = 0x07,
	NX9X2_MPW_MMIO_CFG_com_spi1_cs0n            = 0x08,
	NX9X2_MPW_MMIO_CFG_com_i2c0_scl             = 0x09,
	NX9X2_MPW_MMIO_CFG_com_i2c0_sda             = 0x0a,
	NX9X2_MPW_MMIO_CFG_com_i2c1_scl             = 0x0b,
	NX9X2_MPW_MMIO_CFG_com_i2c1_sda             = 0x0c,
	NX9X2_MPW_MMIO_CFG_com_uart0_tx             = 0x0d,
	NX9X2_MPW_MMIO_CFG_com_uart0_rx             = 0x0e,
	NX9X2_MPW_MMIO_CFG_com_uart0_rtsn           = 0x0f,
	NX9X2_MPW_MMIO_CFG_com_uart0_ctsn           = 0x10,
	NX9X2_MPW_MMIO_CFG_com_uart1_tx             = 0x11,
	NX9X2_MPW_MMIO_CFG_com_uart1_rx             = 0x12,
	NX9X2_MPW_MMIO_CFG_com_uart1_rtsn           = 0x13,
	NX9X2_MPW_MMIO_CFG_com_uart1_ctsn           = 0x14,
	NX9X2_MPW_MMIO_CFG_com_iol_clkref           = 0x15,
	NX9X2_MPW_MMIO_CFG_com_iol_spi_cs1n         = 0x16,
	NX9X2_MPW_MMIO_CFG_com_iol_spi_cs2n         = 0x17,
	NX9X2_MPW_MMIO_CFG_com_mii0_txer            = 0x18,
	NX9X2_MPW_MMIO_CFG_com_mii1_txer            = 0x19,
	NX9X2_MPW_MMIO_CFG_com_gpio0                = 0x1a,
	NX9X2_MPW_MMIO_CFG_com_gpio1                = 0x1b,
	NX9X2_MPW_MMIO_CFG_com_gpio2                = 0x1c,
	NX9X2_MPW_MMIO_CFG_com_gpio3                = 0x1d,
	NX9X2_MPW_MMIO_CFG_com_gxc_sample_global0   = 0x1e,
	NX9X2_MPW_MMIO_CFG_com_gxc_sample_global1   = 0x1f,
	NX9X2_MPW_MMIO_CFG_com_gxc_trigger_global0  = 0x20,
	NX9X2_MPW_MMIO_CFG_com_gxc_trigger_global1  = 0x21,
	NX9X2_MPW_MMIO_CFG_com_wdg_active           = 0x22
} NX9X2_MPW_MMIO_CFG_T;


#endif  /* __NX9X2_MPW_MMIO_CTRL_H__ */
