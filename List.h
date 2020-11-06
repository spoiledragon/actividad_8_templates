#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <cstdlib>
#include <string>
#include <iostream>
#include "Cancion.h"
#include "listexception.h" //para los fallos

template <class T, int SIZE>
class Lista
{
private:
    T *pointers[SIZE];
    int ultlugar;

public:
    bool valida(const int &);
    void copiar(const Lista<T, SIZE> &);
    void swapData(int, int);
    //constructores
    Lista();
    Lista(const Lista<T, SIZE> &);
    ~Lista();

    //comprobadores globales
    bool tavacio();
    bool talleno();
    //fake setters
    //Nombre    //pos           //interprete        //autor
    void insertar(const T &, const int &); //nombre de la canciono, la posicion la usaremos como rank, interprete, Artista, Auttor del artista
    void borrar(const int &);              //pos borra
    void insertasiguiente(const T &);
    //fake getters
    int getfirst();           //la primera
    int getlastp();           //la ultima
    int getprev(const int &); //anterior
    int getnext(const int &); //la que sigue
    std::string tostr();

    T recupera(const int &); //retrueve = recupera
    std::string tostring();  //no confundir con to_string :(
    void print();            //tostring para noobs
    void borrador4k();       //podemos borrar aca bien piola o regresar a la primera posicion depende del caso

    void llenar();

    std::string busquedalineal(const std::string &);
    std::string busquedabinaria(const std::string &);

    //listos para la actividad 6
    void sortBubble();
    void sortBubble(int(const T &, const T &));
    //data ins
    void sortDatainsert();
    void sortDatainsert(int(const T &, const T &));
    //dataashell
    void sortShell();
    void sortShell(int(const T &, const T &));
    //data sellect
    void sortDataSelect();
    void sortDataSelect(int(const T &, const T &));
    void copyAll(const Lista<T, SIZE> &);

    Lista<T, SIZE> &operator=(const Lista<T, SIZE> &); //operador de asignacion}
};

using namespace std;

template <class T, int SIZE>
void Lista<T, SIZE>::copiar(const Lista<T, SIZE> &l)
{
    for (int i = 0; i <= l.ultlugar; i++)
    {
        pointers[i] = l.pointers[i];
    }
}

//constructores
template <class T, int SIZE>
Lista<T, SIZE>::Lista() : ultlugar(-1) {} //aqui parametramos por default que estara en -1

template <class T, int SIZE>
Lista<T, SIZE>::Lista(const Lista<T, SIZE> &l) { copiar(l); }

//implementacion
template <class T, int SIZE>
bool Lista<T, SIZE>::valida(const int &p)
{
    return p >= 0 and p <= ultlugar;
}

template <class T, int SIZE>
bool Lista<T, SIZE>::tavacio()
{
    return ultlugar == -1;
}

template <class T, int SIZE>
bool Lista<T, SIZE>::talleno()
{
    return ultlugar == SIZE;
}

template <class T, int SIZE>
void Lista<T, SIZE>::insertar(const T &cosa, const int &posi)
{
    //validaciones
    if (talleno())
    {
        throw ListException("Desbordamiento de pointers");
    }
    if (posi < -1 and !valida(posi))
    {
        throw ListException("Posicion invalida");
    }
    //creamos un apuntador que te diga donde esta el objeto
    T *pointer;
    pointer = new T;

    //recorremos todo el arreglo para poder insertar donde quiera
    for (int i = ultlugar + 1; i >= posi; i--)
    {
        pointers[i + 1] = pointers[i];
    }
    *pointer = cosa;
    //respectivas asignaciones
    //pointers[posi] = pointer;
    pointers[posi + 1] = pointer;
    cout << endl
         << "se añadio:" << endl
         << &pointers[posi]<<endl;
    //se aumenta el ultimo lugar
    ultlugar++;
    pointer = nullptr;
}

template <class T, int SIZE>
void Lista<T, SIZE>::insertasiguiente(const T &cosa)
{
    insertar(cosa, ultlugar);
}

