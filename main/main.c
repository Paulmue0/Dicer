#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "../ui/ui.c"
#include "../cube/side.c"





// size of side
// GLOBAL VARIABLES FROM side.h
int size_x, size_y = 0;

int main(){

	init_side_size();

	ClearScreen();
	printf("Enter colors for side %d\n", 1);
	char * side_1 = init_single_side();
	char ** sides_2_to_5 = init_multiple_sides();
	printf("Enter colors for side %d\n", 6);
	char * side_3 = init_single_side();

	print_cube(size_x, size_y, side_1, sides_2_to_5, side_3);

	 while(1){
        printf("Press any Key to exit :)\n");
        getch();
        break;
    }

	return 0;

}






