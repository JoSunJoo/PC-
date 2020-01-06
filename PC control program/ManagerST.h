#pragma once
#include <cstdio>	/* C ������� <stdio.h>�� �����ϴ� �Ͱ� ����*/
#include <cstring>	/* C ������� <string.h>�� �����ϴ� �Ͱ� ����*/
#include <iostream>
#define MAX_NAME 10
#define MAX_RANKING_NAME 20
class ManagerST {
protected:
	char name[MAX_NAME];//������ �̸�
	int age;//����
	char ranking[MAX_RANKING_NAME];//��å
public:
	ManagerST(const char* n = "", int a = 0, const char* r = "") { set(n, r); age = a; }//������
	void set(const char* n, const char* r) {//�ʱ�ȭ �Լ�
		strcpy_s(name, n);
		strcpy_s(ranking, r);
	}
	void set(const char* n, const char* r, int a) {//�ʱ�ȭ �Լ�
		strcpy_s(name, n);
		strcpy_s(ranking, r);
		age = a;
	}
};