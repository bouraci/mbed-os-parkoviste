#include <chrono>
#include <stack>

#include "include/car.h"
#include "include/lcd_funcs.h"
#include "include/parking_lot.h"

using namespace std::chrono;

void car_behaviour(
    LCD_DISCO_F469NI *lcd,
    CAR_PARAMS *car_params,
    stack<int> *spaces,
    Semaphore *semaphore,
    Mutex *m_lcd,
    Mutex *m_parking
    ) {
    milliseconds time_parked = milliseconds(car_params->time_parked);
    milliseconds time_driving = milliseconds(car_params->time_driving);

    while (true) {
        ThisThread::sleep_for(time_driving);

        (*semaphore).acquire();

        (*m_parking).lock();
        int space = (*spaces).top();
        (*spaces).pop();
        (*m_parking).unlock();

        (*m_lcd).lock();
        assign_color(lcd, space, car_params->color);
        (*m_lcd).unlock();

        ThisThread::sleep_for(time_parked);

        (*m_parking).lock();
        (*spaces).push(space);
        (*m_parking).unlock();

        (*m_lcd).lock();
        assign_color(lcd, space, LCD_COLOR_GRAY);
        (*m_lcd).unlock();

        (*semaphore).release();
        ThisThread::sleep_for(time_parked);
    }
}
