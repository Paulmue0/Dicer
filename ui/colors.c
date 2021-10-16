#include "colors.h"
#include "../main/main.h"

#ifdef _WIN32
#include <windows.h>
#endif





void print_color_block_unix(char color){
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

void print_color_block(char color){
	#ifdef PLATFORM_NAME_USED
	if(PLATFORM_NAME_USED == "unix")
		print_color_block_unix(color);
	else if (PLATFORM_NAME_USED == "windows")
		print_color_block_windows(color);
	#else
	printf("Error... cannot identify OS.");
	#endif
}

void print_color_block_windows(char color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    

    
	
	if(color == 'r'){
		SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
	}
	else if(color == 'w'){
		SetConsoleTextAttribute(hConsole, (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED));
	}
	else if(color == 'b'){
		SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
	}
	else if(color == 'y'){
		SetConsoleTextAttribute(hConsole, (BACKGROUND_GREEN | BACKGROUND_RED ));
	}
	else if(color == 'o'){
		SetConsoleTextAttribute(hConsole, ((12 & 0x0F) << 4));
	}
	else if(color == 'g'){
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
	}
	
	/* Print block*/
	printf("  ");
	
	/* Restore original attributes */
    SetConsoleTextAttribute(hConsole, saved_attributes);
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