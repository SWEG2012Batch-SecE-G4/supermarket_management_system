using namespace std;
#include<iostream>
#include<string.h>
#include<cstdlib> //this enables to clear screen and pause it
#include<iomanip>
#include<bits/stdc++.h> //for find and sort

//structure declaration for items categories

struct items{   char name[30];
                float cost;
                float price;
                float amount;
            };

//structure declarartion for sold items

struct sold{	char name[30];
                float amount;
                float price;
			};

//Function declarations and definitions
//Function to register newly purchased items

items register_items()
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

//
void display_successful()
{
	cout<<"\n\t-----------------------------------------\n";
	cout<<"\t-----------------------------------------\n";
	cout<<"\t 		Successfully Registered!\n";
	cout<<"\t-----------------------------------------\n";
	cout<<"\t-----------------------------------------\n";
}
//Function to calculate profit of individual category items
//Profit of FOOD category
float food_profit(items f[], int n){
	float profit1=0;
		for(int i = 0; i < n; i++)
                {
					profit1+=(f[i].amount*f[i].price-f[i].amount*f[i].cost);

                }

	return profit1;
}
//Profit of BEVERAGE category
float beverage_profit(items b[],int n){
	float profit2=0;
	for(int i = 0; i < n; i++)
                {
					profit2+=(b[i].amount*b[i].price-b[i].amount*b[i].cost);

                }

	return profit2;
}
//Profit of PERSONAL CARE category
float personal_care_profit(items p[],int n){
	float profit3=0;
	for(int i = 0; i < n; i++)
                {
					profit3+=(p[i].amount*p[i].price-p[i].amount*p[i].cost);

                }

	return profit3;
}
//Profit of HOUSEHOLD SUPPLIES category
float HH_supply_profit(items h[],int n){
	float profit4=0;
	for(int i = 0; i < n; i++)
                {
					profit4+=(h[i].amount*h[i].price-h[i].amount*h[i].cost);

                }

	return profit4;
}
//Profit of OTHERS category
float others_profit(items o[],int n){
	float profit5=0;
	for(int i = 0; i < n; i++)
                {
					profit5+=(o[i].amount*o[i].price-o[i].amount*o[i].cost);

                }

	return profit5;
}

//Function for selling
sold sell(items s[], int n)
{
	sold solled;
	char name[30];	int amount;
	 s[n];

		cout<<"\n\tEnter\nName of the item: ";
		cin.ignore();
		cin.get(name, 30);

		for(int i=0; i<n; i++)
		{
			if(stricmp(s[i].name, name) == 0)
			{
				cout<<"\n\tAmount of sold items: ";
				cin>>amount;
				if(amount <= s[i].amount)
				{
					cout<<"\n\tAmount Available\n";
					s[i].amount = s[i].amount - amount;
					solled.price = amount * s[i].price,
					cout<<"\n\tPrice: "<<solled.price<<" birr.\n";
				}
				else
				{
					cout<<"\n\tNot enought\n\t"<<s[i].amount<<" only available.";
				}
			}
		}
	return solled;
}

