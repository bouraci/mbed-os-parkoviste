#include "include/lcd_funcs.h"
#include "include/parking_lot.h"

void assign_color(LCD_DISCO_F469NI *lcd, int space_num, int car_color) {
    int spot_w = (*lcd).GetXSize() / NUM_SPACES;

    (*lcd).SetTextColor(car_color);
    (*lcd).FillRect(spot_w * space_num, 0, spot_w, (*lcd).GetYSize());
}