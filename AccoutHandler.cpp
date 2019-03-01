/*
  BankingSystem ver 9.0
 AccountHandlerŬ����(control Ŭ����) �Լ��� ����
*/
#include "BankingCommonDel.h"
#include "AccoutHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

void ClearBuf(void)
{
    while(getchar()!='\n'){};
}

AccountHandler::AccountHandler():accNum(0)
{};

void AccountHandler::ShowMenu(void)
{
    system("cls");
    cout<<"===== Menu ====="<<endl;
    cout<<"1. ���°���"<<endl;
    cout<<"2. ��   ��"<<endl;
    cout<<"3. ��   ��"<<endl;
    cout<<"4. �������� ��ü ���"<<endl;
    cout<<"5. ���α׷� ����"<<endl;
}

void AccountHandler::MakeAccount(void)
{
    int sel;

    cout<<"[������������]"<<endl;
    cout<<"1.���뿹�ݰ���"<<endl;
    cout<<"2.�ſ�ŷڰ���"<<endl;
    cout<<"���� : ";
    cin>>sel;

    if(sel==NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();

    ClearBuf();
    getchar();
}

void AccountHandler::MakeNormalAccount(void)
{
    int id;
    //char name[NAME_LEN];
    String name;
    int balance;
    int interRate;

    cout<<"[���뿹�ݰ��� ����]"<<endl;
    cout<<"���� ID : ";cin>>id;
    cout<<"��    ��: ";cin>>name;
    cout<<"�� �� �� : ";cin>>balance;
    cout<<"�� �� �� : ";cin>>interRate;
    cout<<endl;
    accArr[accNum++]=new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::
    MakeCreditAccount(void)
{
    int id;
    //char name[NAME_LEN];
    String name;
    int balance;
    int interRate;
    int creditLevel;

    cout<<"[�ſ�ŷڰ��� ����]"<<endl;
    cout<<"���� ID : ";cin>>id;
    cout<<"��    ��: ";cin>>name;
    cout<<"�� �� �� : ";cin>>balance;
    cout<<"�� �� �� : ";cin>>interRate;
    cout<<"�ſ���(1toA, 2toB, 3toC) : ";cin>>creditLevel;
    cout<<endl;

    switch(creditLevel)
    {
    case 1:
        accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
        break;
    case 2:
        accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
        break;
    case 3:
        accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
        break;
    }

}

void AccountHandler::DepositMoney(void)
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

void AccountHandler::WithdrawMoney(void)
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
                getchar();
                return;
            }

            cout<<"��ݿϷ�"<<endl<<endl;
            getchar();
            return;
        }
    }
}

void AccountHandler::ShowAllAccInfo()
{
    for(int i=0;i<accNum;i++)
    {
        accArr[i]->ShowAccInfo();
        cout<<endl;
    }
    ClearBuf();
    getchar();
}
AccountHandler::~AccountHandler()
{
    for(int i=0;i<accNum;i++)
        delete accArr[i];
}

