#ifndef CAR_H
#define CAR_H

#include <stack>
#include <vector>

#ifndef __LCD_DISCO_F469NI_H
#include "LCD_DISCO_F469NI.h"
#endif

const vector<uint32_t> car_colors = {
    LCD_COLOR_RED,
    LCD_COLOR_GREEN,
    LCD_COLOR_BLUE,
    LCD_COLOR_YELLOW,
    LCD_COLOR_ORANGE,
    LCD_COLOR_CYAN,
    LCD_COLOR_MAGENTA,
};

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
