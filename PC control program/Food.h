#pragma once
#include "FoodList.h"
using namespace std;
class Food : public FoodList {
public:
	void deleteMenu() { //���� �޴� ����
		char name[MAX_FOOD_NAME];
		cout << "������ ������ �̸�: ";
		cin >> name;
		remove(name);
	}
	void insertMenu() { //���� �޴� �߰�
		char c[MAX_CATEGORY_NAME];
		int p;
		char f[MAX_FOOD_NAME];
		cout << "�߰��� ������ ī�װ�: ";
		cin >> c;
		cout << "�߰��� ������ ����: ";
		cin >> p;
		cout << "�߰��� ������ �̸�: ";
		cin >> f;
		insert(new FoodNode(c, p, f));
	}
};