//
//  screen.hpp
//  particle
//
//  Created by raymond on 3/11/21.
//  Copyright © 2021 raymond. All rights reserved.
//

#ifndef screen_hpp
#define screen_hpp

#include <SDL2/SDL.h>

namespace ray {

class Screen
{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    
    Screen();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 *buffer;
public:
    bool init();
    void close();
    bool processEvents();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
};

}
#endif /* screen_hpp */
