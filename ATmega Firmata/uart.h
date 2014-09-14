/*

  Project:       1Sheeld Firmware 
  File:          uart.h

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef UART_H_
#define UART_H_
#include "CommonMacros.h"
#include "sys.h"

#define UART_RX0_INTERRUPT ENABLED
#define UART_RX1_INTERRUPT ENABLED 
#define UART_RX1_BUFFER_SIZE     64
#define UART_RX1_BUFFER_MASK     ( UART_RX1_BUFFER_SIZE - 1)
#define UART1_STATUS   UCSR1A
#define UART1_DATA     UDR1
#define UART0_RX0_BUFFER_SIZE    256
#define UART0_RX0_BUFFER_MASK    ( UART0_RX0_BUFFER_SIZE - 1)
#define UART0_STATUS   UCSR0A
#define UART0_DATA     UDR0

//Error codes
#define UART_NO_DATA          -1              /**< no receive data available   */
#define UART_BUFFER_OVERFLOW  -2              /**< receive ringbuffer overflow */

//#include "sys.h"

void UartInit(uint8 serialPort);
void UartEnd(uint8 serialPort);
void UartTx0(unsigned char data);
void UartTx1(uint8_t data);
int  UartRx0();
int  UartRx1();
#if UART_RX0_INTERRUPT == ENABLED
    int getuartRx1Flag();
    int getuartRx0Flag();
#endif

#endif /* UART_H_ */