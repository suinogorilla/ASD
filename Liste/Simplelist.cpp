#include <iostream> 
#include "Simplelist.h"
#include <cstdlib> // Per rand e srand
#include <ctime>   // Per time

using namespace std;

int main()
{
    / Inizializza il seme una sola volta
    std::srand(std::time(nullptr));

    //creo due liste vuote
    list list1 = nullptr;
    list list2 = nullptr;

    //dimensione liste
    unsigned dim = 10;
    int val;
    //Riempimento liste
    for (unsigned i = 0; i < dim; i++)
    {
        val = (std::rand()% 201) - 100;
        list Ordinsert(list1, val);
    }
    for (unsigned i = 0; i < dim; i++)
    {
        val = (std::rand()% 201) - 100;
        list Ordinsert(list2, val);
    }

    stampalista(list1);
    stampalista(list2);
return();

}