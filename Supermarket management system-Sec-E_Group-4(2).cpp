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

struct items{   char name[30];
                float cost;
                float price;
                float amount;
                float profit;
            };

//structure declarartion for sold items

struct sold{	char name[30];
                float amount;
                float price;
                float cost;
                float profit;
			};
			
//Sorting by price with acsending order
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
        cin.get(f.name,20);
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
	char name[30];	int amount;
	s[n];
	
		cout<<"\n\tEnter\nName of the item: ";
		cin.ignore();
		cin.get(name, 30);
		
		for(int i=0; i<n; i++)
		{
			if(stricmp(s[i].name, name) == 0)
			{
				strcpy(sell.name, name);
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
	char pName[20];
	cout<<"Enter the product name"<<endl;
	cin.ignore();
	cin.get(pName,20);
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

//Beginning of main() function
int main()
{
    items food[20], beverage[20], personalCare[20], household_suplly[20], others[20];
    sold S_food[20], S_beverage[20], S_personalCare[20], S_household_suplly[20], S_others[20];
    int oldF, oldB, oldP, oldH, oldO;    int NewF, NewB, NewP, NewH, NewO;
    int S_oldF= 0, S_oldB=0, S_oldP=0, S_oldH=0, S_oldO=0;    int S_NewF, S_NewB, S_NewP, S_NewH, S_NewO;
	int choice;
    char updateName[30], searchName[30];
    float newPrice; int newAmount;
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
			cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n\t6. Previous menu\n\n";
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
 ////////////////////////////////////////////               sort(food, food + oldF, compare);
				display_successful();
			menu();	
                cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
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
                sort(beverage, beverage + oldF, compare);
                display_successful();
            menu();
                cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
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
                sort(personalCare, personalCare + oldF, compare);
                display_successful();
            menu();
            	cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
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
                sort(household_suplly, household_suplly + oldF, compare);
                display_successful();
            menu();
                cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
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
                sort(others, others + oldF, compare);
                display_successful();
            menu();
                cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev1;	break;
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
        	cout<<"\n\tEnter name of the item: ";
			cin.ignore();
			cin.get(updateName, 30);

				for(int i=0; i<oldF; i++)
				{
					if(stricmp(updateName, food[i].name) == 0)
						{
							updateFor();
							cin>>choice;
							if(choice == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								food[i].price = newPrice;
							}	
							else if(choice == 2)
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
								food[i].profit = food[i].price - food[i].cost;
						}
				}
			continueSearching();
				cin>>choice;
                switch(choice)
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
							updateFor();
							cin>>choice;
							if(choice == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								beverage[i].price = newPrice;
							}	
							else if(choice == 2)
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
								beverage[i].profit = beverage[i].price - beverage[i].cost;
					}
				}
system ("cls");
			continueSearching();
               	cin>>choice;
                switch(choice)
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
							updateFor();
							cin>>choice;
							if(choice == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								personalCare[i].price = newPrice;
							}	
							else if(choice == 2)
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
								personalCare[i].profit = personalCare[i].price - personalCare[i].cost;
					}
				}
system ("cls");
			continueSearching();
				cin>>choice;
                switch(choice)
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
							updateFor();
							cin>>choice;
							if(choice == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								household_suplly[i].price = newPrice;
							}	
							else if(choice == 2)
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
								household_suplly[i].profit = household_suplly[i].price - household_suplly[i].cost;
					}
				}
			continueSearching();
				cin>>choice;
                switch(choice)
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
							updateFor();
							cin>>choice;
							if(choice == 1)
							{
								cout<<"\nEnter the new Price: ";
								cin>>newPrice;
								others[i].price = newPrice;
							}	
							else if(choice == 2)
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
								others[i].profit = others[i].price - others[i].cost;
					}
				}
			continueSearching();
				cin>>choice;
                switch(choice)
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
	        cout<<"\n\tEnter name of the item\n";
			cin.ignore();
			cin.get(searchName, 30);

			for(int i=0; i < oldF; i++)
				{
					if(stricmp(searchName, food[i].name) == 0)
						{
							cout<<"Available\n";
							cout<<" --------------------------------------------------------------------------------- \n";
							cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Quantity"<<setw(10)<<"|"<<setw(10)<<"Price"<<setw(10)<<"|"<<setw(10)<<"Profit"<<setw(10)<<"|"<<endl;
							cout<<"|---------------------|-------------------|-------------------|-------------------|\n";
							cout<<"|"<<setw(21)<<food[i].name<<"|"<<setw(19)<<food[i].amount<<"|"<<setw(19)<<food[i].price<<"|"<<setw(19)<<food[i].profit<<"|"<<endl;
							cout<<" ---------------------------------------------------------------------------------\n";
						}	
				}
			menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto prev2;	break;
