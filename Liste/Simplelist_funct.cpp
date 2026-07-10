//funzione che confronta due liste e verifica che sino identiche
bool are_equal(const list& l1, const list& l2);

// funzione che concatena due liste  mantiene l'ordine (se voglio che la lista risultante sia ordinata poss usare mergesort)
list cat(const list& l1, const list& l2);

//funzione che genera lista contenente l'intersezion degli insiemi di partenza 
list intersect(const list& l1, const list& l2);

// funzione che genera lista contenente l'unione degli insiemi delle due list di partenza
list unione(const list& l1, const list& l2);

//Riempe la lista in ordine crcescente
list Ordinsert (list& l, int val)
{
    if((l-> next == nullptr) || (l->info >= val))
    {
        cell* aux = new cell;
        aux -> info = val;
        aux -> next = l;
        return aux;
    }  
    else 
    {
        list risultato = Ordinsert(l -> next, val);
        l -> next = risultato;
        return l; 
    }
}