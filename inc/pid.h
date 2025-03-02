#ifndef PID_H
#define PID_H

#include <stdint.h>

struct pid_type
{

	float kp;
	float ki;
	float kd;

	uint32_t previous_tick;
	float previous_error;
	float error_sum;
	float desired_value;
};

float pid_calculate_output(struct pid_type* pid, float input);
void pid_manual_tuning(struct pid_type* pid, float kp, float ki, float kd, float desired_value);

#endif /*PID_H*/