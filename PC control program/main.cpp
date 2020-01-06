#include "Order.h"
#include "Food.h"
#include "Member.h"
#include "Seat.h"
#include "Manager.h"
using namespace std;

void startingScreen();
void beforeLoginUserScreen();
void afterLoginUserScreen();
void managerScreen();

Food f; // ���� ��ü
Order ord; // �ֹ� ��ü
Member member; // ����� ��ü
Seat s; //�ڸ� ��ü
Manager manager; // ������ ��ü

void main() {
	// �������� pc�� �⺻ ���� ����Ʈ
	f.insert(new FoodNode("�����", 1000, "�ݶ�"));
	f.insert(new FoodNode("�Ļ��", 4500, "��������"));
	f.insert(new FoodNode("���", 3000, "���"));
	// �������� pc�� �ʱ� ������ ����Ʈ
	manager.insert(new ManagerNode("������", 21, "����"));
	manager.insert(new ManagerNode("����ȣ", 21, "2����"));
	manager.insert(new ManagerNode("�ڵ���", 21, "1����"));
	// ���α׷� ����
	startingScreen();
}

//���� ȭ�� ����
void startingScreen() {
	int enter;
	cout << "===========================PC�� �ڸ� ���� ���α׷�==========================" << endl;
	cout << "                              1. ����� ���                                " << endl;
	cout << "                              2. ������ ���                                " << endl;
	cout << "                              3. ���α׷� ����                              " << endl;
	cin >> enter;
	switch (enter) {
	case 1: //����� ��� ȭ�� ���
		beforeLoginUserScreen();
		break;
	case 2: //������ ��� ȭ�� ���
		managerScreen();
		break;
	case 3: //�ý��� ����
		exit(0);
	default:
		printf("�ùٸ� ���� �Է����ּ���.\n");
		startingScreen();
	}
}

//����� ��� ������ ���
void beforeLoginUserScreen() {
	int enter;
	cout << "                               [����� ���]                                " << endl;
	cout << "                              1. ȸ������                                   " << endl;
	cout << "                              2. �α���                                     " << endl;
	cout << "                              3. ��� ���� ȭ��                             " << endl;
	cin >> enter;
	switch (enter) {
	case 1: //ȸ������
		member.join();
		beforeLoginUserScreen();
		break;
	case 2: //�α���
		if (member.login()) { //�α��� ���� �� ȸ�� ��� ȭ�� ���
			s.login();
			afterLoginUserScreen();
		}
		else //�α��� ���� �� ����� ��� ������ ���
			beforeLoginUserScreen();
		break;
	case 3:
		startingScreen();
		break;
	default:
		printf("�ùٸ� ���� �Է����ּ���.\n");
		beforeLoginUserScreen();
		break;
	}
}

//ȸ�� ��� ȭ�� ���
void afterLoginUserScreen() {
	int enter;
	cout << "                               [����� ���]                                " << endl;
	printf("                                                [�����: %s] [���� �ð�: %d]\n", member.getName(), member.getRestTime());
	cout << "                              1. ���� �ֹ�                                  " << endl;
	cout << "                              2. �ð� �߰�                                  " << endl;
	cout << "                              3. �α׾ƿ�                                   " << endl;
	cin >> enter;
	switch (enter) {
	case 1: //���� �ֹ�
		f.display(); // ���� ���� ���
		ord.order(s.getX(), s.getY()); // ���� �α��� �� �ڸ��� ��ǥ���� �ֹ�
		afterLoginUserScreen();
		break;
	case 2: //�ð� �߰�
		member.addTime();
		afterLoginUserScreen();
		break;
	case 3: //�α׾ƿ�
		member.logout();
		s.logout();
		beforeLoginUserScreen();
		break;
	default:
		printf("�ùٸ� ���� �Է����ּ���.\n");
		afterLoginUserScreen();
		break;
	}
}

//������ ��� ȭ�� ���
void managerScreen() {
	int enter;
	cout << "                               [������ ���]                                " << endl;
	cout << "                              1. ���                                       " << endl;
	cout << "                              2. �ذ�                                       " << endl;
	cout << "                              3. ȸ�� ����Ʈ ���                           " << endl;
	cout << "                              4. ������ ����Ʈ ���                         " << endl;
	cout << "                              5. �ڸ� û��                                  " << endl;
	cout << "                              6. ���� ���                                  " << endl;
	cout << "                              7. ���� �޴� �߰�                             " << endl;
	cout << "                              8. ���� �޴� ����                             " << endl;
	cout << "                              9. ��� ���� ȭ��                             " << endl;
	cin >> enter;
	switch (enter) {
	case 1: //���
		manager.employment();
		managerScreen();
		break;
	case 2: //�ذ�
		manager.fire();
		managerScreen();
		break;
	case 3: //ȸ�� ����Ʈ ���
		member.display();
		managerScreen();
		break;
	case 4: //������ ����Ʈ ���
		manager.display();
		managerScreen();
		break;
	case 5: //�ڸ� û��
		s.clean();
		managerScreen();
		break;
	case 6: //���� ���
		ord.display();
		ord.pay();
		managerScreen();
		break;
	case 7: //���� �޴� �߰�
		f.insertMenu();
		managerScreen();
		break;
	case 8: //���� �޴� ����
		f.display();
		f.deleteMenu();
		managerScreen();
		break;
	case 9: //��� ���� ȭ��
		startingScreen();
		break;
	default:
		printf("�ùٸ� ���� �Է����ּ���.\n");
		afterLoginUserScreen();
		break;
	}
}

