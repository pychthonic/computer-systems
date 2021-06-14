/*
 *
 * Write a function good_echo that reads a line from standard input and writes it to
 * standard output. Your implementation should work for an input line of arbitrary length.
 * You may use the library function fgets, but you must make sure your function works
 * correctly even when the input line requires more space than you have allocated for your
 * buffer. Your code should also check for error conditions and return when one is
 * encountered. Refer to the definitions of the standard I/O functions for documentation
 * [45, 61].
 *
 */


/*
 * Note that this will still limit the size of a line that is input through stdin to
 * 4095 bytes (4096 minus one which is set to '\n' even if no new line has been
 * encountered). The reason for this is the kernel buffer is set to 4096 bytes.
 * 
 */

#include <stdio.h>   // for fgets and printf

int good_echo(char *buffer, char* input_string) {
	while (1) {
		fgets(buffer, 2, (FILE *) input_string);
		if (*(char*) buffer == 0x0) {
			printf("\nFound null byte. Finished reading string.\n");
			printf("count: %d\n", count);
			break;
		}
		if (*(char*) buffer == 0xA) {
			printf("\nFound new line. Finished reading string.\n");
			printf("count: %d\n", count);
			break;
		}

		printf("%s", buffer);
		
	}
	return 0;
}
int main() {
	char naturally_buff[10];
	good_echo(naturally_buff, (char*) stdin);
    	return 0;
}
