#pragma once
#include "FoodList.h"
using namespace std;
class Food : public FoodList {
public:
	void deleteMenu() { //음식 메뉴 제거
		char name[MAX_FOOD_NAME];
		cout << "제거할 음식의 이름: ";
		cin >> name;
		remove(name);
	}
	void insertMenu() { //음식 메뉴 추가
		char c[MAX_CATEGORY_NAME];
		int p;
		char f[MAX_FOOD_NAME];
		cout << "추가할 음식의 카테고리: ";
		cin >> c;
		cout << "추가할 음식의 가격: ";
		cin >> p;
		cout << "추가할 음식의 이름: ";
		cin >> f;
		insert(new FoodNode(c, p, f));
	}
};