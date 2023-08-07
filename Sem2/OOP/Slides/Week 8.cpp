#include<iostream>

using namespace std;


class Human
{
private:
int a;
public:
int b;
protected:
int c;

public:
set_a()
{
	a = 1;
}

set_b()
{
	b = 2;
}

set_c()
{
	c = 3;
}

int get_a()
{
	return a;
}

int get_b()
{
	return b;
}

int get_c()
{
	return c;
}

};

class Patient : public Human 
{
private:
int d;
public:
int e;
protected:
int f;

public:
set_d()
{
	d = get_a() + 1;
	cout<<d;
}

set_e()
{
	e = b + 1;
}

set_f()
{
	f = c + 1;
}

int get_d()
{
	return d;
}

int get_e()
{
	return e;
}

int get_f()
{
	return f;
}

};

class Doctor : private Human
{
private:
int g;
public:
int h;
protected:
int i;
};

class Normal_Patient : private Patient
{
private:
int j;
public:
int k;
protected:
int l;
};

class Special_Patient : public Patient
{
private:
int m;
public:
int n;
protected:
int o;
};

class Normal_doctor : protected Doctor
{
private:
int p;
public:
int q;
protected:
int r;

};

class Special_doctor : public Doctor
{
private:
int s;
public:
int t;
protected:
int u;
};

int main()
{
//	Normal_Patient p1;
//	Special_Patient p2;
//	Normal_Doctor d1;
//	Special_Doctor d2;

	Patient p1;
	p1.set_a();
	p1.set_d();
}
