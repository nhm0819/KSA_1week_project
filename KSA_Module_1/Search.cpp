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
		printf("파일이 열리지 않았습니다.");
		return 1;
	}
	printf("교육생 검색 프로그램\n\n");

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
			printf("검색 조건을 고르세요.\n");
			printf("1. 기업\n2. 이름\n3. 성별\n4. 종료\n:");

			gets_s(input);

			if ((strcmp(input, "기업") == 0) || (strcmp(input, "1") == 0)) {
				option = 1;
				printf("기업 리스트 : [\"11시11분\", \"5Works\", \"메가존클라우드\", \"모코엠시스\", \"시네틱스\", \"미정\"]\n기업명 :");
			}

			else if ((strcmp(input, "이름") == 0) || (strcmp(input, "2") == 0)) {
				option = 2;
				printf("이름 :");
			}

			else if ((strcmp(input, "성별") == 0) || (strcmp(input, "3") == 0)) {
				option = 3;
				printf("성별 (\"남자\", \"여자\") :");
			}
			else if ((strcmp(input, "종료") == 0) || (strcmp(input, "4") == 0)) {
				printf("종료합니다.");
				loop = 0;
				break;
			}
			else {
				printf("조건 범위를 벗어났습니다.");
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
		printf("결과값이 없습니다.");
	}
}