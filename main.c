#include <stdio.h>
#include <stdbool.h>

void print_help();

int main(int argc, char** argv) {
	if(argc == 1) {
		print_help();
		return 0;
	}
	if(argc == 2) {
		if(argv[1][0] == '-' && argv[1][1] == 'h') {
			print_help();
			return 0;
		} else {
			puts("Invalid number of arguments. Run with -h for help.");
			return 1;
		}
	}
	
	bool mode = true;
	for(int i = 0; i < argc; i++) {
		char* arg = argv[i+1];
		if(arg[0] == '-') {
			//Option
			//Ignore for now
			//
		} else {
			if(mode) {
				switch(arg[0]) {
				case 'T':
					puts("Title\nEnter new title(Max 30)> ");
					break;
				case 'A':
					puts("Artist\nEnter new artist(Max 30)>");
					break;
				case 'L':
					puts("Album\nEnter new album(Max 30)>");
					break;
				case 'C':
					puts("Comment\nEnter new comment(Max 30)>");
					break;
				default:
					fputs("unknown option \'", stdout);
					fputs(argv[1], stdout);
					puts("\'. Terminating.");
					return 1;
				}
				mode = false;
			}
		}

	}



	return 0;
}

void print_help() {
	char* help_text = 
		"usage: id3edit [options] <param> <file>\n"\
		"\noptions:\n\t-i: idk\n\n"\
		"modes:\n\tT: edit title\n\tA: edit album\n\tL: edit album\n\tC: edit comment";
	puts(help_text);
}

