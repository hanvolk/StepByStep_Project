/*
  BankingSystem ver 3.0
  BankingSystem�� �ʿ��� �Լ����� ����
*/

#include "BankingCommonDel.h"
#include "Accout.h"

void ClearBuf(void)
{
    while(getchar()!='\n');
}


Account::Account(int ID, int money, char* name):accID(ID), balance(money)
{
    cusName=new char[strlen(name)+1];
    strcpy(cusName,name);
}
Account::Account(const Account& ref):accID(ref.accID), balance(ref.balance)
{
        cusName=new char[strlen(ref.cusName)+1];
        strcpy(cusName,ref.cusName);
}
int Account::GetAccID() const {return accID;}
void Account::Deposit(int money)
{
    balance+=money;
}
int Account::Withdraw(int money)
{
    if(balance<money)
        return 0;
    balance-=money;
    return money;
}
void Account::ShowAllAccInfo() const
{
    cout<<"����ID : "<<accID<<endl;
    cout<<"��  �� : "<<cusName<<endl;
    cout<<"��  �� : "<<balance<<endl;
}
Account::~Account()
{
    delete []cusName;
}



void ShowMenu(void)
{
    system("cls");
    cout<<"===== Menu ====="<<endl;
    cout<<"1. ���°���"<<endl;
    cout<<"2. ��   ��"<<endl;
    cout<<"3. ��   ��"<<endl;
    cout<<"4. �������� ��ü ���"<<endl;
    cout<<"5. ���α׷� ����"<<endl;
}

void MakeAccout(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[���°���]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"��  �� : "; cin>>name;
    cout<<"�Աݾ� : "; cin>>balance;
    cout<<endl;

    accArr[accNum++]=new Account(id,balance,name);

    cout<<name<<"���� �ű� ���� ������ �Ϸ� �Ǿ����ϴ�."<<endl;
    ClearBuf();
    getchar();
}

void DepositMoney(void)
{
    int money;
    int id;
    cout<<"[��   ��]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"�Աݾ� : "; cin>>money;

    for(int i=0;i<accNum;i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            accArr[i]->Deposit(money);
            cout<<"�ԱݿϷ�"<<endl<<endl;
            ClearBuf();
            getchar();
            return;
        }
    }
    cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
}

void WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"[��   ��]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"��ݾ� : "; cin>>money;

    for(int i=0;i<accNum;i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            if(accArr[i]->Withdraw(money)==0)
            {
                cout<<"�ܾ׺���"<<endl<<endl;
                ClearBuf();
                getchar();
                return;
            }

            cout<<"��ݿϷ�"<<endl<<endl;
            ClearBuf();
            getchar();
            return;
        }
    }
}

void ShowAllAccInfo()
{
    for(int i=0;i<accNum;i++)
    {
        accArr[i]->ShowAllAccInfo();
        cout<<endl;
    }
    ClearBuf();
    getchar();
}
