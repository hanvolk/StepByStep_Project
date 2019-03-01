/*
  BankingSystem ver 8.0
  AccountHandlerŬ����(control Ŭ����)�� ����
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
    BoundCheckAccountPtrArray accArr;  // Accout ������ ���� �迭Ŭ����, Account Ŭ���� ��ü�� �ּҰ��� ����
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
