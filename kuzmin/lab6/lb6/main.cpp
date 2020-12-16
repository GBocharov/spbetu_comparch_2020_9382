#include <iostream>
extern "C" void countintervals1(int* numbers, int* unitintervalfrequency, int n, int xmin, int xmax);
extern "C" void countintervals2(int* frequency, int* lgrint, int arr_length, int* unitintervalfrequency, int xmin, int xmax);
int main()
{

	int n;
	int xmin;
	int xmax;
	int arr_length;

	setlocale(LC_ALL, "Russian");

	std::cout << "������� ������ �������: ";
	std::cin >> n;
	while (n <= 0) {
		std::cout << "��������� ����:";
		std::cin >> n;
	}
	int* randomnumbers = new int[n];

	std::cout << "������� �������� �������������: ";
	std::cin >> xmin >> xmax;
	while (xmin > xmax) {
		std::cout << "��������� ����:";
		std::cin >> xmin >> xmax;
	}
	const int range = abs(xmax - xmin) + 1;
	int* unitintervalfrequency = new int[range];


	std::cout << "������� ���������� ����������: ";
	std::cin >> arr_length;
	while (arr_length <= 0) {
		std::cout << "\n��������� ����: ";
		std::cin >> arr_length;
	}
	int* lgrint = new int[arr_length];
	int* frequency = new int[arr_length];


	std::cout << "����� ������� ����������: ";
	for (int i = 0; i < arr_length; i++) {
		std::cin >> lgrint[i];
		frequency[i] = 0;
	}


	std::cout << "���������� �� ���������: ";
	for (int i = 0; i < arr_length; i++) {
		std::cout << "[" << lgrint[i] << ",";
		if (i != arr_length - 1) std::cout << lgrint[i + 1] - 1 << "]";
		else std::cout << xmax << "]";
	}
	std::cout << "\n������ ��������� �����: ";
	for (int i = 0; i < n; i++) {
		randomnumbers[i] = rand() % (abs(xmax - xmin) + 1) + xmin;
		std::cout << randomnumbers[i] << " ";

	}
	for (int i = 0; i < range; i++) unitintervalfrequency[i] = 0;
	std::cout << "\n������������� �� ��������� ����������:\n";
	int h;
	
	countintervals1(randomnumbers, unitintervalfrequency, n, xmin, xmax);

	for (int i = 0; i < range; i++)
		std::cout << "[" << i + xmin << "]: " << unitintervalfrequency[i] << "\n";


	countintervals2(frequency, lgrint, arr_length, unitintervalfrequency, xmin, xmax);


	std::cout << "������������� �� �������� ����������:\n";
	for (int i = 0; i < arr_length; i++)
		if (i != arr_length - 1)std::cout << "[" << lgrint[i] << "," << lgrint[i + 1] - 1 << "]: " << frequency[i] << "\n";
		else std::cout << "[" << lgrint[i] << "," << xmax << "]: " << frequency[i] << "\n";
}

