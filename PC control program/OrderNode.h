#pragma once
#include "OrderST.h"
class OrderNode : public OrderST {
	OrderNode* link;
public:
	OrderNode(int ax = 0, int ay = 0, const char* m = "") : OrderST(ax, ay, m) { link = NULL; } //생성자
	~OrderNode(void) { } //소멸자
	OrderNode* getLink() { return link; } //연결된 링크 값 반환
	void setLink(OrderNode* p) { link = p; } //링크 연결
};