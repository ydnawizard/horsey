//FUNCTIONS FOR ADJUSTING OBJECT DATA SO IT APPEARS HOW/WHERE ITS SUPPOSED TO

void translate_vertices_to_camera_perspective(OBJECT* object_pointer,CAMERA* camera_pointer)
{
	for(int i = 0;i < object_pointer->vertice_count; i++)
	{
		//object_pointer->pre_vertices[i] = malloc(4*sizeof(float));
		object_pointer->post_vertices[i][0] = object_pointer->post_vertices[i][0] + camera_pointer->position[0];
		object_pointer->post_vertices[i][1] = object_pointer->post_vertices[i][1] + camera_pointer->position[1];
		object_pointer->post_vertices[i][2] = object_pointer->post_vertices[i][2] + camera_pointer->position[2];
		object_pointer->post_vertices[i][3] = object_pointer->post_vertices[i][3];
	}
}
