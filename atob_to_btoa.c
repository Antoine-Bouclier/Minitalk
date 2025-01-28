void    atob(char c, char *binary)
{
    int i;
    int j;

    i = 128;
    j = 0;
    while (j < 8)
    {
        if (c & i)
			binary[j] = '1';
		else
			binary[j] = '0';
        j++;
        i /= 2;
    }
    binary[8] = '\0';
}

char    btoa(char *binary)
{
    char result = 0;
    int i = 0;

    while (i < 8)
    {
        result <<= 1;
        if (binary[i] == '1')
            result |= 1;
        i++;
    }

    return (result);
}

int	main(void)
{
	char	c;
	char	binary[9];

	c = 'A';
	atob(c, binary);
	printf("Le caractere %c en binaire = %s\n", c, binary);
    printf("Le binaire %s en char = %c\n", binary, btoa(binary));
	c = 'B';
	atob(c, binary);
	printf("Le caractere %c en binaire = %s\n", c, binary);
    printf("Le binaire %s en char = %c\n", binary, btoa(binary));
}