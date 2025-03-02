#include <stdbool.h>
#include "adt7420.h"
#include "bsp.h"

/**
 * @brief Get the current temperature from the adt7420 sensor.
 * @param  
 * @return Current temperature.
 */
float adt7420_get_temperature(void)
{
	uint8_t reg_addr = ADT7420_TEMP_MSB_ADDR_REG;
	uint16_t temp = 0;
	bool is_negative = false;
	float ret = 0;
	i2c1_write_start(ADT7420_BUS_ADDRESS, &reg_addr, 1);
	i2c1_read_start(ADT7420_BUS_ADDRESS, (uint8_t*)&temp, 2);
	i2c1_transfer_stop();
	/*Get the sign bit.*/
	is_negative = !!(temp & ADT7420_TEMP_SIGN_MASK);
	/*Remove the MSB from the calculation.*/
	temp &= ~ADT7420_TEMP_SIGN_MASK;
	/*Remove the 3 LSB from the calculation since the default 13 bit resolution is used.*/
	temp >>= 3;
	/*Calculate the floating point temperature.*/
	ret = temp * ADT7420_ADC_RESOLUTION;
	/*Add the sign.*/
	if (is_negative == true)
	{
		ret *= -1;
	}
	return ret;
}
