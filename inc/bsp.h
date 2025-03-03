#ifndef BSP_H
#define BSP_H

#include <stdint.h>
#include <stdbool.h>

/*GPIOA pins.*/
#define OPTOISOLATOR_PIN 0
#define ADT7420_SCL_PIN 9
#define ADT7420_SDA_PIN 10
#define SWDIO_PIN 13
#define SWCLK_PIN 14
#define TDI_PIN 15

/*GPIOB pins.*/
#define SWO_PIN 3

void ms_delay(uint32_t milliseconds);
uint32_t get_tick(void);
void i2c1_write_start(uint8_t address, uint8_t* buffer, uint16_t buffer_size);
void i2c1_read_start(uint8_t address, uint8_t* buffer, uint16_t buffer_size);
void i2c1_transfer_stop(void);
void triac_on(void);
void triac_off(void);
void rtc_wakeup_timer_start(uint16_t seconds);
void irq_enter_stop_mode2(void);
void irq_exit_stop_mode2(void);
bool irq_is_wakeup_timeout(void);
void bsp_init(void);



#endif /*BSP_H*/