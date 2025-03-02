#include <stdbool.h>
#include "stm32l412.h"
#include "bsp.h"
#include "pid.h"
#include "adt7420.h"

#define PID_KP 0.5F
#define PID_KI 0.01F
#define PID_KD 0.01F

#define TARGET_TEMPERATURE 25.0F


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
    rtc_wakeup_timer_start(3600);
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

    if (output >= TARGET_TEMPERATURE)
    {
        triac_off();
    }
    else
    {
        triac_on();
    }
}


void RTC_WKUP_IRQHandler(void)
{
    
    if ((RTC->SR & RTC_SR_WUTF) == RTC_SR_WUTF)
    {
        /*Clear the interrupt.*/
        RTC->SCR = RTC_CSR_CWUTF;
        /*Enter stop mode 2.*/
        if (is_running == true)
        {
            triac_off();
            SCB->SCR |= (SCB_SCR_SLEEPDEEP_Msk | SCB_SCR_SLEEPONEXIT_Msk);
            rtc_wakeup_timer_start(7200);
        }
        /*Exit stop mode 2.*/
        else
        {
            SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk | SCB_SCR_SLEEPONEXIT_Msk);
            reenable_peripheral_clocks();
            rtc_wakeup_timer_start(3600);
        }

    }
}