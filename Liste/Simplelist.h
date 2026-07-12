#ifndef SIMPLELIST_H
#define SIMPLELIST_H

struct cell{
    int info;
    cell* next;
};
typedef cell* list;

#endif
//funzione che confronta due liste e verifica che sino identiche
bool are_equal( list& l1, list& l2);

// funzione che concatena due liste  mantiene l'ordine (se voglio che la lista risultante sia ordinata poss usare mergesort)
list cat(const list& l1, const list& l2);

//funzione che genera lista contenente l'intersezion degli insiemi di partenza 
list intersect(const list& l1, const list& l2);

// funzione che genera lista contenente l'unione degli insiemi delle due list di partenza
list unione(const list& l1, const list& l2);

//riempimento lista in maniera ordinata
list Ordinsert (list& l, int val);

//stampa contenuto intera lista
void stampalista(list& l);