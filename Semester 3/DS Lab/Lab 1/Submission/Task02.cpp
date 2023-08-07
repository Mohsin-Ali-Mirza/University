#include <iostream>
#include <fstream>
using namespace std;

void checkInput(fstream &f,char *argv[])
{
	f.open(argv[1],ios::in);
	if(f)
	cout<<"Input File Opened Successfully\n";
	else
	cout<<"Input File Didnt Opened Successfully\n";
}

void checkOutput(fstream &f, char *argv[])
{
	f.open(argv[2],ios::out);
	if(f)
	cout<<"Output File Opened Successfully\n";
	else
	cout<<"Output File Didnt Opened Successfully\n";
}


int main (int argc, char *argv[])
{
	fstream in;
	fstream out;
	char ch;
	
	checkInput(in,argv);
	checkOutput(out,argv);
	
	
	while(in.get(ch))
	{
		out<<ch;
	}
	
	in.close();
	out.close();
	
	return 0;
}
