//FUNCTIONS FOR ADJUSTING OBJECT DATA SO IT APPEARS HOW/WHERE ITS SUPPOSED TO

void normalize_object(OBJECT* object_pointer,CAMERA* camera_pointer)
{
	object_pointer->normalized_vertices = malloc(object_pointer->vertice_count*sizeof(float*));
	for(int i = 0;i < object_pointer->vertice_count; i++)
	{
		object_pointer->normalized_vertices[i] = malloc(4*sizeof(float));
		object_pointer->normalized_vertices[i][0] = object_pointer->vertices[i][0] + camera_pointer->position[0];
		object_pointer->normalized_vertices[i][1] = object_pointer->vertices[i][1] + camera_pointer->position[1];
		object_pointer->normalized_vertices[i][2] = object_pointer->vertices[i][2] - camera_pointer->position[2];
		object_pointer->normalized_vertices[i][3] = object_pointer->vertices[i][3];
	}
}
