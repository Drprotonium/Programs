#include <iostream>
#include <fstream>
using namespace std;

class Record
{
	string name;
	int cust_id;
	double loan;
	int time;//Months
	double roi;
	double si;
	public:
	Record()
	{
		name = " ";
		cust_id =0;
		loan =0;
		time =0;
		roi =0;
	}
	void input()
	{
    cout << "Input name: ";
    cin >> name ;
    cout << "Input customer id ";
    cin >> cust_id;
    cout << "Input primary amount: ";
    cin >>loan;
    cout << "Input time: ";
    cin >> time;
    cout<< "Input roi: ";
    cin >> roi;
	}
	double total_si()
	{
		si = loan*(1+ roi*time);
		return si;
	}

	friend ostream& operator <<(ostream& os, Record &r1);
	friend ifstream& operator  >>(ifstream& ifs ,Record &r1);
	friend ofstream &operator <<(ofstream& ofs,Record &r1);
};
ostream& operator <<(ostream& os, Record &r1)
{
	os << r1.name << " " <<r1.cust_id <<" "<<r1.loan << " "<<r1.time;
	os << " " << r1.roi << r1.total_si()<<endl;
	return os;
}
ifstream& operator  >>(ifstream& ifs ,Record &r1)
{
	ifs >> r1.name >>r1.cust_id >> r1.loan >>r1.time;
	ifs >>r1.roi ;
	return ifs;
}
ofstream &operator <<(ofstream& ofs,Record &r1)
{
	ofs << r1.name << " " <<r1.cust_id <<" "<<r1.loan << " "<<r1.time;
	ofs << " " << r1.roi << " "<< r1.total_si()<< endl;
	return ofs;
}
int main()
{
  double max=-11111;
  double sum=0;
	ofstream rec("loan.dat");
  if(!rec)
  {
    cout << "File is not created";

  }
	Record r1[5];
  for(int i=0;i<5;i++){
    r1[i].input();
  }
  for(int i=0;i<5;i++)
  {
    rec << r1[i];
  }
  rec.close();
  ifstream inp("loan.dat");
  for(int i=0;i<5;i++)
  {
    inp >> r1[i];
    cout << r1[i];
  }
  inp.close();
  for(int j=0;j<5;j++)
  {
    sum+=r1[j].total_si();
  }
  cout << "The total sum of interest is: " <<sum<<endl;
  for(int j=0;j<5;j++)
  {
    if(r1[j].total_si()> max)
    {
      max = r1[j].total_si();

    }

  }
  cout <<"Highest amount of sum of interest: " <<max ;

return 0;
}
