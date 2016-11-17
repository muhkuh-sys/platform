#include "asic_types.h"


#ifndef __UART_STANDALONE_H__
#define __UART_STANDALONE_H__


void uart_standalone_initialize(void);

#if ASIC_TYP==ASIC_TYP_NETX4000_RELAXED
void rap_uart_standalone_initialize(void);
#endif


#endif  /* __UART_STANDALONE_H__ */
