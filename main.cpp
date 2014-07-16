/************************************
*	Aero's Language - By Jakes625
*	=============================
*	* aero thought of this by accident
*
*	* It's a language that moves each
*	  char to the left on your keyboard
*
*	* 'x' goes to 'z', 'h' goes to 'g' etc.
*
*	* Supports caps, numers, and special chars
*
*	* copywright (C) 2013 Jakes625
*
*************************************/

#include <iostream>

#define caps 'a'
#define tab 'q'
#define squig '1'
#define none 'z'

int main(int argc, char** args)
{
	printf("Aero's Language xD\nMade By Jakes625.\n\n");
	char* input = new char[200];
	char letters[40] = "/.,mnbvcxzlkjhgfdsapoiuytrewq0987654321";
	fgets(input, 200, stdin);
	int len = strlen(input);
	char *output = new char[len];
	memset(output, 0, len);
	bool capslock = false;
	while(*input)
	{
		char* pos = strchr(letters, tolower(*input));
		if(pos != NULL)
		{
			if(*pos == caps)
			{
				capslock = !capslock;
				input++;
				continue;
			}
			if(*pos == none)
				input++;
			else if(*pos == tab)
				*output = '\t';
			else if(*pos == squig)
				*output = '~';
			else
				*output = (capslock) ? (isupper(*input) < 1) ? toupper(*++pos) : tolower(*++pos) : (isupper(*input) < 1) ? tolower(*++pos) : toupper(*++pos);
		}
		else
			*output = *input;
		input++;
		printf("%c", *output);
	}
	printf("\nPress [enter] key to exit.");
	getchar();
	return 0;
}
