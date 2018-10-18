#pragma once

/*
     BankingSystem ver 5.0
     프로그램의 기능을 담당하는 컨트롤 클래스 AccountHandler 정의
*/

/*
Control Class AccountHandler
private:
  accArr[100] : 계좌정보 Account 클래스의 포인터를 저장하는 배열
  accNum : 총 계좌의 갯수
*/
#include "Account.h"

class AccountHandler
{
private:
    Account *accArr[100];  // Accout 저장을 위한 배열
    int accNum;        // 저장된 Account 수
public:
    void ShowMenu(void);        // 전체 메뉴 출력
    void MakeAccout(void);      // 계좌 생성
    void DepositMoney(void);    // 입금 기능
    void WithdrawMoney(void);   // 출금 기능
    void ShowAllAccInfo(void);  // 전체 계좌 정보 출력
    void Exit(void);            // 프로그램 종료
    void StoreAccData(void);    // 데이터의 저장
    void LoadAccData(void);     // 데이터의 로드
    void DeleteAccount(void);  // 계좌의 삭제
};
