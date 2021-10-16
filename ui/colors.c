#include "colors.h"

void print_color_block(char color){
	if(color == 'r'){
		printf("\033[0101m  \033[0m");
	}
	else if(color == 'w'){
		printf("\033[107m  \033[0m");
	}
	else if(color == 'b'){
		printf("\033[104m  \033[0m");
	}
	else if(color == 'y'){
		printf("\033[103m  \033[0m");
	}
	else if(color == 'o'){
		printf("\033[48;5;214m  \033[0m");
	}
	else if(color == 'g'){
		printf("\033[102m  \033[0m");
	}
}

int check_valid_color(char color){
	if(color == 'r'){
		return 1;
	}
	if(color == 'w'){
		return 1;
	}
	if(color == 'b'){
		return 1;
	}
	if(color == 'y'){
		return 1;
	}
	if(color == 'o'){
		return 1;
	}
	if(color == 'g'){
		return 1;
	}


	return 0;
	
}