#pragma once
#include "FoodST.h"
class FoodNode : public FoodST {
	FoodNode* link; //���� ��带 ����Ű�� ������ ����
public:
	FoodNode(const char* c, int p, const char* s) : FoodST(c, p, s), link(NULL) {} //������
	FoodNode* getLink() { return link; } //link�� �� ��ȯ
	void setLink(FoodNode* next) { link = next; } //link�� �� ����
	void setData(const char* c, int p, const char* s) { //������ �� ����
		set(c, p, s);
	}
	//�����͸� ������ �ִ��� �˻�
	int hasData(const char* key) {
		if (strcmp(foodName, key) == 0) return true;
		return false;
	}

	//�ڽ��� ������ ���ο� ��� n�� �����ϴ� �Լ�
	void insertNext(FoodNode* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	//�ڽ��� ���� ��带 ����Ʈ���� �����ϴ� �Լ�
	FoodNode* removeNext() {
		FoodNode* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}

	void display() { printf("ī�װ�:%s  �̸�:%s  ����:%d\n", category, foodName, price); }
};
