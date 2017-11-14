/*
 * movement.c
 *
 *  Created on: Sep 7, 2017
 *      Author: Jared & Andrew
 */
#include "open_interface.h"

int move_forward(oi_t *sensor, int centimeters) {

    int sum = 0;
    oi_setWheels(250, 250); // move forward;
    while (sum < centimeters) {
        oi_update(sensor);

        if(sensor->bumpLeft || sensor->bumpRight){
            oi_setWheels(0, 0); // stop
            return sum;
        }

        sum += sensor->distance;
    }
    oi_setWheels(0, 0); // stop

    return sum;
}

void turn_ccw(oi_t *sensor, int degrees) {
    int sum = 0;
    oi_setWheels(250, -250); // move forward;
    while (sum < degrees) {
        oi_update(sensor);
        sum += sensor->angle;
    }
    oi_setWheels(0, 0); // stop

}

void turn_cw(oi_t *sensor, int degrees) {
    int sum = degrees;
    oi_setWheels(-250, 250); // move forward;
    while (sum > 0) {
        oi_update(sensor);
        sum += sensor->angle;
    }
    oi_setWheels(0, 0); // stop

}

void move_backward(oi_t *sensor) {
    int sum = 150;
    oi_setWheels(-250, -250); // move forward;
    while (sum > 0) {
        oi_update(sensor);
        sum += sensor->distance;
    }
    oi_setWheels(0, 0); // stop
}