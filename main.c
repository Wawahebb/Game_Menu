#include "header.h"
int main(){
	char vcr[]="Assets/vcr.ttf";
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)!=0){
		printf("Initialization Error : %s\n",SDL_GetError());
		return 1;
	}
	SDL_Surface *screen = SDL_SetVideoMode(WINDOW_WIDTH,WINDOW_HEIGHT,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
	if(screen == NULL){
		printf("Error Initializing The Screen : %s\n",SDL_GetError());
		return 1;
	}
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)== -1){
		printf("Error Initializing Audio : %s\n",SDL_GetError());
		return 1;
	}
	if(TTF_Init() == -1){
		printf("Error Initializing Fonts : %s\n",SDL_GetError());
		return 1;
	}
	int current_menu = 0; //main_menu = 0/settings = 1/scores = 2/story = 3/credits = 4;
	int running=1,mx,my,hover_check =0,click_check=0,quit_msg=0;
	int master_volume=8,music_volume=6,sfx_volume=0;
	//menu buttons
	Image logo,backg,play_btn,options_btn,scores_btn,story_btn,quit_btn,msg_line_up,msg_line_down,msg_backg,yes_quit,no_quit;
	//settings buttons
	Image options_backg,options_line_up,master_plus,master_minus,music_plus,music_minus,sfx_plus,sfx_minus,master_bar,music_bar,sfx_bar,fullscreen_btn,windowed_btn,back_btn;
	//scores buttons
	Image a;
	Text quit_sure;
	Mix_Music *main_menu_music;
	Mix_Chunk *hover,*click;
	SDL_Event event;
		//init menu
		init_image(&yes_quit,"Assets/images/yes_btn.png",650,700,0,0,250,75);
		init_image(&no_quit,"Assets/images/no_btn.png",1020,700,0,0,250,75);
		init_image(&msg_line_up,"Assets/images/message_line_up.png",460,200,0,0,1000,115);
		init_image(&msg_line_down,"Assets/images/message_line_down.png",585,785,0,0,750,22);
		init_image(&msg_backg,"Assets/images/message_background.png",635,285,0,0,650,500);
		init_image(&logo,"Assets/images/logo.png",760,50,0,0,400,420);
		init_image(&backg,"Assets/images/background.jpg",0,0,0,0,1920,1080);
		init_image(&play_btn,"Assets/images/play_btn.png",785,450,0,0,350,100);
		init_image(&options_btn,"Assets/images/options_btn.png",785,565,0,0,350,100);
		init_image(&scores_btn,"Assets/images/scores_btn.png",785,680,0,0,350,100);
		init_image(&story_btn,"Assets/images/story_btn.png",785,795,0,0,350,100);
		init_image(&quit_btn,"Assets/images/quit_btn.png",785,910,0,0,350,100);
		init_text(&quit_sure,650,500,255,255,255,vcr,35,"Are you sure to quit the game?");
		main_menu_music = Mix_LoadMUS("Assets/audio/menu_mus.mp3");
		hover = Mix_LoadWAV("Assets/audio/hover.wav");
		click = Mix_LoadWAV("Assets/audio/click.wav");
		//init options
		init_image(&options_backg,"Assets/images/options_background.jpg",0,0,0,0,1920,1080);
		init_image(&options_line_up,"Assets/images/options_line_up.png",210,150,0,0,1500,175);

		init_image(&master_plus,"Assets/images/plus_btn.png",1310,325,0,0,80,80);
		init_image(&music_plus,"Assets/images/plus_btn.png",1310,500,0,0,80,80);
		init_image(&sfx_plus,"Assets/images/plus_btn.png",1310,650,0,0,80,80);

		init_image(&master_minus,"Assets/images/minus_btn.png",825,325,0,0,80,80);
		init_image(&music_minus,"Assets/images/minus_btn.png",825,500,0,0,80,80);
		init_image(&sfx_minus,"Assets/images/minus_btn.png",825,650,0,0,80,80);

		init_image(&master_bar,"Assets/images/volume_bar.png",905,305,0,5+master_volume*110,400,100);
		init_image(&music_bar,"Assets/images/volume_bar.png",905,480,0,5+music_volume*110,400,100);
		init_image(&sfx_bar,"Assets/images/volume_bar.png",905,630,0,5+sfx_volume*110,400,100);

		init_image(&back_btn,"Assets/images/volume_bar.png",0,0,0,0,55,55);


	while(running){
		SDL_PollEvent(&event);
		SDL_GetMouseState(&mx,&my);
		switch(current_menu){
			case 0:
				show_image(backg,screen);
				show_image(play_btn,screen);
				show_image(options_btn,screen);
				show_image(scores_btn,screen);
				show_image(story_btn,screen);
				show_image(quit_btn,screen);
				if(!quit_msg){
					if(image_collision(play_btn,mx,my)){
						play_btn.ipos.y=150;
						if(!hover_check){
							Mix_PlayChannel(-1,hover,0);
							hover_check = 1;
						}
					}else{
						play_btn.ipos.y=0;
					}
					if(image_collision(options_btn,mx,my)){
						options_btn.ipos.y=150;
						if(!hover_check){
							Mix_PlayChannel(-1,hover,0);
							hover_check = 1;
						}
					}else{
						options_btn.ipos.y=0;
					}
					if(image_collision(scores_btn,mx,my)){
						scores_btn.ipos.y=150;	
						if(!hover_check){
							Mix_PlayChannel(-1,hover,0);
							hover_check = 1;
						}
					}else{
						scores_btn.ipos.y=0;
					}
					if(image_collision(story_btn,mx,my)){
						story_btn.ipos.y=150;	
						if(!hover_check){
							Mix_PlayChannel(-1,hover,0);
							hover_check = 1;
						}
					}else{
						story_btn.ipos.y=0;
					}
					if(image_collision(quit_btn,mx,my)){
						quit_btn.ipos.y=150;	
						if(!hover_check){
							Mix_PlayChannel(-1,hover,0);
							hover_check = 1;
						}
					}else{
						quit_btn.ipos.y=0;
					}
					if((!image_collision(play_btn,mx,my))&&(!image_collision(options_btn,mx,my))&&(!image_collision(scores_btn,mx,my))&&(!image_collision(story_btn,mx,my))&&(!image_collision(quit_btn,mx,my))){
						hover_check = 0;
					}
				}
				if(quit_msg){
					msg_line_up.image=IMG_Load("Assets/images/message_line_up.png");
					msg_line_down.image=IMG_Load("Assets/images/message_line_down.png");
					yes_quit.image=IMG_Load("Assets/images/yes_btn.png");
					no_quit.image=IMG_Load("Assets/images/no_btn.png");
					msg_backg.image=IMG_Load("Assets/images/message_background.png");
					show_image(msg_line_up,screen);
					show_image(msg_line_down,screen);
					show_image(msg_backg,screen);
					show_text(quit_sure,screen);
					show_image(yes_quit,screen);
					show_image(no_quit,screen);
					if(image_collision(yes_quit,mx,my)){
						yes_quit.ipos.y=112.5;
						if(!hover_check){
							Mix_PlayChannel(-1,hover,0);
							hover_check = 1;
						}
					}else{
						yes_quit.ipos.y=0;
					}
					if(image_collision(no_quit,mx,my)){
						no_quit.ipos.y=112.5;
						if(!hover_check){
							Mix_PlayChannel(-1,hover,0);
							hover_check = 1;
						}
					}else{
						no_quit.ipos.y=0;
					}
							if((!image_collision(no_quit,mx,my))&&(!image_collision(yes_quit,mx,my))){
						hover_check = 0;
					}
				}
				switch(event.type){
					case SDL_KEYDOWN:
						switch(event.key.keysym.sym){
							case SDLK_ESCAPE:
								running = 0;
								break;
						}
						break;
					case SDL_MOUSEBUTTONDOWN:
						if(event.button.button == SDL_BUTTON_LEFT){
							if(!quit_msg){
								if(image_collision(play_btn,mx,my)){
									play_btn.ipos.y=300;
									if(click_check){
										click_check=0;
									}
								}
								if(image_collision(options_btn,mx,my)){
									options_btn.ipos.y=300;
									if(click_check){
										click_check=0;
									}
								}
								if(image_collision(scores_btn,mx,my)){
									scores_btn.ipos.y=300;
									if(click_check){
										click_check=0;
									}
								}
								if(image_collision(story_btn,mx,my)){
									story_btn.ipos.y=300;
									if(click_check){
										click_check=0;
									}
								}
								if(image_collision(quit_btn,mx,my)){
									quit_btn.ipos.y=300;
									if(click_check){
										click_check=0;
									}
									
								}
							}
							if(quit_msg){
								if(image_collision(yes_quit,mx,my)){
									yes_quit.ipos.y=225;
									if(click_check){
										click_check=0;
									}
									
								}
								if(image_collision(no_quit,mx,my)){
									no_quit.ipos.y=225;
									if(click_check){
										click_check=0;
									}
									
								}
							}
						}
						break;
					case SDL_MOUSEBUTTONUP:
						if(event.button.button == SDL_BUTTON_LEFT){
							if(!quit_msg){
								if(image_collision(play_btn,mx,my)){
									if(!click_check){
										Mix_PlayChannel(-1,click,0);
										click_check=1;
									}
								}
								if(image_collision(options_btn,mx,my)){
									if(!click_check){
										Mix_PlayChannel(-1,click,0);
										click_check=1;
										free_image(&yes_quit);
										free_image(&no_quit);
										free_image(&msg_line_up);
										free_image(&msg_line_down);
										free_image(&msg_backg);
										free_image(&logo);
										free_image(&backg);
										free_image(&play_btn);
										free_image(&options_btn);
										free_image(&scores_btn);
										free_image(&story_btn);
										free_image(&quit_btn);
										free_text(&quit_sure);
										current_menu=1;
									}
								}
								if(image_collision(scores_btn,mx,my)){
									if(!click_check){
										Mix_PlayChannel(-1,click,0);
										click_check=1;
									}
								}
								if(image_collision(story_btn,mx,my)){
									if(!click_check){
										Mix_PlayChannel(-1,click,0);
										click_check=1;
									}
								}
								if(image_collision(quit_btn,mx,my)){
									if(!click_check){
										Mix_PlayChannel(-1,click,0);
										click_check=1;
										quit_msg = 1;
									}
								}
							}
							if(quit_msg){
								if(image_collision(yes_quit,mx,my)){
									if(!click_check){
										Mix_PlayChannel(-1,click,0);
										click_check=1;
										running=0;
									}
								}
								if(image_collision(no_quit,mx,my)){
									if(!click_check){
										Mix_PlayChannel(-1,click,0);
										click_check=1;
										free_image(&msg_line_up);
										free_image(&msg_line_down);
										free_image(&msg_backg);
										free_image(&yes_quit);
										free_image(&no_quit);
										quit_msg=0;
									}
								}
							}
						}
						break;
					default:
						break;
				}
				break;
			case 1:
				show_image(options_backg,screen);
				show_image(options_line_up,screen);
				show_image(master_plus,screen);
				show_image(master_minus,screen);
				show_image(music_plus,screen);
				show_image(music_minus,screen);
				show_image(sfx_plus,screen);
				show_image(sfx_minus,screen);
				show_image(master_bar,screen);
				show_image(music_bar,screen);
				show_image(sfx_bar,screen);
				show_image(fullscreen_btn,screen);
				show_image(windowed_btn,screen);
				show_image(back_btn,screen);
				if(image_collision(master_plus,mx,my)){
					master_plus.ipos.y=100;
					if(!hover_check){
						Mix_PlayChannel(-1,hover,0);
						hover_check = 1;
					}
				}else{
					master_plus.ipos.y=0;
				}
				if(image_collision(master_minus,mx,my)){
					master_minus.ipos.y=100;
					if(!hover_check){
						Mix_PlayChannel(-1,hover,0);
						hover_check = 1;
					}
				}else{
					master_minus.ipos.y=0;
				}
				if(image_collision(music_plus,mx,my)){
					music_plus.ipos.y=100;	
					if(!hover_check){
						Mix_PlayChannel(-1,hover,0);
						hover_check = 1;
					}
				}else{
					music_plus.ipos.y=0;
				}
				if(image_collision(music_minus,mx,my)){
					music_minus.ipos.y=100;	
					if(!hover_check){
						Mix_PlayChannel(-1,hover,0);
						hover_check = 1;
					}
				}else{
					music_minus.ipos.y=0;
				}
				if(image_collision(sfx_plus,mx,my)){
					sfx_plus.ipos.y=100;	
					if(!hover_check){
						Mix_PlayChannel(-1,hover,0);
						hover_check = 1;
					}
				}else{
					sfx_plus.ipos.y=0;
				}
				if(image_collision(sfx_minus,mx,my)){
					sfx_minus.ipos.y=100;	
					if(!hover_check){
						Mix_PlayChannel(-1,hover,0);
						hover_check = 1;
					}
				}else{
					sfx_minus.ipos.y=0;
				}
				if((!image_collision(master_plus,mx,my))&&(!image_collision(master_minus,mx,my))&&(!image_collision(music_plus,mx,my))&&(!image_collision(music_minus,mx,my))&&(!image_collision(sfx_plus,mx,my))&&(!image_collision(sfx_minus,mx,my))){
					hover_check = 0;
				}
				switch(event.type){
					case SDL_KEYDOWN:
						switch(event.key.keysym.sym){
							case SDLK_ESCAPE:
								running = 0;
								break;
						}
						break;
					case SDL_MOUSEBUTTONDOWN:
						if(event.button.button == SDL_BUTTON_LEFT){
							if(image_collision(master_plus,mx,my)){
								master_plus.ipos.y=200;
								if(click_check){
									click_check=0;
								}
							}
							if(image_collision(master_minus,mx,my)){
								master_minus.ipos.y=200;
								if(click_check){
									click_check=0;
								}
							}
							if(image_collision(music_plus,mx,my)){
								music_plus.ipos.y=200;
								if(click_check){
									click_check=0;
								}
							}
							if(image_collision(music_minus,mx,my)){
								music_minus.ipos.y=200;
								if(click_check){
									click_check=0;
								}
							}
							if(image_collision(sfx_plus,mx,my)){
								sfx_plus.ipos.y=200;
								if(click_check){
									click_check=0;
								}	
							}
							if(image_collision(sfx_minus,mx,my)){
								sfx_minus.ipos.y=200;
								if(click_check){
									click_check=0;
								}	
							}
						}
						break;
					case SDL_MOUSEBUTTONUP:
						if(event.button.button == SDL_BUTTON_LEFT){
							if(image_collision(master_plus,mx,my)){
								if(!click_check){
									Mix_PlayChannel(-1,click,0);
									click_check=1;
								}
							}
							if(image_collision(master_minus,mx,my)){
								if(!click_check){
									Mix_PlayChannel(-1,click,0);
									click_check=1;
								}
							}
							if(image_collision(music_plus,mx,my)){
								if(!click_check){
									Mix_PlayChannel(-1,click,0);
									click_check=1;
								}
							}
							if(image_collision(music_minus,mx,my)){
								if(!click_check){
									Mix_PlayChannel(-1,click,0);
									click_check=1;
								}
							}
							if(image_collision(sfx_plus,mx,my)){
								if(!click_check){
									Mix_PlayChannel(-1,click,0);
									click_check=1;
								}
							}
							if(image_collision(sfx_minus,mx,my)){
								if(!click_check){
									Mix_PlayChannel(-1,click,0);
									click_check=1;
								}
							}
						}
						break;
				break;
			}
		}// switch menu
		
		SDL_Flip(screen);
	}
	
	SDL_Quit();
	return 0;
}