//Beginning of main() function
int main()
{
    items food[20], beverage[20], personalCare[20], household_suplly[20], others[20];
    sold S_food[20], S_beverage[20], S_personalCare[20], S_household_suplly[20], S_others[20];
     int oldF= 0, oldB=0, oldP=0, oldH=0, oldO=0;    int NewF, NewB, NewP, NewH, NewO;
     int S_oldF= 0, S_oldB=0, S_oldP=0, S_oldH=0, S_oldO=0;    int S_NewF, S_NewB, S_NewP, S_NewH, S_NewO;
	 int choice1, choice2, choice3, choice4, choice5, choice6;
     char updateName[30], searchName[30];
     float newPrice; int newAmount;

//////
		int amount;

			cout<<"\n\t-------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
			cout<<"\t	WELCOME TO SUPERMARKET MANAGEMENT SYSTEM!\n";
			cout<<"\t---------------------------------------------------\n";
			cout<<"\t\tMain menu\n";
main:     	cout<<"\t\t1. Register new items.\n\t\t2. Update Price and Available Amount.\n\t\t3. Checking stack availability.\n\t\t4. Sales.\n\t\t5. Profit.\n\t\t6. Statistical report.\n";
     	 	cout<<"\t---------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
			cin>>choice1;

    system ("cls"); //clears screen

        switch(choice1)
		{
//Register items
    case 1:
        {
prev1:
			cout<<"\n\t-------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
			cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n\n";
            cout<<"\n\t-------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
			cin>>choice2;
        system ("cls");

            switch(choice2)
            {
            case 1:
            	cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>NewF;
                NewF = NewF + oldF;

                for(int i = oldF; i < NewF; i++)
                {
					cout<<"\nItem "<<i+1;
					food[i] = register_items();
                }

        ////////////////////////////////////////////////
				amount = NewF;
					display(food, amount);
				oldF = oldF + NewF;

				display_successful();
			//Ask to continue or terminate
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
			system ("cls");
				}
////////////////////////////////////////////////////////////////////////////////////////////////////////
				break;
            case 2:
                cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tHow many items do you want to register?\n";
                cin>>NewB;
                NewB = NewB + oldB;

                for(int i = oldB; i < NewB; i++)
                {
                	cout<<"\nItem "<<i+1;
                    beverage[i] = register_items();
                }
                oldB = oldB + NewB;

                display_successful();
        //Ask to continue or terminate
                cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
				}
        system ("cls");
                break;
            case 3:
                cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tHow many items do you want to register?\n";
                cin>>NewP;
                NewP = NewP + oldP;

                for(int i = oldP; i < NewP; i++)
                {
                	cout<<"\nItem "<<i+1;
                    personalCare[i] = register_items();
                }
                oldP = oldP + NewP;

                display_successful();
        //Ask to continue or terminate
                cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
				}
		    system ("cls");
                break;
            case 4:
                cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tHow many items do you want to register?\n";
                cin>>NewH;
                NewH = NewH + oldH;

                for(int i = oldH; i < NewH; i++)
                {
                	cout<<"\nItem "<<i+1;
                    household_suplly[i] = register_items();
                }
                oldH = oldH + NewH;

                display_successful();
        //Ask to continue or terminate
                cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
				}
			system ("cls");
                break;
            case 5:
                cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tHow many items do you want to register?\n";
                cin>>NewO;
                NewO = NewO + oldO;

                for(int i = oldO; i < NewO; i++)
                {
                	cout<<"\nItem "<<i+1;
                    others[i] = register_items();
                }
                oldO = oldO + NewO;

                display_successful();
        //Ask to continue or terminate
                cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
                cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
				}

                break;
                case 6:
                	goto main;
                break;

           		default:
        	cout<<"\nYou entered wrong number!\n\tTry again.";
        	goto prev1;
		    }
        }

    	break;

//Make update on price and amount
    case 2:
