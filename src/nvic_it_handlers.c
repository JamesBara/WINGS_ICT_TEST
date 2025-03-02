#include "cmsis_gcc.h"

void NMI_Handler(void)
{
#if (!NDEBUG)
    __BKPT(0);
#else
    NVIC_SystemReset();
#endif
    while (1);
}

void HardFault_Handler(void)
{
#if (!NDEBUG)
    __BKPT(0);
#else
    NVIC_SystemReset();
#endif
    while (1);
}

void MemManage_Handler(void)
{
#if (!NDEBUG)
    __BKPT(0);
#else
    NVIC_SystemReset();
#endif
    while (1);
}

void BusFault_Handler(void)
{
#if (!NDEBUG)
    __BKPT(0);
#else
    NVIC_SystemReset();
#endif
    while (1);
}

void UsageFault_Handler(void)
{
#if (!NDEBUG)
    __BKPT(0);
#else
    NVIC_SystemReset();
#endif
    while (1);
}

void SecureFault_Handler(void)
{
#if (!NDEBUG)
    __BKPT(0);
#else
    NVIC_SystemReset();
#endif
    while (1);
}

void SVC_Handler(void)
{
#if (!NDEBUG)
    __BKPT(0);
#else
    NVIC_SystemReset();
#endif
    while (1);
}
void Debug_Handler(void)
{
#if (!NDEBUG)
    __BKPT(0);
#else
    NVIC_SystemReset();
#endif
    while (1);
}

void PendSV_Handler(void)
{
#if (!NDEBUG)
    __BKPT(0);
#else
    NVIC_SystemReset();
#endif
    while (1);
}