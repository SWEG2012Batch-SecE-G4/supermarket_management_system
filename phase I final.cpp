/*This program is intended to SUPERMARKET MANAGEMENT SYSTEM.
* It mainly helps to register purchased items, solled out items, check stock availability, modification on price and quantity
* profits, calculate discounts.
*/
using namespace std;
#include<iostream>
#include<string.h>
#include<cstdlib>
#include<iomanip>
#include<algorithm>

//structure declaration for items categories

struct items{   string name;
                float cost;
                float price;
                float amount;
                float profit;
            };

//structure declaration for sold items

struct sold{	string name;
                float amount;
                float price;
                float cost;
                float profit;
			};

//Sorting by price with ascending order
bool compare( items a, items b)
{
	if(a.price < b.price)
		return 1;
	else
		return 0;
}

//Function declarations and definitions
//Function to register newly purchased items

items register_items()
{
    items f;

		cout<<"\nEnter NAME: ";
		cin.ignore();
        getline(cin, f.name);
        cout<<"Enter COST: ";
        cin>>f.cost;
        cout<<"Enter PRICE: ";
        cin>>f.price;
        cout<<"Enter AMOUNT: ";
        cin>>f.amount;
		f.profit = f.price - f.cost;
    return f;
}

//display successful
void display_successful()
{
	cout<<"\n\t-----------------------------------------\n";
	cout<<"\t-----------------------------------------\n";
	cout<<" 		Successfully Registered!\n";
}

//Ask to continue or terminate
void menu()
{
	cout<<"\n\t-------------------------------------------------\n";
	cout<<"\t---------------------------------------------------\n";
	cout<<"\n\t1. Main menu \n\t2. Previous menu \n\t0. Exit\n\t\t ";
}

//Ask how many items the user want to register
void R_howMany()
{
	cout<<"\n\t---------------------------------------------------\n";
	cout<<"\t---------------------------------------------------\n";
    cout<<"\n\tEnter number of items to be registered: ";
}

//Ask how many items the user want to sell
void S_howMany()
{
	cout<<"\n\t---------------------------------------------------\n";
	cout<<"\t---------------------------------------------------\n";
	cout<<"\n\tEnter number of items to be sold: ";
}

//Ask to continue searching
void continueSearching()
{
	cout<<"\n\t---------------------------------------------------\n";
	cout<<"\t---------------------------------------------------\n";
	cout<<"\n\tMain menu '1'\n\tPrevious menu '2'\n\tExit '0' : ";
}

//Ask what update is wanted
void updateFor()
{
	cout<<"\n\t-------------------------------------------------\n";
	cout<<"\t---------------------------------------------------\n";
	cout<<"\n\tFor update on: \n\t1. Price.\n\t2. Amount\n\t3. Both\n";
}

//Function to calculate profit of individual category items
//Profit of available items
float profit(items f[], int n){
	float profit=0;
		for(int i = 0; i < n; i++)
                {
					profit+=(f[i].amount*f[i].price-f[i].amount*f[i].cost);

                }

	return profit;
}

//Profit from sold out items
float profit(sold f[], int n){
	float profit=0;
		for(int i = 0; i < n; i++)
                {
					profit+=(f[i].amount*f[i].price-f[i].amount*f[i].cost);

                }

	return profit;
}

//total profit from all products
float total_profit(items f[],items b[],items p[],items h[],items o[],int x,int j,int k,int l,int m){
	float tot_profit, profit1=0, profit2=0, profit3=0, profit4=0, profit5=0;

	for(int i = 0; i < x; i++)
                {
                	profit1+=(f[i].amount*f[i].price-f[i].amount*f[i].cost);}
   for(int i = 0; i < j; i++) {
                	profit2+=(b[i].amount*b[i].price-b[i].amount*b[i].cost);}

    for(int i = 0; i < k; i++){
					profit3+=(p[i].amount*p[i].price-p[i].amount*p[i].cost);}
	for(int i = 0; i < l; i++){
                	profit4+=(h[i].amount*h[i].price-h[i].amount*h[i].cost);}
    for(int i = 0; i < m; i++){
                	profit5+=(o[i].amount*o[i].price-o[i].amount*o[i].cost);
                }
        tot_profit=profit1 + profit2 + profit3 + profit4 + profit5;
        return tot_profit;
}