update:
		cout<<"\n\t-------------------------------------------------\n";
		cout<<"\t---------------------------------------------------\n";
		cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n";
        cin>>choice4;
        switch(choice4)
        {
        	case 1:
        		cout<<"\n\tEnter name of the item: ";
				cin.ignore();
				cin.get(updateName, 30);

				for(int i=0; i<oldF; i++)
				{
					if(stricmp(updateName, food[i].name) == 0)
						{
							cout<<"\n\t-------------------------------------------------\n";
							cout<<"\t---------------------------------------------------\n";
							cout<<"\n\tFor update on: \n\t1. Price.\n\t2. Amount\n\t3. Both\n";
							cin>>choice6;
							if(choice6 == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								food[i].price = newPrice;
							}
							else if(choice6 == 2)
							{
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								food[i].amount = newAmount;
							}
							else
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								food[i].price = newPrice;
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								food[i].amount = newAmount;
							}
						}
				}
			//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto update;	break;
				}
		system ("cls");
        	break;
        	case 2:
        		cout<<"\n\tEnter name of the item\n";
				cin.ignore();
				cin.get(updateName, 30);

				for(int i=0; i<oldB; i++)
				{
					if(stricmp(updateName, beverage[i].name) == 0)
					{
							cout<<"\n\t-------------------------------------------------\n";
							cout<<"\t---------------------------------------------------\n";
							cout<<"\n\tFor update on: \n\t1. Price.\n\t2. Amount\n\t3. Both\n";
							cin>>choice6;
							if(choice6 == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								beverage[i].price = newPrice;
							}
							else if(choice6 == 2)
							{
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								beverage[i].amount = newAmount;
							}
							else
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								beverage[i].price = newPrice;
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								beverage[i].amount = newAmount;
							}
					}
				}
		system ("cls");
			//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
               	cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto update;	break;
				}
		system ("cls");
        	break;
        	case 3:
        		cout<<"\n\tEnter name of the item\n";
				cin.ignore();
				cin.get(updateName, 30);

				for(int i=0; i<oldP; i++)
				{
					if(stricmp(updateName, personalCare[i].name) == 0)
					{
							cout<<"\n\t-------------------------------------------------\n";
							cout<<"\t---------------------------------------------------\n";
							cout<<"\n\tFor update on: \n\t1. Price.\n\t2. Amount\n\t3. Both\n";
							cin>>choice6;
							if(choice6 == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								personalCare[i].price = newPrice;
							}
							else if(choice6 == 2)
							{
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								personalCare[i].amount = newAmount;
							}
							else
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								personalCare[i].price = newPrice;
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								personalCare[i].amount = newAmount;
							}
					}
				}
		system ("cls");
			//ask to continue searching or go back to previous menu
			 	cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto update;	break;
				}
		system ("cls");
        	break;
        	case 4:
        		cout<<"\n\tEnter name of the item\n";
				cin.ignore();
				cin.get(updateName, 30);

				for(int i=0; i<oldH; i++)
				{
					if(stricmp(updateName, household_suplly[i].name) == 0)
					{
							cout<<"\n\t-------------------------------------------------\n";
							cout<<"\t---------------------------------------------------\n";
							cout<<"\n\tFor update on: \n\t1. Price.\n\t2. Amount\n\t3. Both\n";
							cin>>choice6;
							if(choice6 == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								household_suplly[i].price = newPrice;
							}
							else if(choice6 == 2)
							{
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								household_suplly[i].amount = newAmount;
							}
							else
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								household_suplly[i].price = newPrice;
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								household_suplly[i].amount = newAmount;
							}
					}
				}
			//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto update;	break;
				}
		system ("cls");
        	break;
        	case 5:
        		cout<<"\n\tEnter name of the item\n";
				cin.ignore();
				cin.get(updateName, 30);

				for(int i=0; i<oldO; i++)
				{
					if(stricmp(updateName, others[i].name) == 0)
					{
							cout<<"\n\t-------------------------------------------------\n";
							cout<<"\t---------------------------------------------------\n";
							cout<<"\n\tFor update on: \n\t1. Price.\n\t2. Amount\n\t3. Both\n";
							cin>>choice6;
							if(choice6 == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								others[i].price = newPrice;
							}
							else if(choice6 == 2)
							{
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								others[i].amount = newAmount;
							}
							else
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								others[i].price = newPrice;
								cout<<"\nEnter the new Amount: ";
								cin>>newAmount;
								others[i].amount = newAmount;
							}
					}
				}
			//ask to continue searching or go back to previous menu
	   			cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto update;	break;
				}
		system ("cls");
        	break;
        	case 6:
        		goto update;
        	break;
		}
   	system ("cls");
        break;

//Check stack availability
    case 3:
