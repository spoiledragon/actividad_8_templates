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
     //solo para poner las opciones y poderlas reutilizar si en algun momento las llego a ocupar de nuevo
     std::string string1;
     std::string string2;
     std::string string3;
     std::string string4;
     std::string string5;
     std::string string6;
     std::string string7;
     std::string string8;
     std::string string9;

public:
     Menu();
     void mostrar();
};

//implementacion
Menu::Menu()
{    //mi constructor siempre va a poner esto como opciones principales
     string1 = "Menu";
     string2 = "1) Insertar en la ultima posicion";
     string3 = "2) Mostrar Todas las canciones";
     string4 = "3) Buscar cancion";
     string5 = "4) Borrar cancion";
     string6 = "5) Posiciones de cancionesr";
     string7 = "6) Ordenar";
     string8 = "7) Herramientras extras";
     string9 = "0) Salir";
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
          cout << setw(40) << string8 << endl;
          cout << setw(40) << string9 << endl;
          cin >> opcion;

          if (opcion == "1")
          {
               Cancion mySong;
               cin >> mySong;
               myList.insertasiguiente(mySong);
          }
          else if (opcion == "2")
          {
               cout << left;
               cout << myList.tostr();
          }
          else if (opcion == "3")
          {
               string miniopc;
               string b;
               cout << "1) Busqueda Lineal" << endl;
               cout << "2) Busqueda Binaria -debe estar ordenado el arreglo por nombre-" << endl;
               cin >> miniopc;
               if (miniopc == "1")
               {
                    cout << "inserte el nombre a buscar" << endl;
                    fflush(stdin);
                    getline(cin, b);
                    cout << myList.busquedalineal(b) << endl;
               }
               else
               {
                    cout << "inserte el nombre a buscar" << endl;
                    fflush(stdin);
                    getline(cin, b);
                    cout << myList.busquedabinaria(b) << endl;
               }

               system("PAUSE");
          }
          else if (opcion == "4")
          {
               int posx;
               cout << "Inserte la posicion a Borrar" << endl;
               cin >> posx;
               myList.borrar(posx);
               system("PAUSE");
          }
          else if (opcion == "5")
          {

               do
               {
                    string miniopc;
                    int posx;
                    cout << left;
                    cout << "1) Primera posicion" << endl;
                    cout << "2) Ultima posicion" << endl;
                    cout << "3) Posicion anterior" << endl;
                    cout << "4) Posicion siguiente" << endl;
                    cout << "0) Salir" << endl;
                    cin >> miniopc;

                    if (miniopc == "1")
                    {
                         cout << myList.getfirst() << endl;
                         system("PAUSE");
                    }
                    else if (miniopc == "2")
                    {
                         cout << myList.getlastp() << endl;
                         system("PAUSE");
                    }
                    else if (miniopc == "3")
                    {
                         cout << "Inserte la posicion a buscar" << endl;
                         cin >> posx;
                         cout << myList.getprev(posx) << endl;
                         system("PAUSE");
                    }
                    else if (miniopc == "4")
                    {
                         cout << "Inserte la posicion a buscar" << endl;
                         cin >> posx;
                         cout << myList.getnext(posx) << endl;
                         system("PAUSE");
                    }
                    else if (miniopc == "0")
                    {
                         break;
                    }

               } while (true);
          }
          else if (opcion == "6")
          {
               string miniopc;
               string porquecosa;
               cout << left;
               cout << "1) Ordenar by Bubble" << endl;
               cout << "2) Ordenar by Insert" << endl;
               cout << "3) Ordenar by Select" << endl;
               cout << "4) Ordenar by Shell" << endl;
               cin >> miniopc;
               if (miniopc == "1")
               {
                    cout << "Ordenar por : " << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Artista" << endl;
                    cin >> porquecosa;
                    if (porquecosa == "1")
                    {
                         myList.sortBubble(Cancion::comparanombre);
                    }
                    else
                    {
                         myList.sortBubble(Cancion::comparartista);
                    }
               }
               else if (miniopc == "2")
               {
                    cout << "Ordenar por : " << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Artista" << endl;
                    cin >> porquecosa;
                    if (porquecosa == "1")
                    {
                         myList.sortDatainsert(Cancion::comparanombre);
                    }
                    else
                    {
                         myList.sortDatainsert(Cancion::comparartista);
                    }
               }
               else if (miniopc == "3")
               {
                    cout << "Ordenar por : " << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Artista" << endl;
                    cin >> porquecosa;
                    if (porquecosa == "1")
                    {
                         myList.sortDataSelect(Cancion::comparanombre);
                    }
                    else
                    {
                         myList.sortDataSelect(Cancion::comparartista);
                    }
               }
               else if (miniopc == "4")
               {
                    cout << "Ordenar por : " << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Artista" << endl;
                    cin >> porquecosa;
                    if (porquecosa == "1")
                    {
                         myList.sortShell(Cancion::comparanombre);
                    }
                    else
                    {
                         myList.sortShell(Cancion::comparartista);
                    }
               }
          }
          else if (opcion == "7")
          {
               system("CLS");
               string miniopc;
               cout << "1) Insertar en la posicion que quieras "<<endl;;
               cout << "2) Borrar todo "<<endl;
               if (miniopc == "1")
               {
                    cout << "Inserte la posicion donde desea insertar" << endl;
                    int pos;
                    cin >> pos;
                    Cancion mySong;
                    cin >> mySong;
                    myList.insertar(mySong, pos);
               }else if (miniopc=="2")
               {    
                    myList.~Lista();
                    myList.borrador4k();
               }
               
          }
          else if (opcion == "0")
          {
               myList.~Lista();
               break;
          }

          //omitir todo esto es para debugear como un animal despues de transoformar todo a template

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
