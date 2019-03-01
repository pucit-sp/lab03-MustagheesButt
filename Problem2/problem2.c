#include <stdio.h>
#include <stdlib.h>

float to_float(char* str)
{
	if (atof(str) == 0.0)
	{
		printf("Invalid float!\n");
		return -1;
	}
	
	return atof(str);
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Please provide a floating point number!\n");
		return -1;
	}
	
	char* input = argv[1];
	
	printf("Converted: %f\n", to_float(input));
	
	return 0;
}
