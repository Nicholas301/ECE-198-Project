/*
 * motion_control.h
 *
 *  Created on: Nov 15, 2023
 *      Author: Nchow
 */

#ifndef MOTION_CONTROL_H_
#define MOTION_CONTROL_H_

#include "main.h" // Include necessary STM32CubeIDE main header

#include "stm32f4xx_hal.h" // Include necessary STM32 HAL library

#define MOTION_SENSOR_PORT GPIOA
#define MOTION_SENSOR_PIN GPIO_PIN_0 // Replace with actual pin for the motion sensor

#define STEPPER_MOTOR_1_PORT GPIOA
#define STEPPER_MOTOR_1_PIN_1 GPIO_PIN_0 // Replace with actual pins for the first motor
// Define other pins for motor 1

#define STEPPER_MOTOR_2_PORT GPIOB
#define STEPPER_MOTOR_2_PIN_1 GPIO_PIN_4 // Replace with actual pins for the second motor
// Define other pins for motor 2

void move_both_stepper_motors(void);
int check_motion_sensor(void);

#endif /* MOTION_CONTROL_H_ */
