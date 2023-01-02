#include "Header.h"


/********************************************************************************
							    (void)file_read:
	  Läser ur den textfil vi skapat och printar dess innehåll till terminal.

						filepath: filsökväg till "cars.txt".

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