#ifndef SAM3U1C_H
#define SAM3U1C_H

#ifndef __GNUC__
#error Unsupported compiler.
#endif

typedef enum
{
    Reset_IRQn = -15,
    NMI_IRQn = -14,
    HardFault_IRQn = -13,
    MemManage_IRQn = -12,
    BusFault_IRQn = -11,
    UsageFault_IRQn = -10,
    SecureFault_IRQn = -9,
    SVC_IRQn = -5,
    Debug_Monitor_IRQn = -4,
    PendSV_IRQn = -2,
    SysTick_IRQn = -1,
    WWDG_IRQn = 0,
    PVD_PVM_IRQn = 1,
    RTC_TAMP_IRQn = 2,
    RTC_STAMP_IRQn = RTC_TAMP_IRQn,
    CSS_LSE_IRQn = RTC_TAMP_IRQn,
    RTC_WKUP_IRQn = 3,
    FLASH_IRQn = 4,
    RCC_IRQn = 5,
    EXTI0_IRQn = 6,
    EXTI1_IRQn = 7,
    EXTI2_IRQn = 8,
    EXTI3_IRQn = 9,
    EXTI4_IRQn = 10,
    DMA1_CH1_IRQn = 11,
    DMA1_CH2_IRQn = 12,
    DMA1_CH3_IRQn = 13,
    DMA1_CH4_IRQn = 14,
    DMA1_CH5_IRQn = 15,
    DMA1_CH6_IRQn = 16,
    DMA1_CH7_IRQn = 17,
    ADC1_2_IRQn = 18,
    EXTI9_5_IRQn = 23,
    TIM1_BRK_IRQn = 24,
    TIM15_IRQn = TIM1_BRK_IRQn,
    TIM1_UP_IRQn = 25,
    TIM16_IRQn = TIM1_UP_IRQn,
    TIM1_TRG_COM_IRQn = 26,
    TIM1_CC_IRQn = 27,
    TIM2_IRQn = 28,
    I2C1_EV_IRQn = 31,
    I2C1_ER_IRQn = 32,
    I2C2_EV_IRQn = 33,
    I2C2_ER_IRQn = 34,
    SPI1_IRQn = 35,
    SPI2_IRQn = 36,
    USART1_IRQn = 37,
    USART2_IRQn = 38,
    USART3_IRQn = 39,
    EXTI15_10_IRQn = 40,
    RTC_ALARM_IRQn = 41,
    SPI3_IRQn = 51,
    TIM6_IRQn = 54,
    DMA2_CH1_IRQn = 56,
    DMA2_CH2_IRQn = 57,
    DMA2_CH3_IRQn = 58,
    DMA2_CH4_IRQn = 59,
    DMA2_CH5_IRQn = 60,
    COMP_IRQn = 64,
    LPTIM1_IRQn = 65,
    LPTIM2_IRQn = 66,
    USB_IRQn = 67,
    DMA2_CH6_IRQn = 68,
    DMA2_CH7_IRQn = 69,
    LPUART1_IRQn = 70,
    QUADSPI_IRQn = 71,
    I2C3_EV_IRQn = 72,
    I2C3_ER_IRQn = 73,
    TSC_IRQn = 77,
    RNG_IRQn = 80,
    FPU_IRQn = 81,
    CRS_IRQn = 82,
 }IRQn_Type;

/* ================    Configuration of Core Peripherals    ================ */
#define __CM4_REV               0x0001U  /* Core Revision r0p1 */
#define __Vendor_SysTickConfig  0U       /* Set to 1 if different SysTick Config is used */
#define __NVIC_PRIO_BITS        4U       /* Number of Bits used for Priority Levels */
#define __VTOR_PRESENT          1U       /* Set to 1 if VTOR is present */
#define __MPU_PRESENT           1U       /* Set to 1 if MPU is present */
#define __FPU_PRESENT           1U       /* Set to 1 if FPU is present */
#define __FPU_DP                0U       /* Set to 1 if FPU is double precision FPU (default is single precision FPU) */
#define __DSP_PRESENT           0U       /* Set to 1 if DSP extension are present */
#define __SAUREGION_PRESENT     0U       /* Set to 1 if SAU regions are present */
#define __PMU_PRESENT           0U       /* Set to 1 if PMU is present */
#define __PMU_NUM_EVENTCNT      0U       /* Set number of PMU Event Counters */
#define __ICACHE_PRESENT        1U       /* Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT        1U       /* Set to 1 if D-Cache is present */
#define __DTCM_PRESENT          0U       /* Set to 1 if DTCM is present */

#define __PROGRAM_START /*!< Custom Startup Code is used. */

#include "core_cm4.h"
#include "utils.h"

/*Struct specific definitions for registers.*/
typedef __IM uint32_t __RO; /*!< Register is Read-Only.*/
typedef __OM uint32_t __WO; /*!< Register is Write-Only.*/
typedef __IOM uint32_t __RW; /*!< Register is Read-Write.*/
#define RESERVED uint32_t CONCAT(Reserved, __LINE__) /*!< Register is reserved*/


#define MAIN_CLOCK_MAX_FREQUENCY 80000000

#include "flash.h"
#include "pwr.h"
#include "rcc.h"
#include "gpio.h"
#include "i2c.h"
#include "rtc.h"





 


#endif /*SAM3U1C_H*/