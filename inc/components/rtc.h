#ifndef RTC_H
#define RTC_H

typedef struct
{
	__RW TR;
	__RW DR;
	__RO SSR;
	__RW ICSR;
	__RW PRER;
	__RW WUTR;
	__RW CR;
	RESERVED[2];
	__WO WPR;
	__RW CALR;
	__WO SHIFTR;
	__RO TSTR;
	__RO TSDR;
	__RO TSSSR;
	RESERVED;
	__RW ALRMAR;
	__RW ALRMASSR;
	__RW ALRMBR;
	__RW ALRMBSSR;
	__RO SR;
	__RO MISR;
	RESERVED;
	__WO SCR;
}real_time_clock_type;

#define RTC ((real_time_clock_type*) 0x40002800UL)


#define RTC_CR_WUCKSEL_Msk 0x7UL
#define RTC_CR_WUCKSEL_MEDIUM_WAKEUP_PERIOD 0x4UL /*!< Wakeup between 1s - 18hours.*/

#define RTC_CR_WUTIE (0x1UL << 14)
#define RTC_CR_WUTE (0x1UL << 10)

#define RTC_ICSR_WUTWF (0x1UL << 2)

#define RTC_WUTR_WUT_Msk 0xFFFFUL
#define RTC_WUTR_WUT(val) ((val) & 0xFFFFUL)
#define RTC_WUTR_WUTOCLR_Msk (0xFFFFUL << 16)

#define RTC_WPR_KEY0 0xCAUL
#define RTC_WPR_KEY1 0x53UL
#define RTC_WPR_KEY_Msk 0xFFUL

#define RTC_CSR_CWUTF (0x1UL << 2)
#define RTC_SR_WUTF (0x1UL << 2)


#endif /*RTC_H*/
