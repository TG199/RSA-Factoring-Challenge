#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_even(int n)
{
	return n % 2 == 0;
}


void factorize(int n)
{
	int i, j;


	/*for (i = 2; i <= n / 2; i++)
	{
		if (is_even(i) && is_even(n))
			continue;

		if (n % i == 0)
		{
			j = n / 2;
			printf("%d=%d*%d\n", n, j, n);
		}
	}*/

	i = 1;
	j = 1;

	if  ( n % 2 == 0)
	{
		j = n / 2;

		printf("%d=%d*2\n", n, j);
		j++;
	}
	else if (n % 3 == 0)
	{
		j = n / 3;
		printf("%d=%d*3\n", n, j);
		j++;
	}

}		

int main(int argc, char *argv[])
{
	FILE *file;
	int n;
	char line[BUFSIZ];

	if (argc != 2)
	{
		fprintf(stderr,"Usage: factors <file>\n");
		return (-1);
	}
	file = fopen(argv[1], "r");
	
	if (file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
		return (-1);
	}

	while (fgets(line, sizeof(line), file))
	{
		n = atoi(line);
		factorize(n);
	}
	
	fclose(file);
	return (0);
}

