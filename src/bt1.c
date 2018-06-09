#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
	char a[255];
	Input(a);
	WriteFile(a, "BRACKET.INP");

	int check = Check_Day_Ngoac(a);
	if (check == 1)
	{
		printf("\nChuoi la day ngoac Dung");
		WriteFile("0", "BRACKET.OUT");
	}
	else {
		printf("\nChuoi da nhap la day ngoac Sai");
		Dem();
	}
	_getch();
	return 0;
}

int ReadFile(char*a) {
	FILE *file = file = fopen(a, "r");;
	char text[255];
	fgets(text, 255, file);
	puts(text);
	fclose(file);
}

int Input(char*a) {
	int k;
	printf("Nhap chuoi co dau ngoac can kiem tra:");
	do {

		gets(a);
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] == '(' || a[i] == ')') {
				k = 1;
				continue;
			}
			else {
				k = 0;
				break;
			}
		}
		if (k == 0)
			printf("Moi nhap lai:");
	} while (k != 1);
	printf("Chuoi:%s", a);
}

int WriteFile(char*a, char *b)
{
	FILE *file = fopen(b, "w");
	fprintf(file, a);
	fclose(file);
}

int Check_Day_Ngoac(char*a) {
	char n;
abc:
	n = a[0];
	if (n == ')')
		return 0;
	else if (n == '(')
		for (int i = 1; i < strlen(a); i++)
		{
			if (a[i] == ')') {
				Xoa_Vi_Tri(a, 0); Xoa_Vi_Tri(a, i - 1);
				goto abc;
			}
			else
				continue;
		}
	int check = 0;
	if (a[0] == NULL) {
		check = 1;
		return 1;
	}
	else
		return 0;
}

int Dem() {
	FILE *file = file = fopen("BRACKET.INP", "r");;
	char chuoi[255];
	fgets(chuoi, 255, file);
	int mongoac = 0, dongngoac = 0, daucanthem = 0;

	for (int i = 0; i < strlen(chuoi); i++)
	{
		if (chuoi[i] == '(')
			mongoac++;
		else if (chuoi[i] == ')')
			dongngoac++;
	}
	FILE *file1 = fopen("BRACKET.OUT", "w");
	int flag = 0;
	if (mongoac == dongngoac) {


		if (chuoi[0] == ')') {
			daucanthem = 2;
			fprintf(file1, "%d", daucanthem);
			fprintf(file1, "\n( %d", 0);
			fprintf(file1, "\n) %d", strlen(chuoi) - 1);
		}
	}
	if (mongoac > dongngoac) {


		daucanthem = mongoac - dongngoac;
		if (chuoi[0] == ')') {
			daucanthem++;
			flag = 1;
		}
		fprintf(file1, "%d", daucanthem);
		if (flag == 1) {
			fprintf(file1, "\n( %d", 0);
		}
		for (int i = strlen(chuoi); i <strlen(chuoi) + daucanthem; i++)
		{

			fprintf(file1, "\n) %d", i);

		}
	}

	else if (mongoac < dongngoac) {
		daucanthem = dongngoac - mongoac;
		if (chuoi[strlen(chuoi) - 1] == '(') {
			daucanthem++;
			flag = 1;
		}
		fprintf(file1, "%d", daucanthem);


		for (int i = 0; i>-daucanthem; i--)
		{
			fprintf(file1, "\n( %d", i);
		}
		if (flag == 1) {
			fprintf(file1, "\n) %d", strlen(chuoi));
		}
	}

	fclose(file1);
	fclose(file);
}

int Xoa_Vi_Tri(char*a, int vitri)
{
	for (int i = vitri; i < strlen(a); i++)
		a[i] = a[i + 1];
}




