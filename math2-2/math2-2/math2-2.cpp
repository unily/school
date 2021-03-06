// math2-2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "cmath"

#define PI 3.14


using namespace std;

double func(double x);
void compute(double a, double b, double delta);

int main()
{
	compute(0, 3, 0.15);
	getchar();
    return 0;
}

double func(double x)
{
	return x * x * x - 2 * x + 1;
}

void compute(double a, double b, double delta)
{
	double t2 = (sqrt(5) - 1) / 2;
	double t1 = 1.0 - t2;
	double h = b - a;

	double p = a + t1 * h;
	double q = a + t2 * h;

	double func_a = func(a);
	double func_b = func(b);
	double func_p = func(p);
	double func_q = func(q);

	cout << a << ' ' << p << ' ' << q << ' ' << b << endl;
	while (h > delta)
	{
		if (func_p < func_q)
		{
			b = q;
			func_b = func_q;
			q = p;
			func_q = func_p;
			h = b - a;
			p = a + t1 * h;
			func_p = func(p);
		}
		else
		{
			a = p;
			func_a = func_p;
			p = q;
			func_p = func_q;
			h = b - a;
			q = a + t2 * h;
			func_q = func(q);
		}
		cout << a << ' ' << p << ' ' << q << ' ' << b << endl;
	}
	if (func_p <= func_q)
	{
		cout << p << ' ' << func_p << endl;
	}
	else
	{
		cout << q << ' ' << func_q << endl;
	}
}
