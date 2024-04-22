#include "../controller/controller.h"



void menu_principal(persona &p)
{
    while (true)
    {
        int option;

        cout << "Bienvenido " << p.getNombre_persona() << endl;
        cout << "1. Crear viaje" << endl;
        cout << "2. Ver viajes" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            crear_viaje(p);
            break;
        case 2:
            system("cls");
            //  ver_viajes(p);
            break;
        case 3:
            return;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }
}

void iniciar_sesion()
{

    int long long id;
    cout << "ingrese su numero de identificacion: ";
    cin >> id;

    for (persona &p : people)
    {
        if (p.getId_persona() == id)
        {
            menu_principal(p);
            return;
        }
    }
    cout << "Usuario no encontrado" << endl;
}

void registrarse()
{

    persona aux_persona;

    int long long id;
    string nombre;

    cout << "ingrese su numero de identificacion: ";
    cin >> id;

    for (persona &p : people)
    {
        if (p.getId_persona() == id)
        {
            cout << "Usuario ya registrado" << endl;
            return;
        }
    }

    cout << "ingrese su nombre: ";
    cin >> nombre;
    aux_persona.setId_persona(id);
    aux_persona.setNombre_persona(nombre);

    people.push_back(aux_persona);
}

void menu_inicial()
{

    while (true)
    {
        int option;

        cout << "Bienvenido a la aplicacion de viajes" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
           // system("cls");
            iniciar_sesion();
            break;
        case 2:
           // system("cls");
            registrarse();
            break;
        case 3:
            return;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }
}