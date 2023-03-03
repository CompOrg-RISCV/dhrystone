/*
	File : core_portme.c
*/
/*
	Author : Shay Gal-On, EEMBC
	Legal : TODO!
*/
#include <time.h>
typedef unsigned int secs_ret;

/* Automatization : FREQUENCY
    Sets the frequency for a computation of time and Coremark/MHz
*/
#define FREQUENCY 10

/* Porting : Timing functions
	How to capture time and convert to seconds must be ported to whatever is supported by the platform.
	e.g. Read value from on board RTC, read value from cpu clock cycles performance counter etc.
	Sample implementation for standard time.h and windows.h definitions included.
*/
#define GETMYTIME(_t) (_t=clock())
#define CORETIMETYPE clock_t
typedef clock_t CORE_TICKS;


#define MYTIMEDIFF(fin,ini) ((fin)-(ini))
// returned ticks are divided by CC_DIVIDER
#define EE_TICKS_PER_SEC ((FREQUENCY*1000000) / CC_DIVIDER)

/* Function : time_in_secs
	Convert the value returned by get_time to seconds.

	The <secs_ret> type is used to accomodate systems with no support for floating point.
	Default implementation implemented by the EE_TICKS_PER_SEC macro above.
*/
secs_ret time_in_secs(CORE_TICKS ticks) {
	secs_ret retval=((CORE_TICKS)ticks) / (CORE_TICKS)EE_TICKS_PER_SEC;
	return retval;
}
