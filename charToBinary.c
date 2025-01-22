#include <stdio.h>

void charToBinary(char c, char *binary)
{
    binary[0] = (c & 128) ? '1' : '0';
    binary[1] = (c & 64) ? '1' : '0';
    binary[2] = (c & 32) ? '1' : '0';
    binary[3] = (c & 16) ? '1' : '0';
    binary[4] = (c & 8) ? '1' : '0';
    binary[5] = (c & 4) ? '1' : '0';
    binary[6] = (c & 2) ? '1' : '0';
    binary[7] = (c & 1) ? '1' : '0';
    binary[8] = '\0';
}


int main()
{
	char binary[9];
	int i = 1;
	
	while (i <= 255)
	{
		charToBinary(i, binary);
		printf("%s\n", binary);
		i *= 2;
	}
}