#include <iostream>
#include "List.h"
#include "Cancion.h"
using namespace std;

Lista<Cancion,20>myList;
Cancion mySong1("a","a","a",10);
Cancion mySong2;
Cancion mySong3("c","c","c",30);
Cancion mySong4("d","d","d",40);

int main()
{   
    myList.insertasiguiente(mySong4);
    
    myList.insertasiguiente(mySong3);
    
    mySong2.setnombre("etsech");
    mySong2.setartista("wey");
    mySong2.setinterprete("x");
    mySong2.setranking(20);
    myList.insertasiguiente(mySong2);

    mySong2.setnombre("pepe");
    mySong2.setartista("aguilar");
    mySong2.setinterprete("el");
    mySong2.setranking(10);
    myList.insertasiguiente(mySong2);

    myList.insertasiguiente(mySong1);

    
    
    myList.print();
    

    cout<<"ultimo"<<endl;
    cout<<myList.getlastp();


    cout<<endl<<"anterior"<<endl;
    cout<<myList.getprev(2);

    cout<<endl<<"siguiente"<<endl;
    cout<<myList.getnext(2);

    cout<<endl<<"recupera"<<endl;
    cout<<myList.recupera(2);

    cout<<endl<<"busca"<<endl;
    cout<<myList.busquedalineal("pepe");

    cout<<endl<<"busca binariamente"<<endl;
    cout<<myList.busquedalineal("a");

    myList.print();

    cout<<endl<<"ordenarmiento shell"<<endl;
    myList.sortShell(Cancion::comparanombre);
    

    myList.print();




    return 0;

}
