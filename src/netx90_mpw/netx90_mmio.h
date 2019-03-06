////////////////////////////////////////////////////////////
//
// Automatically generated by GEN_MULTIPLEXMATRIX script
// from:      /home/netx/doc/netXtiny/pinning/netxtiny_pinning_160613_1930.xlsx
//
////////////////////////////////////////////////////////////
//
// Hilscher SoCT
//
////////////////////////////////////////////////////////////
//
// Multiplexmatrix MMIO-signal selections
//
////////////////////////////////////////////////////////////



#ifndef __nx90mpw_mmio_ctrl_h
#define __nx90mpw_mmio_ctrl_h

#define NX90MPW_MMIO_SEL_XC_SAMPLE0         0x00
#define NX90MPW_MMIO_SEL_XC_SAMPLE1         0x01
#define NX90MPW_MMIO_SEL_XC_TRIGGER0        0x02
#define NX90MPW_MMIO_SEL_XC_TRIGGER1        0x03
#define NX90MPW_MMIO_SEL_CAN0_APP_RX        0x04
#define NX90MPW_MMIO_SEL_CAN0_APP_TX        0x05
#define NX90MPW_MMIO_SEL_CAN1_APP_RX        0x06
#define NX90MPW_MMIO_SEL_CAN1_APP_TX        0x07
#define NX90MPW_MMIO_SEL_I2C_XPIC_APP_SCL   0x08
#define NX90MPW_MMIO_SEL_I2C_XPIC_APP_SDA   0x09
#define NX90MPW_MMIO_SEL_I2C_APP_SCL        0x0a
#define NX90MPW_MMIO_SEL_I2C_APP_SDA        0x0b
#define NX90MPW_MMIO_SEL_SPI_XPIC_APP_CLK   0x0c
#define NX90MPW_MMIO_SEL_SPI_XPIC_APP_CS0N  0x0d
#define NX90MPW_MMIO_SEL_SPI_XPIC_APP_CS1N  0x0e
#define NX90MPW_MMIO_SEL_SPI_XPIC_APP_CS2N  0x0f
#define NX90MPW_MMIO_SEL_SPI_XPIC_APP_MISO  0x10
#define NX90MPW_MMIO_SEL_SPI_XPIC_APP_MOSI  0x11
#define NX90MPW_MMIO_SEL_SPI1_APP_CLK       0x12
#define NX90MPW_MMIO_SEL_SPI1_APP_CS0N      0x13
#define NX90MPW_MMIO_SEL_SPI1_APP_CS1N      0x14
#define NX90MPW_MMIO_SEL_SPI1_APP_CS2N      0x15
#define NX90MPW_MMIO_SEL_SPI1_APP_MISO      0x16
#define NX90MPW_MMIO_SEL_SPI1_APP_MOSI      0x17
#define NX90MPW_MMIO_SEL_UART_XPIC_APP_RXD  0x18
#define NX90MPW_MMIO_SEL_UART_XPIC_APP_TXD  0x19
#define NX90MPW_MMIO_SEL_UART_XPIC_APP_RTSN 0x1a
#define NX90MPW_MMIO_SEL_UART_XPIC_APP_CTSN 0x1b
#define NX90MPW_MMIO_SEL_UART_APP_RXD       0x1c
#define NX90MPW_MMIO_SEL_UART_APP_TXD       0x1d
#define NX90MPW_MMIO_SEL_UART_APP_RTSN      0x1e
#define NX90MPW_MMIO_SEL_UART_APP_CTSN      0x1f
#define NX90MPW_MMIO_SEL_GPIO0              0x20
#define NX90MPW_MMIO_SEL_GPIO1              0x21
#define NX90MPW_MMIO_SEL_GPIO2              0x22
#define NX90MPW_MMIO_SEL_GPIO3              0x23
#define NX90MPW_MMIO_SEL_GPIO4              0x24
#define NX90MPW_MMIO_SEL_GPIO5              0x25
#define NX90MPW_MMIO_SEL_GPIO6              0x26
#define NX90MPW_MMIO_SEL_GPIO7              0x27
#define NX90MPW_MMIO_SEL_WDG_ACT            0x28
#define NX90MPW_MMIO_SEL_EN_IN              0x29
#define NX90MPW_MMIO_SEL_ETH_MMIO_MDC       0x2a
#define NX90MPW_MMIO_SEL_ETH_MMIO_MDIO      0x2b

