/*
  BankingSystem ver 6.0
  Account�� control Ŭ������ ����
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"

class AccountHandler
{
private:
    Account* accArr[100];  // Accout ������ ���� �迭, Account �迭���� Account ������ �迭�� ����
    int accNum;        // ����� Account ��
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
