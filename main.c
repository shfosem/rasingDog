/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "struct.h"
#include"extern.h"
#include"checkMouse.h"



SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}




int main( int argc, char* args[] )
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    //Create window
    SDL_Window* window = SDL_CreateWindow("Raising a Dog", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    //Create renderer for window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
	
	SDL_Texture* carpe = loadTexture("carpe.jpg", renderer);
	if (carpe == NULL)
	{
		printf("Failed to load texture image!\n");
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	
	SDL_Texture* galpus = loadTexture("galpus.gif", renderer);
	if (galpus == NULL)
	{
		printf("Failed to load texture image!\n");
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	SDL_Texture* rollpe = loadTexture("rollpe.gif", renderer);
	if (rollpe == NULL)
	{
		printf("Failed to load texture image!\n");
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	SDL_Texture* howtoplay = loadTexture("howtoplay.jpg", renderer);
	if (howtoplay == NULL)
	{
		printf("Failed to load texture image!\n");
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	SDL_Texture* dead = loadTexture("dead.jpg", renderer);
	if (dead == NULL)
	{
		printf("Failed to load texture image!\n");
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	
    int quit = 0;   //Main loop flag
    SDL_Event e;    //Event

	
    //While application is running

	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = 1;
			}
			else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				//게임시작
				
				if (checkMouse(box1, x, y)&&map==0)
				{
					Color1.r = MOUSEON;//, StColor.b = 255;
					if (e.button.button == SDL_BUTTON_LEFT)
					
						if (e.type == SDL_MOUSEBUTTONDOWN )
							map++;
				}
//산책
				else if (checkMouse(walking, x, y) && map == 1)
				{
					Color1.r = MOUSEON;
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						if (e.type == SDL_MOUSEBUTTONDOWN)
						{
							status[0] += 5, status[2] -= 5;
							printf("충성도: %d, 체력:%d, 포만감%d\n", status[0], status[1], status[2]);
						}
					}
					else if (e.button.button == SDL_BUTTON_RIGHT)
						if (e.type == SDL_MOUSEBUTTONDOWN)
						{
							status[0] += 100;
							printf("충성도: %d, 체력:%d, 포만감%d\n", status[0], status[1], status[2]);
						}
					
				}
//훈련
				else if (checkMouse(training, x, y) && map == 1)
				{
					Color2.g = MOUSEON;
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						if (e.type == SDL_MOUSEBUTTONDOWN)
						{
							status[0] -= 2, status[1] += 5, status[2] -= 10;
							printf("충성도: %d, 체력:%d, 포만감%d\n", status[0], status[1], status[2]);
						}
					}
					else if (e.button.button == SDL_BUTTON_RIGHT)
						if (e.type == SDL_MOUSEBUTTONDOWN)
						{
							status[1] += 100;
							printf("충성도: %d, 체력:%d, 포만감%d\n", status[0], status[1], status[2]);
						}

				}
				else if (checkMouse(feeding, x, y) && map == 1)
				{
					Color3.b = MOUSEON;
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						if (e.type == SDL_MOUSEBUTTONDOWN)
						{
							status[0] += 10, status[2] += 50;
							printf("충성도: %d, 체력:%d, 포만감%d\n", status[0], status[1], status[2]);
						}
					}
					else if (e.button.button == SDL_BUTTON_RIGHT)
						if (e.type == SDL_MOUSEBUTTONDOWN)
						{
							status[2] += 100;
							printf("충성도: %d, 체력:%d, 포만감%d\n", status[0], status[1], status[2]);
						}

				}
				//게임설명 및 돌아가기
				else if (checkMouse(box2, x, y)&&map==0)
				{
					Color2.g = MOUSEON;
						if (e.button.button == SDL_BUTTON_LEFT)
							if (e.type == SDL_MOUSEBUTTONDOWN && map==0)
								map += 2;
					
				}
				else if (map == 2)
				{
					if (e.button.button == SDL_BUTTON_LEFT)
						if (e.type == SDL_MOUSEBUTTONDOWN)
							map = START;
				}
				else if(status[0] < 0 || status[2] < 0 || status[2]>250)
				{
					if (e.button.button == SDL_BUTTON_LEFT)
						if (e.type == SDL_MOUSEBUTTONDOWN)
							return 0;
				}
				else if (checkMouse(box3, x, y)&&map==0)
				{
					Color3.b = MOUSEON;
						if (e.button.button == SDL_BUTTON_LEFT)
							if (e.type == SDL_MOUSEBUTTONDOWN && map==0)
								return 0;
				}

				else//버튼색 원상복구
				{
					Color1.r = 255, Color1.b = 0;
					Color2.g = 255, Color2.b = 0;
					Color3.b = 255;
				}
			}
		}
	
		//Clear screen

		SDL_SetRenderDrawColor(renderer, ScColor.r, ScColor.g, ScColor.b, 255);
		SDL_RenderClear(renderer);

		switch (map)
		{
		case START:
			SDL_SetRenderDrawColor(renderer, ScColor.r, ScColor.g, ScColor.b, 255);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, Color1.r, Color1.g, Color1.b, 255);
			SDL_RenderFillRect(renderer, &box1);
			SDL_SetRenderDrawColor(renderer, Color2.r, Color2.g, Color2.b, 255);
			SDL_RenderFillRect(renderer, &box2);
			SDL_SetRenderDrawColor(renderer, Color3.r, Color3.g, Color3.b, 255);
			SDL_RenderFillRect(renderer, &box3); 
			
			break;

		case MAP1:
			ScColor.r = 255, ScColor.g = 255, ScColor.b = 255;
			SDL_RenderClear(renderer);
			
			SDL_RenderCopy(renderer, carpe, NULL, &Pet1);

			SDL_SetRenderDrawColor(renderer, Color1.r, Color1.g, Color1.b, 255);
			SDL_RenderFillRect(renderer, &walking);
			SDL_SetRenderDrawColor(renderer, Color2.r, Color2.g, Color2.b, 255);
			SDL_RenderFillRect(renderer, &training);
			SDL_SetRenderDrawColor(renderer, Color3.r, Color3.g, Color3.b, 255);
			SDL_RenderFillRect(renderer, &feeding);
			
			if (status[0] >= 100 && status[1] >= 100 )
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderFillRect(renderer, &Pet1);
				SDL_RenderCopy(renderer, galpus, NULL, &Pet1);
				if (status[2] > 250)
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderFillRect(renderer, &Pet1);
					SDL_RenderClear(renderer);
					SDL_RenderCopy(renderer, dead, NULL, NULL);
				}
				else if (status[0] >= 300 && status[1] >= 300)
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderFillRect(renderer, &Pet1);
					SDL_RenderCopy(renderer, rollpe, NULL, &Pet1);
					
				}

			}
			else if (status[0] < 0 || status[2] < 0 || status[2]>250)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderFillRect(renderer, &Pet1);
				SDL_RenderClear(renderer);
				SDL_RenderCopy(renderer, dead, NULL, NULL);
				
				
				
			}
			break;

		case MAP2:
			
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, howtoplay, NULL, NULL);
			break;
		}
        //Update screen
        SDL_RenderPresent( renderer );
    }

    //Destroy renderer
    SDL_DestroyRenderer(renderer);

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