//Function for selling

sold sell(items s[], int n)
{
	sold sell;
	string name;	int amount;
	s[n];

		cout<<"\n\tEnter\nName of the item: ";
		cin.ignore();
		getline(cin, name);

		for(int i=0; i<n; i++)
		{
			int res = name.compare(s[i].name);
			if(res == 0)
			{
				sell.name = name;
				cout<<"\nQuantity: ";
				cin>>amount;
				if(amount <= s[i].amount)
				{
					cout<<"\nAvailable\n";
					sell.amount = amount;
					s[i].amount = s[i].amount - amount;
					sell.price = amount * s[i].price,
					sell.cost = s[i].cost;
					sell.profit = amount * (s[i].profit);
					cout<<"\n\tPrice: "<<sell.price<<" birr.\n";
				}
			}
		}
	return sell;
}

//rank products in each category
void rankof(float prof[],int n)
{
	float R[n]={};
	for(int i=0;i<n;i++){
		int r=1,s=1;
		for(int j=0;j<n;j++){
			if(j!=i && prof[j]<prof[i])
			r+=1;
			if(j!=1 && prof[j]==prof[i])
			s+=1;
		}
		R[i]=r+(float)(s-1)/(float)2;
	}
	cout<<"PROFIT"<<"___________________"<<"Rank"<<endl;
	for(int i=0;i<n;i++)
	cout<<prof[i]<<"____________________"<<R[i]<<endl;
}

//Display the ratings of items(0-5 stars)
void dispStar()
{
	int no,avg;
	cout<<"How many customers give rating for the product?"<<endl;
	cin>>no;
	cout<<"What is the customer average response out of 100"<<endl;
	for(int k=0;k<no;k++){
     cin>>avg;
     avg++;} int indavg=avg/no;
     int stars=avg/20;
     if(stars==5) cout<<"Product Rate "<<"*****"<<" VERY HIGH"<<endl;
      if(stars==4) cout<<"Product Rate "<<"****"<<" HIGH"<<endl;
       if(stars==3) cout<<"Product Rate "<<"***"<<" MEDIUM"<<endl;
        if(stars==2) cout<<"Product Rate "<<"**"<<" LOW"<<endl;
         if(stars==1) cout<<"Product Rate "<<"*"<<" VERY LOW"<<endl;
}

//A function for items rating
void rate(){
	string pName;
	cout<<"Enter the product name"<<endl;
	cin.ignore();
	getline(cin, pName);
	cout<<pName<<endl;
	dispStar();

}

//Calculates the discount by taking the price and category
void discount()
{

	int rp,sp,cc,discount;
	cout<<"Enter price ";
	cin>>rp;
	cout<<"Enter category code ";
	cin>>cc;

	switch(cc){
		case '310':
			discount=(10*rp)/100;
			sp=rp-discount;
			cout<<"sale price= "<<sp<<endl;
			cout<<"discounted price = "<<discount<<endl;
			break;

	   	case '210':
		   	discount=(12*rp)/100;
		   	sp=rp-discount;
		   	cout<<"sale price= "<<sp<<endl;
		   	cout<<"discounted price= "<<discount<<endl;
	   	break;
	   	default:
	   		discount=(5*rp)/100;
	   		sp=rp-discount;
	   		cout<<"sale price= "<<sp<<endl;
	   		cout<<"discounted price= "<<discount<<endl;
	}
}

//Individual profit for food category
float *food_profind(items f[], int n){
	    float *prof1= &prof1[0];
		for(int i = 0; i < n; i++)
                {
					prof1[i]=(f[i].amount*f[i].price-f[i].amount*f[i].cost);
                	}

	return prof1;
}

