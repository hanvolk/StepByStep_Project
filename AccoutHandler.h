/*
  BankingSystem ver 5.0
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
    void MakeAccout(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void);
    ~AccountHandler();
};
#endif // __ACCOUNTHANDLER_H__
