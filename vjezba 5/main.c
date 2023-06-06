#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

int readWord(FILE *fd, char *buffer)
{
	int c;
	
	do {
		c = fgetc(fd);				
		if(c == EOF)
			return 0;
	} while(!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if(c == 146)
			c = '\'';
	} while(isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	FILE *fd;
	char buffer[1024];
	Dictionary *dict = NULL;
				
	fd = fopen("liar.txt", "rt");
	if(fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	dict = create();

	Word el1, el2;
	el1.word = "dd1";
	el2.word = "dd2";
	el1.next = &el2;
	el2.next = NULL;

	dict = &el1;
	while(readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		/*dict = addEnd(dict, buffer);*/
	}

	dict = addEnd(dict, "ddd4");

	fclose(fd);

	print(dict);

	//destroy(dict);

}