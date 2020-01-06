#pragma once
#include <cstdio>	/* C 헤더파일 <stdio.h>을 포함하는 것과 동일*/
#include <cstring>	/* C 헤더파일 <string.h>을 포함하는 것과 동일*/
#include <iostream>
#define MAX_MENU_NAME 10
class OrderST {
private:
	int x, y; // 음식이 배달될 장소
	char menu[MAX_MENU_NAME]; //주문된 음식이름
public:
	OrderST(int ax = 0, int ay = 0, const char* m = "") { set(ax, ay, m); }//생성자
	void set(int ax, int ay, const char* m) {//초기화 함수
		x = ax; y = ay; strcpy_s(menu, m);
	}
	void display() {//주문 내역 출력 함수
		printf("주문자리의 좌표(%d, %d), 주문음식 : %s\n", x, y, menu);
	}
};