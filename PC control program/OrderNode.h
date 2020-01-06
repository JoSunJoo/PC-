#pragma once
#include "OrderST.h"
class OrderNode : public OrderST {
	OrderNode* link;
public:
	OrderNode(int ax = 0, int ay = 0, const char* m = "") : OrderST(ax, ay, m) { link = NULL; } //������
	~OrderNode(void) { } //�Ҹ���
	OrderNode* getLink() { return link; } //����� ��ũ �� ��ȯ
	void setLink(OrderNode* p) { link = p; } //��ũ ����
};