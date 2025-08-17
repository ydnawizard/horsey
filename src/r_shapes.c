//FUNCTIONS FOR GENERATING SIMPLE SHAPES


//Takes in an empty object struct with size and position data
//returns a cube of input size at input position
void generate_cube(OBJECT* cube_pointer,int size)
{
	//Halve size because cube is drawn in respect to its own origin
	float adj_size = size/2;
	//Generate vertice map so renderer knows what lines to draw
	cube_pointer->line_count = 12;
	int vertice_map[12][2] = 
	{
		{0,1},
		{1,2},
		{2,3},
		{3,0},
		{3,4},
		{2,7},
		{1,6},
		{0,5},
		{4,5},
		{5,6},
		{6,7},
		{7,4},
	};
	cube_pointer->vertice_map = malloc(12 * sizeof(int*));
	for(int i = 0; i < 12; i++)
	{
		cube_pointer->vertice_map[i] = malloc(2 * sizeof(int));
		memcpy(cube_pointer->vertice_map[i],vertice_map[i],2*sizeof(int));
	}
	//Generate vertices in respect to size
	cube_pointer->vertice_count = 8;
	float vertices[8][4] =
	{
		 {-adj_size,adj_size,adj_size,1},
		 {-adj_size,adj_size,-adj_size,1},
		 {-adj_size,-adj_size,-adj_size,1},
		 {-adj_size,-adj_size,adj_size,1},
		 {adj_size,-adj_size,adj_size,1},
		 {adj_size,adj_size,adj_size,1},
		 {adj_size,adj_size,-adj_size,1},
		 {adj_size,-adj_size,-adj_size,1},
	};
	cube_pointer->vertices = malloc(8 * sizeof(float*));
	for(int i = 0; i < 8; i++)
	{
		cube_pointer->vertices[i] = malloc(4 * sizeof(float));
		memcpy(cube_pointer->vertices[i],vertices[i],4*sizeof(float));
	}
	for(int i = 0; i < 8; i++)
	{
		printf("%f\n",cube_pointer->vertices[i][0]);
		printf("%f\n",cube_pointer->vertices[i][1]);
	}
}


void generate_prism(OBJECT* prism_pointer,int length,int width,int height,int position)
{
}

void generate_pyramid(OBJECT* pyramid_pointer,int size,int position)
{
}

 
