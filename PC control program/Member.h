#pragma once
#include"MemberST.h"
using namespace std;
class Member //ȸ���� ������ �����ϴ� Ŭ����
{
private:
	int n = 0, index = 0;
	bool login_check = false;
	MemberST person[1000];

public:
	void join() { //ȸ������
		printf("[ȸ������]\n");
		printf("�̸�: ");
		person[n].setName();//�̸� ����
		printf("����: ");
		person[n].setAge();//���� ����
		printf("��ȭ��ȣ: ");
		person[n].setPnumber();//��ȭ��ȣ ����
		printf("id: ");
		person[n].setid();//id ����
		printf("password: ");
		person[n].setPassword();//��й�ȣ ����
		person[n].setRestTime(0);//�ʱ� �ܿ��ð� 0���� ����
		n++;
		printf("ȸ������ �Ϸ�!\n");
	}

	bool login() {//�α���
		int i;
		char tmp_id[20] = "";
		char tmp_pw[20] = "";
		printf("[�α���]\n");
		printf("id: ");
		cin >> tmp_id;
		printf("pasword: ");
		// get password from console
		string pwd = "";
		pwd = MemberST::getPwd();
		strcpy_s(tmp_pw, pwd.c_str());
		for (i = 0; i < n; i++)
		{//���̵�� ��й�ȣ�� ��ġ�ϸ� �α��� ����
			if (strcmp(tmp_id, person[i].getid()) == 0 && strcmp(tmp_pw, person[i].getPassword()) == 0) {
				printf("�α��� �Ϸ�\n");//�α��� ����
				index = i;
				return true;
			}
		}//�α��� ����
		printf("���̵� �Ǵ� ��й�ȣ�� Ʋ�Ƚ��ϴ�.\n");
		return false;
	}

	void logout() {//�α׾ƿ�
		printf("�α׾ƿ� �Ǿ����ϴ�.\n");
	}

	void addTime() {//�ð� �߰�
		int amount;
		printf("�߰��� �ð��� �Է����ּ���. [����(�ð�)]");
		scanf_s("%d", &amount);
		person[index].addTime(amount);
	}

	void display() {//��� ȸ���� ���� ���
		printf("[ȸ������ ����]\n");
		for (int j = 0; j < n; j++)
			person[j].display();
	}

	int getRestTime() {//�����ð� ��ȯ
		return person[index].getRestTime();
	}

	const char* getName() {//ȸ���� �̸� ��ȯ
		return person[index].getName();
	}
};