#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std; 

void LosujTablice(int rozmiar, int *tab)
{
    srand(time(NULL));
    for (int i = 0; i < rozmiar ; i++)
    {
        tab[i] = rand() % 100 + 1;
    }
}
void WyswietlTablice(int rozmiar, int* tab)
{
    srand(time(NULL));
    for (int i = 0; i < rozmiar; i++)
    {
        cout << "tab["<<i<<"] = "<< tab[i] << endl; 
    }
}
int ZnajdzElementZliczOperacje(int rozmiar, int* tab)
{
    int licznik = 1, wartosc = 0;
    bool logiczny = false; 
    cout << "Podaj wartosc, jakiej mam poszukac: " << endl; 
    cin >> wartosc; 
    for (int i = 0; i < rozmiar; i++)
    {
        if (tab[i] == wartosc)
        {
            logiczny = true;
            cout << "liczba wykonanych porownan: " << licznik << endl;
            cout << "znaleziono podana wartosc. Jej indeks to: " << endl;
            return i; 
        }
        licznik++;
    }
    if (logiczny == false)
    {
        cout << "nie znalezniono wartosci. Zwracam " << endl;
        return -1; 
    }
}





int main()
{
    srand(time(NULL));
    cout << "Podaj rozmiar tablicy jednowymiarowej: " << endl; 
    int rozmiar = 0; 
    cin >> rozmiar;
    int* tab = new int[rozmiar]; 
    LosujTablice(rozmiar, tab);
    WyswietlTablice(rozmiar, tab);
    cout << ZnajdzElementZliczOperacje(rozmiar, tab);
    cout << endl << endl;






    delete[] tab; 
    system("PAUSE"); 
}


