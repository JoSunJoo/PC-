#pragma once
#include"ManagerList.h"
using namespace std;
class Manager :public ManagerList {
public:
	void employment() { // ���ο� �ٹ��� ����
		char name[MAX_NAME];
		int age;
		char ranking[MAX_RANKING_NAME];
		cout << "�̸�: ";
		cin >> name;
		cout << "����: ";
		cin >> age;
		cout << "��ŷ: ";
		cin >> ranking;
		insert(new ManagerNode(name, age, ranking));
	}
	void fire() { // �ٹ��� �ذ�
		char name[MAX_NAME];
		cout << "�ذ��� ������ �̸��� �Է��ϼ���.";
		cin >> name;
		remove(name);
	}
};