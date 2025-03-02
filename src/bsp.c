#include "stm32l412.h"
#include "bsp.h"

__STATIC_INLINE void gpio_setup(void);
__STATIC_INLINE void rtc_setup(void);

/**
 * @brief Sets all gpios to analog with a pull-down resistor, to minimize consumption
          at the initialization of the device. Keeps the debug pins to the default values 
		  if debug is needed.
 * @param  
 * @return 
 */
__STATIC_INLINE void gpio_setup(void)
{
	/*Enable peripheral clock.*/
	RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOAEN);

#if defined(NDEBUG)
	/*Set all GPIO to analog.*/
	GPIOA->MODER = 0xFFFFFFFFUL;
	GPIOA->OSPEEDR = 0;
	/*Set all GPIO to pull down.*/
	GPIOA->PUPDR = 0xAAAAAAAAUL;
#else
	/*Set SWDIO, SWCLK to alternate function. Set all other GPIO to analog.*/
	GPIOA->MODER = ((0xFFFFFFFFUL & ~(GPIO_MODER_Msk(TDI_PIN) | GPIO_MODER_Msk(SWCLK_PIN) | GPIO_MODER_Msk(SWDIO_PIN)))
		| (GPIO_MODER_ALTERNATE_FUNCTION(TDI_PIN) | GPIO_MODER_ALTERNATE_FUNCTION(SWCLK_PIN) | GPIO_MODER_ALTERNATE_FUNCTION(SWDIO_PIN)));
	/*Set SWDIO to very high speed.*/
	GPIOA->OSPEEDR = GPIO_OSPEEDR_VERY_HIGH_SPEED(SWDIO_PIN);
	/*Set TDI and SWDIO to pull-up. Set all other GPIO to pull down.*/
	GPIOA->PUPDR = ((0xAAAAAAAAUL & ~(GPIO_PUPDR_Msk(TDI_PIN) | GPIO_PUPDR_Msk(SWDIO_PIN)))
		| (GPIO_PUPDR_PULLUP(TDI_PIN) | GPIO_PUPDR_PULLUP(SWDIO_PIN)));
#endif
	GPIOA->OTYPER = 0;
	GPIOA->AFRH = 0;
	GPIOA->AFRL = 0;

#if defined(NDEBUG)
	/*Set all GPIO to analog.*/
	GPIOB->MODER = 0xFFFFFFFFUL;
	/*Set all GPIO to pull down.*/
	GPIOB->PUPDR = 0xAAAAAAAAUL;
#else
	/*Set SWO to alternate function. Set all other GPIO to analog.*/
	GPIOB->MODER = ((0xFFFFFFFFUL & ~GPIO_MODER_Msk(SWO_PIN))
		| GPIO_MODER_ALTERNATE_FUNCTION(SWO_PIN));
	/*Set SWO to pull-up. Set all other GPIO to pull down.*/
	GPIOB->PUPDR = ((0xAAAAAAAAUL & ~GPIO_PUPDR_Msk(SWO_PIN))
		| GPIO_PUPDR_PULLUP(SWO_PIN));
#endif
	GPIOB->OSPEEDR = 0;
	GPIOB->OTYPER = 0;
	GPIOB->AFRH = 0;
	GPIOB->AFRL = 0;
}

/**
 * @brief Starts the LSE oscillator and enables the RTC. 
 * @param  
 * @return 
 */
__STATIC_INLINE void rtc_setup(void)
{
	/*Enable access to backup domain.*/
	PWR->CR1 |= PWR_CR1_DBP;
	/*Set LSE to maximum drive capability.*/
	RCC->BDCR |= RCC_BDCR_LSEDRV_HIGHEST_DRIVE;
	/*Enable LSE.*/
	RCC->BDCR |= RCC_BDCR_LSEON;
	/*Wait until LSE is ready.*/
	while ((RCC->BDCR & RCC_BDCR_LSERDY) != RCC_BDCR_LSERDY);

	/*Select LSE as the source clock of RTC.*/
	RCC->BDCR |= RCC_BDCR_RTCSEL_LSE;
	/*Disable propagation (Use LSE only for RTC).*/
	RCC->BDCR |= RCC_BDCR_LSESYSDIS;
	/*Enable RTC.*/
	RCC->BDCR |= RCC_BDCR_RTCEN;
	/*RTC prescaler is left to default which will produce 1 Hz frequency.*/

	/*Configure wakeup interrupt to the lowest priority and enable interrupt line.*/
	NVIC_SetPriority(RTC_WKUP_IRQn, 0xFUL);
	NVIC_EnableIRQ(RTC_WKUP_IRQn);
}

