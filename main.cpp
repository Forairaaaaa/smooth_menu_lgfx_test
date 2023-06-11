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
// static LGFX lcd(128, 128);

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














// #include "smooth_menu/src/lv_anim/lv_anim.h"


// LVGL::Anim_Path test;
// LVGL::Anim_Path test2;


// void smooth_menu_test()
// {
//     test.setAnim(LVGL::bounce, 0, 150, 1000);
//     test.resetTime(SDL_GetTicks());

//     test2.setAnim(LVGL::ease_out, 0, 40, 400);
//     test2.resetTime(SDL_GetTicks());


//     while (1) {

//         _canvas->clear();

//         _canvas->fillSmoothCircle(test.getValue(SDL_GetTicks()) + 10, 20, 10, TFT_YELLOW);

//         _canvas->fillRect(10, 50, test.getValue(SDL_GetTicks()), 10, TFT_GREEN);

//         _canvas->fillSmoothRoundRect(10, test2.getValue(SDL_GetTicks()) + 50, 80, 26, 3, TFT_ORANGE);


//         test.setAnim(LVGL::overshoot, 0, 100, 600);
//         test2.setAnim(LVGL::overshoot, 0, 50, 600);
//         _canvas->fillSmoothRoundRect(110, test2.getValue(SDL_GetTicks()) + 30, test.getValue(SDL_GetTicks()), 26, 3, TFT_ORANGE);
//         test.setAnim(LVGL::bounce, 0, 150, 1000);
//         test2.setAnim(LVGL::ease_out, 0, 40, 400);


//         _canvas_update();






//         if (lgfx::gpio_in(PIN_UP) == 0) {
//             test.resetTime(SDL_GetTicks());
//             test2.resetTime(SDL_GetTicks());
//         }


//     } 



// }






// // #include "smooth_menu/src/menu/menu.h"
// // #include "smooth_menu/src/selector/selector.h"
// #include "smooth_menu/src/smooth_menu.h"



// struct My_menu_callback : public SMOOTH_MENU::MenuRenderCallback_t {
//     void renderCallback(const SMOOTH_MENU::Item_t* item)
//     {
//         _canvas->setTextColor(TFT_WHITE);
//         _canvas->setTextSize(item->height / 24);
//         _canvas->drawString(item->tag.c_str(), item->x, item->y);
//     }
// };


// struct My_selector_callback : public SMOOTH_MENU::SelectorRenderCallback_t {
//     void renderCallback(int x, int y, int width, int height)
//     {
//         _canvas->fillSmoothRoundRect(x, y, width, height, 5, TFT_SKYBLUE);

//         // _canvas->fillSmoothRoundRect(x, y, width, height, 5, Game_random(0, 0xFFFFFF));
//     }
// };


// struct My_camera_callback : public SMOOTH_MENU::SelectorRenderCallback_t {
//     void renderCallback(int x, int y, int width, int height)
//     {
//         _canvas->drawRect(x, y, width, height, TFT_GREENYELLOW);

//         // _canvas->fillSmoothRoundRect(x, y, width, height, 5, Game_random(0, 0xFFFFFF));
//     }
// };



// void smooth_menu_test2()
// {
//     SMOOTH_MENU::Menu_t menu;

//     My_menu_callback mycb;
//     menu.setRenderCallback(&mycb);




//     menu.addItemVertically("asdfa", 12 * 5, 24);
//     menu.addItemVertically("qwe", 12 * 3, 24);
//     menu.addItemVertically("dfgg", 12 * 2 * 4, 24 * 2);
//     menu.addItemVertically("45364356", 12 * 3 * 8, 24 * 3);
//     menu.addItemVertically("as^^^dfa", 12 * 8, 24);
//     menu.addItemVertically("愣头青", 12 * 10, 24);
//     menu.addItemVertically("!...//?", 12 * 7, 24);
//     menu.addItemVertically("???da", 12 * 5, 24);
//     menu.addItemVertically("!!!99090", 12 * 5 * 8, 24 * 5);
//     menu.addItemVertically("多捞啊", 12 * 10, 24);
//     menu.addItemVertically("<><><><>", 12 * 8, 24);
//     menu.addItemVertically("~~~~...", 12 * 7, 24);



//     // menu.addItemHorizontally("asdfa", 12 * 5, 24);
//     // menu.addItemHorizontally("qwe", 12 * 3, 24);
//     // menu.addItemHorizontally("dfgg", 12 * 2 * 4, 24 * 2);
//     // menu.addItemHorizontally("45364356", 12 * 3 * 8, 24 * 3);
//     // menu.addItemHorizontally("as^^^dfa", 12 * 8, 24);
//     // menu.addItemHorizontally("愣头青", 12 * 10, 24);
//     // menu.addItemHorizontally("!...//?", 12 * 7, 24);
//     // menu.addItemHorizontally("???da", 12 * 5, 24);
//     // menu.addItemHorizontally("!!!99090", 12 * 5 * 8, 24 * 5);
//     // menu.addItemHorizontally("多捞啊", 12 * 10, 24);
//     // menu.addItemHorizontally("<><><><>", 12 * 8, 24);
//     // menu.addItemHorizontally("~~~~...", 12 * 7, 24);



