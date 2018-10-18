#pragma once

/*
  BankingSystem ver 5.0
  계좌 정보에 대한 클래스 Account 클래스의 정의
*/

class Account
{
private:
    int accID;    // 계좌번호
    int balance;  // 잔   액
    char *cusName; //고객이름
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