prev2:
		cout<<"\n\t-------------------------------------------------\n";
		cout<<"\t---------------------------------------------------\n";
		cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n";
        cin>>choice5;
        switch(choice5)
        {
        	case 1:
		        cout<<"\n\tEnter name of the item\n";
				cin.ignore();
				cin.get(searchName, 30);

				for(int i=0; i<oldF; i++)
				{
					if(stricmp(searchName, food[i].name) == 0)
						{
							cout<<"Available\n";
							cout<<"Name"<<setw(10)<<"Amount"<<setw(10)<<"Price\n";
							cout<<food[i].name<<setw(10)<<food[i].amount<<setw(10)<<food[i].price<<"\n";
						}
					else
						cout<<"\n\tOut of Stack :(\n";
				}

			//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev2;	break;
				}
		system ("cls");
			break;
			case 2:
				cout<<"\n\tEnter name of the item\n";
				cin.ignore();
				cin.get(searchName, 30);

				for(int i=0; i<oldB; i++)
				{
					if(stricmp(searchName, beverage[i].name) == 0)
					{
						cout<<"Available\n";
						cout<<"Name"<<setw(10)<<"Amount"<<setw(10)<<"Price\n";
						cout<<beverage[i].name<<setw(10)<<beverage[i].amount<<setw(10)<<beverage[i].price<<"\n";
					}
					else
						cout<<"\n\tOut of Stack :(\n";
				}
			//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
               	cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev2;	break;
				}
		system ("cls");
			break;
			case 3:
				cout<<"\n\tEnter name of the item\n";
				cin.ignore();
				cin.get(searchName, 30);

				for(int i=0; i<oldP; i++)
				{
					if(stricmp(searchName, personalCare[i].name) == 0)
					{
						cout<<"Available\n";
						cout<<"Name"<<setw(10)<<"Amount"<<setw(10)<<"Price\n";
						cout<<personalCare[i].name<<setw(10)<<personalCare[i].amount<<setw(10)<<personalCare[i].price<<"\n";
					}
					else
						cout<<"\n\tOut of Stack :(\n";
				}
			//ask to continue searching or go back to previous menu
			 	cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev2;	break;
				}
		system ("cls");
			break;
			case 4:
				cout<<"\n\tEnter name of the item\n";
				cin.ignore();
				cin.get(searchName, 30);

				for(int i=0; i<oldH; i++)
				{
					if(stricmp(searchName, household_suplly[i].name) == 0)
					{
						cout<<"Available\n";
						cout<<"Name"<<setw(10)<<"Amount"<<setw(10)<<"Price\n";
						cout<<household_suplly[i].name<<setw(10)<<household_suplly[i].amount<<setw(10)<<household_suplly[i].cost<<"\n";
					}
					else
						cout<<"\n\tOut of Stack :(\n";
				}
			//ask to continue searching or go back to previous menu
			 	cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev2;	break;
				}
		system ("cls");
			break;
			case 5:
				cout<<"\n\tEnter name of the item\n";
				cin.ignore();
				cin.get(searchName, 30);

				for(int i=0; i<oldO; i++)
				{
					if(stricmp(searchName, others[i].name) == 0)
					{
						cout<<"Available\n";
						cout<<"Name"<<setw(10)<<"Amount"<<setw(10)<<"Price\n";
						cout<<others[i].name<<setw(10)<<others[i].amount<<setw(10)<<others[i].cost<<"\n";
					}
					else
						cout<<"\n\tOut of Stack :(\n";
				}
			//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev2;	break;
				}
		system ("cls");
			break;
			case 6:
				goto prev2;
			break;
		}


        break;

//Selling items
    case 4:
sell:	cout<<"\n\t-------------------------------------------------\n";
		cout<<"\t---------------------------------------------------\n";
		cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n";
        cin>>choice5;
		switch(choice5)
		{
			case 1:
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>NewF;
                S_NewF = S_NewF + S_oldF;

                for(int i = S_oldF; i < S_NewF; i++)
                {
					cout<<"\nItem "<<i+1;
					S_food[i] = sell(food, NewF);
                }
		//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
				}
			break;
			case 2:
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tHow many items do you want to register?\n";
                cin>>S_NewB;
                NewB = S_NewB + S_oldB;

                for(int i = S_oldB; i < S_NewB; i++)
                {
                	cout<<"\nItem "<<i+1;
                    S_beverage[i] = sell(beverage, NewB);
                }
                S_oldB = S_oldB + S_NewB;

		//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
				}
			break;
			case 3:
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tHow many items do you want to register?\n";
                cin>>S_NewP;
                S_NewP = S_NewP + S_oldP;

                for(int i = S_oldP; i < S_NewP; i++)
                {
                	cout<<"\nItem "<<i+1;
                    S_personalCare[i] = sell(personalCare, NewP);
                }
                S_oldP = S_oldP + S_NewP;
		//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
				}
			break;
			case 4:
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tHow many items do you want to register?\n";
                cin>>S_NewH;
                S_NewH = S_NewH + S_oldH;

                for(int i = S_oldH; i < S_NewH; i++)
                {
                	cout<<"\nItem "<<i+1;
                    S_household_suplly[i] = sell(household_suplly, NewH);
                }
                S_oldH = S_oldH + S_NewH;
		//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
				}
			break;
			case 5:
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tHow many items do you want to register?\n";
                cin>>S_NewO;
                S_NewO = S_NewO + S_oldO;

                for(int i = S_oldO; i < S_NewO; i++)
                {
                	cout<<"\nItem "<<i+1;
                    S_others[i] = sell(others, NewO);
                }
                S_oldO = S_oldO + S_NewO;
		//ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
				}
			break;
		}

        break;
    case 5:
    		cout<<"\n\t-------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
   			cout<<"\t------Profit Of Individual Category Items-----\n";

            cout<<"\n\tThe profit gained from FOOD items is: "<< food_profit(food,NewF)<<" birr.\n";
            cout<<"\n\tThe profit gained from BEVERAGE items is: "<<beverage_profit(beverage,NewB)<<" birr.\n";
            cout<<"\n\tThe profit gained from PERSONAL CARE items is: "<<personal_care_profit(personalCare,NewP)<<" birr.\n";
            cout<<"\n\tThe profit gained from HOUSEHOLD SUPPLIEES items is: "<<HH_supply_profit(household_suplly,NewH)<<" birr.\n";
            cout<<"\n\tThe profit gained from UNCATEGORIZED items is: "<<others_profit(others,NewO)<<" birr.\n";

        //ask to continue searching or go back to previous menu
				cout<<"\n\t-------------------------------------------------\n";
				cout<<"\t---------------------------------------------------\n";
				cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
				cin>>choice3;
                switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	             //   case 2: goto profit;	break;
				}
		system ("cls");
		   break;
    case 6:

		cout<<"\n\t-------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
   			cout<<"\t				Statistical Reports\n";
   			cout<<"\n\t-------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";

