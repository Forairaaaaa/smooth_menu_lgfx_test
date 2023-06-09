/**
 * @file main.cpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2023-01-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <vector>
#include <random>

#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>

static LGFX lcd(240, 135);
// static LGFX Lcd(320, 240);

static LGFX_Sprite* _canvas;
#define _canvas_update() _canvas->pushSprite(0, 0)


#define PIN_LEFT    39
#define PIN_DOWN    38
#define PIN_RIGHT   37
#define PIN_UP      36

std::random_device rd;
std::mt19937 gen(rd());
int Game_random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}














#include "smooth_menu/src/lv_anim/lv_anim.h"


LVGL::Anim_Path test;
LVGL::Anim_Path test2;


void smooth_menu_test()
{
    test.setAnim(LVGL::bounce, 0, 150, 1000);
    test.resetTime(SDL_GetTicks());

    test2.setAnim(LVGL::ease_out, 0, 40, 400);
    test2.resetTime(SDL_GetTicks());


    while (1) {

        _canvas->clear();

        _canvas->fillSmoothCircle(test.getValue(SDL_GetTicks()) + 10, 20, 10, TFT_YELLOW);

        _canvas->fillRect(10, 50, test.getValue(SDL_GetTicks()), 10, TFT_GREEN);

        _canvas->fillSmoothRoundRect(10, test2.getValue(SDL_GetTicks()) + 50, 80, 26, 3, TFT_ORANGE);


        test.setAnim(LVGL::overshoot, 0, 100, 600);
        test2.setAnim(LVGL::overshoot, 0, 50, 600);
        _canvas->fillSmoothRoundRect(110, test2.getValue(SDL_GetTicks()) + 30, test.getValue(SDL_GetTicks()), 26, 3, TFT_ORANGE);
        test.setAnim(LVGL::bounce, 0, 150, 1000);
        test2.setAnim(LVGL::ease_out, 0, 40, 400);


        _canvas_update();






        if (lgfx::gpio_in(PIN_UP) == 0) {
            test.resetTime(SDL_GetTicks());
            test2.resetTime(SDL_GetTicks());
        }


    } 



}














void setup()
{
    lcd.init();
    _canvas = new LGFX_Sprite(&lcd);
    _canvas->createSprite(lcd.width(), lcd.height());


    _canvas->fillScreen(TFT_BLUE);
    _canvas_update();



}



void loop()
{
    smooth_menu_test();
}

