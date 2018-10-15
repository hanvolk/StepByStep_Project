/*
  BankingSystem ver 3.0
  ���� ������ ���� Ŭ������ ����
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "BankingCommonDel.h"

class Account
{
private:
    int accID;      //���¹�ȣ
    int balance;    //��   ��
    char* cusName;  //���̸� , char�� �迭���� char�� ������ �迭�� ����

public:
    Account(int ID, int money, char* name);
    Account(const Account& ref);

    int GetAccID();
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAllAccInfo();
    ~Account();
};

Account* accArr[100];  // Accout ������ ���� �迭, Account �迭���� Account ������ �迭�� ����
int accNum=0;        // ����� Account ��

#endif // __ACCOUNT_H__

