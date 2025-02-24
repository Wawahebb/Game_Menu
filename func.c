#include "header.h"
void show_image(Image img,SDL_Surface *screen){
	SDL_BlitSurface(img.image,&img.ipos,screen,&img.pos);
}
void free_image(Image *img){
	SDL_FreeSurface(img->image);
}
void init_image(Image *img,char path[],float x,float y,float ix,float iy,float w,float h){
	img->image=IMG_Load(path);
	if(img->image == NULL){
		printf("Error Loading Image : %s\n",SDL_GetError());
		return;
	}
	img->pos.x=x;
	img->pos.y=y;
	img->ipos.x=ix;
	img->ipos.y=iy;
	img->ipos.w=w;
	img->ipos.h=h;
}
void init_text(Text *t,int x,int y,int r,int g,int b,char font[],int size,char txt[]){
	t->pos.x=x;
	t->pos.y=y;
	t->color.r=r;
	t->color.g=g;
	t->color.b=b;
	t->font=TTF_OpenFont(font,size);
	strcpy(t->txt,txt);
}
void show_text(Text t,SDL_Surface *screen){
	t.text=TTF_RenderText_Blended(t.font,t.txt,t.color);
	SDL_BlitSurface(t.text,NULL,screen,&t.pos);
}
void free_text(Text *t){
	SDL_FreeSurface(t->text);
}
int image_collision(Image img,float x,float y){
	if(x>=img.pos.x && x<=img.pos.x+img.ipos.w && y>=img.pos.y && y<=img.pos.y+img.ipos.h){
		return 1;	
	}else{
		return 0;
	}
}
