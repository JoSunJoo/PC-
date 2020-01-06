#pragma once
#include <cstdio>	/* C ������� <stdio.h>�� �����ϴ� �Ͱ� ����*/
#include <cstring>	/* C ������� <string.h>�� �����ϴ� �Ͱ� ����*/
#include <iostream>
#define MAX_MENU_NAME 10
class OrderST {
private:
	int x, y; // ������ ��޵� ���
	char menu[MAX_MENU_NAME]; //�ֹ��� �����̸�
public:
	OrderST(int ax = 0, int ay = 0, const char* m = "") { set(ax, ay, m); }//������
	void set(int ax, int ay, const char* m) {//�ʱ�ȭ �Լ�
		x = ax; y = ay; strcpy_s(menu, m);
	}
	void display() {//�ֹ� ���� ��� �Լ�
		printf("�ֹ��ڸ��� ��ǥ(%d, %d), �ֹ����� : %s\n", x, y, menu);
	}
};