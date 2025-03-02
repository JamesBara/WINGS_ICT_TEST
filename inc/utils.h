#ifndef UTILS_H
#define UTILS_H

#ifndef __CONCAT
#define __CONCAT(x, y) x ## y
#endif
#ifndef CONCAT
#define CONCAT(x, y) __CONCAT(x, y)
#endif

#ifndef UNUSED
#define UNUSED(val) (void)(val)
#endif

#ifndef MIN
#define MIN(x, y) ((x) < (y)) ? (x) : (y)
#endif

#ifndef MAX
#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#endif

__STATIC_INLINE void assert_func(const char* file, int line, const char* func)
{
    #if defined(NDEBUG)
    UNUSED(file);
    UNUSED(line);
    UNUSED(func);
	NVIC_SystemReset();
    #else
    (void)file;
	(void)line;
	(void)func;
	__BKPT(0);
    #endif
}

#ifndef ASSERT
#define ASSERT(val) do \
{ \
    uint32_t param = (val); \
    if(!param) \
    { \
        assert_func(__FILE__, __LINE__, __func__); \
    } \
}while(0)
#endif





#endif /*UTILS_H*/