stat:
			cout<<"\n\t-------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
			cout<<"\t1. List of Available Items.\n\t2. List of Sold out Items.\n\t";
			cin>>choice6;
			switch(choice6)
			{
				case 1:
				    cout<<"\n\t-------------------------------------------------\n";
                    cout<<"\t---------------------------------------------------\n";
                    cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n";
				    cin>>choice1;
				    switch(choice1)
				    {
                   case 1:
                        cout<<"\n\t-------------------------------------------------\n";
                        cout<<"\t---------------------------------------------------\n";
                        cout<<"\n\tAVAILABLE FOOD\n";
                        cout<<"NAME"<<setw(20)<<"COST\tPRICE\tAMOUNT\n";
                        for(int i=0; i<NewF; i++)
                        {
                            cout<<food[i].name<<setw(20)<<food[i].cost<<"\t"<<food[i].price<<"\t"<<food[i].amount<<"\t"<<endl;
                        }
                    break;
                   case 2:
                        cout<<"\n\t-------------------------------------------------\n";
                        cout<<"\t---------------------------------------------------\n";
                        cout<<"\n\tAVAILABLE Beverage\n";
                        cout<<"NAME"<<setw(20)<<"COST\tPRICE\tAMOUNT\n";
                        for(int i=0; i<NewF; i++)
                        {
                            cout<<beverage[i].name<<setw(20)<<beverage[i].cost<<"\t"<<beverage[i].price<<"\t"<<beverage[i].amount<<"\t"<<endl;
                        }
                    break;
                    case 3:
                        cout<<"\n\t-------------------------------------------------\n";
                        cout<<"\t---------------------------------------------------\n";
                        cout<<"\n\tAVAILABLE Personal Care\n";
                        cout<<"NAME"<<setw(20)<<"COST\tPRICE\tAMOUNT\n";
                        for(int i=0; i<NewF; i++)
                        {
                            cout<<personalCare[i].name<<setw(20)<<personalCare[i].cost<<"\t"<<personalCare[i].price<<"\t"<<personalCare[i].amount<<"\t"<<endl;
                        }
                    break;
                    case 4:
                        cout<<"\n\t-------------------------------------------------\n";
                        cout<<"\t---------------------------------------------------\n";
                        cout<<"\n\tAVAILABLE Household supply\n";
                        cout<<"NAME"<<setw(20)<<"COST\tPRICE\tAMOUNT\n";
                        for(int i=0; i<NewF; i++)
                        {
                            cout<<household_suplly[i].name<<setw(20)<<household_suplly[i].cost<<"\t"<<household_suplly[i].price<<"\t"<<household_suplly[i].amount<<"\t"<<endl;
                        }
                    break;
                    case 5:
                        cout<<"\n\t-------------------------------------------------\n";
                        cout<<"\t---------------------------------------------------\n";
                        cout<<"\n\tAVAILABLE Others\n";
                        cout<<"NAME"<<setw(20)<<"COST\tPRICE\tAMOUNT\n";
                        for(int i=0; i<NewF; i++)
                        {
                            cout<<others[i].name<<setw(20)<<others[i].cost<<"\t"<<others[i].price<<"\t"<<others[i].amount<<"\t"<<endl;
                        }
                    break;
				    }

				break;
				case 2:
                    cout<<"\n\t-------------------------------------------------\n";
                    cout<<"\t---------------------------------------------------\n";
				break;
				default:
                    goto main;
			}

			cout<<"\n\t-------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
			cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
			cin>>choice3;
            switch(choice3)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto stat;	break;
				}
        break;

        default:
        cout<<"\nYou entered wrong number!\n\tTry again.";
        goto main;
	    }

    return 0;
}

