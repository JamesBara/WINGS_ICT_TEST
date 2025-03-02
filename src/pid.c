#include "bsp.h"
#include "pid.h"


/**
 * @brief Perform pid calculations.
 * @param pid A struct that contains all the pid info.
 * @param input Measurement that want to perfom calculations to.
 * @return Result of PID calculations.
 */
float pid_calculate_output(struct pid_type *pid, float input)
{
	float p, i, d, err, tick, dt;

	tick = get_tick();
	dt = (float)(tick - pid->previous_tick);
	err = pid->desired_value - input;
	pid->error_sum += (err * dt);

	p = pid->kp * err;
	i = pid->ki * pid->error_sum;
	d = pid->kd * ((err - pid->previous_error) / dt);

	pid->previous_tick = tick;
	pid->previous_error = err;

	return (p + d + i);
}

/**
 * @brief Register the tuning info to the pid struct.
 * @param pid A struct that contains all the pid info.
 * @param kp Value of the manually calculated Kp.
 * @param ki Value of the manually calculated Ki.
 * @param kd Value of the manually calculated Kd.
 * @param desired_value Constant that the pid is trying to achieve.
 */
void pid_manual_tuning(struct pid_type* pid, float kp, float ki, float kd, float desired_value)
{
	pid->desired_value = desired_value;
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
}