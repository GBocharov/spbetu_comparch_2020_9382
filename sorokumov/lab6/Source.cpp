#include<cstdlib>
#include<iostream>
#include"windows.h"
#include"fstream"
#include<ctime>
#include<iomanip>

using namespace std;

void generation(int*, int, int, int);
int compare(const void*, const void*);

extern"C"
{
	void poisk(int NumRanDat, int* arr, int* LG, int* kol, int NInt);

}
void out1(ofstream& out)
{
	cout << "��������� ������ ���������:" << endl;;
	out << "��������� ������ ��������:" << endl;
	cout << setw(15) << "����� ���������  ";
	cout << setw(20) << "�������   ";
	cout << setw(35) << "���������� ����� � ���������" << endl;
	out << setw(15) << "����� ���������  ";
	out << setw(20) << "�������   ";
	out << setw(35) << "���������� ����� � ��������" << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream fout("output.txt");
	int NumRanDat, Xmin, Xmax, NInt, i, j;
	int* kol;			//������ ��� �������� ���������� ���������� �� ���������
	int* arr;			 //������ ��������������� �����
	int* RG;			//������ ������ ������
	int* LG;			//������ ����� ������

	cout << "������� ����� ������� ��������������� ����� (<16000)" << endl;
	cin >> NumRanDat;
	while ((NumRanDat >= 16000) || (NumRanDat <= 0)) {      //�������� ������������        
		cout << "�������� ����� �������. ��������� ����" << endl;
		cin >> NumRanDat;			//���������� ���������� �����
	}
	arr = new int[NumRanDat];		//��������� ������ ��� ������ ��������������� �����
	cout << "������� ������ ��������� ��������� Xmin" << endl;
	cin >> Xmin;			//���������� ������������ �������� ���������
	cout << "������� ����� ��������� ��������� Xmax" << endl;
	cin >> Xmax;			//���������� ������������� �������� ���������
	while (Xmin > Xmax) {	//�������� ����������� ����� ���������� � ���������
		cout << "�������� ����������� ����� ���������� � ��������� ���������" << endl;
		cin >> Xmin;
		cin >> Xmax;
	}
	generation(arr, NumRanDat, Xmin, Xmax);	//����� ������� ��� ��������� ������� 
	cout << "������ ���������������� �����:" << endl;
	fout << "������ ���������������� �����:" << endl;
	for (i = 0; i < NumRanDat; i++) {
		cout << arr[i] << " ";
		fout << arr[i] << " ";
	}
	cout << endl;
	cout << "������� ���������� ���������� (<24)" << endl;
	cin >> NInt;			//���������� ���������� ����������
	while ((NInt < 0) || (NInt > 24) || (NInt >= (Xmax - Xmin)))		//�������� 
	{
		cout << "�������� ��������. ��������� ����" << endl;
		cin >> NInt;
	}
	kol = new int[NInt];			//��������� ������ ��� ������ ����������
	RG = new int[NInt];			//��������� ������ ��� ������ ������ ������
	LG = new int[NInt];			//��������� ������ ��� ������ ����� ������
	cout << "������� ����� ������� ����������" << endl;
	if (NInt != 0)
	{
		LG[0] = Xmin;	//������� ����� �������-����������� �������� ��������������� �����
		i = 0, j = 1;
		for (; i < NInt - 1; i++, j++)
		{
			cin >> LG[j];			//���������� ����� ������
			while ((LG[j] < Xmin) || (LG[j] > Xmax)) //�������� ������������ ���-������ 

			{
				cout << "�������� ��������. ������� ������ �������� " << endl;
				cin >> LG[j];
			}
			RG[i] = LG[j] - 1;			//��������� ������ ������ ������

		}
		RG[NInt - 1] = Xmax;	  //������� ������ �������-������������ �������� 

		qsort(LG, NInt, sizeof(int), compare);  //���������� ������� ����� ������ �� 

		qsort(RG, NInt, sizeof(int), compare);	//���������� ������� ������ ������ ��


		for (int i = 0; i < NInt; i++)
		{
			kol[i] = 0;			//��������� ������� ������
		}
		poisk(NumRanDat, arr, RG, kol, NInt);//����� ������� ��� ���������� �������
		out1(fout);	//����� ������� ��� ����� ��������� �� ����� � ������ �� � ����
		for (int i = 0; i < NInt; i++)
		{
			cout << setw(10) << i + 1 << setw(18) << "[" << LG[i] << "," << RG[i] << "]" << setw(25) << kol[i] << endl;
			fout << setw(10) << i + 1 << setw(18) << "[" << LG[i] << "," << RG[i] << "]" << setw(25) << kol[i] << endl;

		}
	}
	else
	{
		out1(fout);
		cout << setw(10) << 1 << setw(18) << "[" << Xmin << "," << Xmax << "]" << setw(25) << NumRanDat << endl;
		fout << setw(10) << 1 << setw(18) << "[" << Xmin << "," << Xmax << "]" << setw(25) << NumRanDat << endl;
	}
}

void generation(int* array, int size, int min, int max) {//������� ��� ��������� �������


	int i = 0;
	srand(time(0));
	for (i = 0; i < size; i++) {
		array[i] = rand() % (max - min + 1) + min;
	}
}

int compare(const void* x1, const void* x2) {//������� ��� ��������� ���� �����, �����������


	return(*(int*)x1 - *(int*)x2);
}
