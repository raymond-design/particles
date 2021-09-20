//
//  main.cpp
//  particle
//
//  Created by raymond on 3/10/21.
//  Copyright © 2021 raymond. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "screen.hpp"
using namespace ray;
int main()
{
    Screen screen;
    if(!screen.init())
    {
        std::cout << "init failed" << std::endl;
    }
    //bool quit = false;
 
    while(true)
    {
        for(int y =0; y<Screen::SCREEN_HEIGHT; y++)
        {
            for(int x =0; x<Screen::SCREEN_WIDTH; x++)
            {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }
        screen.setPixel(400, 300, 255, 255, 255);
        screen.update();
        if(!screen.processEvents())
        { break; }
        
    }
    screen.close();
    
    return 0;
}
