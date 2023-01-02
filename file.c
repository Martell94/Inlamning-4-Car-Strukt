#include "Header.h"


/********************************************************************************
							    (void)file_read:
	  L�ser ur den textfil vi skapat och printar dess inneh�ll till terminal.

						filepath: fils�kv�g till "cars.txt".

********************************************************************************/
void file_read(const char* filepath){

	FILE* istream = fopen(filepath, "r");
	if (!istream) return;

	char s[100] = {'\0'};

	while (fgets(s, sizeof(s), istream)){
		printf("%s", s);
	}

	fclose(istream);
	return;
}