#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

SDL_Rect r, r2, r3, r4;

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("", 400, 400, 500, 400, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    r.h = 20; r.w = 200;
    r.x = 40; r.y = 40;

    r2.h = 20; r2.w = 200;
    r2.x = 40; r2.y = 70;

    r3.h = 20; r3.w = 200;
    r3.x = 40; r3.y = 120;

    r4.h = 20; r4.w = 200;
    r4.x = 40; r4.y = 170;

    bool done = false;
    while(!done){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    done = true;
                    break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_ESCAPE:
                            done = true;
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }

        } 
       
        SDL_SetRenderDrawColor(renderer, 70, 80, 100, 0);        
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(renderer, &r);
        SDL_RenderDrawRect(renderer, &r2);    
        SDL_RenderDrawRect(renderer, &r3);
        SDL_RenderDrawRect(renderer, &r4);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
