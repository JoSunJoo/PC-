#pragma once
#include "OrderQueue.h"
using namespace std;
class Order : public OrderQueue {
public:
	void pay() { // 음식 결제(배달)
		if (!isEmpty()) {
			dequeue();
			cout << "배달 완료\n";
		}
		else
			cout << "배달될 음식이 없습니다.\n";
	}
	void order(int ax, int ay) { // 음식 주문
		char menu[MAX_MENU_NAME];
		cout << "음식 이름 : ";
		cin >> menu;
		enqueue(new OrderNode(ax, ay, menu));
		cout << "주문 완료\n";
	}
};