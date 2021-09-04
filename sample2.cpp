using namespace std;
#include <iostream>
#include <string.h>
#include <cstdlib> //this enables to clear screen and pause it

//structure declaration for items categories

struct items{   char name[30];
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

		cout<<"\nEnter NAME: ";
		cin.ignore();
        cin.get(f.name,20);
        cout<<"Enter COST: ";
        cin>>f.cost;
        cout<<"Enter PRICE: ";
        cin>>f.price;
        cout<<"Enter AMOUNT: ";
        cin>>f.amount;

    return f;
}
/////////////////////////////////////////
void display (items f[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"\nNAME: ";
		cout<<f[i].name<<endl;
        cout<<"COST: ";
        cout<<f[i].cost<<endl;
        cout<<"PRICE: ";
        cout<<f[i].price<<endl;
        cout<<"AMOUNT: ";
        cout<<f[i].amount<<endl;
	}
}
//register items under BEVERAGE category
items register_B ()
{
    items b;

        cout<<"\nEnter NAME: ";
       	cin.ignore();
		cin.get(b.name,30);
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

        cout<<"\nEnter NAME: ";
       	cin.ignore();
       	cin.get(p.name,30);
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

        cout<<"\nEnter NAME: ";
    	cin.ignore();
        cin.get(h.name,30);
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

        cout<<"\nEnter NAME: ";
    	cin.ignore();
        cin.get(o.name,30);
		cout<<"Enter COST: ";
        cin>>o.cost;
        cout<<"Enter PRICE: ";
        cin>>o.price;
        cout<<"Enter AMOUNT: ";
        cin>>o.amount;

    return o;
}

//Begining of main () function
int main()
{
    items food[20], beverage[20], personalCare[20], household_suplly[20], others[20];
     int old= 0;    int New;
     int choice1, choice2, choice3, choice4;
     char updateName[30];
//////
		int amount;
tryagain:
main:     	cout<<"\n\t1. Register new items.\n\t2. Sell items.\n\t3. Checking stack availability.\n\t4. Total no. of sales.\n\t5. Profit.\n\t6. statistical report.\n";
     	cin>>choice1;

     system ("cls"); //clears screen

        switch(choice1){
    case 1:
        {
	tryagain2:
 prev:  	cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n";
            cin>>choice2;
            system ("cls"); //clears screen

            switch(choice2)
            {
            case 1:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                New = New + old;
                
                for(int i = old; i < New; i++)
                {
					cout<<"\nItem "<<i+1;
					food[i] = register_F();
                }
                
        ////////////////////////////////////////////////
				amount = New;
					display(food, amount);
				old = old + New;
				
				
		//Ask to continue or termminate
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;
	                    break;
	                case 1: goto main;
	                    break;
	                case 2: goto prev;
	                    break;
				}
				break;
            case 2:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                New = New + old;
                
                for(int i = old; i < New; i++)
                {
                	cout<<"\nItem "<<i+1;
                    beverage[i] = register_B();
                }
                old = old + New;
        //Ask to continue or termminate
                cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;
	                    break;
	                case 1: goto main;
	                    break;
	                case 2: goto prev;
	                    break;
				}
                
                break;
            case 3:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                New = New + old;
                
                for(int i = old; i < New; i++)
                {
                	cout<<"\nItem "<<i+1;
                    personalCare[i] = register_P();
                }
                old = old + New;
        //Ask to continue or termminate
                cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;
	                    break;
	                case 1: goto main;
	                    break;
	                case 2: goto prev;
	                    break;
				}    
                break;
            case 4:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                New = New + old;
                
                for(int i = old; i < New; i++)
                {
                	cout<<"\nItem "<<i+1;
                    household_suplly[i] = register_H();
                }
                old = old + New;
        //Ask to continue or termminate
                cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;
	                    break;
	                case 1: goto main;
	                    break;
	                case 2: goto prev;
	                    break;
				}
                break;
            case 5:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                New = New + old;
                
                for(int i = old; i < New; i++)
                {
                    others[i] = register_O();
                }
                old = old + New;
        //Ask to continue or termminate
                cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;
	                    break;
	                case 1: goto main;
	                    break;
	                case 2: goto prev;
	                    break;
				}
                break;

           		default:
        	cout<<"\nYou entered wrong number!\n\tTry again.";
        	goto tryagain2;
		    }
        }
    //Make update on price
    	cout<<"\n\tUpdate on price?\n\t\t1. Yes\n\t\t2. No\n";
    	cin>>choice4;
    	cout<<"Enter name of item to be updated\n";
    	cin.ignore();
    	cin.get(updateName, 30);
    	
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

        default:
        cout<<"\nYou entered wrong number!\n\tTry again.";
        goto tryagain;
	    }

    return 0;
}
