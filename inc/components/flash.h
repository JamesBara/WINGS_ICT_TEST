#ifndef FLASH_H
#define FLASH_H

typedef struct
{
	__RW ACR;
	__WO PDKEYR;
	__WO KEYR;
	__WO OPTKEYR;
	__RW SR;
	__RW CR;
	__RW ECCR;
	__RW OPTR;
	__RW PCROP1SR;
	__RW PCROP1ER;
	__RW WRP1AR;
	__RW WRP1BR;
}embedded_flash_memory_type;

#define FLASH_BASE_ADDRESS (0x40022000UL)
#define FLASH ((embedded_flash_memory_type*) FLASH_BASE_ADDRESS)

#define FLASH_ACR_PRFTEN (0x1UL << 8)
#define FLASH_ACR_LATENCY_Msk 0x7UL
#define FLASH_ACR_LATENCY_WAIT_STATE_4 0x4UL



#endif /*FLASH_H*/