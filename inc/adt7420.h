#ifndef ADT7420_H
#define ADT7420_H

#define ADT7420_BUS_ADDRESS 0x48U
#define ADT7420_TEMP_MSB_ADDR_REG 0x0U
#define ADT7420_TEMP_LSB_ADDR_REG 0x1U

#define ADT7420_TEMP_SIGN_MASK 0x8000U
#define ADT7420_ADC_RESOLUTION 0.0625F

#define ADT7420_POWERUP_CONVERSION_TIMEOUT 6
#define ADT7420_CONVERSION_TIMEOUT 240


float adt7420_get_temperature(void);

#endif /*ADT7420_H*/