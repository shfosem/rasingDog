
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
// 필수요구사항 A,C

int checkMouse(SDL_Rect a, int x, int y)
{
	if (x < a.x)
		return 0;
	else if (x > a.x + a.w)
		return 0;
	else if (y < a.y)
		return 0;
	else if (y > a.y + a.h)
		return 0;
	return 1;
}