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
    cout<<" "<<accID<<"    "<<cusName<<"   "<<balance;
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
    StoreAccData();
    ClearBuf();
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
            StoreAccData();
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
            StoreAccData();
            ClearBuf();
            getchar();
            return;
        }
    }
}

void ShowAllAccInfo()
{
    cout<<"계좌ID"<<"   "<<"성 명"<<"    "<<"잔 액"<<endl;
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

void StoreAccData()
{
    FILE* fpw=fopen("PhoneData.dat","wb");
    if(fpw==NULL)
    {
        cout<<"파일을 불러 오는데 실패 했습니다."<<endl;
        ClearBuf();
        getchar();
    }

    fwrite((void*)&accNum,sizeof(int),1,fpw);
    //파일 제일 앞 부분에 총 계좌수 정보를 기록

    for(int i=0;i<accNum;i++)
    {
        bufAcc buf(accArr[i]->GetAccID(), accArr[i]->GetBalance(),accArr[i]->GetCusName());
        /*
           bufAcc 클래스는 계좌 정보 저장, 불러오기를 위해 정의한 클래스로 이름을 저장하는 맴버변수 cusName이
           char* 형이 아닌, char형 배열로 정의 되어 있기 때문에 파일에 이름 문자열을 제대로 저장 할 수 있다.
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
    /* bufAcc는 저장과 불러오기를 위해 정의한 클래스로
       bufAcc형 임시 객체를 생성
         ==> 그 주소값을 bufAcc 포인터 형 객체 buf에 저장 */


    FILE* fpr=fopen("PhoneData.dat","rb");
    if(fpr==NULL)
    {
        cout<<"파일을 불러 오는데 실패 하였습니다."<<endl;

        getchar();
        return;
    }

    fread((void*)&accNum,sizeof(int),1,fpr);
    // 파일의 제일 앞 부분에 저장된 전체 계좌수 정보가 있으므로 그것 부터 불러 와서 accNum을 초기화

    cout<<"accNum : "<<accNum<<endl;

    while(i<accNum)
    {
        fread((void*)buf,sizeof(bufAcc),1,fpr);
        // fpr(파일 포인터)에서 한번에 bufAcc 크기만큼의 데이터를
        // buf(bufAcc형 포인터)에 저장

        accArr[i]=new Account(buf->GetID(),buf->Getbalance(),buf->GetcusName());
        /*
          accArr 배열에(Account 포인터 배열) buf에 저장된 값을 Account 임시 객체를 생성 후
          그 주소값을 동적 할당 해서 파일에 계좌 정보 값을 불러와서 저장하고 있다.
        */

        i++;
    }


    fclose(fpr);
    return;
}
