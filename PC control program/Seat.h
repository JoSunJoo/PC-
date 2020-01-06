#pragma once
#include <cstdio>
#include<iostream>
#define ROW 5
#define COL 10
using namespace std;
class Seat {//PC �¼� ���� Ŭ����
private:
	int x = 0, y = 0;//�¼��� ��,��
	char seat[ROW][COL];//�¼� �迭
public:
	Seat() {//������
		x = 0, y = 0;
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
				seat[i][j] = '0';
	}
	~Seat() { }//�Ҹ���
	void display() {//���� �ڸ� ���� ���
		cout << "[���� �ڸ� ����]\n";
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++)
				printf("%c ", seat[i][j]);
			printf("\n");
		}
	}
	void clean() {//�¼� û�� ����
		display();
		cout << "û�� �� �ڸ��� �����ϼ���. [x��ǥ(1~10), y��ǥ(1~5)]\n";
		cin >> x >> y;
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 5)) {//û���ؾ� �ϴ� �¼��� ���
			if (seat[y - 1][x - 1] == '*') {
				seat[y - 1][x - 1] = '0';
				printf("û�� �Ϸ�\n");//û���ϱ�
			}
			else//û���ؾ� �ϴ� �¼��� �ƴ� ���
				printf("�̹� û�� �Ϸ�Ǿ��ų� ������� �ڸ��Դϴ�.\n");//�������� ���
		}
		else {//�Է� ������ �¼��� ������ ����� ���
			cout << "���� ���� �ڸ��� �Է����ּ���.\n";
			clean();
		}
	}
	void login() {//�α��� ���
		display();//�¼� ��Ȳ ���
		cout << "�α��� �� �ڸ��� �����ϼ���. [x��ǥ(1~10), y��ǥ(1~5)]\n";
		cin >> x >> y;//���ϴ� �¼� �Է� �ޱ�
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 5)) {
			if (seat[y - 1][x - 1] == '0' || seat[y - 1][x - 1] == '*') //û�� ���� ���� �ڸ��� ���� ���� ����
				seat[y - 1][x - 1] = '1';
			else {
				cout << "������� �ڸ��Դϴ�.\n";
				login();
			}
		}
		else {//�Է� ������ �¼��� ������ ����� ���
			cout << "���� ���� �ڸ��� �Է����ּ���.\n";
			login();
		}
	}
	void logout() {//�α׾ƿ�
		seat[y - 1][x - 1] = '*';
	}
	int getX() {//x�� ��ȯ
		return x;
	}
	int getY() {//y�� ��ȯ
		return y;
	}
};