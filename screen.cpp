//
//  screen.cpp
//  particle
//
//  Created by raymond on 3/11/21.
//  Copyright © 2021 raymond. All rights reserved.
//

#include "screen.hpp"

namespace ray {

Screen::Screen() : window(NULL), renderer(NULL), texture(NULL), buffer(NULL)
{
   
}


   bool Screen::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return false;
    }
        window = SDL_CreateWindow("particle fire", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window==NULL)
        {
            SDL_Quit();
            return false;
        }
        
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
        if(renderer == nullptr)
        {
            SDL_DestroyWindow(window);
            SDL_Quit();
            return false;
        }
        if(texture == nullptr)
        {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
                   SDL_Quit();
            return false;
        }
       buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
        memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
        
        //buffer[600] = 0xff0000ff;
        /**for(int i =0; i < SCREEN_WIDTH*SCREEN_HEIGHT/2; i++)
        {
            buffer[i] = 0xffffffff;
        }**/
        
      
        
    return true;
}
   void Screen::close()
{
    delete [] buffer;
     SDL_DestroyRenderer(renderer);
     SDL_DestroyTexture(texture);
     SDL_DestroyWindow(window);
     SDL_Quit();
}

void Screen::update(){
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
          SDL_RenderClear(renderer);
          SDL_RenderCopy(renderer, texture, NULL, NULL);
          SDL_RenderPresent(renderer);
}

   bool Screen::processEvents()
{
       SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            return false;
        }
    }
    return true;
}
void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    Uint32 color = 0;
    
    color+= red;
    color <<= 8;
    color+= green;
    color <<= 8;
    color+= blue;
    color <<= 8;
    color+= 0xFF;
    
    buffer[(y*SCREEN_WIDTH)+x] = color;
}


}