//Display statistical report
void report(items x[], int n)
{
	x[n];
	cout<<"\n	-------------------------------------------------\n";
    cout<<"		AVAILABLE ITEMS\n			Sorted with Name\n";
	cout<<"	-------------------------------------------------\n\n";
    cout<<" -----------------------------------------------------------------------------------------------------\n";
    cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
    cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
	   for(int i=0; i < n; i++)
       {
           	cout<<"|"<<setw(21)<<x[i].name<<"|"<<setw(19)<<x[i].cost<<"|"<<setw(19)<<x[i].price<<"|"<<setw(19)<<x[i].profit * x[i].amount<<"|"<<setw(19)<<x[i].amount<<"|"<<endl;
       		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
	   }
	   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(x, n)<<"|"<<endl;
	   		cout<<" -----------------------------------------------------------------------------------------------------\n";
}

void report(sold x[], int n)
{
	x[n];
	cout<<"\n	-------------------------------------------------\n";
    cout<<"		SOLED ITEMS\n			Sorted with Name\n";
	cout<<"	-------------------------------------------------\n\n";
    cout<<" -----------------------------------------------------------------------------------------------------\n";
    cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
    cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
	   for(int i=0; i < n; i++)
       {
           	cout<<"|"<<setw(21)<<x[i].name<<"|"<<setw(19)<<x[i].cost<<"|"<<setw(19)<<x[i].price<<"|"<<setw(19)<<x[i].profit * x[i].amount<<"|"<<setw(19)<<x[i].amount<<"|"<<endl;
       		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
	   }
	   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(x, n)<<"|"<<endl;
	   		cout<<" -----------------------------------------------------------------------------------------------------\n";
}

//Update items information
items modify(items h[], int n)
{
	h[n];
	float newPrice; int newAmount, choice;
	string updateName;
		cout<<"\n\tEnter name of the item: ";
		cin.ignore();
		getline(cin, updateName);

			for(int i=0; i < n; i++)
			{
				int res = updateName.compare(h[i].name);
				if(res == 0)
					{
						updateFor();
						cin>>choice;
						if(choice == 1)
						{
							cout<<"\nEnter the new Price: ";
							cin>>newPrice;
							h[i].price = newPrice;
						}
						else if(choice == 2)
						{
							cout<<"\nEnter the new Amount: ";
							cin>>newAmount;
							h[i].amount = newAmount;
						}
						else
						{
							cout<<"\nEnter the new Price: ";
							cin>>newPrice;
							h[i].price = newPrice;
							cout<<"\nEnter the new Amount: ";
							cin>>newAmount;
							h[i].amount = newAmount;
						}
							h[i].profit = h[i].price - h[i].cost;
					}
                return h[i];
			}
}

//Ckecking stock availability
void checkStock(items h[], int n)
{
	h[n];
	string searchName;
		cout<<"\n\tEnter name of the item\n";
		cin.ignore();
		getline(cin, searchName);

		for(int i=0; i < n; i++)
			{
				int res = searchName.compare(h[i].name);
				if(res == 0)
					{
						cout<<"Available\n";
						cout<<" --------------------------------------------------------------------------------- \n";
						cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Quantity"<<setw(10)<<"|"<<setw(10)<<"Price"<<setw(10)<<"|"<<setw(10)<<"Profit"<<setw(10)<<"|"<<endl;
						cout<<"|---------------------|-------------------|-------------------|-------------------|\n";
						cout<<"|"<<setw(21)<<h[i].name<<"|"<<setw(19)<<h[i].amount<<"|"<<setw(19)<<h[i].price<<"|"<<setw(19)<<h[i].profit<<"|"<<endl;
						cout<<" ---------------------------------------------------------------------------------\n";
					}
			}
}

