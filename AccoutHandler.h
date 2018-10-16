/*
  BankingSystem ver 5.0
  Account의 control 클래스의 정의
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"

class AccountHandler
{
private:
    Account* accArr[100];  // Accout 저장을 위한 배열, Account 배열에서 Account 포인터 배열로 변경
    int accNum;        // 저장된 Account 수
public:
    AccountHandler();
    void ShowMenu(void);
    void MakeAccout(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void);
    ~AccountHandler();
};
#endif // __ACCOUNTHANDLER_H__
