#pragma once
#include "FoodNode.h"
class FoodList {
	FoodNode org; //�����
public:
	FoodList() : org("", 0, "") { }
	~FoodList() { clear(); } //�Ҹ���
	void clear() { while (!isEmpty()) delete remove(0); } //���� �Լ�
	bool isEmpty() { return getHead() == NULL; }//����Ʈ�� ����ִ��� ��ȯ
	FoodNode* getHead() { return org.getLink(); }//����� ��ȯ

	//pos��° �׸��� ��ȯ��
	FoodNode* getEntry(int pos) {
		FoodNode* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	//����Ʈ�� � ��ġ�� �׸� ����
	void insert(FoodNode* n) {
		int pos = size();
		FoodNode* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	//����Ʈ�� � ��ġ�� �׸� ����
	FoodNode* remove(const char* key) {
		int pos = find(key);
		if (pos == -1) {
			cout << "�ش��ϴ� �̸��� �����ϴ�.\n";
			return NULL;
		}
		else {
			FoodNode* prev = getEntry(pos - 1);
			return prev->removeNext();
		}
	}

	//Ž�� �Լ�
	int find(const char* key) {
		int cnt = 0;
		FoodNode* p;
		for (p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(key)) return cnt;
			cnt++;
		}
		return -1;
	}

	//����Ʈ �׸� ������ ��ȯ
	int size() {
		int cnt = 0;
		for (FoodNode* p = getHead(); p != NULL; p = p->getLink())
			cnt++;
		return cnt;
	}

	//ȭ�鿡 �̻ڰ� ���
	void display() {
		printf("[���� �޴�]\n");
		for (FoodNode* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};