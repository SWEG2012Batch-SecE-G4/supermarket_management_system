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

//register items under FOOD category
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
//register items under BEVERAGE category
items register_B ()
{
    items b;

        cout<<"Enter NAME: ";
        gets(b.name);
        cout<<"Enter COST: ";
        cin>>b.cost;
        cout<<"Enter PRICE: ";
        cin>>b.price;
        cout<<"Enter AMOUNT: ";
        cin>>b.amount;

    return b;
}
//register items under PERSONAL CARE category
items register_P()
{
    items p;

        cout<<"Enter NAME: ";
        gets(p.name);
        cout<<"Enter COST: ";
        cin>>p.cost;
        cout<<"Enter PRICE: ";
        cin>>p.price;
        cout<<"Enter AMOUNT: ";
        cin>>p.amount;

    return p;
}
//register items under HOUSEHOLD category
items register_H ()
{
    items h;

        cout<<"Enter NAME: ";
        gets(h.name);
        cout<<"Enter COST: ";
        cin>>h.cost;
        cout<<"Enter PRICE: ";
        cin>>h.price;
        cout<<"Enter AMOUNT: ";
        cin>>h.amount;

    return h;
}
//register items under OTHERS category
items register_O()
{
    items o;

        cout<<"Enter NAME: ";
        gets(o.name);
        cout<<"Enter COST: ";
        cin>>o.cost;
        cout<<"Enter PRICE: ";
        cin>>o.price;
        cout<<"Enter AMOUNT: ";
        cin>>o.amount;

    return o;
}
int main()
{
    items food[20], beverage[20], personalCare[20], household_suplly[20], others[20];
     int old= 0;    int New;
     int choice1, choice2;

     cout<<"\n\t1. Register new items.\n\t2. Sell items.\n\t3. Checking stack availability.\n\t4. Total no. of sales.\n\t5. Profit.\n\t6. statistical report.\n";
     cin>>choice1;
        switch(choice1){
    case 1:
        {
            cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n";
            cin>>choice2;
            switch(choice2)
            {
            case 1:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                for(int i = old; i < New; i++)
                {
                    food[i] = register_F();
                }
                break;
            case 2:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                for(int i = old; i < New; i++)
                {
                    beverage[i] = register_B();
                }
                break;
            case 3:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                for(int i = old; i < New; i++)
                {
                    personalCare[i] = register_P();
                }
                break;
            case 4:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                for(int i = old; i < New; i++)
                {
                    household_suplly[i] = register_H();
                }
                break;
            case 5:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                for(int i = old; i < New; i++)
                {
                    others[i] = register_O();
                }
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
