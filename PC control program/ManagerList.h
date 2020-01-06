#pragma once
#include "ManagerNode.h"
class ManagerList {
	ManagerNode org; //�����
public:
	ManagerList() : org("", 0, "") {  } //������
	~ManagerList() { clear(); } //�Ҹ���
	void clear() { while (!isEmpty()) delete remove(0); } //���� �Լ�
	bool isEmpty() { return getHead() == NULL; }//����Ʈ�� ����ִ��� ��ȯ
	ManagerNode* getHead() { return org.getLink(); }//����� ��ȯ

	//pos��° �׸��� ��ȯ��
	ManagerNode* getEntry(int pos) {
		ManagerNode* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	//����Ʈ�� � ��ġ�� �׸� ����
	void insert(ManagerNode* n) {
		int pos = size();
		ManagerNode* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	//����Ʈ�� � ��ġ�� �׸� ����
	ManagerNode* remove(const char* key) {
		int pos = find(key);
		if (pos == -1) {
			cout << "�ش��ϴ� �̸��� �����ϴ�.\n";
			return NULL;
		}
		else {
			ManagerNode* prev = getEntry(pos - 1);
			return prev->removeNext();
		}
	}

	//Ž�� �Լ�
	int find(const char* key) {
		int cnt = 0;
		ManagerNode* p;
		for (p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(key)) return cnt;
			cnt++;
		}
		return -1;
	}

	//����Ʈ �׸� ������ ��ȯ
	int size() {
		int cnt = 0;
		for (ManagerNode* p = getHead(); p != NULL; p = p->getLink())
			cnt++;
		return cnt;
	}

	//ȭ�鿡 �̻ڰ� ���
	void display() {
		printf("[������ ����]\n");
		for (ManagerNode* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}

};
