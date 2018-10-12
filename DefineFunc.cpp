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
    cout<<"����ID : "<<accID<<endl;
    cout<<"��  �� : "<<cusName<<endl;
    cout<<"��  �� : "<<balance<<endl;
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
   // StoreAccData();
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
           // StoreAccData();
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
        //    StoreAccData();
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
/*
void StoreAccData()
{

    FILE* fpw=fopen("PhoeData.dat","wb");
    if(fpw==NULL)
    {
        cout<<"���� ���忡 ������ �߻� �߽��ϴ�."<<endl;
        ClearBuf();
        getchar();
        return;
    }
    fwrite((void*)accArr,sizeof(Account),accNum,fpw);
    fclose(fpw);
}

void LoadAccData()
{
    int i=0,cnt=0;
    Account buf;
    FILE* fpr=fopen("PhoeData.dat","rb");
    if(fpr==NULL)
    {
        cout<<"������ �ҷ� ���µ� ���� �Ͽ����ϴ�."<<endl;

        getchar();
        return;
    }

    while(1)
    {
        cnt=fread((void*)&buf,sizeof(Account),1,fpr);
        if(cnt<1)
            break;
        accArr[i]=buf;
        i++;
    }
    accNum=i;

    fclose(fpr);
    return;
}
*/
