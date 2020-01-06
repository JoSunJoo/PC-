#pragma once
#include<cstdio>
#include<conio.h>
#include<cstring>
#include<iostream>
using namespace std;
//회원의 정보에 관한 클래스
class MemberST {
protected:
	char name[10];//이름
	int age;//나이
	char pnumber[20];//휴대폰번호 
	int restTime;// 남은 시간
	char id[20];//아이디
	char password[20];//비밀번호
public:
	MemberST(const char* n = "", int a = 0, const char* pn = "", int r = 0, const char* i = "", const char* pw = "") { set(n, a, pn, r, i, pw); }//생성자
	void set(const char* n, int a, const char* pn, int r, const char* i, const char* pw) {//초기화 함수
		strcpy_s(name, n);
		age = a;
		strcpy_s(pnumber, pn);
		restTime = r;
		strcpy_s(id, i);
		strcpy_s(password, pw);
	}
	const char* getName()//이름 반환
	{
		return name;
	}
	void setName()//이름 설정
	{
		cin >> name;
	}
	int getAge()//나이 반환
	{
		return age;
	}
	void setAge()//나이 설정
	{
		cin >> age;
	}
	const char* getPnumber()//전화번호 반환
	{
		return pnumber;
	}
	void setPnumber()//전화번호 설정
	{
		cin >> pnumber;
	}
	int getRestTime()//남은 사용 시간 반환
	{
		return restTime;
	}
	void setRestTime(int r)//남은 사용 시간 설정
	{
		restTime = r;
	}
	const char* getid()//아이디 반환
	{
		return id;
	}
	void setid()//아이디 설정
	{
		cin >> id;
	}
	const char* getPassword()//비밀번호 반환
	{
		return password;
	}
	void setPassword()//비밀번호 설정
	{
		string pwd = "";
		pwd = getPwd();
		strcpy_s(password, pwd.c_str());
	}
	void addTime(int hour) {//시간 추가 기능
		restTime += hour;
	}
	void display() {//회원의 정보 출력
		printf("이름:%s  나이:%d  휴대폰 번호:%s  남은시간:%d  id:%s  password:%s\n", name, age, pnumber, restTime, id, password);
	}
	static string getPwd(void) {//비밀번호 설정
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
			if (c < 33 || c > 126) continue;//알파벳과 숫자만 입력할 수 있도록 처리함
			pwd += c;
			cout << "*";//비밀번호 입력 시 *표시로 출력되도록 구현(보안)
		}
		cout << endl;
		return pwd;
	}
};