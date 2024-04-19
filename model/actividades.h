#include <iostream>

using namespace std;

class actividades
{

private:
    int id_Actividad;
    int dias;
    string hora;
    string actividad;

public:
    actividades() {}

    void setId_Actividad(int newId)
    {
        id_Actividad = newId;
    }

    int getId_Actividad()
    {
        return id_Actividad;
    }

    void setDias(int newDias)
    {
        dias = newDias;
    }

    int getDias()
    {
        return dias;
    }

    void setHoras(string horas)
    {
        this->hora = horas;
    }

    string getHoras()
    {
        return hora;
    }

    void setActividad(string actividades)
    {
        this->actividad = actividades;
    }

    string getActividad()
    {
        return actividad;
    }
};