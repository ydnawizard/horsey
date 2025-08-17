//FUNCTIONS FOR ADJUSTING OBJECT DATA SO IT APPEARS HOW/WHERE ITS SUPPOSED TO

void normalize_object(OBJECT* object_pointer,CAMERA* camera_pointer)
{
	for(int i = 0;i < object_pointer->vertice_count; i++)
	{
		object_pointer->vertices[i][0] = window_width/2 - camera_pointer->position[0];
		object_pointer->vertices[i][1] = window_height/2 - camera_pointer->position[1];
		object_pointer->vertices[i][2] = 0 - camera_pointer->position[2];
		object_pointer->vertices[i][3] = camera_pointer->position[3];
	}
}
