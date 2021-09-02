using namespace std;
#include <iostream>
#include <string.h>
#include <cstdlib> //this enables to clear screen and pause it
int n;
 int old= 0;    int New;
//structure declaration for items categories

struct items{   char name[20];
                float cost;
                float price;
                float amount;
                
            };
//structure declaration for profit catagories
struct profit{
	float cost;
	float price;
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
float food_profit(profit f[]){
	float f_price=0, f_cost=0, f_profit;
	for(int i=old; i<n; i++){
		f_price+=f[i].price;
	}
	for(int i=old; i<n; i++){
		f_cost+=f[i].cost;
	}
	f_profit=f_price-f_cost;
	return f_profit;
}
float beverage_profit(profit b[]){
	float b_price=0, b_cost=0, b_profit;
	for(int i=old; i<n; i++){
		b_price+=b[i].price;
	}
	for(int i=old; i<n; i++){
		b_cost+=b[i].cost;
	}
	b_profit=b_price-b_cost;
	return b_profit;
	
}
float pCare_profit(profit p[]){
	float p_price=0, p_cost=0, p_profit;
	for(int i=old; i<n; i++){
		p_price+=p[i].price;
	}
	for(int i=old; i<n; i++){
		p_cost+=p[i].cost;
	}
	p_profit=p_price-p_cost;
	return p_profit;
}
float HHsupply_profit(profit h[]){
	float h_price=0, h_cost=0, h_profit;
	for(int i=old; i<n; i++){
		h_price+=h[i].price;
	}
	for(int i=old; i<n; i++){
		h_cost+=h[i].cost;
	}
	h_profit=h_price-h_cost;
	return h_profit;
}
float others_profit(profit O[]){
	float O_price=0, O_cost=0, O_profit;
	for(int i=old; i<n; i++){
		O_price+=O[i].price;
	}
	for(int i=old; i<n; i++){
		O_cost+=O[i].cost;
	}
	O_profit=O_price-O_cost;
	return O_profit;
	
}
float total_profit(){
	
	
}

int main()
{
    items food[20], beverage[20], personalCare[20], household_supply[20], Others[20];
    profit f[20], b[20], p[20], h[20], O[20];
	int old= 0;    int New;
	int choice1, choice2, choice3;

     cout<<"\n\t1. Register new items.\n\t2. Sell items.\n\t3. Checking stack availability.\n\t4. Total no. of sales.\n\t5. Profit.\n\t6. statistical report.\n";
     cin>>choice1;
     
     system ("cls"); //clears screen
        switch(choice1){
    case 1:
        {
            cout<<"\n\tChoose Item Category\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n";
            cin>>choice2;
            system ("cls"); //clears screen
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
                    household_supply[i] = register_H();
                }
                break;
            case 5:
                cout<<"\n\tHow many items do you want to register?\n";
                cin>>New;
                for(int i = old; i < New; i++)
                {
                    Others[i] = register_O();
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
    	{
    	cout<<"\n\t choose which profit you want to know\n\t1. Individual catagory items profit\n\t2. Total profit\n";
    	cin>>choice2;
    	system("cls"); //clears screen
    	switch(choice2)
    	{
    		case 1:
    			cout<<"\n\twhich item catagory's profit you want to know?\n\t1. Food\n\t2. Beverage\n\t3. Personal Care\n\t4. Household supply\n\t5. Others\n";
    			cin>>choice3;
    			system("cls"); //clears screen
    			switch(choice3)
    			{
    				case 1:
    					cout<<"how many items profit do you want to calculate?\n";
    					cin>>n;
    					cout<<"enter the cost of each food items\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>f[i].cost;
							}
						cout<<"enter the price of each food items\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>f[i].price;
    						}
    					cout<<"the profit gain from food items is: "<<food_profit(f);
    					break;
    				case 2:
    					cout<<"how many items profit do you want to calculate?\n";
    					cin>>n;
    					cout<<"enter the cost of each beverage items\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>b[i].cost;
							}
						cout<<"enter the price of each beverage items\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>b[i].price;
    						}
    					cout<<"the profit gain from beverage items is: "<<beverage_profit(b);
    					break;
    				case 3:
    					cout<<"how many items profit do you want to calculate?\n";
    					cin>>n;
    					cout<<"enter the cost of each personal care items\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>p[i].cost;
							}
						cout<<"enter the price of each personal care items\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>p[i].price;
    						}
    					cout<<"the profit gain from personal care items is: "<<pCare_profit(p);
    					break;
    				case 4:
    					cout<<"how many items profit do you want to calculate?\n";
    					cin>>n;
    					cout<<"enter the cost of each house hold supply items\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>h[i].cost;
							}
						cout<<"enter the price of each house hold supply care items\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>h[i].price;
    						}
    					cout<<"the profit gain from household supply items is: "<<HHsupply_profit(h);
    					break;
    				case 5:
    					cout<<"how many items profit do you want to calculate?\n";
    					cin>>n;
    					cout<<"enter the cost of each items which aren't catagorized\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>O[i].cost;
							}
						cout<<"enter the price of each items which aren't catagorized\n";
    					for(int i=0; i<n; i++){
    						cout<<"\n\t"<<i+1<<". ";
    						cin>>O[i].price;
    						}
    					cout<<"the profit gain from uncatagorized items is: "<<others_profit(O);
    					break;
    					}
    					
			break;
			case 2:
				
			break;}}
    case 6:

        break;
        }
    return 0;}
