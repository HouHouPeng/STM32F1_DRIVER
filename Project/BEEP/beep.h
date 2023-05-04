#ifndef BEEP__H_
#define BEEP__H_

#include "sys.h"

void BEEP_Init(void);
#define BEEP_ON  PGout(15) = 0;
#define BEEP_OFF PGout(15) = 1;

#endif