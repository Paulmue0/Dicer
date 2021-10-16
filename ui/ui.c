#include "ui.h"
#include "../main.h"

extern int size_x;
extern int size_y;


void init_cube_size(){
	int check = 0;

	printf("Please Enter the size of the cube...\n");
	printf("x:\n");
	check += scanf ("%d",&size_x);


	printf("y:\n");
	check += scanf ("%d",&size_y);

	if(check != 2 ){
		printf("Input not accepted... please restart the program...\n");
		exit(0);
	}

	else if(size_x < 1 || size_x > MAX_SIZE_X || size_x < 1 || size_y > MAX_SIZE_Y){
		printf("The size of the cube is to big...\n");
		printf("Maximal size is %dx%d\n", MAX_SIZE_X, MAX_SIZE_Y);
		init_cube_size();
	}

}

char * init_single_side(){
	
	char *cube = malloc( sizeof(char) * (size_x*size_y) );

	for(int i = 0; i < size_x*size_y; i++){
		int check = 0;
		printf("Please Enter the color...\n");
		printf("color:\n");
		check += scanf(" %c", &cube[i]);

		


		if(check != 1 ){
			printf("Input not accepted... please restart the program...\n");
			exit(0);
		}

		else if(cube[i] != 'r'){
			printf("%c is not a valid color. Try 'r'\n", cube[i]);
			i = -1;
		}
	}
	return cube;

}

void indent_cube(int x){
	while(x){
		printf("   ");
		x--;
	}
	printf(" ");
	
}

void print_top_or_bottom_row(int x){
	indent_cube(x);
	for(int i = 0; i < x; i++){
		printf("###");
	}
	printf("##\n");
}

void print_middle_row(x){
	for(int i = 0; i < 4*x; i++){
		printf("###");
	}
	printf("#####\n");
}

void print_short_side(int x, int y, char *cube){
	for(int i = 0; i < y; i++){
		indent_cube(x);
		printf("#");
		for(int j = 0; j < x; j++){
			printf("[%c]", cube[j]);
		}
		printf("#\n");
	}
}

void print_long_side(int x, int y){
	for(int i = 0; i < y; i++){
		printf("#");
		for(int j = 0; j < 4*x; j++){
			printf("[x]");

			if(((j+1) % x) == 0){
				printf("#");
			}
		}
		printf("\n");
	}
}

void print_cube(int x, int y, char *cube){
	
	
	print_top_or_bottom_row(x);
	print_short_side(x, y, cube);
	print_middle_row(x);
	print_long_side(x, y);
	print_middle_row(x);
	print_short_side(x, y, cube);
	print_top_or_bottom_row(x);
}