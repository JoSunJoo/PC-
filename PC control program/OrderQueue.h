#pragma once
#include "OrderNode.h"
class OrderQueue {//주문 내역을 관리하는 Queue 클래스
	OrderNode* front;
	OrderNode* rear;
public:
	OrderQueue() : front(NULL), rear(NULL) {}//생성자
	~OrderQueue() { while (!isEmpty()) delete dequeue(); }//소멸자
	bool isEmpty() { return front == NULL; }//queue가 비어있는지 검사

	void enqueue(OrderNode* p) {//queue에 주문 내역 삽입
		if (isEmpty()) front = rear = p;
		else {
			rear->setLink(p);
			rear = p;
		}
	}
	OrderNode* dequeue() {//queue에서 데이터 삭제
		if (isEmpty()) return NULL;
		OrderNode* p = front;
		front = front->getLink();
		if (front == NULL) rear = NULL;
		return p;
	}
	OrderNode* peek() { return front; }//첫번째 데이터 반환
	void display() {//모든 음식 주문 내역을 출력
		printf("[현재 주문된 음식 정보]\n");
		for (OrderNode* p = front; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};
