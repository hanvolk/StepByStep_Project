#pragma once

/*
     BankingSystem ver 5.0
     ���α׷��� ����� ����ϴ� ��Ʈ�� Ŭ���� AccountHandler ����
*/

/*
Control Class AccountHandler
private:
  accArr[100] : �������� Account Ŭ������ �����͸� �����ϴ� �迭
  accNum : �� ������ ����
*/
#include "Account.h"

class AccountHandler
{
private:
    Account *accArr[100];  // Accout ������ ���� �迭
    int accNum;        // ����� Account ��
public:
    void ShowMenu(void);        // ��ü �޴� ���
    void MakeAccout(void);      // ���� ����
    void DepositMoney(void);    // �Ա� ���
    void WithdrawMoney(void);   // ��� ���
    void ShowAllAccInfo(void);  // ��ü ���� ���� ���
    void Exit(void);            // ���α׷� ����
    void StoreAccData(void);    // �������� ����
    void LoadAccData(void);     // �������� �ε�
    void DeleteAccount(void);  // ������ ����
};
