#include <iostream>
#include <string>
using namespace std;

int main(){
	cout<<"\n\t\t\tCategory Code\t"<<"\n\tFOOD CATEGORY--------------------------110\n\t"<<
	"\n\tBEVERAGE CATEGORY------------------210\n\t"<<"\n\tPRESONAL CARE CATEGORY--------------310\n\t"<<
	"\n\tHOUSEHOLD CATEGORY-----------------410\n\t"<<"\n\tOTHERS--------------------------510\n\t"<<endl;
	int rp,sp,cc,discount;
	cout<<"Enter price ";
	cin>>rp;
	cout<<"Enter category code ";
	cin>>cc;
	switch(cc){
		case'310':
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
	   	 case '110':
	   	discount=(14*rp)/100;
	   	sp=rp-discount;
	   	cout<<"sale price= "<<sp<<endl;
	   	cout<<"discounted price= "<<discount<<endl;
	   	 case '410':
	   	discount=(16*rp)/100;
	   	sp=rp-discount;
	   	cout<<"sale price= "<<sp<<endl;
	   	cout<<"discounted price= "<<discount<<endl;
	   	break;
	   	default:
	   		discount=(5*rp)/100;
	   		sp=rp-discount;
	   		cout<<"sale price= "<<sp<<endl;
	   		cout<<"discounted price= "<<discount<<endl;
}}
