/*
 * motion_control.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Nchow
 */
#ifndef MOTION_CONTROL_C
#define MOTION_CONTROL_C

#include "motion_control.h"
#include "stm32f4xx_hal.h" // Include necessary STM32 HAL library

// Define GPIO ports and pins for motion sensor and two stepper motors
#define MOTION_SENSOR_PORT GPIOA
#define MOTION_SENSOR_PIN GPIO_PIN_0 // Replace with actual pin for the motion sensor

#define STEPPER_MOTOR_1_PORT GPIOA
#define STEPPER_MOTOR_1_PIN_1 GPIO_PIN_1 // Replace with actual pins for the first motor
#define STEPPER_MOTOR_1_PIN_2 GPIO_PIN_2
#define STEPPER_MOTOR_1_PIN_3 GPIO_PIN_3
#define STEPPER_MOTOR_1_PIN_4 GPIO_PIN_4

#define STEPPER_MOTOR_2_PORT GPIOB
#define STEPPER_MOTOR_2_PIN_1 GPIO_PIN_5 // Replace with actual pins for the second motor
#define STEPPER_MOTOR_2_PIN_2 GPIO_PIN_6
#define STEPPER_MOTOR_2_PIN_3 GPIO_PIN_7
#define STEPPER_MOTOR_2_PIN_4 GPIO_PIN_8

int check_motion_sensor() {
    if (HAL_GPIO_ReadPin(MOTION_SENSOR_PORT, MOTION_SENSOR_PIN) == GPIO_PIN_SET) {
        return 1; // Motion detected
    } else {
        return 0; // No motion
    }
}

void move_both_stepper_motors() {
    // Sequence for both stepper motors (assuming the same sequence for both)
    uint16_t step_sequence[4] = {STEPPER_MOTOR_1_PIN_1 | STEPPER_MOTOR_2_PIN_1,
                                 STEPPER_MOTOR_1_PIN_2 | STEPPER_MOTOR_2_PIN_2,
                                 STEPPER_MOTOR_1_PIN_3 | STEPPER_MOTOR_2_PIN_3,
                                 STEPPER_MOTOR_1_PIN_4 | STEPPER_MOTOR_2_PIN_4};

    // Perform stepping sequence to move both motors simultaneously
    for (int i = 0; i < 4; i++) {
        HAL_GPIO_WritePin(STEPPER_MOTOR_1_PORT, step_sequence[i], GPIO_PIN_SET);
        HAL_GPIO_WritePin(STEPPER_MOTOR_2_PORT, step_sequence[i], GPIO_PIN_SET);
        HAL_Delay(10); // Adjust delay based on motor speed
        HAL_GPIO_WritePin(STEPPER_MOTOR_1_PORT, step_sequence[i], GPIO_PIN_RESET);
        HAL_GPIO_WritePin(STEPPER_MOTOR_2_PORT, step_sequence[i], GPIO_PIN_RESET);
        HAL_Delay(10); // Adjust delay based on motor speed
    }
}
#endif /* MOTION_CONTROL_C_ */