//     // menu.addItemVertically("asdfa", 12 * 5, 24, 0);
//     // menu.addItemVertically("qwe", 12 * 3, 24, 50);
//     // menu.addItemVertically("dfgg", 12 * 2 * 4, 24 * 2, 30);
//     // menu.addItemVertically("45364356", 12 * 3 * 8, 24 * 3, 200);
//     // menu.addItemVertically("as^^^dfa", 12 * 8, 24, 100);
//     // menu.addItemVertically("愣头青", 12 * 10, 24, 300);
//     // menu.addItemVertically("!...//?", 12 * 7, 24, 100);
//     // menu.addItemVertically("???da", 12 * 5, 24, 20);
//     // menu.addItemVertically("!!!99090", 12 * 5 * 8, 24 * 5, 0);
//     // menu.addItemVertically("多捞啊", 12 * 10, 24, 250);
//     // menu.addItemVertically("<><><><>", 12 * 8, 24, 80);
//     // menu.addItemVertically("~~~~...", 12 * 7, 24, 20);


    


//     printf("size: %d\n", (int)menu.getItemNum());





//     SMOOTH_MENU::Selector_t selector;
//     My_selector_callback selector_cb;

//     selector.setMenu(&menu);
//     selector.setRenderCallback(&selector_cb);





//     SMOOTH_MENU::Camrea_t camera;
//     My_camera_callback camera_cb;

//     camera.setSize(240, 135);
//     camera.setMenu(&menu);
//     camera.setRenderCallback(&camera_cb);







//     int i = 0;

//     while (1) {

//         _canvas->clear();


//         selector.update(SDL_GetTicks());
//         camera.update(SDL_GetTicks());


//         _canvas_update();



        
//         int time_count = 0;
//         if (lgfx::gpio_in(PIN_UP) == 0) {

//             while (lgfx::gpio_in(PIN_UP) == 0) {
//                 // SDL_Delay(1);
//                 // time_count++;
//                 // if (time_count > 100) {
//                 //     break;
//                 // }
//             }



//             selector.goLast();
//             camera.goLast();
            
//             printf("target %d\n", selector.getTargetItem());
//         }


//         time_count = 0;
//         if (lgfx::gpio_in(PIN_DOWN) == 0) {

//             while (lgfx::gpio_in(PIN_DOWN) == 0) {
//                 // SDL_Delay(1);
//                 // time_count++;
//                 // if (time_count > 100) {
//                 //     break;
//                 // }
//             }



//             selector.goNext();
//             camera.goNext();

//             printf("target %d\n", selector.getTargetItem());
//         }


        

//         // if (selector.isAnimFinished()) {
//         //     printf("anim finshed\n");
//         // }

//     }




// }







#include <smooth_menu.h>


struct My_SimpleMenu_CB : public SMOOTH_MENU::SimpleMenuCallback_t {
    void renderCallback(
        const std::vector<SMOOTH_MENU::Item_t*>& menuItemList,
        const SMOOTH_MENU::RenderAttribute_t& selector,
        const SMOOTH_MENU::RenderAttribute_t& camera
    )
    {
        _canvas->clear();





        

        // /* Draw selector */
        // _canvas->fillSmoothRoundRect(
        //     selector.x,
        //     // selector.x - (selector.width - menuItemList[selector.targetItem]->width) / 2,
        //     selector.y + (menuItemList[selector.targetItem]->height - selector.height) / 2,
        //     selector.width,
        //     selector.height,
        //     5, TFT_SKYBLUE);

        // /* Draw camera */
        // _canvas->drawRect(camera.x, camera.y, camera.width, camera.height, TFT_GREENYELLOW);

        // /* Draw menu */
        // for (int i = 0; i < menuItemList.size(); i++) {
        //     _canvas->setTextColor(TFT_WHITE);
        //     _canvas->setTextSize(menuItemList[i]->height / 24);
        //     _canvas->drawString(menuItemList[i]->tag.c_str(), menuItemList[i]->x, menuItemList[i]->y);
        // }



        
        /* Draw selector */
        _canvas->fillSmoothRoundRect(
            selector.x - camera.x,
            // selector.x - camera.x - (selector.width - menuItemList[selector.targetItem]->width) / 2,
            selector.y - camera.y + (menuItemList[selector.targetItem]->height - selector.height) / 2,
            selector.width,
            selector.height,
            5, TFT_SKYBLUE);

        /* Draw menu */
        for (int i = 0; i < menuItemList.size(); i++) {
            _canvas->setTextColor(TFT_WHITE);
            _canvas->setTextSize(menuItemList[i]->height / 24);
            _canvas->drawString(menuItemList[i]->tag.c_str(), menuItemList[i]->x - camera.x, menuItemList[i]->y - camera.y);
        }

        /* Draw camera */
        _canvas->drawRect(0, 0, camera.width, camera.height, TFT_GREENYELLOW);






        _canvas_update();

    }
};





