#include <string>
#include <map>
#include <algorithm>

#include "../model/persona.h"


set<persona> people;
set<viaje> trips;
set<destinos> destiny;



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


void crear_viaje(persona &pp)
{
    viaje newViaje;
    int id = rand() % 1000 + 1;
    newViaje.setId_viaje(id);

    set<actividades> lista_act_aux;
    set<destinos> lista_act_dest;
    set<viaje> lista_Act_viaje;

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

        for (const destinos &d : destiny)
        {

            if ((d.getNombre_destino() == nombre_lugar) || (d.getFecha_ida() == ida) || (d.getFecha_regreso() == regreso))
            {
                cout << "ya existe un destino con ese nombre o fechas iguales" << endl;
            }
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

        lista_act_aux.insert(aux);

        cout << "deseas agregar una nueva actividad?: " << endl;
        cout << "1- si " << endl
             << "2- no " << endl;
        cin >> x;
    } while (x == 1);

    aux_des.setActividades_array(lista_act_aux); // pasar
    destiny.insert(aux_des);                     // pasar
    lista_act_dest.insert(aux_des);              // pasar

    newViaje.setDestinos_array(lista_act_dest);
    lista_Act_viaje.insert(newViaje);
    trips.insert(newViaje);

    pp.setViajes_array(lista_Act_viaje);
};


void ver_viajes(const persona &p)
{
    
    set<string>todos_destinos;
    cout << "Tus viajes son: " << endl;
    for (const viaje v : p.getViajes_array())
    {
        cout << "\tID: " << v.getId_viaje() << endl;
        cout << "\tDestinos: " << endl;
        for(const destinos &d : v.getDestinos_array()){
            todos_destinos.push_back(d.getNombre_destino());
        }
        sort(todos_destinos.begin(),todos_destinos.end());
        for (const destinos &d : v.getDestinos_array())
        {
            cout << "\t\tNombre: " << todos_destinos << endl;
            cout << "\t\tFecha ida: " << d.getFecha_ida() << endl;
            cout << "\t\tFecha regreso: " << d.getFecha_regreso() << endl;
            cout << "\t\tActividades: " << endl;
            for (const actividades &a : d.getActividades_array())
            {
                cout << "\t\t\tDia: " << a.getDias() << endl;
                cout << "\t\t\tHora: " << a.getHoras() << endl;
                cout << "\t\t\tActividad: " << a.getActividad() << endl;
            }
        }
    }
};


void verPersonasConDestino(const destinos &d)
{
    cout << "Las personas que tienen este destino son: " << endl;
    for (const persona &p : people)
    {
        for (const viaje &v : p.getViajes_array())
        {
            for (const destinos &d1 : v.getDestinos_array())
            {
                if (d.getNombre_destino() == d1.getNombre_destino())
                {
                    cout << "- " << p.getNombre_persona() << endl;
                }
            }
        }
    }
}


