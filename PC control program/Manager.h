#pragma once
#include"ManagerList.h"
using namespace std;
class Manager :public ManagerList {
public:
	void employment() { // 새로운 근무자 삽입
		char name[MAX_NAME];
		int age;
		char ranking[MAX_RANKING_NAME];
		cout << "이름: ";
		cin >> name;
		cout << "나이: ";
		cin >> age;
		cout << "랭킹: ";
		cin >> ranking;
		insert(new ManagerNode(name, age, ranking));
	}
	void fire() { // 근무자 해고
		char name[MAX_NAME];
		cout << "해고할 직원의 이름을 입력하세요.";
		cin >> name;
		remove(name);
	}
};