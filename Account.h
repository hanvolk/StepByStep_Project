#pragma once

/*
  BankingSystem ver 5.0
  ���� ������ ���� Ŭ���� Account Ŭ������ ����
*/

class Account
{
private:
    int accID;    // ���¹�ȣ
    int balance;  // ��   ��
    char *cusName; //���̸�
public:
    Account();
    Account(int ID, int money, char* name);
    Account(const Account& ref);

    int GetAccID() const;
    int GetBalance();
    char* GetCusName();

    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;

    ~Account();
};

class bufAcc
{
private:
    int ID;
    int balance;
    char cusName[20];
public:
    bufAcc(int id, int money, char* name):ID(id), balance(money)
    {
        strcpy(cusName,name);
    }
    bufAcc():ID(0), balance(0) //Default Construct
    {

    }

    int GetID(){return ID;}
    int Getbalance(){return balance;}
    char* GetcusName(){return cusName;}
};



