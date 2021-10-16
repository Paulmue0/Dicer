#include "ui.h"
#include "colors.c"

void indent_side(int x){
	while(x){
		printf("  ");
		x--;
	}
	printf(" ");
	
}

void print_top_or_bottom_row(int x){
	indent_side(x);
	for(int i = 0; i < x; i++){
		printf("##");
	}
	printf("##\n");
}

void print_middle_row(int x){
	for(int i = 0; i < 4*x; i++){
		printf("##");
	}
	printf("#####\n");
}

void print_short_side(int x, int y, char *side){
	int tmp_cnt = 0;

	for(int i = 0; i < y; i++){
		indent_side(x);
		printf("#");
		for(int j = 0; j < x; j++){
			print_color_block(side[tmp_cnt]);
			tmp_cnt++;
		}
		printf("#\n");
	}
}

void print_long_side(int x, int y, char **sides){
	int tmp_cnt;

	for(int i = 0; i < y; i++){
		printf("#");
		tmp_cnt = 0;
		for(int side = 0; side < 4; side++){
			for(int j = 0; j < x; j++){
			print_color_block(sides[side][j]);
		}
		printf("#");

		}
		printf("\n");
	}
}

void print_cube(int x, int y, char *side_1, char **sides_2_to_5, char *side_6){
	
	
	print_top_or_bottom_row(x);
	print_short_side(x, y, side_1);
	print_middle_row(x);
	print_long_side(x, y, sides_2_to_5);
	print_middle_row(x);
	print_short_side(x, y, side_6);
	print_top_or_bottom_row(x);
}