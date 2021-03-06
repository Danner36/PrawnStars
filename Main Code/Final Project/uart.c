#include "uart.h"

///Initialize USART1
/**
 * Uses GPIO Port B, Pin 1B.
 * Sets baud rate.
 */
void uart_init(void) {

    //enable clock to GPIO, R1 = port B
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;

    //enable clock to UART1, R1 = UART1. ***Must be done before setting Rx and Tx (See DataSheet)
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R1;

    //enable alternate functions on port b pins 0 and 1
    GPIO_PORTB_AFSEL_R |= (BIT0 | BIT1);

    //enable Rx and Tx on port B on pins 0 and 1
    GPIO_PORTB_PCTL_R |= 0x00000011;

    //set pin 0 and 1 to digital
    GPIO_PORTB_DEN_R |= (BIT0 | BIT1);

    //set pin 0 to Rx or input
    GPIO_PORTB_DIR_R &= ~BIT0;

    //set pin 1 to Tx or output
    GPIO_PORTB_DIR_R |= BIT1;

    //calculate baudrate
    uint16_t iBRD = 8;
    uint16_t fBRD = 44;

    //turn off uart1 while we set it up
    UART1_CTL_R &= ~(UART_CTL_UARTEN);

    //set baud rate
    UART1_IBRD_R = iBRD;
    UART1_FBRD_R = fBRD;

    //set frame, 8 data bits, 1 stop bit, no parity, no FIFO
    UART1_LCRH_R = UART_LCRH_WLEN_8 ;

    //use system clock as source
    UART1_CC_R = UART_CC_CS_SYSCLK;

    //re-enable enable RX, TX, and uart1
    UART1_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
}

///Blocking call to receive over uart1.
/**
 * Waits in a while loop for received data.
 * Returns char with data just received.
 */
char uart_receive(){
    char data = 0;

    //wait to receive
    while(UART1_FR_R & UART_FR_RXFE){ }

     //mask the 4 error bits and grab only 8 data bits
    data = (char)(UART1_DR_R & 0xFF);

    return data;
}

///Blocking call that sends a single char over UART 1
/**
 * @param data - data to transmit
 */
void uart_sendChar(char data)
{
    //wait until there is room to send data
    while(UART1_FR_R & 0x20){
        //Do not put any code here
    }

    //send data
    UART1_DR_R = data;
}

