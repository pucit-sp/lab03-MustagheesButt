/*
**	This program is a template for SP lab 3 task 3 you are 
**	required to implement its one function.
*/


#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
*/
void mygrep(FILE*, char*);

/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
** 	and char pointer as an third argument to replace the string finded with it.
*/
void myreplace(FILE *fp,char *find, char * replace);

static const int GREP = 1;
static const int REPLACE = 2;

int  main(int argc,char *argv[])
{


	/*	creating variables */

	int behaviour;
	FILE *fp;
	char *filename=argv[1];
	char *find=argv[2];
	char * replace;

	/*	check if mygrep is called or myreplace */
	if(strcmp(argv[0], "mygrep.exe") == 0 || strcmp(argv[0], "mygrep") == 0 || strcmp(argv[0], "./mygrep") == 0)
	{
		if(argc != 3)
		{
			printf("usage\t./mygrep filename <string-to-search>\n");
			exit(1);
		}

		behaviour = GREP;
	}
	else if(strcmp(argv[0], "myreplace.exe") == 0 || strcmp(argv[0], "myreplace") == 0 || strcmp(argv[0], "./myreplace") == 0)
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>");
			exit(1);
		}
		behaviour = REPLACE;
		replace = argv[3];
	}
	else
	{
		behaviour = -1;
	}


	/* opening file */

	fp=fopen(filename,"rt");

	if(behaviour == GREP)
	{
		mygrep(fp,find);		/*	calling function */
	}
	else if ( behaviour == REPLACE )
	{
		myreplace(fp,find,replace);		/*	calling myreplace */
	}
	
	fclose(fp);		/*	closing file */
	return 0;
}


void mygrep(FILE *fp,char *find)
{
	char c1[500];

	while(fgets(c1, 500, fp) != NULL)
	{
		for (int i = 0; i < strlen(c1); i++)
		{
			if (find[0] == c1[i])
			{
				if (memcmp(find, c1 + i, strlen(find)) == 0)
				{
					printf("%s\n", c1);
					break;
				}
			}
		}
		
		memset(c1, 0, 500);
	}
}

void myreplace(FILE *fp,char *find, char * replace)
{
	char c1[500];
	int flen = strlen(find);

	while(fgets(c1, 500, fp) != NULL)
	{
		for (int i = 0; i < strlen(c1); i++)
		{
			if (find[0] == c1[i])
			{
				if (memcmp(find, c1 + i, strlen(find)) == 0)
				{
					char c2[500];

					memcpy(c2, c1, i);
					memcpy(c2 + i, replace, strlen(replace));
					memcpy(c2 + i + strlen(replace), c1 + i + flen, strlen(c1) - (i + flen));
					
					printf("%s\n", c2);
					
					memset(c2, 0, 500);
					
					break;
				}
			}
		}

		memset(c1, 0, 500);
	}
}


