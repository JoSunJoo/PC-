#pragma once
#include <cstdio>	/* C 헤더파일 <stdio.h>을 포함하는 것과 동일*/
#include <cstring>	/* C 헤더파일 <string.h>을 포함하는 것과 동일*/
#include <iostream>
#define MAX_NAME 10
#define MAX_RANKING_NAME 20
class ManagerST {
protected:
	char name[MAX_NAME];//관리자 이름
	int age;//나이
	char ranking[MAX_RANKING_NAME];//직책
public:
	ManagerST(const char* n = "", int a = 0, const char* r = "") { set(n, r); age = a; }//생성자
	void set(const char* n, const char* r) {//초기화 함수
		strcpy_s(name, n);
		strcpy_s(ranking, r);
	}
	void set(const char* n, const char* r, int a) {//초기화 함수
		strcpy_s(name, n);
		strcpy_s(ranking, r);
		age = a;
	}
};