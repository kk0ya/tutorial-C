//����ó ���� ���α׷�

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define MAX_NUM 100

#include <stdio.h>
#include <string.h>

// ����ó ����ü ����
struct address {
	char name[30];
	char age[5];
	char phone[15];
};

void input_data(struct address* add_list, int* count); //�����͸� ����ü�� �Է�
void print_menu();
void view_juso();
void add_juso();
void find_juso(struct address* add_list, int* count);
void delete_juso();

// ����ó ���ϸ��� ���������� ����
const char* fname = "c:\\temp\\juso.txt";

int main()
{
	struct address add_list[MAX_NUM]; //�ִ� ���尡���� ����ó ��
	int count=0; //���� ������ ������ ��

	input_data(add_list, &count);

	char select = 0;
	puts(" \n### ģ�� ���� Ver 2.0 ### \n");

	while (select != 5)
	{
		print_menu();
		select = getch();
		printf("\n");

		switch (select)
		{
		case '1': view_juso();
			break;
		case '2': add_juso();
			break;
		case '3': find_juso(add_list,&count);
			break;
		case '4': delete_juso();
			break;
		case '5': return 0;
			break;
		default: printf("\n �߸� �Է��߾��. �ٽ� �����ϼ���.\n");
		}
	}

	return 0;
}

//�����͸� ����ü�� ����
void input_data(struct address* add_list, int* count) {
	int i;
	FILE* rfp;
	rfp = fopen(fname, "r");

	if (rfp == NULL)
	{
		printf("������ �����ϴ�!");
	}

	for (i = 0; ; i++) {
		fscanf(rfp, "%s %s %s", &add_list[i].name, &add_list[i].age, &add_list[i].phone);
		
		if (feof(rfp))
			break;

		*count = *count + 1;
	}
	fclose(rfp);
	return 0;
}

// ó���� ������� ������ ���� �޴� ���
void print_menu()
{
	printf("\n");
	printf("1. ����ó ��� \n");
	printf("2. ����ó ��� \n");
	printf("3. ����ó �˻� \n");
	printf("4. ����ó ���� \n");
	printf("5. ������ \n");
}

// ����ó ���Ͽ��� ���� �Էµ� ������ �о ���
void view_juso()
{
	char str[200] = "";
	FILE* rfp, * wfp;
	int i;

	rfp = fopen(fname, "r");

	// ����, ����ó ������ ���ٸ� �������� ����
	if (rfp == NULL)
	{
		wfp = fopen(fname, "w");
		fclose(wfp);
		rfp = fopen(fname, "r");
	}

	// ������ ����ó�� ��� �о ���
	for (i = 1; ; i++)  // i�� ��� 1�� �����ϴ� ���ѷ���
	{
		fgets(str, 200, rfp);

		if (feof(rfp))
			break;

		printf("%2d:  %s", i, str);
	}

	// i�� 1�̸� ���� ���Ͽ��� ������ ����
	if (i == 1)
		puts("\n ** ����ó ���Ͽ� ��ȭ��ȣ�� �ϳ��� �����. **\n");

	fclose(rfp);
}

// ����ó�� �߰�
void add_juso()
{
	struct address adr = { "", "", "" };
	char wstr[200] = "";
	FILE* wfp;

	wfp = fopen(fname, "a"); // ���� �߰� ���� ����

	printf("�̸��� �Է� ==> ");
	scanf(" %s",&adr.name);
	printf("���̸� �Է� ==> ");
	scanf(" %s", &adr.age);
	printf("��ȭ��ȣ�� �Է� ==> ");
	scanf(" %s", &adr.phone);

	//�Էµ� 3���� ���� �ϳ��� ���ڿ��� ����
	strcat(wstr, adr.name);
	strcat(wstr, "\t");
	strcat(wstr, adr.age);
	strcat(wstr, "\t");
	strcat(wstr, adr.phone);
	strcat(wstr, "\n");

	fputs(wstr, wfp);  // ���Ͽ� ���ڿ� ����

	fclose(wfp);
}

//����ó ���Ͽ��� �˻�
void find_juso(struct address* add_list, int* count) {
	char name[30];
	int i,compare;
	printf("�˻��� ��� �̸��� �Է��ϼ��� : ");
	scanf("%s", &name);
	for (i = 0; i < *count; i++) {
		compare = strcmp(name, add_list[i].name);

		if (compare == 0) {
			printf("\n%d %s %s %s\n", i + 1, add_list[i].name, add_list[i].age, add_list[i].phone);
			break;
		}


		if (i == *count-1) {
			printf("\n%s�� ã���� �����ϴ�\n", name);
			break;
		}

	}
}

// ����ó ���Ͽ��� ������ ����ó�� ����
void delete_juso()
{
	// ����ó ������ ���� ��ü�� �����ϱ� ���� 2���� �迭
	char read_str[50][200] = { "", }; // �ִ� ����ó ������ 50���� ����

	char str[200] = "";
	FILE* rfp, * wfp;
	int del_line, i, count = 0;

	rfp = fopen(fname, "r");

	// ����ó ������ ������ ���ư���.
	if (rfp == NULL)
	{
		puts("\n!! ����ó ������ �����ϴ�. !!\n");
		return;
	}

	printf("\n������ �� ��ȣ�� ? ");
	scanf("%d", &del_line);

	for (i = 0; i < 50; i++)  // ���Ͽ� �ִ� ���ȿ� ����, �� �ִ� 50��
	{
		strcpy(str, "");
		fgets(str, 200, rfp);

		if (i + 1 != del_line)  // �����ϴ� ���� �ƴ϶��, �߰�
		{
			strcpy(read_str[i], str);
			count++;
		}
		else
			printf("%d ���� �����Ǿ����ϴ�. \n", del_line);

		if (feof(rfp))
			break;
	}

	fclose(rfp);

	// ������ ���� ���� ����, ���ο� ������ ����.
	wfp = fopen(fname, "w");

	for (i = 0; i < count; i++)
		fputs(read_str[i], wfp);

	fclose(wfp);
}