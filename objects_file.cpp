#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	int a,e,i,o,u;
	a=e=i=o=u=0;
	int total=0;
	int special=0;
  string name;
	int roll;
	int marks;
	ofstream out("File.txt");
	if(!out)
	{
		cout << "File not created: ";

	}

	for(int j=0;j<3;j++)
	{
		cout << "Enter the students name: ";
		cin >> name;
		cout << "Enter the students roll no: ";
		cin >> roll;
		cout << "Enter the students marks: ";
		cin >> marks;
		out << name << " " << roll << " "<<marks<<endl;
	}
	out.close();
	ifstream ins("File.txt");
	if(!ins)
	{
		cout << "File not opened";

	}
	string op;
  string cop;
	while(!ins.eof())
	{
		getline(ins,cop);
    op.append(cop);

	}

	for(int j=0;op[j]!=EOF;j++)
	{
		if(op[j]=='a'||op[j]=='A')
		{
			a++;
		}
		else if(op[j]=='e'||op[j]=='E')
		{
			e++;
		}
		else if(op[j]=='i'|| op[j]=='I')
		{
			i++;
		}
		else if(op[j]=='o'||op[j] == 'O')
		{
			o++;
		}
		else if(op[j]=='u'||op[j]=='U')
		{
			u++;
		}
		else if(op[j]==' '|| op[j] == '\n')
		{
			special++;
		}
    else;
		total++;
	}
	cout << "Vowel a count: " << a <<endl;
	cout << "Vowel e count: " << e <<endl;
	cout << "Vowel i count: " << i <<endl;
	cout << "Vowel o count: " << o <<endl;
	cout << "Vowel u count: " << u <<endl;
	cout << "Total digits: " << total <<endl;
	cout << "Special symbols: "<< special;
return 0;
}
