#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_even(int n)
{
	return n % 2 == 0;
}


void factorize(int n)
{
	int i;


	for (i = 2; i <= n / 2; i++)
	{
		if (is_even(i) && is_even(n))
			continue;

		if (n % i == 0)
		{
			printf("%d=%d*%d\n", n, i, n / i);
			return;
		}
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

