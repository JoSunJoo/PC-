#pragma once
#include "ManagerST.h"

class ManagerNode : public ManagerST {
	ManagerNode* link; //다음 노드를 가리키는 포인터 변수
public:
	ManagerNode(const char* s, int a, const char* r) : ManagerST(s, a, r), link(NULL) {} //생성자
	ManagerNode* getLink() { return link; } //link의 값 반환
	void setLink(ManagerNode* next) { link = next; } //link의 값 설정
	void setData(const char* s, int a, const char* r) { //데이터 값 설정
		set(s, r, a);
	}
	//데이터를 가지고 있는지 검사
	int hasData(const char* key) {
		if (strcmp(name, key) == 0) return true;
		return false;
	}

	//자신의 다음에 새로운 노드 n을 삽입하는 함수
	void insertNext(ManagerNode* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	//자신의 다음 노드를 리스트에서 삭제하는 함수
	ManagerNode* removeNext() {
		ManagerNode* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}

	void display() { printf("이름:%s  나이:%d  직급:%s\n", name, age, ranking); }
};