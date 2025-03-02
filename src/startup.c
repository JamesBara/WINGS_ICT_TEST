#include "stm32l412.h"

extern uint32_t __stack_top__;
typedef void(*__isr_vector_type)(void);

extern int main(void);

void Reset_Handler(void);
void Default_Handler(void);

#define STM32L412

void NMI_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler (void) __attribute__ ((weak));
void MemManage_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void SecureFault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void Debug_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler (void) __attribute__ ((weak, alias("Default_Handler")));

void WWDG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_PVM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_TAMP_STAMP_CSS_LSE_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC1_2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM15_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM16_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_ALARM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_CH1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_CH2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_CH3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_CH4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_CH5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void COMP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LPTIM1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LPTIM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USB_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_CH6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_CH7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LPUART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void QUADSPI_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TSC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RNG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CRS_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

const __isr_vector_type __isr_vector_table[] __attribute__((section(".isr_vector"))) =
{ 
    (__isr_vector_type)(&__stack_top__),
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    SecureFault_Handler,
    0,
    0,
    0,
    SVC_Handler,
    Debug_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,
    WWDG_IRQHandler,
    PVD_PVM_IRQHandler,
    RTC_TAMP_STAMP_CSS_LSE_IRQHandler,
    RTC_WKUP_IRQHandler,
    FLASH_IRQHandler,
    RCC_IRQHandler,
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA1_CH1_IRQHandler,
    DMA1_CH2_IRQHandler,
    DMA1_CH3_IRQHandler,
    DMA1_CH4_IRQHandler,
    DMA1_CH5_IRQHandler,
    DMA1_CH6_IRQHandler,
    DMA1_CH7_IRQHandler,
    ADC1_2_IRQHandler,
    0,
    0,
    0,
    0,
    EXTI9_5_IRQHandler,
    TIM1_BRK_TIM15_IRQHandler,
    TIM1_UP_TIM16_IRQHandler,
    TIM1_TRG_COM_IRQHandler,
    TIM1_CC_IRQHandler,
    TIM2_IRQHandler,
    0,       
    0,
    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    I2C2_EV_IRQHandler,
    I2C2_ER_IRQHandler,  
    SPI1_IRQHandler,
    SPI2_IRQHandler,
    USART1_IRQHandler,
    USART2_IRQHandler,  
    USART3_IRQHandler, 
    EXTI15_10_IRQHandler,
    RTC_ALARM_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0, 
    0,
    SPI3_IRQHandler,
    0,
    0,
    TIM6_IRQHandler,
    0,
    DMA2_CH1_IRQHandler,
    DMA2_CH2_IRQHandler,
    DMA2_CH3_IRQHandler,
    DMA2_CH4_IRQHandler,
    DMA2_CH5_IRQHandler,
    0,
    0,     
    0,
    COMP_IRQHandler,
    LPTIM1_IRQHandler,
    LPTIM2_IRQHandler,
    USB_IRQHandler,      
    DMA2_CH6_IRQHandler,
    DMA2_CH7_IRQHandler,
    LPUART1_IRQHandler,
    QUADSPI_IRQHandler,
    I2C3_EV_IRQHandler,
    I2C3_ER_IRQHandler,
    0,      
    0,
    0,
    TSC_IRQHandler,
    0,  
    0,
    RNG_IRQHandler,
    FPU_IRQHandler,
    CRS_IRQHandler,
    0,
    0 
};

void Reset_Handler(void)
{
    extern uint32_t __rom_data_start__;
    extern uint32_t __data_start__;
    extern uint32_t __data_end__;
    extern uint32_t __bss_start__;
    extern uint32_t __bss_end__;

    uint32_t *data_start = &__data_start__, *data_end = &__data_end__, *rom_data_start = &__rom_data_start__,
        *bss_start = &__bss_start__, *bss_end = &__bss_end__;

    /*Copy flash data section to sram data section*/
    while (data_start < data_end)
    {
        *data_start++ = *rom_data_start++;
    }

    /*Empty bss section from uninitialized global variables*/
    while (bss_start < bss_end)
    {
        *bss_start++ = 0x0U;
    }

    /*Set the Vector Table Address.*/
    SCB->VTOR = (uint32_t)(&__isr_vector_table);
    main();
}

void Default_Handler(void)
{
    while (1);
}