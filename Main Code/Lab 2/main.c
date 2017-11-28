//LIBRARIES

#include "init.h"
#include "uart.h" //Lab 5
#include "wifi.h"
#include "adc.h" //Lab 6
#include "sonar.h" //Lab 7
#include "servo.h" //Lab 8
#include <string.h>
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"
#include <stdio.h>
#include <math.h>




/**
 * MAIN PROGRAM. Runs loop, collects data, performs calculations, and transmits data.
 */
void main() {


    //Initializes all devices and variables.
    initialize();

    while(1){

    };
}



/**
 * Initializes all peripherals and resets the position of the device.
 */
void initialize(){

    portB_init();
    adc_init();
    lcd_init();
    uart_init();


    //Enables WiFi.
    int established = WiFi_start("");
    timer_waitMillis(10000);

    //Checks if WiFi has completed initialization.
    WiFi_Check(established);



}


/**
 * Sends current information to Putty.
 */
void sendData(int i){
    char data[50];
    //sprintf(data, "%i\t\t%0.1f\t\t\t%0.2f\t\t\t%0.2f", i, irDis, sonarDis, Comparator.linearWidth);

    uart_sendChar('\r');

    int j = 0;
    for(j = 0; j < strlen(data); j++) {
       uart_sendChar(data[j]);
    }

    uart_sendChar('\n');
}


/**
 * Sends Header information to Putty.
 */
void sendHeader(){

    char* header = "Degrees\t\tIR Distance (cm)\tSonar Distance (cm)\tWidth";

    //Resets the position of the cursor to 2 lines below and the beginning of the line.
    uart_sendChar('\n');
    uart_sendChar('\n');
    uart_sendChar('\r');


    int i = 0;
    //Iterators through the array, sends each character to Putty via WiFi.
    for(i = 0; i < strlen(header); i++){
        uart_sendChar(header[i]);
    }

    //New lines.
    uart_sendChar('\n');
    uart_sendChar('\n');
}
