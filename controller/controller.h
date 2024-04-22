#include <string>
#include <list>
#include <map>
#include <algorithm>

#include "../model/persona.h"

// set<persona> people;

list<persona> people;
list<viaje> trips;
// map<persona, viaje> peopleTrips;

void crear_viaje(persona &persona)
{

    viaje newViaje;
    int id = rand() % 1000 + 1;
    newViaje.setId_viaje(id);

    //-------------------------------------------------------------------- actividades

    list<actividades> lista_act_aux;

    int x = 1;

    while (x = 1)
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
        cout << "digita la hora de tu actividad asi HH:MM : " << endl;
        cin >> hora;
        cout << "digita la actividad: " << endl;
        cin >> actividad;

        aux.setDias(dia);
        aux.setHoras(hora);
        aux.setActividad(actividad);

        lista_act_aux.push_back(aux);

        cout << "deseas agregar una nueva actividad?: " << endl;
        cout << "1- si " << endl
             << "2- no " << endl;
        cin >> x;
    }

    //--------------------------------------------------------------------
};

/*
class Controller
{
private:
    set<viaje> trips;
    set<persona> people;
    map<persona, viaje> peopleTrips;

public:
    Controller() : people(), trips(), peopleTrips(){};
    Controller(set<persona> people) : people(people), trips(), peopleTrips()
    {
        for (persona persona : people)
        {
            peopleTrips[persona] = viaje();
        }
    };
    ~Controller()
    {
        people.clear();
        trips.clear();
        peopleTrips.clear();
    };

    // Getters
    set<persona> getPeople() { return people; };
    set<viaje> getTrips() { return trips; };
    map<persona, viaje> getPeopleDestinies() { return peopleTrips; };
    viaje getPersonDestinies(persona persona) { return peopleTrips[persona]; };
    set<persona> getPeopleWithDestiny(destinos destinos)
    {
        set<persona> peopleWithDestiny;
        for (auto it = peopleTrips.begin(); it != peopleTrips.end(); it++)
        {
            if (it->second.getDestinos_array().find(destinos) != it->second.getDestinos_array().end())
            {
                peopleWithDestiny.insert(it->first);
            }
        }
        return peopleWithDestiny;
    }

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

    void addDestiny(persona persona, destinos destinos)
    {
        if (peopleTrips.find(persona) != peopleTrips.end())
        {
            peopleTrips[persona].getDestinos_array().insert(destinos);
        }
        else
        {
            cout << "persona not found" << endl;
        }
    };

    void removeDestiny(persona persona, destinos destinos)
    {
        if (peopleTrips.find(persona) != peopleTrips.end())
        {
            peopleTrips[persona].getDestinos_array().erase(destinos);
        }
        else
        {
            cout << "persona not found" << endl;
        }
    };

    void addActivity(destinos destinos, actividades actividades)
    {
        if (find(trips.begin(), trips.end(), destinos) != trips.end())
        {
            destinos.getActividades_array().insert(actividades);
        }
        else
        {
            cout << "Destiny not found" << endl;
        }
    };

    void removeActivity(destinos destinos, actividades actividad)
    {
        if (find(trips.begin(), trips.end(), destinos) != trips.end())
        {
            set<actividades> activities = destinos.getActividades_array();
            activities.erase(actividad);
            destinos.setActividades_array(activities);
        }
        else
        {
            cout << "Destiny not found" << endl;
        }
    };

    void registerTrip(persona persona, viaje viaje){
        if (peopleTrips.find(persona) != peopleTrips.end())
        {
            peopleTrips[persona] = viaje;
        }
        else
        {
            cout << "persona not found" << endl;
        }
    };
}; */