void smooth_menu_test3()
{
    SMOOTH_MENU::Simple_Menu simple_menu;
    My_SimpleMenu_CB my_cb;


    // simple_menu.init(240, 135);
    // simple_menu.init(100, 200);
    simple_menu.init(128, 128);
    simple_menu.setRenderCallback(&my_cb);

    auto cfg = simple_menu.getCamera()->config();
    cfg.animPath_x = LVGL::overshoot;
    cfg.animPath_y = LVGL::overshoot;
    cfg.animTime_x = 400;
    cfg.animTime_y = 400;
    simple_menu.getCamera()->config(cfg);


    simple_menu.setMenuLoopMode(true);
    // simple_menu.setMenuLoopMode(false);

    

    // simple_menu.getMenu()->setPostion(50, 30);



    simple_menu.getMenu()->addItemVertically("asdfa", 12 * 5, 24);
    simple_menu.getMenu()->addItemVertically("qwe", 12 * 3, 24);
    simple_menu.getMenu()->addItemVertically("dfgg", 12 * 2 * 4, 24 * 2);
    simple_menu.getMenu()->addItemVertically("45364356", 12 * 3 * 8, 24 * 3);
    simple_menu.getMenu()->addItemVertically("as^^^dfa", 12 * 8, 24);
    simple_menu.getMenu()->addItemVertically("愣头青", 12 * 10, 24);
    simple_menu.getMenu()->addItemVertically("!...//?", 12 * 7, 24);
    simple_menu.getMenu()->addItemVertically("???da", 12 * 5, 24);
    simple_menu.getMenu()->addItemVertically("!!!99090", 12 * 5 * 8, 24 * 5);
    simple_menu.getMenu()->addItemVertically("多捞啊", 12 * 10, 24);
    simple_menu.getMenu()->addItemVertically("<><><><>", 12 * 8, 24);
    simple_menu.getMenu()->addItemVertically("~~~~...", 12 * 7, 24);


    // simple_menu.getMenu()->addItemVertically("asdfa", 12 * 5, 24, 0);
    // simple_menu.getMenu()->addItemVertically("qwe", 12 * 3, 24, 50);
    // simple_menu.getMenu()->addItemVertically("dfgg", 12 * 2 * 4, 24 * 2, 30);
    // simple_menu.getMenu()->addItemVertically("45364356", 12 * 3 * 8, 24 * 3, 200);
    // simple_menu.getMenu()->addItemVertically("as^^^dfa", 12 * 8, 24, 100);
    // simple_menu.getMenu()->addItemVertically("愣头青", 12 * 10, 24, 300);
    // simple_menu.getMenu()->addItemVertically("!...//?", 12 * 7, 24, 100);
    // simple_menu.getMenu()->addItemVertically("???da", 12 * 5, 24, 20);
    // simple_menu.getMenu()->addItemVertically("!!!99090", 12 * 5 * 8, 24 * 5, 0);
    // simple_menu.getMenu()->addItemVertically("多捞啊", 12 * 10, 24, 250);
    // simple_menu.getMenu()->addItemVertically("<><><><>", 12 * 8, 24, 80);
    // simple_menu.getMenu()->addItemVertically("~~~~...", 12 * 7, 24, 20);




    while (1) {

        simple_menu.update(SDL_GetTicks());



        if (lgfx::gpio_in(PIN_DOWN) == 0) {
            simple_menu.goNext();
            while (lgfx::gpio_in(PIN_DOWN) == 0) { simple_menu.update(SDL_GetTicks()); }
        }

        if (lgfx::gpio_in(PIN_UP) == 0) {
            simple_menu.goLast();
            while (lgfx::gpio_in(PIN_UP) == 0) { simple_menu.update(SDL_GetTicks()); }
        }


        if (lgfx::gpio_in(PIN_RIGHT) == 0) {
            simple_menu.getSelector()->pressed();
            while (lgfx::gpio_in(PIN_RIGHT) == 0) { simple_menu.update(SDL_GetTicks()); }
            simple_menu.getSelector()->released();
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



    _canvas->setFont(&fonts::efontCN_24);

}



void loop()
{
    // smooth_menu_test();
    // smooth_menu_test2();

    smooth_menu_test3();
}

