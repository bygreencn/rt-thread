#ifndef __WDT_H 
#define __WDT_H

#define WDEN              (0x1<<0)
#define WDRESET           (0x1<<1)
#define WDTOF             (0x1<<2)
#define WDINT             (0x1<<3)
#define WDPROTECT         (0x1<<4)

#define WDT_FEED_VALUE    0x186a0         //计数器溢出定义(1.5S)

#define WINDOW_MODE       0
#define PROTECT_MODE      1
#define WATCHDOG_RESET    0

extern void WDT_IRQHandler(void);
extern void WDTInit( void );
extern void WDTFeed( void );

#endif /* end __WDT_H */
