/*
  BankingSystem ver 11.0
  Main Function
*/
#include "BankingCommonDel.h"
#include "AccoutHandler.h"

int main()
{
    AccountHandler manager;
    int choice;


    while(1)
    {
        manager.ShowMenu();
        cout<<"Select : ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            getchar();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout<<"Illegal selection.."<<endl;
        }
    }
    return 0;
}
