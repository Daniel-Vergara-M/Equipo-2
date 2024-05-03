#include "../controller/controller.h"

/**
 * @brief Muestra los viajes de una persona. Posee una complejidad de O(n^3), al tener que usar las funciones con esa complejidad.
 * @param p Persona a la que se le mostraran los viajes
 * @return void
 */
void menu_principal(const persona &p)
{
    while (true)
    {
        int option;

        cout << "Bienvenido " << p.getNombre_persona() << endl;
        cout << "1. Crear viaje" << endl;
        cout << "2. Ver viajes" << endl;
        cout << "3. Ver personas con destino en común" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            crear_viaje(const_cast<persona &>(p));
            break;
        case 2:
            ver_viajes(p);
            break;
        case 3:
        {
            destinos auxDestD;
            string auxDest;
            cout << "Ingrese el destino a buscar: ";
            cin >> auxDest;
            auxDestD.setNombre_destino(auxDest);
            for (size_t i = 0; i < destiny.size(); i++)
            {
                if (destiny.top().getNombre_destino() == auxDest)
                {
                    verPersonasConDestino(destiny.top());
                    break;
                }
                destiny.pop();
            }
            cout << "Destino no encontrado" << endl;
            break;
        }
        case 4:
            return;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }
}

/**
 * @brief Inicia sesion de un usuario. Posee una complejidad de O(n)
 * @return void
 */
void iniciar_sesion()
{

    int long long id;
    cout << "ingrese su numero de identificacion: ";
    cin >> id;

    while (!people.empty())
    {
        persona p = people.top();
        if (p.getId_persona() == id)
        {
            menu_principal(p);
            return;
        }
        people.pop();
    }
    cout << "Usuario no encontrado" << endl;
}

/**
 * @brief Registra un usuario. Posee una complejidad de O(n)
 * @return void
 */
void registrarse()
{

    persona aux_persona;

    int long long id;
    string nombre;

    cout << "ingrese su numero de identificacion: ";
    cin >> id;
    for (size_t i = 0; i < people.size(); i++)
    {
        if (people.top().getId_persona() == id)
        {
            cout << "Usuario ya registrado" << endl;
            return;
        }
        people.pop();
    }
    cout << "ingrese su nombre: ";
    cin >> nombre;

    aux_persona.setId_persona(id);
    aux_persona.setNombre_persona(nombre);

    people.push(aux_persona);
}

/**
 * @brief Muestra el menu inicial. Posee una complejidad de O(1)
 * @return void
 */
void menu_inicial()
{
    while (true)
    {
        int option;

        cout << "1. Iniciar sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            iniciar_sesion();
            break;
        case 2:
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