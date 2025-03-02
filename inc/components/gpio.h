#ifndef GPIO_H
#define GPIO_H

typedef struct
{
	__RW MODER;
	__RW OTYPER;
	__RW OSPEEDR;
	__RW PUPDR;
	__RO IDR;
	__RW ODR;
	__WO BSRR;
	__RW LCKR;
	__RW AFRL;
	__RW AFRH;
	__RW BRR;
}general_purpose_input_output_type;

#define GPIOA_BASE_ADDRESS (0x48000000UL)
#define GPIOB_BASE_ADDRESS (0x48000400UL)

#define GPIOA ((general_purpose_input_output_type*) GPIOA_BASE_ADDRESS)
#define GPIOB ((general_purpose_input_output_type*) GPIOB_BASE_ADDRESS)


#define GPIO_MODER_Msk(pin) (0x3UL << ((pin) << 1))
#define GPIO_MODER_INPUT(pin) (0x0UL << ((pin) << 1))
#define GPIO_MODER_OUTPUT(pin) (0x1UL << ((pin) << 1))
#define GPIO_MODER_ALTERNATE_FUNCTION(pin) (0x2UL << ((pin) << 1))
#define GPIO_MODER_ANALOG(pin) GPIO_MODER_Msk(pin)

#define GPIO_OSPEEDR_Msk(pin) (0x3UL << ((pin) << 1))
#define GPIO_OSPEEDR_LOW_SPEED(pin) (0x0UL << ((pin) << 1))
#define GPIO_OSPEEDR_MEDIUM_HIGH_SPEED(pin) (0x1UL << ((pin) << 1))
#define GPIO_OSPEEDR_HIGH_SPEED(pin) (0x2UL << ((pin) << 1))
#define GPIO_OSPEEDR_VERY_HIGH_SPEED(pin) GPIO_OSPEEDR_Msk(pin)

#define GPIO_PUPDR_Msk(pin) (0x3UL << ((pin) << 1))
#define GPIO_OSPEEDR_NO_PULLUP_PULLDOWN(pin) (0x0UL << ((pin) << 1))
#define GPIO_PUPDR_PULLUP(pin) (0x1UL << ((pin) << 1))
#define GPIO_PUPDR_PULLDOWN(pin) (0x2UL << ((pin) << 1))

#define GPIO_AFRH_Msk(pin) (0xFUL << (((pin) - 8) << 2))
#define GPIO_AFRH(af, pin) (((af) & 0xFUL) << (((pin) - 8) << 2))






#endif /*GPIO_H*/