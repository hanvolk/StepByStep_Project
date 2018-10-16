#include "BankingCommonDel.h"
#include "AccoutHandler.h"

int main()
{
    AccountHandler manager;
    int choice;


    while(1)
    {
        manager.ShowMenu();
        cout<<"���� : ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case MAKE:
            manager.MakeAccout();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
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
