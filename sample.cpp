using namespace std;
#include <iostream>
#include <string.h>

//structure declaration for items categories

struct items{   char name[20];
                float cost;
                float price;
                float amount;
            };
//Function declaration and definition
//Function to register newly purchased items

items register_F ()
{
    items f;

        cout<<"Enter NAME: ";
        gets(f.name);
        cout<<"Enter COST: ";
        cin>>f.cost;
        cout<<"Enter PRICE: ";
        cin>>f.price;
        cout<<"Enter AMOUNT: ";
        cin>>f.amount;

    return f;
}


int main()
{
    items food[20], beverage[20], personalCare[20], household_suplly[20], others[20];
     int old= 0;    int New;
     int choice1, choice2;

     cout<<"\n\t1. Register new items.\n\t2. Sell items.\n\t3.Checking stack availability.\n\t4.Total no. of sales.\n\t5.Profit.\n\t6.statistical report.";
     cin>>choice1;
        switch(choice1){
    case 1:
        {
            cout<<"\n\tChoose Item Category\n\t1.Food\n\t2.Beverage\n\t3.Personal Care\n\t4.Household supply\n\t5.Others\n";
            cin>>choice2;
            switch(choice2)
            {
            case 1:
                cout<<"\n\tHow many items do you want to register?";
                cin>>New;
                for(int i = old; i < New; i++)
                {
                    food[i] = register_F();
                }
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            }
        }
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
        }
    return 0;
}
