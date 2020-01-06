#pragma once
#include "FoodNode.h"
class FoodList {
	FoodNode org; //헤드노드
public:
	FoodList() : org("", 0, "") { }
	~FoodList() { clear(); } //소멸자
	void clear() { while (!isEmpty()) delete remove(0); } //제거 함수
	bool isEmpty() { return getHead() == NULL; }//리스트가 비어있는지 반환
	FoodNode* getHead() { return org.getLink(); }//헤드노드 반환

	//pos번째 항목을 반환함
	FoodNode* getEntry(int pos) {
		FoodNode* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	//리스트의 어떤 위치에 항목 삽입
	void insert(FoodNode* n) {
		int pos = size();
		FoodNode* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	//리스트의 어떤 위치의 항목 삭제
	FoodNode* remove(const char* key) {
		int pos = find(key);
		if (pos == -1) {
			cout << "해당하는 이름이 없습니다.\n";
			return NULL;
		}
		else {
			FoodNode* prev = getEntry(pos - 1);
			return prev->removeNext();
		}
	}

	//탐색 함수
	int find(const char* key) {
		int cnt = 0;
		FoodNode* p;
		for (p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(key)) return cnt;
			cnt++;
		}
		return -1;
	}

	//리스트 항목 개수를 반환
	int size() {
		int cnt = 0;
		for (FoodNode* p = getHead(); p != NULL; p = p->getLink())
			cnt++;
		return cnt;
	}

	//화면에 이쁘게 출력
	void display() {
		printf("[음식 메뉴]\n");
		for (FoodNode* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};