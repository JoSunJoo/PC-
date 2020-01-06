#pragma once
#include "FoodST.h"
class FoodNode : public FoodST {
	FoodNode* link; //다음 노드를 가리키는 포인터 변수
public:
	FoodNode(const char* c, int p, const char* s) : FoodST(c, p, s), link(NULL) {} //생성자
	FoodNode* getLink() { return link; } //link의 값 반환
	void setLink(FoodNode* next) { link = next; } //link의 값 설정
	void setData(const char* c, int p, const char* s) { //데이터 값 설정
		set(c, p, s);
	}
	//데이터를 가지고 있는지 검사
	int hasData(const char* key) {
		if (strcmp(foodName, key) == 0) return true;
		return false;
	}

	//자신의 다음에 새로운 노드 n을 삽입하는 함수
	void insertNext(FoodNode* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	//자신의 다음 노드를 리스트에서 삭제하는 함수
	FoodNode* removeNext() {
		FoodNode* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}

	void display() { printf("카테고리:%s  이름:%s  가격:%d\n", category, foodName, price); }
};
