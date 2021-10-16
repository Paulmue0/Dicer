#include <stdio.h>
#include <stdlib.h>
#include "ui/ui.c"
#include "main.h"


// size of cube
int size_x, size_y = 0;

int main(){
		
	init_cube_size();
	char * cube_1 = init_single_side();
	//char cube_2_to_5[4][size_x*size_y] init_multiple_sides();
	// char cube_3[size_x*size_y] = init_single_side();

	print_cube(size_x, size_y, cube_1);

	return 0;

}