//Beginning of main() function
int main()
{
    items food[20], beverage[20], personalCare[20], household_suplly[20], others[20];
    sold S_food[20], S_beverage[20], S_personalCare[20], S_household_suplly[20], S_others[20];
    int oldF, oldB, oldP, oldH, oldO;    int NewF, NewB, NewP, NewH, NewO;
    int S_oldF= 0, S_oldB=0, S_oldP=0, S_oldH=0, S_oldO=0;    int S_NewF, S_NewB, S_NewP, S_NewH, S_NewO;
	int choice;
    char searchName[30];
    int New1,New2,New3,New4,New5;

			cout<<"\n\t---------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
			cout<<"\t	WELCOME TO SUPERMARKET MANAGEMENT SYSTEM!\n";
main:		cout<<"\t---------------------------------------------------\n";
			cout<<"\t\tMain menu\n";
	     	cout<<"\t\t1. Register new items.\n\t\t2. Update Price and Available Amount.\n\t\t3. Checking stack availability.";
		    cout<<"\n\t\t4. Sales.\n\t\t5. Profit.\n\t\t6.Item ranking and rating.\n\t\t7.Discount\n\t\t8.Statistical report.\n";
     	 	cout<<"\t-----------------------------------------------------\n";
			cout<<"\t-----------------------------------------------------\n";
			cin>>choice;

system ("cls"); //clears screen

    switch(choice)	//main operations
	{
//Register items
    case 1:{
prev1:  	cout<<"\n\t---------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
			cout<<"\n\tChoose Item Category\n\t1. Food\n\t2,. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n\n";
            cout<<"\n\t---------------------------------------------------\n";
			cout<<"\t---------------------------------------------------\n";
			cin>>choice;
system ("cls");

    	switch(choice)
        {
        case 1:
        	R_howMany();
            cin>>NewF;
            NewF = NewF + oldF;

                for(int i = oldF; i < NewF; i++)
                {
					cout<<"\nItem "<<i+1;
					food[i] = register_items();
                }
                oldF = oldF + NewF;
				sort(food, food + NewF, compare);
				display_successful();
			menu();
                cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev1;	break;
system ("cls");
				}
				break;
        case 2:
            R_howMany();
            cin>>NewB;
            NewB = NewB + oldB;

                for(int i = oldB; i < NewB; i++)
                {
                	cout<<"\nItem "<<i+1;
                    beverage[i] = register_items();
                }
                oldB = oldB + NewB;
                sort(beverage, beverage + NewB, compare);
                display_successful();
            menu();
                cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev1;	break;
				}
system ("cls");
                break;
        case 3:
            R_howMany();
            cin>>NewP;
            NewP = NewP + oldP;

                for(int i = oldP; i < NewP; i++)
                {
                	cout<<"\nItem "<<i+1;
                    personalCare[i] = register_items();
                }
                oldP = oldP + NewP;
                sort(personalCare, personalCare + NewP, compare);
                display_successful();
            menu();
            	cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev1;	break;
				}
system ("cls");
                break;
        case 4:
            R_howMany();
           	cin>>NewH;
    		NewH = NewH + oldH;

                for(int i = oldH; i < NewH; i++)
                {
                	cout<<"\nItem "<<i+1;
                    household_suplly[i] = register_items();
                }
                oldH = oldH + NewH;
                sort(household_suplly, household_suplly + NewH, compare);
                display_successful();
            menu();
                cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev1;	break;
				}
system ("cls");
                break;
        case 5:
        	R_howMany();
        	cin>>NewO;
            NewO = NewO + oldO;

                for(int i = oldO; i < NewO; i++)
                {
                	cout<<"\nItem "<<i+1;
                    others[i] = register_items();
                }
                oldO = oldO + NewO;
                sort(others, others + NewO, compare);
                display_successful();
            menu();
                cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev1;	break;
				}
system ("cls");
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
		cout<<"\n\t---------------------------------------------------\n";
		cout<<"\t---------------------------------------------------\n";
		cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
			modify(food, NewF);
			continueSearching();
				cin>>choice;
