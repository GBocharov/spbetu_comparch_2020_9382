#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

/* function
Name 	Acos - compute acos
Usage 	double Acos(double *xP);
Prototype in math.h
Description Computes acos of the number pointed to by xP.
Arguments to acos must be in the range - 1 to 1, acos returns a value in the range 0 to pi.
Use the trig identities acos(x) = atan(sqrt(1 - x ^ 2) / x) */
double Acos(double* xP)
{
	double x = *xP;
	double y = -1;
	_asm {
		fld x;		// ��������� � ���� x, stack: 0)x
		fld x;		// ��������� � ���� x, stack: 0)x , 1)x
		fmul;		// ������������ ��� ������ �������� � �����, stack: 0)x^2
		fld1;		// ��������� ������� � ����, stack: 0)1 , 1)x^2
		fxch st(1);	// ������ ������� �������� ����� 0 � 1, stack: 0)x^2, 1)1
		fsub;		// �������� �� 1, 0 ������� ����� � ��������� � 0 �������, stack: 0) 1-x^2
		fsqrt;		// ��������� ������ � 0 �������� ����� � ��������� � 0 �������, stack: 0) sqrt(1-x^2)
		fld x;		// ��������� � ���� x, stack: 0)x , 1)sqrt(1-x^2)
		fdiv;		// ����� 1 ������� ����� �� ������� � ��������� � ����, stack: 0) sqrt(1-x^2)/x
		fld1;		// ��������� 1 � ����, stack: 0)1 , 1)sqrt(1-x^2)/x
		fpatan;		// ������� ���������� �� �����, �������������
					// �������� 1 �������� �� 0 ������� �����, stack: 0) arctan(sqrt(1-x^2)/x)
		fstp y;		// ������� �� ����� ������� 0 � ���������� y.

		//���� ����������� ������ � ������������� ���������

		fldz;		//��������� � ���� ����� 0, stack: 0) 0
		fld x;		//��������� � ���� ���������� x, stack: 0)x, 1)0
		fcom;		//���������� ��� �������� �� �����
		fstsw ax;	//�������� ��������� �� ������������  
		sahf		//��������� ax � ������� ������
			jae to_end;	//���� x >= 0
		fld y;		//���������� � ���� ���������� y, stack 0)y
		fldpi;		//���������� � ���� ��������� ��, stack: 0)pi, 1)y
		fadd;		//���������� ��� �������� �� ����� � ������ � 0 �������, stack: 0) pi+y
		fstp y;		//������ ������� �� ����� � y
	to_end:
	}
	return y;
}


int main()
{
	system("chcp 1251 > nul");
	double x;
	cout << "������� x: ";
	cin >> x;
	while (x < -1 || x>1) {
		cout << "�������� ������ ���� � �������� �� -1 �� 1!" << endl;
		cout << "������� x: ";
		cin >> x;
	}
	cout << "acos(x) �� ���������� math.h: " << setprecision(15) << acos(x) << endl;
	cout << "Acos(x) ������������: " << setprecision(15) << Acos(&x) << endl;
	return 0;
}
