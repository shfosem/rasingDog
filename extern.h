#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "struct.h"
// �ʼ��䱸���� A,F,G
#define MOUSEON 200;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int status[3] = { 20,0,70 };//0 �漺��, 1 ü�� 2 �����
int map = 0;

SDL_Rect Pet1 = { 200,100,200,200 };	//������ �׸� Rect
SDL_Rect box1 = { 220,100,200,50 }; // ��ư Rect
SDL_Rect box2 = { 220,200,200,50 };
SDL_Rect box3 = { 220,300,200,50 };

SDL_Rect walking = { 0, 430, 200, 50 };
SDL_Rect training = { 220, 430, 200, 50 };
SDL_Rect feeding = { 440, 430, 200, 50 };

Color Color1 = { 255,0,0 };
Color Color2 = { 0,255,0 };
Color Color3 = { 0,0,255 };
Color ScColor = { 0,0,0 };