template <class T, int SIZE>
void Lista<T, SIZE>::borrar(const int &p)
{
    if (!valida(p))
    {
        throw ListException("Posicion invalida");
    }
    for (int i = p; i < ultlugar + 1; i++)
    {
        pointers[i - 1] = pointers[i];
    }

    ultlugar--;
}

template <class T, int SIZE>
int Lista<T, SIZE>::getfirst()
{
    if (tavacio())
    {
        throw ListException("getElementAt() - Lista vacia");
    }
    return 0;
}

template <class T, int SIZE>
int Lista<T, SIZE>::getlastp()
{

    if (ultlugar == -1)
    {
        throw ListException("getElementAt() - Posición invalida");
    }
    return ultlugar;
}

template <class T, int SIZE>
int Lista<T, SIZE>::getprev(const int &p)
{
    if (p == -1 or !valida(p))
    {
        throw ListException("getElementAt() - Posición invalida");
    }

    return p - 1;
}

template <class T, int SIZE>
int Lista<T, SIZE>::getnext(const int &p)
{
    if (p == -1 or !valida(p))
    {
        throw ListException("getElementAt() - Posición invalida");
    }

    return p + 1;
}

template <class T, int SIZE>
T Lista<T, SIZE>::recupera(const int &p)
{
    if (p == -1 or !valida(p))
    {
        throw ListException("getElementAt() - Posición invalida");
    }
    return *pointers[p-1];
}

template <class T, int SIZE>
void Lista<T, SIZE>::borrador4k()
{
    ultlugar = -1;
}

template <class T, int SIZE>
string Lista<T, SIZE>::busquedalineal(const string &b)
{
    T *temporal;
    Cancion *pointer;
    pointer = new Cancion;
    pointer = NULL;
    for (int i = 0; i < ultlugar + 1; i++)
    {
        temporal = pointers[i];
        pointer = temporal;
        if (b == pointer->getnombre())
        {
            return pointer->tostr();
        }
        free(pointer);
        pointer = nullptr;
        temporal = nullptr;
    }
    free(pointer);
    pointer = nullptr;
    temporal = nullptr;
    return "no se encontro tu elemento";
}

template <class T, int SIZE>
string Lista<T, SIZE>::busquedabinaria(const string &b)
{
    T *temporal;
    Cancion *pointer;
    pointer = new Cancion;
    pointer = NULL;
    int i = 0, j = ultlugar + 1, m;
    while (i <= j)
    {
        m = (i + j) / 2;
        temporal = pointers[m];
        pointer = temporal;
        if (pointer->getnombre() == b)
        {
            return pointer->tostr();
        }

        if (b < pointer->getnombre())
        {
            j = m - 1;
        }
        else
        {
            i = m + 1;
        }
        free(pointer);
        pointer = nullptr;
        temporal = nullptr;
    }
    return "no se encontro tu elemento";
}


template <class T, int SIZE>
string Lista<T, SIZE>::tostr()
{
    Cancion x;
    string exp = "";
    for (size_t i = 0; i <= ultlugar; i++)
    {   
        x=*pointers[i];
        exp += x.tostr();
        exp += "\n ";
        
    }
    
    return exp;
}

//aqui van los de la actividad 6
template <class T, int SIZE>
void Lista<T, SIZE>::swapData(int A, int B)
{
    //aqui se copia todo a
    T *Copia;
    Copia = pointers[A];
    //PASAMOS DE B a A
    pointers[A] = pointers[B];
    //AHORA PASAMOS A a B a travez de copias
    pointers[B] = Copia;
}

template <class T, int SIZE>
void Lista<T, SIZE>::sortBubble()
{

    int i = ultlugar;
    bool banderita;
    do
    {
        banderita = false;
        for (int j = 0; j < i; j++)
        {
            if (*pointers[j] > *pointers[j + 1])
            {
                swapData(j, j + 1);
                banderita = true;
            }
        }
        i--;
    } while (banderita);
}

