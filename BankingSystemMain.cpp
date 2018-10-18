#include "BankingCommonDel.h"
#include "AccountHandler.h"


int main()
{
    AccountHandler manager;
    manager.LoadAccData();
    int choice;

    while(1)
    {
        manager.ShowMenu();
        cout<<"select :";
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
            manager.Exit();
            return 0;
        case 0:
            manager.DeleteAccount();
        default:
            cout<<"Illegal selection.."<<endl;
        }
    }
    return 0;
}
