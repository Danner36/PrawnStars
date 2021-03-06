#include "servo.h"
#include <inc/tm4c123gh6pm.h>

///Rotate servo
/**
 * Set the period of PWM correctly as adjusted for particular bots.
 *
 * @param pulse - length of pulse
 */
void move_servo(int pulse) {
    //Lower 16
    TIMER1_TBILR_R = pulse & 0xFFFF;

    //Upper 8
    TIMER1_TBPR_R = (pulse >> 16) & 0xFF;

    //Set
    TIMER1_TBMATCHR_R = PERIOD & 0xFFFF;
    TIMER1_TBPMR_R = (PERIOD >> 16) & 0xFF;

    //Pause between servo movements
    timer_waitMillis(20);
}
