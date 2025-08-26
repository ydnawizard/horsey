/*
____    ____   ____   ________      ____  __________ ____     ___ 
`MM'    `MM'  6MMMMb  `MMMMMMMb.   6MMMMb\`MMMMMMMMM `MM(     )M' 
 MM      MM  8P    Y8  MM    `Mb  6M'    ` MM      \  `MM.    d'  
 MM      MM 6M      Mb MM     MM  MM       MM          `MM.  d'   
 MM      MM MM      MM MM     MM  YM.      MM    ,      `MM d'    
 MMMMMMMMMM MM      MM MM    .M9   YMMMMb  MMMMMMM       `MM'     
 MM      MM MM      MM MMMMMMM9'       `Mb MM    `        MM      
 MM      MM MM      MM MM  \M\          MM MM             MM      
 MM      MM YM      M9 MM   \M\         MM MM             MM      
 MM      MM  8b    d8  MM    \M\  L    ,M9 MM      /      MM      
_MM_    _MM_  YMMMM9  _MM_    \M\_MYMMMM9 _MMMMMMMMM     _MM_     

FONT: GEROGI16 ON PATORJK

SDL3-BASED ENGINE FOR BUILDING SIMPLE GAMES/VISUALS
WRITTEN BY: ELLIS "ANDY" WEGLEWSKI/OSCILLATOR

*/

//QUATERNIONS!

#include "main.h"

SDL_Window* window;
SDL_Renderer* renderer;

int main()
{
	SDL_Event event;
	bool running = true;
	const bool* keyboard_state = SDL_GetKeyboardState(NULL);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("window",window_width,window_height,SDL_WINDOW_RESIZABLE,&window,&renderer);
	///
	///
	float camera_position[4] = {window_width/2.0f,window_height/2.0f,1.0f,1.0f};
	CAMERA camera;
	memcpy(camera.position,camera_position,sizeof(float*));
	///
	///
	OBJECT cube_1;
	cube_1.id = 0;
	float position[4] = {0.0f,0.0f,0.0f,0.0f};
	memcpy(cube_1.position,position,sizeof(float*));
	memcpy(cube_1.color,GREEN,sizeof(float*));
	generate_cube(&cube_1,250);
	///
	///
	int degrees = 1;
	while(running)
	{
		/*for(int i = 0;i < cube_1.vertice_count;i++)
		{
			memcpy(cube_1.post_vertices[i],cube_1.pre_vertices[i],4 * sizeof(float));
		}
		*/
		if(degrees > 360)
		{
			degrees = 1;
		}
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_EVENT_QUIT)
			{
				running = false;
			}
			else if(event.type == SDL_EVENT_KEY_DOWN)
			{
				if(keyboard_state[SDL_SCANCODE_Q])
				{
					exit(0);
				}
			}
		}
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		SDL_RenderClear(renderer);
		rotate_object_y_pre(&cube_1,1);
		rotate_object_x_post(&cube_1,3);
		translate_vertices_to_camera_perspective(&cube_1,&camera);
		degrees +=2;
		draw_object(renderer,&camera,&cube_1);
		SDL_RenderPresent(renderer);
		usleep(15000);
	}
	return 0;
}
