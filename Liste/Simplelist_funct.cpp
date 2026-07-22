#include <iostream> 
#include "Simplelist.h"
using namespace std;

//funzione che confronta due liste e verifica che sino identiche
bool are_equal(list& l1, list& l2)
{
    if((l1 == nullptr) && (l2 == nullptr)) return true;
    if(((l1 == nullptr) && (l2 !=nullptr)) || ((l2 == nullptr) && (l1 !=nullptr))) return false;
    if(l1 -> info == l2-> info) return are_equal(l1 -> next, l2 ->next);
    else return false;
}

// funzione che concatena due liste  mantiene l'ordine (se voglio che la lista risultante sia ordinata poss usare mergesort)
list cat(const list& l1, const list& l2);
/*void mergeSort(vector<int>& v)
{
 ms(v, 0, v.size()-1);
}
void ms(vector<int>& v, unsigned int inizio, unsigned int fine)
{
 if (inizio < fine)
 {
 unsigned int centro = (inizio+fine)/2;
 ms(v, inizio, centro);
 ms(v, centro+1, fine);
 fondi(v, inizio, centro, fine);
 }
}*/

//funzione che ordina la lista con mergesort
 void Mergesort(list& l1)
{
    
}

//funzione che genera lista contenente l'intersezion degli insiemi di partenza 
list intersect(const list& l1, const list& l2);

// funzione che genera lista contenente l'unione degli insiemi delle due list di partenza
list unione(const list& l1, const list& l2);

//Riempe la lista in ordine creescente
list Ordinsert (list& l, int val)
{
    list aux = new cell;
    aux -> info = val;
    aux -> next = nullptr;
    if (l == nullptr) l = aux;
    list curr = l;

    while (curr != nullptr)
    {   
        if (curr == curr-> next)
            curr = curr -> next;
        }
        curr ->next = aux;
        return l;
}
//inserisce l'elemento in testa alla lista
list InsertFirst (list& l, int val)
{
    list aux = new cell;
    aux -> info = val;
    aux -> next = l;
    l = aux;
    return l;
}

//stampa lista
void stampalista(list& l){
    if ( l == nullptr) return;
    cout << l->info<<" ";   
    stampalista(l->next);
}
