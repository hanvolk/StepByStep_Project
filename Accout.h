#pragma once

/*
  BankingSystem ver 1.0
  ���� ������ ���� ����ü ����
*/


class Account
{
private:
    int accID;    // ���¹�ȣ
    int balance;  // ��   ��
    char *cusName; //���̸�
public:
    Account(int ID, int money, char* name);
    int GetAccID();
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo();
    ~Account(){delete []cusName;};
};

Account *accArr[100];  // Accout ������ ���� �迭
int accNum;        // ����� Account ��


