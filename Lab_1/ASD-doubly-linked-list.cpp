// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include "ASD-doubly-linked-list.h"

using namespace list;
using namespace std;

/*Descrizione da come e' fatta  la struttura node. */
/*I dettagli interni non saranno visibili dal main*/
struct list::node {  
  Elem info;
  node *prev;
  node *next;
};

/**************************************************/
/*      funzioni da implementare                    */
/**************************************************/
  
/* crea la lista vuota */
void list::createEmpty(List& li){
  node* aux = new node;
  li = aux;
  aux -> next = li;
  aux -> prev = li; 
  return;
}

/* "smantella" la lista (tranne la sentinella) */
void list::clear(List& li){
 if(isEmpty(li)) return;
  li -> prev -> next = nullptr;
  li -> prev = li;
  list::node* aux = li -> next;
  list::node* curr = aux -> next;
  while (curr != nullptr)
  {
    delete aux;
    aux = curr;
    curr = curr -> next;
  }
  delete aux;
  li -> next = li;
  return;
}

/* restituisce true se la lista e' vuota */
bool list::isEmpty(const List& li){
  if((li == nullptr) || (li -> next == li)) return true;
  return false;
}

/* restituisce la dimensione della lista */
unsigned int list::size(const List& li){
  if(isEmpty(li)) return 0;
  list::node* aux = li -> next;
  int i = 0;
  while(aux != li)
  {
    i++;
    aux = aux -> next;
  }
  return i;
}

/* restituisce l'elemento in posizione pos */
/* se pos non e corretta, solleva una eccezione di tipo string*/
Elem list::get(unsigned int pos, const List& li){ 
  if(isEmpty(li)) return 0;
  unsigned dim = list::size(li);
  if(pos > dim) throw std::runtime_error("Errore: la lista non contiene abbastanza elementi"); 
  list::node* aux = nullptr;
  if(pos > dim/2)
  {
    unsigned distance = dim - pos + 1;
    aux = li -> prev; 
    for(unsigned i = 1; i <= distance; i++)
    {
      aux = aux -> prev;
    }
  } 
  else
  {
    aux = li -> next;
for(unsigned i = 1; i < pos + 1; i++)
    {
      aux = aux -> next;
    }
  }
  return aux -> info;
}

/* modifica l'elemento in posizione pos */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::set(unsigned int pos, Elem el, const List& li){
//gestione eccezioni
  if(isEmpty(li)) throw std::runtime_error("Errore: la lista e vuota o non esiste");
  unsigned dim = list::size(li);
  if((pos > dim)) throw std::runtime_error("Errore: la posizione indicata non e valida");
  list::node* aux = nullptr;
  if (pos > dim/2)
  {
    unsigned distance = dim - pos + 1;
    aux = li -> prev; 
    for(unsigned i = 1; i <= distance; i++)
    {
      aux = aux -> prev;
    }
  } 
  else 
  {
    aux = li -> next;
  for(unsigned i = 1; i < pos + 1; i++)
    {
      aux = aux -> next;
    }
  }
  aux -> info = el;
  return;
}

/* inserisce l'elemento in posizione pos*/
/*shiftando a destra gli altri elementi */
/*se pos non e' corretta, solleva una eccezione di tipo string*/
void list::add(unsigned int pos, Elem el, const List& li){
  unsigned dim = list::size(li);
  if(pos > dim) throw std::runtime_error("Errore: la posizione non e disponibile");
  list::node* aux = new node;
  list::node* curr = li -> next;
  aux -> info = el;
  if(pos + 1 < dim/2)
  {
    for(unsigned i = 0; i < pos; i++)
    {
      curr = curr -> next;
    }
  }
  else
  {
    unsigned distance = dim - pos;
    for(unsigned i = 0; i <= distance; i++)
    {
      curr = curr -> prev;
    }
  }
  aux -> prev = curr -> prev;
  aux -> next = curr;
  curr -> prev = aux;
  aux -> prev -> next = aux;
  return;
}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem el, const List& li){
  list::node* aux = new node;
  aux -> info = el;
  aux -> next = li;
  li -> prev -> next = aux;
  li -> prev = aux;
  return;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem el, const List& li) {
	//TO DO
}

/* cancella l'elemento in posizione pos dalla lista */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::removePos(unsigned int pos,const List& li){
	//TO DO
}

/* cancella tutte le occorrenze dell'elemento elem*/
/*se presenti, dalla lista */
void list::removeEl(Elem el,const List& li){
	//TO DO
}

/**************************************************/
/*      funzioni implementate                    */
/**************************************************/
  
/* riempie una lista da file */
void list::readFromFile(string name_file, const List& li){
  ifstream infile;
  string read_data;
  infile.open(name_file);
  while (getline (infile,read_data)){
    if(read_data.length()>0){
      addRear(stoi(read_data),li);
    }
  }
}

/* riempie una lista da standard input */
void list::readFromStdin(const List& li){
  cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
  string read_data;
  cin>>read_data;
  while(read_data!="END"){
    addRear(stoi(read_data),li);
    cin>>read_data;
  }
}

/* stampa la lista */
void list::print(const List& li){
  if(li==li->next){
    cout<<"vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    cout << cur->info;
    cur= cur->next;
    if(cur!=li) cout<<" <-> ";
  }
  cout<<endl;
}

/* produce una string contenendo la lista*/
std::string list::tostring(const List& li){
  string out="";
  if(li==li->next){
    out+="vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    out+=to_string(cur->info);
    cur= cur->next;
    if(cur!=li) out+=" <-> ";
  }
  return out;
}