typedef enum
{
	NX90MPW_MMIO_CFG_XC_SAMPLE0         = 0x00,
	NX90MPW_MMIO_CFG_XC_SAMPLE1         = 0x01,
	NX90MPW_MMIO_CFG_XC_TRIGGER0        = 0x02,
	NX90MPW_MMIO_CFG_XC_TRIGGER1        = 0x03,
	NX90MPW_MMIO_CFG_CAN0_APP_RX        = 0x04,
	NX90MPW_MMIO_CFG_CAN0_APP_TX        = 0x05,
	NX90MPW_MMIO_CFG_CAN1_APP_RX        = 0x06,
	NX90MPW_MMIO_CFG_CAN1_APP_TX        = 0x07,
	NX90MPW_MMIO_CFG_I2C_XPIC_APP_SCL   = 0x08,
	NX90MPW_MMIO_CFG_I2C_XPIC_APP_SDA   = 0x09,
	NX90MPW_MMIO_CFG_I2C_APP_SCL        = 0x0a,
	NX90MPW_MMIO_CFG_I2C_APP_SDA        = 0x0b,
	NX90MPW_MMIO_CFG_SPI_XPIC_APP_CLK   = 0x0c,
	NX90MPW_MMIO_CFG_SPI_XPIC_APP_CS0N  = 0x0d,
	NX90MPW_MMIO_CFG_SPI_XPIC_APP_CS1N  = 0x0e,
	NX90MPW_MMIO_CFG_SPI_XPIC_APP_CS2N  = 0x0f,
	NX90MPW_MMIO_CFG_SPI_XPIC_APP_MISO  = 0x10,
	NX90MPW_MMIO_CFG_SPI_XPIC_APP_MOSI  = 0x11,
	NX90MPW_MMIO_CFG_SPI1_APP_CLK       = 0x12,
	NX90MPW_MMIO_CFG_SPI1_APP_CS0N      = 0x13,
	NX90MPW_MMIO_CFG_SPI1_APP_CS1N      = 0x14,
	NX90MPW_MMIO_CFG_SPI1_APP_CS2N      = 0x15,
	NX90MPW_MMIO_CFG_SPI1_APP_MISO      = 0x16,
	NX90MPW_MMIO_CFG_SPI1_APP_MOSI      = 0x17,
	NX90MPW_MMIO_CFG_UART_XPIC_APP_RXD  = 0x18,
	NX90MPW_MMIO_CFG_UART_XPIC_APP_TXD  = 0x19,
	NX90MPW_MMIO_CFG_UART_XPIC_APP_RTSN = 0x1a,
	NX90MPW_MMIO_CFG_UART_XPIC_APP_CTSN = 0x1b,
	NX90MPW_MMIO_CFG_UART_APP_RXD       = 0x1c,
	NX90MPW_MMIO_CFG_UART_APP_TXD       = 0x1d,
	NX90MPW_MMIO_CFG_UART_APP_RTSN      = 0x1e,
	NX90MPW_MMIO_CFG_UART_APP_CTSN      = 0x1f,
	NX90MPW_MMIO_CFG_GPIO0              = 0x20,
	NX90MPW_MMIO_CFG_GPIO1              = 0x21,
	NX90MPW_MMIO_CFG_GPIO2              = 0x22,
	NX90MPW_MMIO_CFG_GPIO3              = 0x23,
	NX90MPW_MMIO_CFG_GPIO4              = 0x24,
	NX90MPW_MMIO_CFG_GPIO5              = 0x25,
	NX90MPW_MMIO_CFG_GPIO6              = 0x26,
	NX90MPW_MMIO_CFG_GPIO7              = 0x27,
	NX90MPW_MMIO_CFG_WDG_ACT            = 0x28,
	NX90MPW_MMIO_CFG_EN_IN              = 0x29,
	NX90MPW_MMIO_CFG_ETH_MMIO_MDC       = 0x2a,
	NX90MPW_MMIO_CFG_ETH_MMIO_MDIO      = 0x2b,
	NX90MPW_MMIO_CFG_PIO                = 0xff,
} NX90MPW_MMIO_CFG_T;

#define NX90MPW_MMIO_CFG_DISABLE NX90MPW_MMIO_CFG_PIO

#endif

////////////////// autogenerated file end //////////////////
