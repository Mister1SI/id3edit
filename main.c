#include <stdio.h>

void print_help();

int main(int argc, char** argv) {
	if(argc == 1) {
		print_help();
		return 0;
	}
	if(argc == 2) {
		if(argv[1] == "-h") {
			print_help();
			return 0;
		} else {
			puts("Invalid number of arguments. Run with -h for help.");
			return 1;
		}
	}
	if(argc > 3) {
		puts("More arguments than expected. Ignoring all past 2.");
	}
	return 0;
}

void print_help() {
	char* help_text = 
		"usage: id3edit <param> <file> [options]";
	puts(help_text);
}

