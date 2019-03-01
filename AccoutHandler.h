/*
  BankingSystem ver 8.0
  AccountHandler클래스(control 클래스)의 정의
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
    BoundCheckAccountPtrArray accArr;  // Accout 저장을 위한 배열클래스, Account 클래스 객체의 주소값을 저장
    int accNum;        // 저장된 Account 수
public:
    AccountHandler();
    void ShowMenu(void);
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void);
    ~AccountHandler();
protected:
    void MakeNormalAccount(void);
    void MakeCreditAccount(void);
};
#endif // __ACCOUNTHANDLER_H__
