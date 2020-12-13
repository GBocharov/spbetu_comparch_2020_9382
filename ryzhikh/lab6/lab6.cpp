#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;


extern "C" {
	void distribution(int capacity, int* arr, int* LGrInt, int* range);
}


int main() {
	setlocale(LC_ALL, "Russian");
	int capacity = 0, Xmin = 0, Xmax = 0, NInt = 0;
	cout << "Введите размер массива (размер не должен превышать 2^14):\n";
	cin >> capacity;
	if (capacity > 16 * 1024 || capacity <= 0) {
		cout << "Ошибка! Неверный размер массива.\n";
		exit(1);
	}
	cout << "Введите нижний предел:\n";
	cin >> Xmin;
	cout << "Ведите верхний предел:\n";
	cin >> Xmax;
	if (Xmin > Xmax) {
		cout << "Верхний и нижний пределы поменяны местами!\n";
		swap(Xmin, Xmax);
	}
	cout << "Введите количество диапазонов (количество должно быть <= 24): \n";
	cin >> NInt;
	if (NInt > 24 || NInt < 1 || NInt > (Xmax - Xmin + 1)) {
		cout << "Ошибка! Неверное количество диапазонов.\n";
		exit(1);
	}
	int* LGrInt = new int[NInt]();
	cout << "Введите нижние пределы диапазонов в количестве " << NInt - 1 << ":\n";
	for (int i = 0; i < NInt - 1; i++) {
		cin >> LGrInt[i];
		if (LGrInt[i] < LGrInt[i - 1]) {
			cout << "Введенный предел " << LGrInt[i] << " больше предыдущего\n";
			cin >> LGrInt[i];
		}
		if (LGrInt[i] < Xmin || LGrInt[i] > Xmax) {
			cout << "Ошибка! Неверный нижний предел.\n";
			exit(1);
		}
	}
	LGrInt[NInt - 1] = Xmax;
	int* arr = new int[capacity]();
	for (int i = 0; i < capacity; i++) {
		arr[i] = Xmin + rand() % (Xmax - Xmin);
	}
	int* range = new int[NInt];
	for (int i = 0; i < NInt; i++)
		range[i] = 0;
	distribution(capacity, arr, LGrInt, range);
	ofstream file("result.txt");
	if (!file.is_open())
		cout << "Невозможно открыть файл!\n";
	cout << "\nСгенерированные псевдослучайные числа:\n";
	file << "Сгенерированные псевдослучайные числа:\n";
	for (int i = 0; i < capacity; i++) {
		cout << arr[i] << " ";
		file << arr[i] << " ";
	}
	cout << "\n\n";
	file << "\n\n";
	cout << "Номер|Диапазон|Содержание\n";
	file << "Номер|Диапазон|Содержание\n";
	cout << "-------------------------" << endl;
	file << "-------------------------" << endl;
	int n1, n2;
	for (int i = 0; i < NInt; i++) {
		if (i == 0) {
			n1 = Xmin;
			n2 = LGrInt[i];
		}
		else
		{
			n1 = LGrInt[i - 1];
			n2 = LGrInt[i];
		}
		file << "  " << i + 1 << "  |  " << n1 << ", " << n2 << "  |  " << range[i] << "\n";
		cout << "  " << i + 1 << "  |  " << n1 << ", " << n2 << "  |  " << range[i] << "\n";
	}
	file.close();
}