template <class T, int SIZE>
void Lista<T, SIZE>::sortBubble(int comp(const T &t1, const T &t2))
{

    int i = ultlugar;
    bool banderita;
    do
    {
        banderita = false;
        for (int j = 0; j < i; j++)
        {
            if (comp(*pointers[j], *pointers[j + 1]) > 0)
            {
                swapData(j, j + 1);
                banderita = true;
            }
        }
        i--;
    } while (banderita);
}

template <class T, int SIZE>
void Lista<T, SIZE>::sortDatainsert()
{

    int j;
    for (int i = 1; i <= ultlugar; i++)
    {

        T *Copia = pointers[i];
        j = i;

        while (j > 0 && *Copia < *pointers[j - 1])
        {
            pointers[j] = pointers[j - 1];
            j--;
        }

        if (i != j)
        {
            pointers[j] = Copia;
        }
    }
}

template <class T, int SIZE>
void Lista<T, SIZE>::sortDatainsert(int comp(const T &t1, const T &t2))
{

    int j;
    for (int i = 1; i <= ultlugar; i++)
    {

        T *Copia = pointers[i];
        j = i;

        while (j > 0 && comp(*Copia, *pointers[j - 1]) < 0)
        {
            pointers[j] = pointers[j - 1];
            j--;
        }

        if (i != j)
        {
            pointers[j] = Copia;
        }
    }
}

template <class T, int SIZE>
void Lista<T, SIZE>::sortDataSelect()
{ //acomodo por competencias xd
    int j, m, i;
    for (i = 0; i < ultlugar; i++)
    {
        m = i;
        j = i + 1;

        while (j <= ultlugar)
        {
            if (*pointers[j] < *pointers[m])
            {
                m = j; //seleccionamos al mas bajito uwu
            }
            j++;
        }

        if (i != m) //si i es diferente del mas bajito , entonces hacemos el cambio poderoso
        {
            swapData(m, i);
        }
    }
}

template <class T, int SIZE>
void Lista<T, SIZE>::sortDataSelect(int comp(const T &t1, const T &t2))
{ //acomodo por competencias xd
    int j, m, i;
    for (i = 0; i < ultlugar; i++)
    {
        m = i;
        j = i + 1;

        while (j <= ultlugar)
        {
            if (comp(*pointers[j], *pointers[m]) < 0)
            {
                m = j; //seleccionamos al mas bajito uwu
            }
            j++;
        }

        if (i != m) //si i es diferente del mas bajito , entonces hacemos el cambio poderoso
        {
            swapData(m, i);
        }
    }
}

template <class T, int SIZE>
void Lista<T, SIZE>::sortShell()
{

    float factor = (0.5);
    int diferencial = ((ultlugar + 1) * factor), i, j;
    while (diferencial > 0)
    {
        i = diferencial;
        while (i <= ultlugar)
        {
            j = i;
            while (j >= diferencial && *pointers[j - diferencial] > *pointers[j])
            {
                swapData(j - diferencial, j);
                j = j - diferencial;
            }
            i++;
        }
        diferencial = (diferencial * factor);
    }
}

template <class T, int SIZE>
void Lista<T, SIZE>::sortShell(int comp(const T &t1, const T &t2))
{

    float factor = (0.5);
    int diferencial = ((ultlugar + 1) * factor), i, j;
    while (diferencial > 0)
    {
        i = diferencial;
        while (i <= ultlugar)
        {
            j = i;
            while (j >= diferencial && comp(*pointers[j - diferencial], *pointers[j]) > 0)
            {
                swapData(j - diferencial, j);
                j = j - diferencial;
            }
            i++;
        }
        diferencial = (diferencial * factor);
    }
}

template <class T, int SIZE>
Lista<T, SIZE>::~Lista()
{
    for (size_t i = ultlugar; i > -1; i--)
    {
        delete [] pointers[i];
    }
    ultlugar = -1;
}
#endif // LIST_H_INCLUDED
