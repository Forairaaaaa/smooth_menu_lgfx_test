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

// static LGFX lcd(240, 135);
static LGFX lcd(720, 480);

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






#include "smooth_menu/src/menu/menu.h"


struct My_menu_callback : public SMOOTH_MENU::MenuRenderCallback_t {
    void renderMenu(const SMOOTH_MENU::Item_t* item)
    {
        _canvas->setTextColor(TFT_YELLOW);
        _canvas->setTextSize(item->heigh / 24);
        _canvas->drawString(item->tag.c_str(), item->x, item->y);
    }
};



void smooth_menu_test2()
{
    SMOOTH_MENU::Menu_t menu;

    My_menu_callback mycb;
    menu.setRenderCallback(&mycb);


    // menu.addItem("aaaa", 10, 10, 40, 30);
    // menu.addItem("bb", 10, 10 + 30, 40, 30);
    // menu.addItem("aaaasdasda", 10, 10 + 30 * 2, 40, 30);
    // menu.addItem("yyy", 10, 10 + 30 * 3, 40, 30);
    // menu.addItem("???", 10, 10 + 30 * 4, 40, 30);
    // menu.addItem("aa1234123aa", 10, 10 + 30 * 5, 40, 30);
    // menu.addItem("oofvbf", 10, 10 + 30 * 6, 40, 30);


    menu.addItemVertically("asdfa", 50, 24);
    menu.addItemVertically("qwe", 50, 24);
    menu.addItemVertically("dfgg", 50, 24 * 2);
    menu.addItemVertically("45364356", 50, 24 * 3);
    menu.addItemVertically("as^^^dfa", 50, 24);
    menu.addItemVertically("???da", 50, 24);
    menu.addItemVertically("!!!99090", 50, 24 * 5);
    menu.addItemVertically("!...//?", 50, 24);


    printf("size: %d\n", (int)menu.getItemNum());

    

    while (1) {

        _canvas->clear();
        menu.renderMenu();
        _canvas_update();

    }




}





void setup()
{
    lcd.init();
    _canvas = new LGFX_Sprite(&lcd);
    _canvas->createSprite(lcd.width(), lcd.height());


    _canvas->fillScreen(TFT_BLUE);
    _canvas_update();



    _canvas->setFont(&fonts::efontCN_24);

}



void loop()
{
    // smooth_menu_test();
    smooth_menu_test2();
}

