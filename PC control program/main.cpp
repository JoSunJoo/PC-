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

Food f; // 음식 객체
Order ord; // 주문 객체
Member member; // 사용자 객체
Seat s; //자리 객체
Manager manager; // 관리자 객체

void main() {
	// 교수몰래 pc방 기본 음식 리스트
	f.insert(new FoodNode("음료류", 1000, "콜라"));
	f.insert(new FoodNode("식사류", 4500, "제육덮밥"));
	f.insert(new FoodNode("면류", 3000, "라면"));
	// 교수몰래 pc방 초기 관리자 리스트
	manager.insert(new ManagerNode("박형진", 21, "신입"));
	manager.insert(new ManagerNode("정찬호", 21, "2년차"));
	manager.insert(new ManagerNode("박동진", 21, "1년차"));
	// 프로그램 시작
	startingScreen();
}

//시작 화면 설정
void startingScreen() {
	int enter;
	cout << "===========================PC방 자리 관리 프로그램==========================" << endl;
	cout << "                              1. 사용자 모드                                " << endl;
	cout << "                              2. 관리자 모드                                " << endl;
	cout << "                              3. 프로그램 종료                              " << endl;
	cin >> enter;
	switch (enter) {
	case 1: //사용자 모드 화면 출력
		beforeLoginUserScreen();
		break;
	case 2: //관리자 모드 화면 출력
		managerScreen();
		break;
	case 3: //시스템 종료
		exit(0);
	default:
		printf("올바른 수를 입력해주세요.\n");
		startingScreen();
	}
}

//사용자 모드 선택지 출력
void beforeLoginUserScreen() {
	int enter;
	cout << "                               [사용자 모드]                                " << endl;
	cout << "                              1. 회원가입                                   " << endl;
	cout << "                              2. 로그인                                     " << endl;
	cout << "                              3. 모드 설정 화면                             " << endl;
	cin >> enter;
	switch (enter) {
	case 1: //회원가입
		member.join();
		beforeLoginUserScreen();
		break;
	case 2: //로그인
		if (member.login()) { //로그인 성공 시 회원 모드 화면 출력
			s.login();
			afterLoginUserScreen();
		}
		else //로그인 실패 시 사용자 모드 선택지 출력
			beforeLoginUserScreen();
		break;
	case 3:
		startingScreen();
		break;
	default:
		printf("올바른 수를 입력해주세요.\n");
		beforeLoginUserScreen();
		break;
	}
}

//회원 모드 화면 출력
void afterLoginUserScreen() {
	int enter;
	cout << "                               [사용자 모드]                                " << endl;
	printf("                                                [사용자: %s] [남은 시간: %d]\n", member.getName(), member.getRestTime());
	cout << "                              1. 음식 주문                                  " << endl;
	cout << "                              2. 시간 추가                                  " << endl;
	cout << "                              3. 로그아웃                                   " << endl;
	cin >> enter;
	switch (enter) {
	case 1: //음식 주문
		f.display(); // 음식 정보 출력
		ord.order(s.getX(), s.getY()); // 현재 로그인 된 자리의 좌표에서 주문
		afterLoginUserScreen();
		break;
	case 2: //시간 추가
		member.addTime();
		afterLoginUserScreen();
		break;
	case 3: //로그아웃
		member.logout();
		s.logout();
		beforeLoginUserScreen();
		break;
	default:
		printf("올바른 수를 입력해주세요.\n");
		afterLoginUserScreen();
		break;
	}
}

//관리자 모드 화면 출력
void managerScreen() {
	int enter;
	cout << "                               [관리자 모드]                                " << endl;
	cout << "                              1. 고용                                       " << endl;
	cout << "                              2. 해고                                       " << endl;
	cout << "                              3. 회원 리스트 출력                           " << endl;
	cout << "                              4. 관리자 리스트 출력                         " << endl;
	cout << "                              5. 자리 청소                                  " << endl;
	cout << "                              6. 음식 배달                                  " << endl;
	cout << "                              7. 음식 메뉴 추가                             " << endl;
	cout << "                              8. 음식 메뉴 제거                             " << endl;
	cout << "                              9. 모드 설정 화면                             " << endl;
	cin >> enter;
	switch (enter) {
	case 1: //고용
		manager.employment();
		managerScreen();
		break;
	case 2: //해고
		manager.fire();
		managerScreen();
		break;
	case 3: //회원 리스트 출력
		member.display();
		managerScreen();
		break;
	case 4: //관리자 리스트 출력
		manager.display();
		managerScreen();
		break;
	case 5: //자리 청소
		s.clean();
		managerScreen();
		break;
	case 6: //음식 배달
		ord.display();
		ord.pay();
		managerScreen();
		break;
	case 7: //음식 메뉴 추가
		f.insertMenu();
		managerScreen();
		break;
	case 8: //음식 메뉴 제거
		f.display();
		f.deleteMenu();
		managerScreen();
		break;
	case 9: //모드 선택 화면
		startingScreen();
		break;
	default:
		printf("올바른 수를 입력해주세요.\n");
		afterLoginUserScreen();
		break;
	}
}

