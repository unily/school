// math2-4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "cmath"

using namespace std;

double func(double x);
double compute(double s0, double s1, double s2, double func_s0, double func_s1, double func_s2);
void compute(double s0, double s1, double s2, double delta);


int main()
{
	compute(0, 1, 3, 0.01);
	getchar();
    return 0;
}

double func(double x)
{
	return x * x * x - 2 * x + 1;
}

double compute(double s0, double s1, double s2, double func_s0, double func_s1, double func_s2)
{
	double x1 = (s1 + s2) * func_s0 - 2 * (s0 + s2) * func_s1 + (s0 + s1) * func_s2;
	double x2 = 2 * (func_s0 - 2 * func_s1 + func_s2);

	return x1 / x2;
}

void compute(double s0, double s1, double s2, double delta)
{
	double func_s0 = func(s0);
	double func_s1 = func(s1);
	double func_s2 = func(s2);

	double h = s2 - s0 ;

	cout << s0 << ' ' << s1 << ' ' << s2 << ' ' << func_s1 << endl;

	while ((abs(h) - delta) > 1e-6)
	{
		double s = compute(s0, s1, s2, func_s0, func_s1, func_s2);
		double func_s = func(s);
		if (func_s1 <= func_s)
		{
			if (s1 < s)
			{
				s2 = s;
				func_s2 = func_s;
			}
			else
			{
				s0 = s;
				func_s0 = func_s;
			}
		}
		else
		{
			if (s1 > s)
			{
				s2 = s1;
				s1 = s;
				func_s2 = func_s1;
				func_s1 = func_s;
			}
			else
			{
				s0 = s1;
				s1 = s;
				func_s0 = func_s1;
				func_s1 = func_s;
			}
		}
		h = s2 - s0;
		cout << s0 << ' ' << s1 << ' ' << s2 << ' ' << func_s1 << endl;
	}
}

