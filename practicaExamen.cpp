#include <iostream>
#include <string>
#include <vector>
#include "Usuario.hpp"

using namespace std;
void eliminar(vector<Usuario *> list)
{
    int pos = 0;
    cout << "Ingrese la posiciona a elimiar: ";
    cin >> pos;
    list.erase(list.begin() + pos);
}
void imprimir(vector<Usuario *> list)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        Usuario *user = list[i];
        cout << "Usuario: " << user->getUser();
        cout << "Contra: " << user->getContra();
    }
}
void modificar(vector<Usuario *> list)
{
    bool acabar = true;
    int pos = 0;
    
    cout << "Ingrese la posicion a modificar: ";
    cin >> pos;
    Usuario *user = list[pos];

    while (acabar)
    {
        int op = 1;
        cout << "1. Username 2. Contra 3. Edad 4. Nombre 0. Salir" << endl;
        cin >> op;

        switch (op)
        {
            case 1:
            {
                string username = "";
                cout << "Ingrese el nuevo usuario: " << endl;
                cin >> username;
                user->setUsername(username);
                break;
            }
            case 2:
            {
                string contra = "";
                cout << "Ingrese la nueva contraseña: " << endl;
                cin >> contra;
                user->setContra(contra);
                break;
            }
            case 3:
            {
                int edad = 0;
                cout << "Ingrese la nueva edad: " << endl;
                cin >> edad;
                user->setEdad(edad);
                break;
            }
            case 4:
            {
                string nombre = "";
                cout << "Ingrese el nuevo nombre: " << endl;
                cin >> nombre;
                user->setNombre(nombre);
                break;
            }
            case 0:
            {
                acabar = false;
                break;
            }
            default:
            {
                cout << "Ingrese una opción válida" << endl;
                break;
            }
        }
    }
}

Usuario *crear()
{
    string nombre, usuario, contra;
    int edad;
    cout << "Ingrese el nombre del usuario: ";
    cin >> nombre;
    cout << "Ingrese la edad del usuario: ";
    cin >> edad;
    cout << "Ingrese el usuario: ";
    cin >> usuario;
    cout << "Ingrese la contraseña: ";
    cin >> contra;
    Usuario *user = new Usuario(nombre, edad, usuario, contra);
    return user;
}

void menu()
{
    vector<Usuario *> list;
    bool parar = true;
    int opcion;

    do
    {
        cout << "---MENU---" << endl;
        cout << "1. Crear usuarios" << endl;
        cout << "2. Modificar usuarios" << endl;
        cout << "3. Imprimir usuarios/Eliminar" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            bool terminar = false;
            int ingresar;
            do
            {
                cout << "Desea ingresar un usuario? (1 = sí / 2 = no): ";
                cin >> ingresar;
                switch (ingresar)
                {
                case 1:
                {
                    list.push_back(crear());
                    break;
                }
                case 2:
                    terminar = true;
                    break;
                default:
                    cout << "Ingrese una opción válida" << endl;
                }
            } while (!terminar);
            break;
        }
        case 2:
        {
            int mod = 0;
            bool terminar = true;
            do
            {
                cout << "Desea modificar un usuario? (1 = sí / 2 = no): ";
                cin >> mod;
                switch (mod)
                {
                case 1:
                {
                    modificar(list);
                    break;
                }
                case 2:
                {
                    terminar = false;
                    break;
                }
                default:
                    cout << "Ingrese una opcion valida" << endl;
                    break;
                }
            } while (terminar);
            break;
        }
        case 3:
        {
            int mod;
            cout << "1. Imprimir 2. Eliminar";
            cin >> mod;
            switch (mod)
            {
            case 1:
            {
                imprimir(list);
                break;
            }
            case 2:
            {
                eliminar(list);
                break;
            }
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
            }
            break;
        }
        case 4:
            parar = false;
            break;
        default:
            cout << "Ingrese una opción válida" << endl;
            break;
        }
    } while (parar);
}

int main()
{
    menu();
    return 0;
}