/**
 * @brief Enable oscillator and clocks that were disabled.
 * @param  
 */
void reenable_peripheral_clocks(void)
{
	/*Enable Syscfg clock*/
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	/*Enable pwr clock*/
	RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN;
	/*Enable gpio clocks.*/
	RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN);
	/*Enable I2C1 clock.*/
	RCC->APB1ENR1 |= RCC_APB1ENR1_I2C1EN;

}

/**
 * @brief Gets the current value in the Cycle Count Register.
 * @param  
 * @return The current value of the Cycle Count Register.
 */
uint32_t get_tick(void)
{
	return DWT->CYCCNT;
}

/**
 * @brief Initialize clocks and I/O for the I2C1 peripheral.
 * @param  
 */
void i2c1_setup(void)
{
	/*Enable peripheral clocks.*/
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;	
	RCC->APB1ENR1 |= RCC_APB1ENR1_I2C1EN;

	GPIOA->MODER &= ~(GPIO_MODER_Msk(ADT7420_SDA_PIN) | GPIO_MODER_Msk(ADT7420_SCL_PIN));
	GPIOA->MODER |= (GPIO_MODER_ALTERNATE_FUNCTION(ADT7420_SDA_PIN) | GPIO_MODER_ALTERNATE_FUNCTION(ADT7420_SCL_PIN));
	GPIOA->OTYPER |= ((0x1UL << ADT7420_SDA_PIN) | (0x1UL << ADT7420_SCL_PIN));
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_Msk(ADT7420_SDA_PIN) | GPIO_OSPEEDR_Msk(ADT7420_SCL_PIN));
	GPIOA->OSPEEDR |= (GPIO_OSPEEDR_VERY_HIGH_SPEED(ADT7420_SDA_PIN) | GPIO_OSPEEDR_VERY_HIGH_SPEED(ADT7420_SCL_PIN));
	GPIOA->AFRH &= ~(GPIO_AFRH_Msk(ADT7420_SDA_PIN) | GPIO_AFRH_Msk(ADT7420_SCL_PIN));
	GPIOA->AFRH |= (GPIO_AFRH(4, ADT7420_SDA_PIN) | GPIO_AFRH(4, ADT7420_SCL_PIN));

	/*Disable I2C.*/
	I2C1->CR1 &= ~I2C_CR1_PE;
	/*Configure the timings.*/
	/*Value is calculated from CUBEMX for 400KHz I2C at 4Mhz SYSCLK.*/
	I2C1->TIMINGR = 0x4UL;
	/*Enable I2C.*/
	I2C1->CR1 |= I2C_CR1_PE;
}

/**
 * @brief Transmit data in blocking mode using the I2C1 peripheral.
 * @param address Target address.
 * @param buffer Pointer to the data buffer to transmit.
 * @param buffer_size Size of the data buffer to tranmit.
 */
void i2c1_write_start(uint8_t address, uint8_t* buffer, uint16_t buffer_size)
{
	uint8_t* src = buffer;
	uint16_t cnt = buffer_size;
	/*Begin writing data.*/
	I2C1->CR2 = I2C_CR2_NBYTES(cnt) | I2C_CR2_START | I2C_CR2_SADD_7_1(address);
	/*Send the data.*/
	while (cnt)
	{
		if ((I2C1->ISR & I2C_ISR_TXIS) == I2C_ISR_TXIS)
		{
			I2C1->TXDR = *src++;
			cnt--;
		}
	}
	/*Wait for the completion flag to be set.*/
	while ((I2C1->ISR & I2C_ISR_TC) != I2C_ISR_TC);
}

