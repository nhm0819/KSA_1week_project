#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"


void print_info(Student);
void search(Student *student, char input[20], int option);


int main(void)
{
	int ch;
	FILE* fp;

	Student students[25];

	fopen_s(&fp, "D:\\1week\\students.txt", "r");

	if (fp == NULL) {
		printf("������ ������ �ʾҽ��ϴ�.");
		return 1;
	}
	printf("������ �˻� ���α׷�\n\n");

	for (int count = 0; count < 25; count++) {
		fscanf_s(fp, "%s", &students[count].company, 80);
		fscanf_s(fp, "%s", &students[count].name, 10);
		fscanf_s(fp, "%s", &students[count].sex, 10);
		fscanf_s(fp, "%s", &students[count].phone, 20);
		fscanf_s(fp, "%s", &students[count].mail, 30);
		fscanf_s(fp, "%d", &students[count].birth);
		fscanf_s(fp, "%s", &students[count].major, 80);
	}

	char input[20];
	int option = 0;
	int loop = 1;

	while (loop) {
		while (option == 0) {
			printf("----------------------------------------------\n");
			printf("�˻� ������ ������.\n");
			printf("1. ���\n2. �̸�\n3. ����\n4. ����\n:");

			gets_s(input);

			if ((strcmp(input, "���") == 0) || (strcmp(input, "1") == 0)) {
				option = 1;
				printf("��� ����Ʈ : [\"11��11��\", \"5Works\", \"�ް���Ŭ����\", \"���ڿ��ý�\", \"�ó�ƽ��\", \"����\"]\n����� :");
			}

			else if ((strcmp(input, "�̸�") == 0) || (strcmp(input, "2") == 0)) {
				option = 2;
				printf("�̸� :");
			}

			else if ((strcmp(input, "����") == 0) || (strcmp(input, "3") == 0)) {
				option = 3;
				printf("���� (\"����\", \"����\") :");
			}
			else if ((strcmp(input, "����") == 0) || (strcmp(input, "4") == 0)) {
				printf("�����մϴ�.");
				loop = 0;
				break;
			}
			else {
				printf("���� ������ ������ϴ�.");
			}

		}

		gets_s(input);

		for (int i = 0; i < 25; i++) {
			search(&students[i], input, option);
		}
		option = 0;
	}
	
	fclose(fp);

	return 0;
}


//Student* ps = (Student *)malloc((25 * sizeof(Student));
//free(ps);


void print_info(Student *student)
{

	printf("----------------------------------------------\n");
	printf("%s\n", student->name);
	printf("%s\n", student->company);
	printf("%s\n", student->sex);
	printf("%s\n", student->phone);
	printf("%s\n", student->mail);
	printf("%d\n", student->birth);
	printf("%s\n", student->major);
	
}

void search(Student *student, char input[20], int option) {

	if (option == 1) {
		if (strcmp(input, student->company) == 0)
		{
			print_info(student);
		}
	}
	else if (option == 2) {
		if (strcmp(input, student->name) == 0)
		{
			print_info(student);
		}
	}
	else if (option == 3) {
		if (strcmp(input, student->sex) == 0)
		{
			print_info(student);
		}
	}

	else {
		printf("������� �����ϴ�.");
	}
}