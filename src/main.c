#include <stdbool.h>
#include "bsp.h"
#include "pid.h"
#include "adt7420.h"


#define STOP_TIMEOUT 7200
#define RUN_TIMEOUT 3600

#define PID_KP 0.5F
#define PID_KI 0.01F
#define PID_KD 0.01F


#define TARGET_TEMPERATURE 25.0F
#define TARGET_TEMPERATURE_MAX 25.5F
#define TARGET_TEMPERATURE_MIN 24.5F

static struct pid_type pid_heater;
static bool is_running;

static void main_loop(void);

int main(void)
{
    /*Initialize the hardware.*/
    bsp_init();
    /*Initialize the pid values.*/
    pid_manual_tuning(&pid_heater, PID_KP, PID_KI, PID_KD, TARGET_TEMPERATURE);
    /*Start the wakeup timer.*/
    rtc_wakeup_timer_start(RUN_TIMEOUT);
    is_running = true;
    while(1)
    {
        main_loop();
    }
}

static void main_loop(void)
{
    float output = 0;
    float input = adt7420_get_temperature();

    output = pid_calculate_output(&pid_heater, input);

    if (output > TARGET_TEMPERATURE_MAX)
    {
        triac_off();
    }
    else if(output < TARGET_TEMPERATURE_MIN)
    {
        triac_on();
    }
    else
    {
        /*Leave as is.*/
    }

}

/**
 * @brief RTC wakeup interrupt handler.
 * @param  
 */
void RTC_WKUP_IRQHandler(void)
{ 
    if (irq_is_wakeup_timeout() == true)
    {
        /*Enter stop mode 2.*/
        if (is_running == true)
        {
            irq_enter_stop_mode2();
            triac_off();
            rtc_wakeup_timer_start(STOP_TIMEOUT);
        }
        /*Exit stop mode 2.*/
        else
        {
            irq_exit_stop_mode2();
            rtc_wakeup_timer_start(RUN_TIMEOUT);
        }
    }
}