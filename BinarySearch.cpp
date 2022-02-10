#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;
int* RandTab(int length)
{
    int* Tab = new int[length];
    for (int i = 0; i < length; i++)
    {
        Tab[i] = rand();
    }
    return Tab;
}
void Swap(int* tab, int i, int j)
{
    int pom = 0;
    pom = tab[i];
    tab[i] = tab[j];
    tab[j] = pom;
}
void QuickSort(int* tab, int left, int right)
{
    int pos, i;
    if (left < right)
    {
        pos = left;
        i = left + 1;
        while (i <= right)
        {
            if (tab[i] < tab[left])
            {
                pos++;
                Swap(tab, pos, i);
            }
            i++;
        }
        Swap(tab, pos, left);
        QuickSort(tab, left, pos - 1);
        QuickSort(tab, pos + 1, right);
    }
}
int BinarySearch(int* tab, int length, int t)
{
    int left = 0, mid = 0, counter = 0;
    int right = length - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        counter++;
        if (tab[mid] == t)
        {
            return counter;
        }
        counter++;
        if (tab[mid] < t)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
float BinarySearchStatistics(int max, int length)
{
    float por = 0;
    int j = 0;
    for (int i = 0; i < max; i++)
    {
        int* tab = RandTab(length);
        QuickSort(tab, 0, length - 1);
        do
        {
            j = rand();
        } while (j > length - 1);
        por += BinarySearch(tab, length, tab[j]);
    }
    return por / max;
}
void TestBinarySearch()
{
    ofstream file("binarysearch.txt");
    for (int i = 10; i <= 1000; i += 10)
    {
        file << i << "\t" << BinarySearchStatistics(1000, i) << endl;
    }
    file.close();
}
int main()
{
    srand(time(NULL));
    TestBinarySearch();
    system("PAUSE"); 
    return 0;
}