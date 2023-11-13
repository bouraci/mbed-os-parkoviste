#ifndef CAR_H
#define CAR_H

#include <stack>

#ifndef __LCD_DISCO_F469NI_H
#include "LCD_DISCO_F469NI.h"
#endif

typedef struct {
    int color;
    int time_parked;
    int time_driving;
   
} CAR_PARAMS;

void car_behaviour(
    LCD_DISCO_F469NI *lcd,
    CAR_PARAMS *car_params,
    stack<int> *spaces,
    Semaphore *semaphore,
    Mutex *m_lcd,
    Mutex *m_parking
);

#endif
