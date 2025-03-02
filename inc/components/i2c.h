#ifndef I2C_H
#define I2C_H

typedef struct
{
	__RW CR1;
	__RW CR2;
	__RW OAR1;
	__RW OAR2;
	__RW TIMINGR;
	__RW TIMEOUTR;
	__RW ISR;
	__WO ICR;
	__RO PECR;
	__RO RXDR;
	__RW TXDR;
}inter_intergrated_circuit_type;

#define I2C1_BASE_ADDRESS (0x40005400UL)

#define I2C1 ((inter_intergrated_circuit_type*) I2C1_BASE_ADDRESS)

#define I2C_CR1_PE 0x1UL


#define I2C_CR2_AUTOEND (0x1UL << 25)
#define I2C_CR2_NBYTES(val) (((val) & 0xFFUL) << 16)
#define I2C_CR2_STOP (0x1UL << 14)
#define I2C_CR2_START (0x1UL << 13)
#define I2C_CR2_RD_WRN (0x1UL << 10)
#define I2C_CR2_SADD_7_1(val) (((val) & 0x7FUL) << 1)

#define I2C_ISR_TC (0x1UL << 6)
#define I2C_ISR_RXNE (0x1UL << 2)
#define I2C_ISR_TXIS (0x1UL << 1)





#endif /*I2C_H*/