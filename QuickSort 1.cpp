#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std; 

void Swap(int* tab, int i, int j)
{
	int pom;
	pom = tab[i];
	tab[i] = tab[j];
	tab[j] = pom;
}

int* RandomTable(int length)
{
	int* RandomTable = new int[length];

	for (int i = 0; i < length; i++)
	{
		RandomTable[i] = rand();
	}
	return RandomTable;
}

void QuickSort(int* tab, int left, int right, int& por)
{
	if (left >= right) return; 
	int pos = left;
	for (int i = left + 1; i <= right; i++)
	{
		if (tab[i] < tab[left])
		{
			pos++; 
			Swap(tab, pos, i); 
		}
		por++; 
	}
	Swap(tab, pos, left);
	QuickSort(tab, left, pos - 1, por);
	QuickSort(tab, pos + 1, right, por);
}
int QuickSortStatistics(int ilosc, int length) {
	int por2 = 0;
	for (int i = 0; i < ilosc; i++) {
		int* array = RandomTable(length);
		int por = 0;
		QuickSort(array, 0, length - 1, por);
		por2 += por;
		delete[] array;
	}
	return por2 / ilosc;
}
void TestQuickSort() {
	ofstream plik("quicksort.dat");
	for (int i = 10; i <= 1000; i += 10) 
	{
		int sr = QuickSortStatistics(1000, i);
		plik << i << " " << sr << endl;
	}
	plik.close();
}



int main()
{
	srand(time(NULL)); 
	TestQuickSort();
}


