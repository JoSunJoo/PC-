#pragma once
#include <cstdio>	/* C ������� <stdio.h>�� �����ϴ� �Ͱ� ����*/
#include <cstring>	/* C ������� <string.h>�� �����ϴ� �Ͱ� ����*/
#include <iostream>
#define MAX_CATEGORY_NAME 10
#define MAX_FOOD_NAME 10
class FoodST {
protected:
	char category[MAX_CATEGORY_NAME];//���� ����
	int price;//����
	char foodName[MAX_FOOD_NAME];//���� �̸�
public:
	FoodST(const char* c = "", int p = 0, const char* f = "") { set(c, p, f); }//������
	void set(const char* c = "", int p = 0, const char* f = "") {//�ʱ�ȭ �Լ�
		strcpy_s(category, c);
		price = p;
		strcpy_s(foodName, f);
	}
};