//FUNCTIONS FOR VECTOR TRANSFORMATIONS


void matrix_multiply_source_to_source(float ** source_vector,float matrix[4][4])
{
	(*source_vector)[0] = (*source_vector)[0] * matrix[0][0] + (*source_vector)[1] * matrix[0][1] + (*source_vector)[2] * matrix[0][2] + (*source_vector)[3] * matrix[0][3];
	(*source_vector)[1] = (*source_vector)[0] * matrix[1][0] + (*source_vector)[1] * matrix[1][1] + (*source_vector)[2] * matrix[1][2] + (*source_vector)[3] * matrix[1][3];
	(*source_vector)[2] = (*source_vector)[0] * matrix[2][0] + (*source_vector)[1] * matrix[2][1] + (*source_vector)[2] * matrix[2][2] + (*source_vector)[3] * matrix[2][3];
	(*source_vector)[3] = (*source_vector)[0] * matrix[3][0] + (*source_vector)[1] * matrix[3][1] + (*source_vector)[2] * matrix[3][2] + (*source_vector)[3] * matrix[3][3];
	if((*source_vector)[3] != 0.000f)
	{
		(*source_vector)[0] /= (*source_vector)[3];
		(*source_vector)[1] /= (*source_vector)[3];
		(*source_vector)[2] /= (*source_vector)[3];
	}
}
//Matrix mult with source vector and matrix mult operation outputting to a specified destination vector
void matrix_multiply_source_to_destination(float ** source_vector,float ** destination_vector,float matrix[4][4])
{
	(*destination_vector)[0] = (*source_vector)[0] * matrix[0][0] + (*source_vector)[1] * matrix[0][1] + (*source_vector)[2] * matrix[0][2] + (*source_vector)[3] * matrix[0][3];
	(*destination_vector)[1] = (*source_vector)[0] * matrix[1][0] + (*source_vector)[1] * matrix[1][1] + (*source_vector)[2] * matrix[1][2] + (*source_vector)[3] * matrix[1][3];
	(*destination_vector)[2] = (*source_vector)[0] * matrix[2][0] + (*source_vector)[1] * matrix[2][1] + (*source_vector)[2] * matrix[2][2] + (*source_vector)[3] * matrix[2][3];
	(*destination_vector)[3] = (*source_vector)[0] * matrix[3][0] + (*source_vector)[1] * matrix[3][1] + (*source_vector)[2] * matrix[3][2] + (*source_vector)[3] * matrix[3][3];
	if((*destination_vector)[3] != 0.000f)
	{
		(*destination_vector)[0] /= (*destination_vector)[3];
		(*destination_vector)[1] /= (*destination_vector)[3];
		(*destination_vector)[2] /= (*destination_vector)[3];
	}
}

void rotate_object_x(OBJECT* object_pointer,int degrees)
{
	object_pointer->x_rotational_orientation += degrees;
	object_pointer->x_rotational_orientation = object_pointer->x_rotational_orientation % 360;
	float theta = 0.0174533 * object_pointer->x_rotational_orientation;
	float matrix[4][4] = {
		{1,0,0,0},
		{0,cosf(theta),-sinf(theta),0},
		{0,sinf(theta),cosf(theta),0},
		{0,0,0,1}
	};
	for(int i = 0; i < object_pointer->vertice_count; i++)
	{
		matrix_multiply_source_to_destination(&object_pointer->pre_vertices[i],&object_pointer->post_vertices[i],matrix);
		//matrix_multiply_source_to_source(&object_pointer->post_vertices[i],matrix);
	}
}

void rotate_object_y(OBJECT* object_pointer,int degrees)
{
	object_pointer->y_rotational_orientation += degrees;
	object_pointer->y_rotational_orientation = object_pointer->y_rotational_orientation % 360;
	float theta = 0.0174533 * object_pointer->y_rotational_orientation;
	float matrix[4][4] = {
		{cosf(theta),0,sinf(theta),0},
		{0,1,0,0},
		{-sinf(theta),0,cosf(theta),0},
		{0,0,0,1}
	};
	for(int i = 0; i < object_pointer->vertice_count; i++)
	{
		//matrix_multiply_source_to_destination(&object_pointer->pre_vertices[i],&object_pointer->post_vertices[i],matrix);
		matrix_multiply_source_to_source(&object_pointer->post_vertices[i],matrix);
	}
}


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
