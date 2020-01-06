#pragma once
#include <cstdio>
#include<iostream>
#define ROW 5
#define COL 10
using namespace std;
class Seat {//PC 좌석 관리 클래스
private:
	int x = 0, y = 0;//좌석의 행,열
	char seat[ROW][COL];//좌석 배열
public:
	Seat() {//생성자
		x = 0, y = 0;
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
				seat[i][j] = '0';
	}
	~Seat() { }//소멸자
	void display() {//현재 자리 정보 출력
		cout << "[현재 자리 정보]\n";
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++)
				printf("%c ", seat[i][j]);
			printf("\n");
		}
	}
	void clean() {//좌석 청소 관리
		display();
		cout << "청소 할 자리를 선택하세요. [x좌표(1~10), y좌표(1~5)]\n";
		cin >> x >> y;
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 5)) {//청소해야 하는 좌석일 경우
			if (seat[y - 1][x - 1] == '*') {
				seat[y - 1][x - 1] = '0';
				printf("청소 완료\n");//청소하기
			}
			else//청소해야 하는 좌석이 아닐 경우
				printf("이미 청소 완료되었거나 사용중인 자리입니다.\n");//오류문구 출력
		}
		else {//입력 범위가 좌석의 범위를 벗어나는 경우
			cout << "범위 내의 자리를 입력해주세요.\n";
			clean();
		}
	}
	void login() {//로그인 기능
		display();//좌석 현황 출력
		cout << "로그인 할 자리를 선택하세요. [x좌표(1~10), y좌표(1~5)]\n";
		cin >> x >> y;//원하는 좌석 입력 받기
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 5)) {
			if (seat[y - 1][x - 1] == '0' || seat[y - 1][x - 1] == '*') //청소 되지 않은 자리도 앉을 수는 있음
				seat[y - 1][x - 1] = '1';
			else {
				cout << "사용중인 자리입니다.\n";
				login();
			}
		}
		else {//입력 범위가 좌석의 범위를 벗어나는 경우
			cout << "범위 내의 자리를 입력해주세요.\n";
			login();
		}
	}
	void logout() {//로그아웃
		seat[y - 1][x - 1] = '*';
	}
	int getX() {//x값 반환
		return x;
	}
	int getY() {//y값 반환
		return y;
	}
};