/**
 * @brief Receive data in blocking mode using the I2C1 peripheral.
 * @param address Target address.
 * @param buffer Pointer to the data to receive.
 * @param buffer_size Size of the data buffer.
 */
void i2c1_read_start(uint8_t address, uint8_t* buffer, uint16_t buffer_size)
{
	uint8_t* dst = buffer;
	uint16_t cnt = buffer_size;
	/*Begin writing data.*/
	I2C1->CR2 = I2C_CR2_NBYTES(cnt) | I2C_CR2_START | I2C_CR2_SADD_7_1(address);
	/*Send the data.*/
	while (cnt)
	{
		if ((I2C1->ISR & I2C_ISR_TXIS) == I2C_ISR_TXIS)
		{
			*dst++ = I2C1->RXDR;
			cnt--;
		}
	}
	/*Wait for the completion flag to be set.*/
	while ((I2C1->ISR & I2C_ISR_TC) != I2C_ISR_TC);
}

/**
 * @brief Stops the current data transfer of I2C1 peripheral.
 * @param  
 */
void i2c1_transfer_stop(void)
{
	I2C1->CR2 = I2C_CR2_STOP;
}

/**
 * @brief Initialize clocks and I/O for triac pin.
 * @param  
 */
void triac_setup(void)
{
	/*Enable peripheral clock.*/
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

	GPIOA->MODER &= ~GPIO_MODER_Msk(OPTOISOLATOR_PIN);
	GPIOA->MODER |= GPIO_MODER_OUTPUT(OPTOISOLATOR_PIN);
	GPIOA->OTYPER &= ~(0x1UL << OPTOISOLATOR_PIN);
	GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_Msk(OPTOISOLATOR_PIN);
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_VERY_HIGH_SPEED(OPTOISOLATOR_PIN);
	/*Set to high.*/
	GPIOA->ODR |= (0x1UL << OPTOISOLATOR_PIN);
}

/**
 * @brief Turns on the triac.
 * @param  
 */
void triac_on(void)
{
	GPIOA->ODR &= ~(0x1UL << OPTOISOLATOR_PIN);
}

/**
 * @brief Turns off the triac.
 * @param  
 */
void triac_off(void)
{
	GPIOA->ODR |= (0x1UL << OPTOISOLATOR_PIN);
}

/**
 * @brief Begins the RTC peripheral wakeup counter.
 * @param seconds Time in seconds until the RTC peripheral causes an interrupt. 
 */
void rtc_wakeup_timer_start(uint16_t seconds)
{
	/*Enable RTC access.*/
	RTC->WPR = RTC_WPR_KEY0;
	RTC->WPR = RTC_WPR_KEY1;
	/*Disable wakeup timer .*/
	RTC->CR &= ~RTC_CR_WUTE;
	/*Wait until wakeup timer flag is set.*/
	while ((RTC->ICSR & RTC_ICSR_WUTWF) != RTC_ICSR_WUTWF);
	/*Set the Wakeup timer.*/
	RTC->WUTR = RTC_WUTR_WUT((seconds - 1));
	/*Set the wakeup period between 1s and 18 hours.*/
	RTC->CR &= ~RTC_CR_WUCKSEL_Msk;
	RTC->CR |= RTC_CR_WUCKSEL_MEDIUM_WAKEUP_PERIOD;
	/*Enable wakeup timer and wakeup interrupt.*/
	RTC->CR |= (RTC_CR_WUTE | RTC_CR_WUTIE);
	/*Disable RTC access.*/
	RTC->WPR = RTC_WPR_KEY_Msk;
}

/**
 * @brief Initialize the hardware.
 * @param  
 */
void bsp_init(void)
{
	/*Enable SYSCFGEN clock.*/
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	/*Enable PWR clock.*/
	RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN;
	/*Prepare for stop 2 mode.*/
	PWR->CR1 &= ~PWR_CR1_LPMS_Msk;
	PWR->CR1 |= PWR_CR1_LPMS_STOP_2; 
	/*Enable prefetch.*/
	FLASH->ACR |= FLASH_ACR_PRFTEN;
	rtc_setup();
	gpio_setup();
	i2c1_setup();
	triac_setup();
}






