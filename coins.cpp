#include <iostream>
using namespace std;

int main()
{

	double paise_25[3], paise_50[3], rs_one[3];
	double tot_rs[3];
	double *pnt[4];
	double sum=0;
	pnt[0] = paise_25;
	pnt[1] = paise_50;
	pnt[2] = rs_one;
	pnt[3] = tot_rs;
	cout << "Enter the value of different money: ";
	for(int i=0;i<3;i++)
	{
		cin >> *pnt[0] >> *pnt[1] >> *pnt[2];
		if(i==2)
		{
			break;
		}
		cout << "Money for next list: ";
		pnt[0]++;
		pnt[1]++;
		pnt[2]++;
	}
	cout << "Total money in Rs is: ";
	for(int i=0;i<3;i++)
	{
		*pnt[3] = 0.25 *paise_25[i] + 0.50*paise_50[i] + rs_one[i];
		cout << *pnt[3]<<endl;
		 pnt[3]++;
	}

	for(int i=0;i<3-1;i++)
	{
		for(int j=0;j<3-1-i;j++)
		{
			if(tot_rs[j]>=tot_rs[j+1])
			{
				int temp;
				temp = tot_rs[j];
				tot_rs[j] = tot_rs[j+1];
				tot_rs[j+1] = temp;
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		sum+= tot_rs[i];
	}

	cout <<"Range of the list: "<<tot_rs[2] - tot_rs[0]<<endl;
	cout << "Mean of the list: " << sum/3 <<endl;
	cout << "Median of the list: " << tot_rs[1];



return 0;
}
