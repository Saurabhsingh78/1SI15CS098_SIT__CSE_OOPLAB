//* Raingauge problem *//

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
class RAINGUAGE 
{
	char loc[30];
	double fall;
	public:
	RAINGUAGE();
	void readMeasurement();
	void displayreading();
	friend double Avgrainfall(RAINGUAGE[],int);	
};
RAINGUAGE::RAINGUAGE()
{
	fall=0.0;
	strcpy(loc,"\0");
}
void RAINGUAGE::readMeasurement()
{
	cout<<"\n Enter location";
	cin>>loc;
	fall=(rand()%2000)/100.0;
}
void RAINGUAGE::displayreading()
{
	cout<<"\nLocation :\t"<<loc<<"  Rainfall:\t"<<fall<<"cms"<<endl;
}
double Avgrainfall(RAINGUAGE a[],int n)
{
	int i;
	double rain=0.0;
	for(i=0;i<n;i++)
	rain=rain +a[i].fall;
	return(double)rain/n;
}
int main()
{
	RAINGUAGE RAIN[50];
	int i,n;
	cout<<"\n Enter the number of location :";
	cin>>n;
	srand(time(NULL));
	for(i=0;i<n;i++)
	RAIN[i].readMeasurement();
	for(i=0;i<n;i++)
	RAIN[i].displayreading();
	cout<<"The average Rainfall is : \t"<<Avgrainfall(RAIN,n)<<endl;
	return 0;
	
}