system ("cls");				
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto update;	break;
				}
        	break;
        case 2:
			modify(beverage, NewB);
			continueSearching();
				cin>>choice;
system ("cls");				
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto update;	break;
				}
        	break;
       	case 3:
			modify(personalCare, NewP);
			continueSearching();
				cin>>choice;
system ("cls");				
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto update;	break;
				}
system ("cls");
        	break;
        case 4:
			modify(household_suplly, NewH);
			continueSearching();
				cin>>choice;
system ("cls");			
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto update;	break;
				}
        	break;
       	case 5:
			modify(others, NewO);
			continueSearching();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto update;	break;
				}
system ("cls");
        	break;
        case 6:
        		goto update;
        	break;
		}
system ("cls");
        break;

//Check stock availability
    case 3:
prev2:
		cout<<"\n\t---------------------------------------------------\n";
		cout<<"\t---------------------------------------------------\n";
		cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
////////////////		//////////////////////////////		////////////////////////////		///////////////////////////	  
			checkStock(food, NewF);      
			menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev2;	break;
system ("cls");
				}
			break;
		case 2:
			checkStock(beverage, NewB);
			menu();
               	cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev2;	break;
				}
		system ("cls");
			break;
		case 3:
			checkStock(personalCare, NewP);
			menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev2;	break;
				}
system ("cls");
			break;
		case 4:
			checkStock(household_suplly, NewH);
			menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev2;	break;
				}
system ("cls");
			break;
		case 5:
			checkStock(others, NewO);
			menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto prev2;	break;
				}
system ("cls");
			break;
		case 6:
				goto prev2;
			break;
		}


        break;

//Selling
	case 4:
sell:	cout<<"\n\t---------------------------------------------------\n";
		cout<<"\t---------------------------------------------------\n";
		cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n";
        cin>>choice;
		switch(choice)
		{
		case 1:
			S_howMany();
        	cin>>S_NewF;
            S_NewF = S_NewF + S_oldF;

                for(int i = S_oldF; i < S_NewF; i++)
                {
					cout<<"\nItem "<<i+1;
					S_food[i] = sell(food, NewF);
                }
                S_oldF += S_NewF;
			menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto sell;	break;
				}
			break;
		case 2:
				S_howMany();
                cin>>S_NewB;
                NewB = S_NewB + S_oldB;

                for(int i = S_oldB; i < S_NewB; i++)
                {
                	cout<<"\nItem "<<i+1;
                    S_beverage[i] = sell(beverage, NewB);
                }
                S_oldB += S_NewB;
		menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto sell;	break;
				}
			break;
		case 3:
				S_howMany();
                cin>>S_NewP;
                S_NewP = S_NewP + S_oldP;

                for(int i = S_oldP; i < S_NewP; i++)
                {
                	cout<<"\nItem "<<i+1;
                    S_personalCare[i] = sell(personalCare, NewP);
                }
                S_oldP += S_NewP;
		menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto sell;	break;
				}
			break;
		case 4:
				S_howMany();
                cin>>S_NewH;
                S_NewH = S_NewH + S_oldH;

                for(int i = S_oldH; i < S_NewH; i++)
                {
                	cout<<"\nItem "<<i+1;
                    S_household_suplly[i] = sell(household_suplly, NewH);
                }
                S_oldH += S_NewH;
		menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto sell;	break;
				}
			break;
		case 5:
				S_howMany();
                cin>>S_NewO;
                S_NewO = S_NewO + S_oldO;

                for(int i = S_oldO; i < S_NewO; i++)
                {
                	cout<<"\nItem "<<i+1;
                    S_others[i] = sell(others, NewO);
                }
                S_oldO += S_NewO;
		menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto sell;	break;
				}
			break;
		}

        break;
