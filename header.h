#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <unistd.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

typedef struct{
	SDL_Rect pos;
	SDL_Rect ipos;
	SDL_Surface *image;
}Image;

typedef struct{
	SDL_Rect pos;
	TTF_Font *font;
	SDL_Surface *text;
	SDL_Color color;
	char txt[50];
}Text;

void init_image(Image *img,char path[],float x,float y,float ix, float iy,float w,float h);
void show_image(Image img,SDL_Surface *screen);
void free_image(Image *img);

void init_text(Text *t,int x,int y,int r,int g,int b,char font[],int size,char txt[]);
void show_text(Text t,SDL_Surface *screen);
void free_text(Text *t);

int image_collision(Image img,float x,float y);

#endif
