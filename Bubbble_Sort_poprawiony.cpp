#include <iostream>
#include <ctime>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;


void Swap(int* tab, int i, int j)
{
	int pom;
	pom = tab[i];
	tab[i] = tab[j];
	tab[j] = pom;
}
int BubbleSort1(int* tab, int length)
{
	int suma = 0;
	bool ch = 0;
	do
	{
		ch = 0;
		for (int i = 0; i < length - 1; i++)
		{
			suma++;
			if (tab[i] > tab[i + 1])
			{
				ch = 1;
				Swap(tab, i, i + 1);
			}

		}
	} while (ch != 0);
	return suma;
}
int  BubbleSort2(int* tab, int length)
{
	int suma = 0;
	int p = 0;
	bool ch = 0;
	do
	{
		ch = 0;
		for (int i = 0; i < length - p - 1; i++)
		{
			suma++;
			if (tab[i] > tab[i + 1])
			{
				ch = 1;
				Swap(tab, i, i + 1);
			}
		}
		p = p + 1;

	} while (ch != 0);
	return suma;
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
void Show(int* c, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "| " << c[j] << " |";
	}
	cout << "\n";
}
float BubbleSortStatistics1(int max, int length)
{
	float porownanie = 0;
	for (int i = 0; i < max; i++)
	{
		int* tab1 = RandomTable(length);
		porownanie += BubbleSort1(tab1, length);
	}
	return porownanie / max;
}
float BubbleSortStatistics2(int max, int length)
{
	float porownanie = 0;
	for (int i = 0; i < max; i++)
	{
		int* tab1 = RandomTable(length);
		porownanie += BubbleSort2(tab1, length);
	}
	return porownanie / max;
}
void TestBubbleSort1()
{
	ofstream plik("bubblesort1.dat");
	for (int i = 10; i <= 1000; i += 10)
	{
		plik << i << " " << BubbleSortStatistics1(1000, i) << endl;
	}
	plik.close();
}

void TestBubbleSort2()
{
	ofstream plik1("bubblesort2.dat");
	for (int i = 10; i <= 1000; i = i + 10)
	{
		plik1 << i << " " << BubbleSortStatistics2(1000, i) << endl;
	}
	plik1.close();
}

int main()
{

	TestBubbleSort2();

	return 0;
}
