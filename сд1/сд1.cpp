#include <fstream>
#include <iostream>
#include <clocale>
#include <time.h>

//Лабораторная работа 1. Поливцев Михаил, ИВТ-31. Индивидуальный вариант 16.

using namespace std;

void sort_simple_choice(int* mas, int size);

int main() {
	setlocale(LC_ALL, "ru");

	ofstream inputfile("input.dat");
	ofstream outputfile("output.dat");


	const int MAX_SIZE = 450;

	int k[MAX_SIZE], a[MAX_SIZE], m[MAX_SIZE];

	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {
		k[i] = 100 + rand() % 100;
	}

	int x1, x2;
	cout << "Введите число х1 >> ";
	cin >> x1;
	cout << "Введите число х2 >> ";
	cin >> x2;
	if (x1 > x2) {
		cout << "\nОшибка: x2 должно превышать х1" << endl;
		return 1;
	}

	int s1 = 0, s2 = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (k[i] <= x1) {
			a[s1] = k[i];
			s1++;
		}
		if (k[i] > x2) {
			m[s2] = k[i];
			s2++;
		}
	}

	sort_simple_choice(k, MAX_SIZE);
	sort_simple_choice(a, s1);
	sort_simple_choice(m, s2);

	cout << "K:" << endl;
	inputfile << "K: ";
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << k[i] << endl;
		inputfile << k[i] << " ";
	}

	cout << "количество элементов А: " << s1 << endl;
 	cout << "A:" << endl;
	outputfile << "количество элементов А: " << s1 << endl;
	outputfile << "A: ";
	for (int i = 0; i < s1; i++) {
		cout << a[i] << endl;
		outputfile << a[i] << " ";
	}
	cout << "количество элементов M: " << s2 << endl;
	cout << "M:" << endl;
	outputfile << "\nколичество элементов M: " << s2 << endl;
	outputfile << "M: ";
	for (int i = 0; i < s2; i++) {
		cout << m[i] << endl;
		outputfile << m[i] << " ";
	}

	inputfile.close();
	outputfile.close();
}

void sort_simple_choice(int* mas, int size) {
	int k, x;
	for (int i = 0; i < size; i++) {
		k = i;
		x = mas[i];
		for (int j = i + 1; j < size; j++) {
			if (mas[j] < x) {
				k = j;
				x = mas[j];
			}
		}
		mas[k] = mas[i];
		mas[i] = x;
	}
}
