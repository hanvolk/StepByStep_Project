#include "BankingCommonDel.h"
#include "Declaration.h"


int main()
{
    LoadAccData();
    int choice;

    while(1)
    {
        ShowMenu();
        cout<<"select :";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case MAKE:
            MakeAccout();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            Exit();
            return 0;
        default:
            cout<<"Illegal selection.."<<endl;
        }
    }
    return 0;
}
