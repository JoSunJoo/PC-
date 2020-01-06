#pragma once
#include "ManagerST.h"

class ManagerNode : public ManagerST {
	ManagerNode* link; //���� ��带 ����Ű�� ������ ����
public:
	ManagerNode(const char* s, int a, const char* r) : ManagerST(s, a, r), link(NULL) {} //������
	ManagerNode* getLink() { return link; } //link�� �� ��ȯ
	void setLink(ManagerNode* next) { link = next; } //link�� �� ����
	void setData(const char* s, int a, const char* r) { //������ �� ����
		set(s, r, a);
	}
	//�����͸� ������ �ִ��� �˻�
	int hasData(const char* key) {
		if (strcmp(name, key) == 0) return true;
		return false;
	}

	//�ڽ��� ������ ���ο� ��� n�� �����ϴ� �Լ�
	void insertNext(ManagerNode* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	//�ڽ��� ���� ��带 ����Ʈ���� �����ϴ� �Լ�
	ManagerNode* removeNext() {
		ManagerNode* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}

	void display() { printf("�̸�:%s  ����:%d  ����:%s\n", name, age, ranking); }
};