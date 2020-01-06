#pragma once
#include"MemberST.h"
using namespace std;
class Member //회원의 정보를 관리하는 클래스
{
private:
	int n = 0, index = 0;
	bool login_check = false;
	MemberST person[1000];

public:
	void join() { //회원가입
		printf("[회원가입]\n");
		printf("이름: ");
		person[n].setName();//이름 설정
		printf("나이: ");
		person[n].setAge();//나이 설정
		printf("전화번호: ");
		person[n].setPnumber();//전화번호 설정
		printf("id: ");
		person[n].setid();//id 설정
		printf("password: ");
		person[n].setPassword();//비밀번호 설정
		person[n].setRestTime(0);//초기 잔여시간 0으로 설정
		n++;
		printf("회원가입 완료!\n");
	}

	bool login() {//로그인
		int i;
		char tmp_id[20] = "";
		char tmp_pw[20] = "";
		printf("[로그인]\n");
		printf("id: ");
		cin >> tmp_id;
		printf("pasword: ");
		// get password from console
		string pwd = "";
		pwd = MemberST::getPwd();
		strcpy_s(tmp_pw, pwd.c_str());
		for (i = 0; i < n; i++)
		{//아이디와 비밀번호가 일치하면 로그인 성공
			if (strcmp(tmp_id, person[i].getid()) == 0 && strcmp(tmp_pw, person[i].getPassword()) == 0) {
				printf("로그인 완료\n");//로그인 성공
				index = i;
				return true;
			}
		}//로그인 실패
		printf("아이디 또는 비밀번호가 틀렸습니다.\n");
		return false;
	}

	void logout() {//로그아웃
		printf("로그아웃 되었습니다.\n");
	}

	void addTime() {//시간 추가
		int amount;
		printf("추가할 시간을 입력해주세요. [단위(시간)]");
		scanf_s("%d", &amount);
		person[index].addTime(amount);
	}

	void display() {//모든 회원의 정보 출력
		printf("[회원들의 정보]\n");
		for (int j = 0; j < n; j++)
			person[j].display();
	}

	int getRestTime() {//남은시간 반환
		return person[index].getRestTime();
	}

	const char* getName() {//회원의 이름 반환
		return person[index].getName();
	}
};