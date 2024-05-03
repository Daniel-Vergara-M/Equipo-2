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

    void setId_Actividad(const int newId)
    {
        id_Actividad = newId;
    }

    int getId_Actividad() const
    {
        return id_Actividad;
    }

    void setDias(const int newDias)
    {
        dias = newDias;
    }

    int getDias() const
    {
        return dias;
    }

    void setHoras(const string horas)
    {
        this->hora = horas;
    }

    string getHoras() const
    {
        return hora;
    }

    void setActividad(const string actividades)
    {
        this->actividad = actividades;
    }

    string getActividad() const
    {
        return actividad;
    }
    
    bool operator <(const actividades &a) const
    {
        return id_Actividad < a.id_Actividad;
    }
};