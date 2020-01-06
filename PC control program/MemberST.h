#pragma once
#include<cstdio>
#include<conio.h>
#include<cstring>
#include<iostream>
using namespace std;
//ȸ���� ������ ���� Ŭ����
class MemberST {
protected:
	char name[10];//�̸�
	int age;//����
	char pnumber[20];//�޴�����ȣ 
	int restTime;// ���� �ð�
	char id[20];//���̵�
	char password[20];//��й�ȣ
public:
	MemberST(const char* n = "", int a = 0, const char* pn = "", int r = 0, const char* i = "", const char* pw = "") { set(n, a, pn, r, i, pw); }//������
	void set(const char* n, int a, const char* pn, int r, const char* i, const char* pw) {//�ʱ�ȭ �Լ�
		strcpy_s(name, n);
		age = a;
		strcpy_s(pnumber, pn);
		restTime = r;
		strcpy_s(id, i);
		strcpy_s(password, pw);
	}
	const char* getName()//�̸� ��ȯ
	{
		return name;
	}
	void setName()//�̸� ����
	{
		cin >> name;
	}
	int getAge()//���� ��ȯ
	{
		return age;
	}
	void setAge()//���� ����
	{
		cin >> age;
	}
	const char* getPnumber()//��ȭ��ȣ ��ȯ
	{
		return pnumber;
	}
	void setPnumber()//��ȭ��ȣ ����
	{
		cin >> pnumber;
	}
	int getRestTime()//���� ��� �ð� ��ȯ
	{
		return restTime;
	}
	void setRestTime(int r)//���� ��� �ð� ����
	{
		restTime = r;
	}
	const char* getid()//���̵� ��ȯ
	{
		return id;
	}
	void setid()//���̵� ����
	{
		cin >> id;
	}
	const char* getPassword()//��й�ȣ ��ȯ
	{
		return password;
	}
	void setPassword()//��й�ȣ ����
	{
		string pwd = "";
		pwd = getPwd();
		strcpy_s(password, pwd.c_str());
	}
	void addTime(int hour) {//�ð� �߰� ���
		restTime += hour;
	}
	void display() {//ȸ���� ���� ���
		printf("�̸�:%s  ����:%d  �޴��� ��ȣ:%s  �����ð�:%d  id:%s  password:%s\n", name, age, pnumber, restTime, id, password);
	}
	static string getPwd(void) {//��й�ȣ ����
		string pwd = "";
		cout.flush();
		char c = ' ';
		while (true)
		{
			c = (char)_getch();
			if (c == 13 || c == 10) break; // \r or \n
			if (c == 3 || c == 26) exit(-1);// ^C or ^Z
			if (c == 8) { //back space, works in Windows only.
				if (pwd.size() > 0) {
					cout << "\b \b";
					pwd = pwd.substr(0, pwd.size() - 1);
				}
				continue;
			}
			if (c < 33 || c > 126) continue;//���ĺ��� ���ڸ� �Է��� �� �ֵ��� ó����
			pwd += c;
			cout << "*";//��й�ȣ �Է� �� *ǥ�÷� ��µǵ��� ����(����)
		}
		cout << endl;
		return pwd;
	}
};