#ifndef PWR_H
#define PWR_H


typedef struct
{
	__RW CR1;
	__RW CR2;
	__RW CR3;
	__RW CR4;
	__RO SR1;
	__RO SR2;
	__WO SCR;
	RESERVED;
	__RW PUCRA;
	__RW PDCRA;
	__RW PUCRB;
	__RW PDCRB;
	__RW PUCRC;
	__RW PDCRC;
	__RW PUCRD;
	__RW PDCRD;
	__RW PUCRE;
	__RW PDCRE;
	RESERVED;
	RESERVED;
	uint32_t RESERVED3;
	RESERVED;
	__RW PUCRH;
	__RW PDCRH;
}power_control_type;

#define PWR ((power_control_type*) 0x40007000UL)


#define PWR_CR1_DBP (0x1UL << 8)


#define PWR_CR1_LPMS_Msk 0x7UL
#define PWR_CR1_LPMS_STOP_2 0x2UL





#endif /*PWR_H*/