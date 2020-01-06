#pragma once
#include "OrderNode.h"
class OrderQueue {//�ֹ� ������ �����ϴ� Queue Ŭ����
	OrderNode* front;
	OrderNode* rear;
public:
	OrderQueue() : front(NULL), rear(NULL) {}//������
	~OrderQueue() { while (!isEmpty()) delete dequeue(); }//�Ҹ���
	bool isEmpty() { return front == NULL; }//queue�� ����ִ��� �˻�

	void enqueue(OrderNode* p) {//queue�� �ֹ� ���� ����
		if (isEmpty()) front = rear = p;
		else {
			rear->setLink(p);
			rear = p;
		}
	}
	OrderNode* dequeue() {//queue���� ������ ����
		if (isEmpty()) return NULL;
		OrderNode* p = front;
		front = front->getLink();
		if (front == NULL) rear = NULL;
		return p;
	}
	OrderNode* peek() { return front; }//ù��° ������ ��ȯ
	void display() {//��� ���� �ֹ� ������ ���
		printf("[���� �ֹ��� ���� ����]\n");
		for (OrderNode* p = front; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};