//profit
	case 5:
    	cout<<"\n\t---------------------------------------------------\n";
		cout<<"\t---------------------------------------------------\n";
   		cout<<"\t------Profit Of Individual Category Items-----\n";
        cout<<"\n\tThe profit gained from FOOD items is: "<<profit(food,NewF) + profit(S_food, S_NewF)<<" birr.\n";
		cout<<"\n\tThe profit gained from BEVERAGE items is: "<<profit(beverage,NewB) + profit(S_beverage, S_NewB)<<" birr.\n";
     	cout<<"\n\tThe profit gained from PERSONAL CARE items is: "<<profit(personalCare,NewP) + profit(S_personalCare, S_NewP)<<" birr.\n";
       	cout<<"\n\tThe profit gained from HOUSEHOLD SUPPLIEES items is: "<<profit(household_suplly,NewH) + profit(S_household_suplly, S_NewH)<<" birr.\n";
        cout<<"\n\tThe profit gained from UNCATEGORIZED items is: "<<profit(others,NewO) + profit(S_others, S_NewO)<<" birr.\n\n";
		cout<<"\n\tThe total profit gain from all items is: "<<total_profit(food,beverage,personalCare,household_suplly,others,New1,New2,New3,New4,New5)<<" birr.\n";

        menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;	case 1: goto main;	break;	//case 2: goto profit;	break;
				}
		system ("cls");
		   break;
//Items ranking
	case 6:
    	rankof(food_profind(food,NewF),NewF);
        rate();
         	break;
//Discount
	case 7:
    	cout<<"\n\tCategory Code\t"<<"\nFOOD CATEGORY--------------------------110\n\t"<<
			"\n\tBEVERAGE CATEGORY------------------210\n\t"<<"\n\tPRESONAL CARE CATEGORY--------------310\n\t"<<
			"\n\tHOUSEHOLD CATEGORY-----------------410\n\t"<<"\n\tOTHERS--------------------------510\n\t"<<endl;
    	discount();
    	break;
//Display statistical reports
	case 8:
		/////////////////////////////////////////////////
			////////////////////////
			////////////////	sort(food, food + oldF, compare);
		///////////////////////////////////////////////
		cout<<"\n	-------------------------------------------------\n";
   		cout<<"		Statistical Reports\n";
   		cout<<"	-------------------------------------------------\n\n";
system ("cls");
stat:
		cout<<"\t---------------------------------------------------\n";
		cout<<"\t1. List of Available Items.\n\t2. List of Sold out Items.\n\t";
		cin>>choice;
		switch(choice)
		{
		case 1:
		    cout<<"\n\t-------------------------------------------------\n";
            cout<<"\t---------------------------------------------------\n";
            cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n";
			cin>>choice;
			switch(choice)
			{
            case 1:
				report(food, NewF);
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
                    break;
		    case 2:
                report(beverage, NewB);
            menu();
				cin>>choice;
	            switch(choice)
		            {
						case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
                    break;
            case 3:
                report(personalCare, NewP);
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
                    break;
            case 4:
                report(household_suplly, NewH);
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
                    break;
            case 5:
                report(others, NewO);
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
                    break;
			}

				break;
		case 2:
            cout<<"\n\t-------------------------------------------------\n";
            cout<<"\t---------------------------------------------------\n";
            cout<<"\n\tChoose Item Category\n\t1. Sold Food\n\t2. Sold Beverage\n\t3. Sold Personal Care\n\t4. Sold Household supply\n\t5. Sold Others\n\t6. Previous menu\n";
			cin>>choice;
			switch(choice)
			{
            case 1:
				report(S_food, S_NewF);
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
                    break;
            case 2:
                report(S_beverage, S_NewB);
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
                    break;
            case 3:
                report(S_personalCare, S_NewP);
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
                    break;
            case 4:
                report(S_household_suplly, S_NewH);
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
                    break;
            case 5:
                report(S_others, S_NewO);
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;	case 1: goto main;	break;	case 2: goto stat;	break;
					}
				break;
			default:
			    goto main;
			}
    	}
    	default:
	        cout<<"\nYou entered wrong number!\n\tTry again.";
	        goto main;
	}

    return 0;
}
