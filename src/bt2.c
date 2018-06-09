#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <io.h>

int main()
{
		char m[200];
	Input(m);
	Program(m);

	_getch();
	return 0;
}

int Input (char *a) {
	FILE *file;
	printf("Enter File: ");
	do { 
		gets(a);
		file = fopen(a, "r");
	
		if ( file == NULL)
			printf("Fail !!! Please Enter File: ");
		else
		{
			printf("Valid File, please choose the features !!!");
			break;
		}
	} while (file == NULL);
	fclose(file);
	
}
int Program(char *a) {
	int chon;
	do
	{
		printf("\n-----------------------------------");
		printf("\n1. Search");
		printf("\n2. Replace");
		printf("\n3. Exit");
		printf("\n-----------------------------------\n");

		scanf("%d",&chon);

		switch (chon)
		{
		case 1: {
			Search(a);
			break;
		}
						
		case 2: 
		{
			printf("Chua hoan thanh !!!");
			break;
		}
		case 3: {
			printf("Exit !!!");		
			break;
		}
			
		default:
		{
			printf("Fail Number, please choose again !!!");
			break; }
		}

	} while (chon < 1 || chon > 3);

}

int Search(char *a) {
	FILE *file = fopen(a, "r");
	char giatri[200];

	char key[100];
	printf("\n\tEnter Keyword: ");
	getchar();
	gets(key);

	int line_num = 1;
	int find_result = 0;
	char temp[100];

	while (fgets(temp, 100, file)) {
		char *vitri = temp;	

		while (vitri = (strstr(vitri, key)))
		{	
			printf("Ln: %d, Col: %d\n", line_num,(int)(vitri - temp ) +1);
			vitri++;

			find_result++;	


		}
		line_num++;
	}
	
	printf("\tTotal appeared tine: %d\n", find_result);

	if (find_result == 0) {
		printf("\nSorry, couldn't find a match.\n");
	}

	//Close the file if still open.
	if (file) {
		fclose(file);
	}
}

int Replace(char *a) {

	FILE *file = fopen(a, "r");

	printf("Enter Word(s): ");
	char key1[100];
	gets(key1);

	printf("Enter new word(s): ");
	char key2[100];
	gets(key2);

	fclose(file);
}