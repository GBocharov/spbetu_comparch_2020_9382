#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double sqrt(double x, double y)
{
	double z = 0;
	__asm
	{
		FLD x; // ������� �������� � ���� // ��������� �� ������ � ������� ����� ������������ ����� x
		FLD x;
		FMUL; // ��������� ������������ �����
		FLD y; // ������� �������� � ���� // ��������� �� ������ � ������� ����� ������������ ����� y
		FLD y;
		FMUL; // ��������� ������������ �����
		FADD; // �������� ������������ �����
		FSQRT; // ���������� ����������� �����
		Fstp z; // ������� ������������ ����� �� �����

	end:
	}
	return z;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	double a, b;
	cout << "������� �������������� ����� x:" << endl;
	cin >> a;
	cout << "������� �������������� ����� y:" << endl;
	cin >> b;

	cout << "������� ������ x=" << a << "; y=" << b << endl;
	cout << "�������� ������ x=" << sqrt(a, b) << endl;

	system("pause");
	return 0;
}