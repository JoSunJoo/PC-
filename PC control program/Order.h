#pragma once
#include "OrderQueue.h"
using namespace std;
class Order : public OrderQueue {
public:
	void pay() { // ���� ����(���)
		if (!isEmpty()) {
			dequeue();
			cout << "��� �Ϸ�\n";
		}
		else
			cout << "��޵� ������ �����ϴ�.\n";
	}
	void order(int ax, int ay) { // ���� �ֹ�
		char menu[MAX_MENU_NAME];
		cout << "���� �̸� : ";
		cin >> menu;
		enqueue(new OrderNode(ax, ay, menu));
		cout << "�ֹ� �Ϸ�\n";
	}
};