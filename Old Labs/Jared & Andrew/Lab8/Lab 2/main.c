#include "button.h"
#include "servo.h"
#include "lcd.h"

#define DEGREE 152

void main() {

    init_PortB();
    clock_timer_init();
    button_init();
    lcd_init();

    int pulse_period = PERIOD + MID;
    float current_degree = 90.0;
    int direction = 1;

    while (1) {

        switch(button_getButton()) {

        //Move 1 degree
       case 1:
           if (direction == -1 && current_degree <= 0) break;
           else if (direction == 1 && current_degree >= 180) break;

           pulse_period += (DEGREE * direction);
           move_servo2(pulse_period);
           current_degree += (float)direction;
           timer_waitMillis(200);
           break;

       //Move 2.5 degrees
       case 2:
           if (direction == -1 && current_degree <= 0) break;
           else if (direction == 1 && current_degree >= 180) break;

           pulse_period += (DEGREE*2.5*direction);
           move_servo2(pulse_period);
           current_degree += (float)direction*2.5;
           timer_waitMillis(200);
           break;

           //Move 5 degrees
       case 3:
           if (direction == -1 && current_degree <= 0) break;
           else if (direction == 1 && current_degree >= 180) break;

           pulse_period += (DEGREE*5*direction);
           move_servo2(pulse_period);
           current_degree += (float)direction*5;
           timer_waitMillis(200);
           break;

       //Switch direction CW or CCW
       case 4:
           direction *= -1;
           timer_waitMillis(200);
           break;

       }

       lcd_printf("Current Degree: %0.1f", current_degree);
    }
}
