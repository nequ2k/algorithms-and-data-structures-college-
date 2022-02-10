#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int* RandomTable(int length)
{
    int k = length;
    int* tab = new int[k];
    for (int i = 0; i <= length - 1; i++)
    {
        tab[i] = rand();
    }
    return tab;
}
int LosujIndex(int length)
{
    int k = 0;
    do
    {
        k = rand();
        if (k <= length - 1)
        {
            return k;
        }
    } while (true);
}
int SequentialSearch(int* tab, int length, int s, int& count)
{
    count = 0;
    for (int i = 0; i < length - 1; i++)
    {
        count++;
        if (tab[i] == s)
        {
            return i;
        }
    }
    return -1;
}
float SequentialSearchStatistics(int* tab1, int length, int max)
{
    int c = 0;
    float sum = 0;
    float sr = 0;
    for (int i = 0; i < max - 1; i++)
    {
        tab1 = RandomTable(length);
        SequentialSearch(tab1, length, tab1[LosujIndex(length)], c);
        sum += c;
    }
    sr = float(sum / max);
    return sr;
}

void TestSearch(int* tab1, int max)
{
    max = 1001;
    int c = 100; 
    ofstream plik; 
    plik.open("wyszukiwanie.txt"); 
    for (int i = 10; i < max; i += 10)
    {
        plik << i << " ";
        plik << SequentialSearchStatistics(tab1, i, c);
        plik << endl; 
    }
}

int main()
{
    srand(time(0));
    int max = 100;
    int* tab=0;
    TestSearch(tab, max);
    delete[]tab;
    return 0;
}
