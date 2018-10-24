/*
  BankingSystem ver 6.0
  NormalAccount(���뿹�� ����) Ŭ������ ����
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
// ������ ���� : �ּ����� ���ڸ� �����ϴ� ���� ����ݽ� ����

#include "Account.h"

class NormalAccount:public Account
{
private:
    int interRate;  // ������ %����
public:
    NormalAccount(int ID, int money, char* name, int rate):Account(ID,money,name), interRate(rate)
    {
        // Normal Account Class�� ��ü ������������ �����ڷ� ������(interRate) ������ ��� �ϰ� �ִ�.
    }

    virtual void Deposit(int money)
    {
        Account::Deposit(money); //�����߰�
        Account::Deposit(money*(interRate/100.0));  // �����߰�
    }
};
#endif // __NORMAL_ACCOUNT_H__

