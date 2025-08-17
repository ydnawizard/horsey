// STRUCTURE FOR STORING DATA ABOUT OBJECTS ON SCREEN

typedef struct OBJECT
{
	int id;
	int color[4];
	int vertice_count;
	int line_count;
	float position[4];
	int** vertice_map;
	float** vertices;
	float** normalized_vertices;
}OBJECT;

