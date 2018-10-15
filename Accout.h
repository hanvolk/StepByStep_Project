#pragma once

/*
  BankingSystem ver 1.0
  계좌 정보에 대한 구조체 정의
*/


/*
  Accout 클래스의 이름을 char형 배열에서 char형 포인터 배열로 변경 하면서
  그냥 단순히 char* 형 cusName을 저장해 버리면, 주소값만을 저장 하는 것 이므로
  나중에 제대로된 이름 문자열을 불러올 수가 없다. 즉, 주소값이 아닌 이름 문자열을 저장 해야 해서
  bufacc라는 저장과 불러오기에 사용할 클래스를 따로 정의 했다.
*/

class Account
{
private:
    int accID;    // 계좌번호
    int balance;  // 잔   액
    char *cusName; //고객이름
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

Account *accArr[100];  // Accout 저장을 위한 배열
int accNum;        // 저장된 Account 수


