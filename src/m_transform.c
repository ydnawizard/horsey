//MATRIX MULTIPLICATION

void matrix_multiply(float** vector,float matrix[4][4])
{
	(*vector)[0] = (*vector)[0] * matrix[0][0] + (*vector)[1] * matrix[0][1] + (*vector)[2] * matrix[0][2] + (*vector)[3] * matrix[0][3];
	(*vector)[1] = (*vector)[0] * matrix[1][0] + (*vector)[1] * matrix[1][1] + (*vector)[2] * matrix[1][2] + (*vector)[3] * matrix[1][3];
	(*vector)[2] = (*vector)[0] * matrix[2][0] + (*vector)[1] * matrix[2][1] + (*vector)[2] * matrix[2][2] + (*vector)[3] * matrix[2][3];
	(*vector)[3] = (*vector)[0] * matrix[3][0] + (*vector)[1] * matrix[3][1] + (*vector)[2] * matrix[3][2] + (*vector)[3] * matrix[3][3];
	if((*vector)[3] != 0.000f)
	{
		(*vector)[0] /= (*vector)[3];
		(*vector)[1] /= (*vector)[3];
		(*vector)[2] /= (*vector)[3];
	}
}

void rotate_object(OBJECT* object_pointer,float theta,char axis)
{
	if(axis == 'y')
	{
		float matrix[4][4] = {
			{cosf(theta),0,sinf(theta),0},
			{0,1,0,0},
			{-sinf(theta),0,cosf(theta),0},
			{0,0,0,1}
		};
		for(int i = 0; i < object_pointer->vertice_count; i++)
		{
			matrix_multiply(&object_pointer->vertices[i],matrix);
		}
	}
}
