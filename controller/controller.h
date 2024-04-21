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

    string nombre_destino;
    string fecha_ida;
    string fecha_regreso;

    cout << "Ingrese el nombre del destino: ";
    cin >> nombre_destino;
    newViaje.setNombre_destino(nombre_destino);
    cout << "Ingrese la fecha de ida (DD-MM-YYYY): ";
    cin >> fecha_ida;
    newViaje.setFecha_ida(fecha_ida);
    cout << "Ingrese la fecha de regreso (DD-MM-YYYY): ";
    cin >> fecha_regreso;
    newViaje.setFecha_regreso(fecha_regreso);
    
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