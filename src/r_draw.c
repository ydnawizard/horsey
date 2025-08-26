//FUNCTIONS FOR DRAWING OBJECT TO SCREEN

void draw_object(SDL_Renderer* render_pointer,CAMERA* camera_pointer,OBJECT* object_pointer)
{
	SDL_SetRenderDrawColor(
			render_pointer,
			object_pointer->color[0],
			object_pointer->color[1],
			object_pointer->color[2],
			object_pointer->color[3]
			);
	for(int i = 0; i < object_pointer->line_count;i++)
	{
		SDL_RenderLine(render_pointer,
				object_pointer->post_vertices[object_pointer->vertice_map[i][0]][0],
				object_pointer->post_vertices[object_pointer->vertice_map[i][0]][1],
				object_pointer->post_vertices[object_pointer->vertice_map[i][1]][0],
				object_pointer->post_vertices[object_pointer->vertice_map[i][1]][1]
			      );
	}
}
