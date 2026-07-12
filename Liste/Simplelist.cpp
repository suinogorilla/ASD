#include <iostream> 
#include "Simplelist.h"
#include <cstdlib> // Per rand e srand
#include <ctime>   // Per time

using namespace std;

int main()
{
    // Inizializza il seme una sola volta
    srand(time(nullptr));

    //creo due liste vuote
    list list1 = nullptr;
    list list2 = nullptr;

    //dimensione liste
    unsigned dim = 10;
    int val;
    //Riempimento liste
    for (unsigned i = 0; i < dim; i++)
    {
        val = (rand()% 201) - 100;
        Ordinsert(list1, val);
    }
    for (unsigned i = 0; i < dim; i++)
    {
        val = (rand()% 201) - 100;
        Ordinsert(list2, val);
    }

    stampalista(list1);
    cout << endl;
    stampalista(list2);
return 0;
}