// STRUCTURE FOR STORING DATA ABOUT OBJECTS ON SCREEN

typedef struct OBJECT
{
	int id;
	int color[4];
	int vertice_count;
	int line_count;
	int x_rotational_orientation;
	int y_rotational_orientation;
	int z_rotational_orientation;
	float position[4];
	int** vertice_map;
	float** pre_vertices;
	float** post_vertices;
}OBJECT;

