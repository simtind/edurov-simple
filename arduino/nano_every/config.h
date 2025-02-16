#ifndef _EDUROV_CONFIG_H_
#define _EDUROV_CONFIG_H_

// Set to true if compiling for Arduino nano 33 ble sense.
#define HAS_ONBOARD_SENSORS false

// ----- Other I/O -----
#define PIN_SENSE_BATTERY A5
#define PIN_SENSE_PRESSURE A6
#define PIN_SENSE_TEMPERATURE A7

#define SENSOR_SCALE 100

#define BATTERY_ADC_TO_VOLT(adc_value)     map(adc_value,  0, 1023, 0, 150.0f)  // 0V to 5V in, multiply by 3 for divider.
#define PRESSURE_ADC_TO_KPA(adc_value)     map(adc_value, 41, 1023, 0, 250.0f) // 0.2V to 5V -> 0kPa to 250kPa
#define TEMPERATURE_ADC_TO_DEGC(adc_value) map(adc_value,  0, 1023, 0, 50.0f)  // 5V / (10mV / degC) = 50 degC  

#define PIN_LED_PWM 3

// ---- Motor I/O -----

#define PIN_SENSE_MOTOR1 A3
#define PIN_SENSE_MOTOR2 A2
#define PIN_SENSE_MOTOR3 A1
#define PIN_SENSE_MOTOR4 A0
#define MOTOR_ADC_TO_A(adc_value)         map(adc_value, 0, 1023, -5.0, 5.0)

// Select motor I/O pins so that we can use hw PWM outputs.
#define MOTOR_DIR_VAL(thrust, forward_val) (thrust > 0 ? forward_val : !forward_val)
#define MOTOR_PWM_VAL(thrust, dir_val)     (dir_val ? map(abs(thrust), 0, 1023, 255, 0) : map(abs(thrust), 0, 1023, 0, 255))

#define PIN_MOTOR_ENABLE 2

#define PIN_MOTOR1_PWM 5         // IO1B
#define PIN_MOTOR1_DIR 4         // IO1A
#define MOTOR1_DIR_VAL(thrust) MOTOR_DIR_VAL(thrust, true) // DIR is A-pin, so set it high for positive motor voltage

#define PIN_MOTOR2_PWM 6  // IO2A
#define PIN_MOTOR2_DIR 7  // IO2B
#define MOTOR2_DIR_VAL(thrust) MOTOR_DIR_VAL(thrust, false) // DIR is B-pin, so set it low for positive motor voltage

#define PIN_MOTOR3_PWM 9  // IO3B
#define PIN_MOTOR3_DIR 8  // IO3A
#define MOTOR3_DIR_VAL(thrust) MOTOR_DIR_VAL(thrust, true) // DIR is A-pin, so set it high for positive motor voltage

#define PIN_MOTOR4_PWM 10 // IO4A
#define PIN_MOTOR4_DIR 11 // IO4B
#define MOTOR4_DIR_VAL(thrust) MOTOR_DIR_VAL(thrust, false) // DIR is B-pin, so set it low for positive motor voltage

#endif /* _EDUROV_CONFIG_H_ */
