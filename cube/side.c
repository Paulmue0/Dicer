#include <memory.h>
#include "side.h"
#include "../main/main.h"

void init_side_size(){
	int check = 0;
	printf("Please Enter the size of the side...\n");
	printf("x:\n");
	check += scanf ("%d",&size_x);


	printf("y:\n");
	check += scanf ("%d",&size_y);

	if(check != 2 ){
		printf("Input not accepted... please restart the program...\n");
		exit(0);
	}

	else if(size_x < 1 || size_x > MAX_SIZE_X || size_x < 1 || size_y > MAX_SIZE_Y){
		printf("The size of the side is to big...\n");
		printf("Maximal size is %dx%d\n", MAX_SIZE_X, MAX_SIZE_Y);
		init_side_size();
	}
}

char * init_single_side(){
	
	char *side = malloc( sizeof(char) * (size_x*size_y) );

	for(int i = 0; i < size_x*size_y; i++){
		print_side_raw(size_x, size_y ,side);

		int check = 0;
		printf("Please Enter the color...\n");
		printf("color:\n");
		check += scanf(" %c", &side[i]);
		
		if(check != 1 ){
			printf("Input not accepted... please restart the program...\n");
			exit(0);
		}

		else if(!check_valid_color(side[i])){
			ClearScreen();
			printf("%c is not a valid color.\n", side[i]);
			printf("Try 'r', 'w', 'y', 'b', 'o', 'g'...\n");
			memset(side,0,sizeof side);
	
			i = -1;
		}
		else{
			ClearScreen();
		}
	}
	return side;
}
char ** init_multiple_sides(){
	char **sides = malloc( sizeof(char*) * 4);

	for(int i = 0;i<4;i++)
    	sides[i] = malloc(sizeof(char) * (size_x*size_y));

	for(int side = 0; side < 4; side ++){
		ClearScreen();
		printf("Enter colors for side %d\n", side+2);
		sides[side] = init_single_side();
	}
	return sides;
}