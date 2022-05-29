#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void countFile(char* filename, int* cNumber, int* wNumber);
int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		int cNumber = 0, wNumber = 0;
		countFile(argv[2], &cNumber, &wNumber);
		if (strcmp(argv[1], "-c") == 0)
		{
			printf("字符数：%d\n", cNumber);
		}

		else if (strcmp(argv[1], "-w") == 0)
		{
			printf("单词数：%d\n", wNumber);
		}
	}

	return 0;
}

void countFile(char* filename, int* cCount, int* wCount)
{
	FILE* fp;
	char buffer[1000];
	int isBlank = 1;
	int cNumber = 0, wNumber = 0;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		return;
	}

	while (fgets(buffer, 1000, fp) != NULL)
	{
		cNumber += strlen(buffer);
		for (int i = 0; i < strlen(buffer); i++)
		{
			char c = buffer[i];
			if (c == ' ' || c == '\t' || c == ',' || c == ':' || c == ';' || c == '.' || c == '"' || c == '?' || c == '!')
			{
				if (!isBlank)
				{
					wNumber++;
					isBlank = 1;
				}
			}
			else
				isBlank = 0;
		}
		if (!isBlank)
		{
			wNumber++;
			isBlank = 1;
		}
	}
	*cCount = cNumber;
	*wCount = wNumber;
	fclose(fp);
	return;
}















