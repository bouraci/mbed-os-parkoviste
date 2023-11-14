#include "mbed.h"
#include "LCD_DISCO_F469NI.h"

#include "include/car.h"
#include "include/lcd_funcs.h"
#include "include/parking_lot.h"

LCD_DISCO_F469NI lcd;

Mutex m_parking;
Mutex m_lcd;

Thread threads_car[NUM_CARS];
CAR_PARAMS car_params[NUM_CARS];

Semaphore semaphore(NUM_SPACES);

stack<int> spaces;

void init() {
}

void exit() {
}

int main()
{
    lcd.Clear(LCD_COLOR_GRAY);

    for (int i = 0; i < NUM_SPACES; i++) {
        spaces.push(i);
    }

    for (int i = 0; i < NUM_CARS; i++) {
        car_params[i].color = car_colors[i % car_colors.size()];
        car_params[i].time_parked = (rand() % 5 + 1) * 1000;
        car_params[i].time_driving = (rand() % 4 + 1) * 1000;
    }

    for (int i = 0; i < NUM_CARS; i++) {
        threads_car[i].start(callback([=] { car_behaviour(&lcd, &car_params[i], &spaces, &semaphore, &m_lcd, &m_parking); } ));
    }
}



