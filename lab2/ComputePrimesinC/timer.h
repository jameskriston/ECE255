#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

void timer_init(void);
void timer_start(void);
uint64_t timer_stop(void);

#endif