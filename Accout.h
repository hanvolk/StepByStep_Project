#pragma once

/*
  BankingSystem ver 1.0
  ���� ������ ���� ����ü ����
*/


/*
  Accout Ŭ������ �̸��� char�� �迭���� char�� ������ �迭�� ���� �ϸ鼭
  �׳� �ܼ��� char* �� cusName�� ������ ������, �ּҰ����� ���� �ϴ� �� �̹Ƿ�
  ���߿� ����ε� �̸� ���ڿ��� �ҷ��� ���� ����. ��, �ּҰ��� �ƴ� �̸� ���ڿ��� ���� �ؾ� �ؼ�
  bufacc��� ����� �ҷ����⿡ ����� Ŭ������ ���� ���� �ߴ�.
*/

class Account
{
private:
    int accID;    // ���¹�ȣ
    int balance;  // ��   ��
    char *cusName; //���̸�
public:
    Account():accID(0), balance(0){cusName=NULL;};
    Account(int ID, int money, char* name);
    Account(const Account& ref);
    int GetAccID() const;
    int GetBalance(){return balance;};
    char* GetCusName(){return cusName;};
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account(){delete []cusName;};
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

Account *accArr[100];  // Accout ������ ���� �迭
int accNum;        // ����� Account ��


