#include <string>
#include <map>
#include <stack>
#include <algorithm>

#include "../model/persona.h"
#include <queue>

// set<persona> people;

stack<persona> people;
stack<viaje> trips;
stack<destinos> destiny;
// map<persona, viaje> peopleTrips;

/**
 * @brief Verifica si una fecha es valida. Posee una complejidad de O(1)
 * @param date Fecha a verificar
 * @return true si la fecha es valida, false en caso contrario
 */
bool isDateValid(string date)
{
    if (date.size() != 10)
        return false;
    if (date[2] != '-' || date[5] != '-')
        return false;
    if (stoi(date.substr(0, 2)) > 31 || stoi(date.substr(0, 2)) < 1)
        return false;
    if (stoi(date.substr(3, 2)) > 12 || stoi(date.substr(3, 2)) < 1)
        return false;
    if (stoi(date.substr(6, 4)) < 1900 || stoi(date.substr(6, 4)) > 2053)
        return false;
    return true;
}

/**
 * @brief Verifica si una hora es valida. Posee una complejidad de O(1)
 * @param time Hora a verificar
 * @return true si la hora es valida, false en caso contrario
 */
bool isTimeValid(string time)
{
    if (time.size() != 5)
        return false;
    if (time[2] != ':')
        return false;
    if (stoi(time.substr(0, 2)) > 23 || stoi(time.substr(0, 2)) < 0)
        return false;
    if (stoi(time.substr(3, 2)) > 59 || stoi(time.substr(3, 2)) < 0)
        return false;
    return true;
}

/**
 * @brief Crea un viaje para una persona. Posee una complejidad de O(n^3)
 * @param pp Persona a la que se le creara el viaje
 * @return void
 */
void crear_viaje(persona &pp)
{
    viaje newViaje;
    int id = rand() % 1000 + 1;
    newViaje.setId_viaje(id);

    queue<actividades> lista_act_aux;
    queue<destinos> lista_act_dest;
    queue<viaje> lista_Act_viaje;

    //-------------------------------------------------------------------- destinos

    int y = 1;
    destinos aux_des;

    while (y == 1)
    {

        int id_destino = rand() % 1000 + 1;
        string nombre_lugar;
        string ida;
        string regreso;

        cout << "digita nombre del destino : ";
        cin >> nombre_lugar;

        cout << "digite fecha ida asi DD-MM-AAAA :";
        cin >> ida;

        if (!isDateValid(ida))
        {
            cout << "Fecha invalida" << endl;
            return;
        }

        cout << "digite fecha regreso asi DD-MM-AAAA :";
        cin >> regreso;

        if (!isDateValid(regreso))
        {
            cout << "Fecha invalida" << endl;
            return;
        }

        for (int i = 0; i < destiny.size(); i++)
        {
            if ((destiny.top().getNombre_destino() == nombre_lugar) || (destiny.top().getFecha_ida() == ida) || (destiny.top().getFecha_regreso() == regreso))
            {
                cout << "ya existe un destino con ese nombre o fechas iguales" << endl;
            }
            destiny.pop();
        }
        aux_des.setId_Destino(id_destino);
        aux_des.setNombre_destino(nombre_lugar);
        aux_des.setFecha_ida(ida);
        aux_des.setFecha_regreso(regreso);

        cout << "Destino agregado con exito!" << endl;

        cout << "deseas agregar una nueva actividad?: " << endl;
        cout << "1- si " << endl
             << "2- no " << endl;
        cin >> y;
    }

    //-------------------------------------------------------------------- actividades

    int x = 1;
    do
    {

        actividades aux; //------------------------ objeto aux
        int id2 = rand() % 1000 + 1;
        int dia;
        string hora;
        string actividad;
        aux.setId_Actividad(id2); // id aleatorio
        cout << "selecciona un dia: " << endl
             << "1- lunes" << endl
             << "2- martes" << endl
             << "3- miercoles" << endl
             << "4- jueves" << endl
             << "5- viernes" << endl
             << "6- sabado" << endl
             << "7- domingo" << endl;
        cin >> dia;
        cout << "digita la hora de tu actividad asi HH:MM : ";
        cin >> hora;
        if (!isTimeValid(hora))
        {
            cout << "Hora invalida" << endl;
            return;
        }
        cout << "digita la actividad: ";
        cin >> actividad;

        aux.setDias(dia);
        aux.setHoras(hora);
        aux.setActividad(actividad);

        lista_act_aux.push(aux);

        cout << "deseas agregar una nueva actividad?: " << endl;
        cout << "1- si " << endl
             << "2- no " << endl;
        cin >> x;
    } while (x == 1);

    aux_des.setActividades_array(lista_act_aux); // pasar
    destiny.push(aux_des);                       // pasar
    lista_act_dest.push(aux_des);                // pasar

    newViaje.setDestinos_array(lista_act_dest);
    lista_Act_viaje.push(newViaje);
    trips.push(newViaje);

    pp.setViajes_array(lista_Act_viaje);
};

/**
 * @brief Elimina un viaje de una persona. Posee una complejidad de O(n^3)
 * @param p Persona a la que se le eliminara el viaje
 * @return void
 */
void ver_viajes(const persona &p)
{
    cout << "Tus viajes son: " << endl;

    queue<viaje> lista_viajes = p.getViajes_array();

    while (!lista_viajes.empty())
    {
        viaje v = lista_viajes.front();
        cout << "\tID: " << v.getId_viaje() << endl;
        cout << "\tDestinos: " << endl;
        queue<destinos> lista_destinos = v.getDestinos_array();
        while (!lista_destinos.empty())
        {
            destinos d = lista_destinos.front();
            cout << "\t\tNombre: " << d.getNombre_destino() << endl;
            cout << "\t\tFecha ida: " << d.getFecha_ida() << endl;
            cout << "\t\tFecha regreso: " << d.getFecha_regreso() << endl;
            cout << "\t\tActividades: " << endl;
            queue<actividades> lista_actividades = d.getActividades_array();
            while (!lista_actividades.empty())
            {
                actividades a = lista_actividades.front();
                cout << "\t\t\tDia: " << a.getDias() << endl;
                cout << "\t\t\tHora: " << a.getHoras() << endl;
                cout << "\t\t\tActividad: " << a.getActividad() << endl;
                lista_actividades.pop();
            }
            lista_destinos.pop();
        }
        lista_viajes.pop();
    }
};

void verPersonasConDestino(const destinos &d)
{
    cout << "Personas con destino " << d.getNombre_destino() << " son: " << endl;

    for (int i = 0; i < people.size(); i++)
    {
        viaje v = trips.top();
        for (int j = 0; j < v.getDestinos_array().size(); j++)
        {
            destinos d1 = v.getDestinos_array().front();
            if (d1.getNombre_destino() == d.getNombre_destino())
            {
                cout << people.top().getNombre_persona() << endl;
            }
        }
        trips.pop();
    }
};