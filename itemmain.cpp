#include <iostream>
#include <string>
using namespace std;
void rankof(float* A, int n );
void rate();
void dispStar();
float profitind();
int r; 
float prof1[]={345,566,563,657,677};
int main(){
	rankof(prof1,5);
	rate();

}
//Ranks items based on individual profit
void rankof(float* prof,int n){
	float R[n]={};
	for(int i=0;i<n;i++){
		int r=1,s=1;
		for(int j=0;j<n;j++){
			if(j!=i && prof1[j]<prof1[i])
			r+=1;
			if(j!=1 && prof1[j]==prof1[i])
			s+=1;
		}
		R[i]=r+(float)(s-1)/(float)2;
	}
	cout<<"PROFIT"<<"___________________"<<"Rank"<<endl;
	for(int i=0;i<n;i++)
	cout<<prof1[i]<<"____________________"<<R[i]<<endl;
	}
//Display the ratings of items(0-5 stars)
void dispStar(){
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

void rate(){
	char pName[20];
	cout<<"Enter the product name"<<endl;
	cin.ignore();
	cin.get(pName,20);
	cout<<pName<<endl;
	dispStar();

}
