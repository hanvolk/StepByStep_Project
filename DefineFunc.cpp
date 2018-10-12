/*
  BankingSystem ver 1.0
  BankingSystem에 필요한 함수들의 정의
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
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입   금"<<endl;
    cout<<"3. 출   금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
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
    cout<<"계좌ID : "<<accID<<endl;
    cout<<"이  름 : "<<cusName<<endl;
    cout<<"잔  액 : "<<balance<<endl;
}

void MakeAccout(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID : "; cin>>id;
    cout<<"이  름 : "; cin>>name;
    ClearBuf();
    cout<<"입금액 : "; cin>>balance;
    cout<<endl;

   accArr[accNum++]=new Account(id,balance,name);

    cout<<name<<"님의 신규 계좌 개설이 완료 되었습니다."<<endl;
    cout<<"accNum : "<<accNum<<endl;
   // StoreAccData();
    ClearBuf();
    getchar();

}

void DepositMoney(void)
{
    int money;
    int id;
    cout<<"[입   금]"<<endl;
    cout<<"계좌ID : "; cin>>id;
    cout<<"입금액 : "; cin>>money;

    for(int i=0;i<accNum;i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            accArr[i]->Deposit(money);
            cout<<"입금완료"<<endl<<endl;
           // StoreAccData();
            ClearBuf();
            getchar();
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
    ClearBuf();
    getchar();
}

void WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"[출   금]"<<endl;
    cout<<"계좌ID : "; cin>>id;
    cout<<"출금액 : "; cin>>money;

    for(int i=0;i<accNum;i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            if(accArr[i]->Withdraw(money)==0)
            {
                cout<<"잔액부족"<<endl<<endl;
                ClearBuf();
                getchar();
                return;
            }

            cout<<"출금완료"<<endl<<endl;
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

    cout<<"총 계좌수 : "<<accNum<<endl;
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
        cout<<"파일 저장에 오류가 발생 했습니다."<<endl;
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
        cout<<"파일을 불러 오는데 실패 하였습니다."<<endl;

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
