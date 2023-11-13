#ifndef LCD_FUNCTIONS_H
#define LCD_FUNCTIONS_H

#include "car.h"

#ifndef __LCD_DISCO_F469NI_H
#include "LCD_DISCO_F469NI.h"
#endif

void assign_color(LCD_DISCO_F469NI *lcd, int space_num, int car_color);

#endif