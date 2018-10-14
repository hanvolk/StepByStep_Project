/*
  BankingSystem ver 1.0
  BankingSystem�� �ʿ��� �Լ����� ����
*/

#include"BankingCommonDel.h"
#include "BankingCommonDel.h"
#include "Declaration.h"
#include "Accout.h"



void ClearBuf(void)
{
    while(getchar()!='\n');
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

Account::Account(int ID, int money, char* name):accID(ID),balance(money)
{
    cusName=new char[strlen(name)+1];
    strcpy(cusName,name);
}

int Account::GetAccID(){return accID;}
void Account::Deposit(int money){balance+=money;}

int Account::Withdraw(int money)
{
    if(balance<money)
        return 0;

    balance-=money;
    return money;
}

void Account::ShowAccInfo()
{
    cout<<" "<<accID<<"    "<<cusName<<"   "<<balance;
}

void MakeAccout(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[���°���]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"��  �� : "; cin>>name;
    ClearBuf();
    cout<<"�Աݾ� : "; cin>>balance;
    cout<<endl;

   accArr[accNum++]=new Account(id,balance,name);

    cout<<name<<"���� �ű� ���� ������ �Ϸ� �Ǿ����ϴ�."<<endl;
    cout<<"accNum : "<<accNum<<endl;
    StoreAccData();
    ClearBuf();
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
            StoreAccData();
            ClearBuf();
            getchar();
            return;
        }
    }
    cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
    ClearBuf();
    getchar();
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
            StoreAccData();
            ClearBuf();
            getchar();
            return;
        }
    }
}

void ShowAllAccInfo()
{
    cout<<"����ID"<<"   "<<"�� ��"<<"    "<<"�� ��"<<endl;
    for(int i=0;i<accNum;i++)
    {
        accArr[i]->ShowAccInfo();
        cout<<endl;
    }

    cout<<"�� ���¼� : "<<accNum<<endl;
    ClearBuf();
    getchar();
}

void Exit()
{
     for(int i=0;i<accNum;i++)
            delete accArr[i];
}

void StoreAccData()
{
    FILE* fpw=fopen("PhoneData.dat","wb");
    if(fpw==NULL)
    {
        cout<<"������ �ҷ� ���µ� ���� �߽��ϴ�."<<endl;
        ClearBuf();
        getchar();
    }

    fwrite((void*)&accNum,sizeof(int),1,fpw);
    //���� ���� �� �κп� �� ���¼� ������ ���

    for(int i=0;i<accNum;i++)
    {
        bufAcc buf(accArr[i]->GetAccID(), accArr[i]->GetBalance(),accArr[i]->GetCusName());
        /*
           bufAcc Ŭ������ ���� ���� ����, �ҷ����⸦ ���� ������ Ŭ������ �̸��� �����ϴ� �ɹ����� cusName��
           char* ���� �ƴ�, char�� �迭�� ���� �Ǿ� �ֱ� ������ ���Ͽ� �̸� ���ڿ��� ����� ���� �� �� �ִ�.
        */

        fwrite((void*)&buf,sizeof(bufAcc),1,fpw);
    }

    ClearBuf();
    fclose(fpw);
}

void LoadAccData()
{
    int i=0;
    bufAcc* buf=new bufAcc();
    /* bufAcc�� ����� �ҷ����⸦ ���� ������ Ŭ������
       bufAcc�� �ӽ� ��ü�� ����
         ==> �� �ּҰ��� bufAcc ������ �� ��ü buf�� ���� */


    FILE* fpr=fopen("PhoneData.dat","rb");
    if(fpr==NULL)
    {
        cout<<"������ �ҷ� ���µ� ���� �Ͽ����ϴ�."<<endl;

        getchar();
        return;
    }

    fread((void*)&accNum,sizeof(int),1,fpr);
    // ������ ���� �� �κп� ����� ��ü ���¼� ������ �����Ƿ� �װ� ���� �ҷ� �ͼ� accNum�� �ʱ�ȭ

    cout<<"accNum : "<<accNum<<endl;

    while(i<accNum)
    {
        fread((void*)buf,sizeof(bufAcc),1,fpr);
        // fpr(���� ������)���� �ѹ��� bufAcc ũ�⸸ŭ�� �����͸�
        // buf(bufAcc�� ������)�� ����

        accArr[i]=new Account(buf->GetID(),buf->Getbalance(),buf->GetcusName());
        /*
          accArr �迭��(Account ������ �迭) buf�� ����� ���� Account �ӽ� ��ü�� ���� ��
          �� �ּҰ��� ���� �Ҵ� �ؼ� ���Ͽ� ���� ���� ���� �ҷ��ͼ� �����ϰ� �ִ�.
        */

        i++;
    }


    fclose(fpr);
    return;
}
