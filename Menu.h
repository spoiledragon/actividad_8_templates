#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iomanip>
#include "Cancion.h"
#include "List.h"
#include <string>
#include <iostream>

using namespace std;
class Menu
{
private:
     std::string string1;
     std::string string2;
     std::string string3;
     std::string string4;
     std::string string5;
     std::string string6;
     std::string string7;

public:
     Menu();
     void mostrar();
};

//implementacion
Menu::Menu()
{
     string1 = "Menu";
     string2 = "1) Insertar en la ultima posicion";
     string3 = "2) Mostrar Todas las canciones";
     string4 = "3) Buscar cancion";
     string5 = "4) Posiciones de cancionesr";
     string6 = "5) Ordenar";
     string7 = "0 salir";
}
void Menu::mostrar()
{
     string opcion;
     Lista<Cancion, 1000> myList;

     do
     {
          cout << left;
          cout << setw(40) << string1 << endl;
          cout << setw(40) << string2 << endl;
          cout << setw(40) << string3 << endl;
          cout << setw(40) << string4 << endl;
          cout << setw(40) << string5 << endl;
          cout << setw(40) << string6 << endl;
          cout << setw(40) << string7 << endl;
          cin >> opcion;

          if (opcion == "1")
          {
               Cancion mySong;
               cin >> mySong;
               myList.insertasiguiente(mySong);
          }
          else if (opcion == "2")
          {    cout<<left;
               cout<<myList.tostr();
          }
          else if (opcion == "3")
          {   
               int pos;
               cout<<"Inserte la posicion a buscar"<<endl; cin>>pos;
                cout<<myList.recupera(pos);
                system("PAUSE");
          }
          else if (opcion == "0")
          {
               myList.~Lista();
               break;
          }
          /*


          cout << "ultimo" << endl;
          cout << myList.getlastp();

          cout << endl
               << "anterior" << endl;
          cout << myList.getprev(2);

          cout << endl
               << "siguiente" << endl;
          cout << myList.getnext(2);

          cout << endl
               << "recupera" << endl;
          cout << myList.recupera(2);

          cout << endl
               << "busca" << endl;
          cout << myList.busquedalineal("pepe");

          cout << endl
               << "busca binariamente" << endl;
          cout << myList.busquedalineal("a");

          myList.print();

          cout << endl
               << "ordenarmiento shell" << endl;
          myList.sortShell(Cancion::comparanombre);

          myList.print();*/

     } while (true);
}

#endif
