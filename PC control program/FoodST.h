#pragma once
#include <cstdio>	/* C 헤더파일 <stdio.h>을 포함하는 것과 동일*/
#include <cstring>	/* C 헤더파일 <string.h>을 포함하는 것과 동일*/
#include <iostream>
#define MAX_CATEGORY_NAME 10
#define MAX_FOOD_NAME 10
class FoodST {
protected:
	char category[MAX_CATEGORY_NAME];//음식 종류
	int price;//가격
	char foodName[MAX_FOOD_NAME];//음식 이름
public:
	FoodST(const char* c = "", int p = 0, const char* f = "") { set(c, p, f); }//생성자
	void set(const char* c = "", int p = 0, const char* f = "") {//초기화 함수
		strcpy_s(category, c);
		price = p;
		strcpy_s(foodName, f);
	}
};