system ("cls");
				}
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
						cout<<" --------------------------------------------------------------------------------- \n";
							cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Quantity"<<setw(10)<<"|"<<setw(10)<<"Price"<<setw(10)<<"|"<<setw(10)<<"Profit"<<setw(10)<<"|"<<endl;
							cout<<"|---------------------|-------------------|-------------------|-------------------|\n";
							cout<<"|"<<setw(21)<<beverage[i].name<<"|"<<setw(19)<<beverage[i].amount<<"|"<<setw(19)<<beverage[i].price<<"|"<<setw(19)<<beverage[i].profit<<"|"<<endl;
							cout<<" ---------------------------------------------------------------------------------\n";
						}
				}
			menu();
               	cin>>choice;
                switch(choice)
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
						cout<<" --------------------------------------------------------------------------------- \n";
							cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Quantity"<<setw(10)<<"|"<<setw(10)<<"Price"<<setw(10)<<"|"<<setw(10)<<"Profit"<<setw(10)<<"|"<<endl;
							cout<<"|---------------------|-------------------|-------------------|-------------------|\n";
							cout<<"|"<<setw(21)<<personalCare[i].name<<"|"<<setw(19)<<personalCare[i].amount<<"|"<<setw(19)<<personalCare[i].price<<"|"<<setw(19)<<personalCare[i].profit<<"|"<<endl;
							cout<<" ---------------------------------------------------------------------------------\n";
					}
				}
			menu();
				cin>>choice;
                switch(choice)
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
						cout<<" --------------------------------------------------------------------------------- \n";
							cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Quantity"<<setw(10)<<"|"<<setw(10)<<"Price"<<setw(10)<<"|"<<setw(10)<<"Profit"<<setw(10)<<"|"<<endl;
							cout<<"|---------------------|-------------------|-------------------|-------------------|\n";
							cout<<"|"<<setw(21)<<household_suplly[i].name<<"|"<<setw(19)<<household_suplly[i].amount<<"|"<<setw(19)<<household_suplly[i].price<<"|"<<setw(19)<<household_suplly[i].profit<<"|"<<endl;
							cout<<" ---------------------------------------------------------------------------------\n";
					}
				}
			menu();
				cin>>choice;
                switch(choice)
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
						cout<<" --------------------------------------------------------------------------------- \n";
							cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Quantity"<<setw(10)<<"|"<<setw(10)<<"Price"<<setw(10)<<"|"<<setw(10)<<"Profit"<<setw(10)<<"|"<<endl;
							cout<<"|---------------------|-------------------|-------------------|-------------------|\n";
							cout<<"|"<<setw(21)<<others[i].name<<"|"<<setw(19)<<others[i].amount<<"|"<<setw(19)<<others[i].price<<"|"<<setw(19)<<others[i].profit<<"|"<<endl;
							cout<<" ---------------------------------------------------------------------------------\n";
					}
				}
			menu();
				cin>>choice;
                switch(choice)
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
			menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
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
                S_oldB = S_oldB + S_NewB;	
		menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
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
                S_oldP = S_oldP + S_NewP;
		menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
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
                S_oldH = S_oldH + S_NewH;
		menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
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
                S_oldO = S_oldO + S_NewO;
		menu();
				cin>>choice;
                switch(choice)
	            {
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	                case 2: goto sell;	break;
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
				    case 0: return 0;	break;
	                case 1: goto main;	break;
	            	//case 2: goto profit;	break;
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
                cout<<"\n	-------------------------------------------------\n";
                cout<<"		AVAILABLE ITEMS UNDER FOOD CATEGORY\n			Sorted with Price\n";
				cout<<"	-------------------------------------------------\n\n";
                cout<<" -----------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<food[i].name<<"|"<<setw(19)<<food[i].cost<<"|"<<setw(19)<<food[i].price<<"|"<<setw(19)<<food[i].profit * food[i].amount<<"|"<<setw(19)<<food[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }
				   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(food,NewF)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
					}
                    break;
		    case 2:
                cout<<"\n	-------------------------------------------------\n";
                cout<<"		AVAILABLE ITEMS UNDER BEVERAGE CATEGORY\n			Sorted with Price\n";
                cout<<"	-------------------------------------------------\n\n";
				cout<<" -----------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<beverage[i].name<<"|"<<setw(19)<<beverage[i].cost<<"|"<<setw(19)<<beverage[i].price<<"|"<<setw(19)<<beverage[i].profit * beverage[i].amount<<"|"<<setw(19)<<beverage[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }	
				   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(beverage,NewB)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";
            menu();		
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
					}
                    break;
            case 3:
                cout<<"\n	-------------------------------------------------\n";
                cout<<" 	AVAILABLE ITEMS UNDER PERSONAL CARE CATEGORY\n			Sorted with Price\n";
                cout<<"	-------------------------------------------------\n\n";
                cout<<" -----------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<personalCare[i].name<<"|"<<setw(19)<<personalCare[i].cost<<"|"<<setw(19)<<personalCare[i].price<<"|"<<setw(19)<<personalCare[i].profit * personalCare[i].amount<<"|"<<setw(19)<<personalCare[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }
				   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(personalCare,NewP)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";
			menu();	
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
					}
                    break;
            case 4:
                cout<<"\n	-------------------------------------------------\n";
                cout<<"		AVAILABLE ITEMS UNDER HOUSEHOLD SUPPLIES CATEGORY\n			Sorted with Price\n";
                cout<<"	-------------------------------------------------\n\n";
                cout<<" -----------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<household_suplly[i].name<<"|"<<setw(19)<<household_suplly[i].cost<<"|"<<setw(19)<<household_suplly[i].price<<"|"<<setw(19)<<household_suplly[i].profit * household_suplly[i].amount<<"|"<<setw(19)<<household_suplly[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }
				   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(household_suplly,NewH)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";
			menu();	
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
					}
                    break;
            case 5:
                cout<<"\n	-------------------------------------------------\n";
                cout<<"		AVAILABLE ITEMS UNDER OTHERS CATEGORY\n			Sorted with Price\n";
                cout<<"	-------------------------------------------------\n\n";
               	cout<<" -----------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<others[i].name<<"|"<<setw(19)<<others[i].cost<<"|"<<setw(19)<<others[i].price<<"|"<<setw(19)<<others[i].profit * others[i].amount<<"|"<<setw(19)<<others[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }
				   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(others,NewO)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";
			menu();	
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
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
				cout<<"\n	-------------------------------------------------\n";
                cout<<"		SOLD ITEMS UNDER FOOD CATEGORY\n";
                cout<<"	-------------------------------------------------\n\n";
               	cout<<" -----------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<S_NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<S_food[i].name<<"|"<<setw(19)<<S_food[i].cost<<"|"<<setw(19)<<S_food[i].price<<"|"<<setw(19)<<S_food[i].profit * S_food[i].amount<<"|"<<setw(19)<<S_food[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }
				   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(S_food, S_NewF)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
					}
                    break;
            case 2:
                cout<<"\n	-------------------------------------------------\n";
                cout<<"		SOLD ITEMS UNDER BEVERAGE CATEGORY\n";
                cout<<"	-------------------------------------------------\n\n";
               	cout<<" ------------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<S_NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<S_beverage[i].name<<"|"<<setw(19)<<S_beverage[i].cost<<"|"<<setw(19)<<S_beverage[i].price<<"|"<<setw(19)<<S_beverage[i].profit * S_beverage[i].amount<<"|"<<setw(19)<<S_beverage[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }
				   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(S_beverage, S_NewB)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
					}
                    break;
            case 3:
                cout<<"\n	-------------------------------------------------\n";
                cout<<"		SOLD ITEMS UNDER PERSONAL CARE CATEGORY\n";
                cout<<"	-------------------------------------------------\n\n";
               	cout<<" -----------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<S_NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<S_personalCare[i].name<<"|"<<setw(19)<<S_personalCare[i].cost<<"|"<<setw(19)<<S_personalCare[i].price<<"|"<<setw(19)<<S_personalCare[i].profit * S_personalCare[i].amount<<"|"<<setw(19)<<S_personalCare[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }
				   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(S_personalCare, S_NewP)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
					}
                    break;
            case 4:
                cout<<"\n	-------------------------------------------------\n";
                cout<<"		SOLD ITEMS UNDER HOUSEHOLD SUPPLIES CATEGORY\n";
                cout<<"	-------------------------------------------------\n\n";
               	cout<<" -----------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<S_NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<S_household_suplly[i].name<<"|"<<setw(19)<<S_household_suplly[i].cost<<"|"<<setw(19)<<S_household_suplly[i].price<<"|"<<setw(19)<<S_household_suplly[i].profit * S_household_suplly[i].amount<<"|"<<setw(19)<<S_household_suplly[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }
						cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(S_household_suplly, S_NewH)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";			   
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
					}
                    break;
            case 5:
                cout<<"\n	-------------------------------------------------\n";
                cout<<"		SOLD ITEMS UNDER OTHERS CATEGORY\n";
                cout<<"	-------------------------------------------------\n\n";
               cout<<" -----------------------------------------------------------------------------------------------------\n";
                cout<<"|"<<setw(10)<<"Name"<<setw(12)<<"|"<<setw(10)<<"Cost(birr)"<<setw(10)<<"|"<<setw(10)<<"Price(birr)"<<setw(9)<<"|"<<setw(10)<<"Profit(birr)"<<setw(8)<<"|"<<setw(5)<<"Quantity"<<setw(12)<<"|"<<endl;
                cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   for(int i=0; i<S_NewF; i++)
                   {
                       	cout<<"|"<<setw(21)<<S_others[i].name<<"|"<<setw(19)<<S_others[i].cost<<"|"<<setw(19)<<S_others[i].price<<"|"<<setw(19)<<S_others[i].profit * S_others[i].amount<<"|"<<setw(19)<<S_others[i].amount<<"|"<<endl;
                   		cout<<"|---------------------|-------------------|-------------------|-------------------|-------------------|\n";
				   }
				   		cout<<"|"<<setw(10)<<"Total"<<setw(12)<<"|"<<setw(40)<<"|"<<setw(19)<<profit(S_others, S_NewO)<<"|"<<endl;
				   		cout<<" -----------------------------------------------------------------------------------------------------\n";
			menu();
				cin>>choice;
	            switch(choice)
		            {
					    case 0: return 0;	break;
		                case 1: goto main;	break;
		                case 2: goto stat;	break;
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
