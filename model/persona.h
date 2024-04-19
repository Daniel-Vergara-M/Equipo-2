#include "viaje.h"

class persona : viaje
{

private:
    int long long id_persona;
    string nombre_persona;
    list<viaje> viajes_array;

public:
    persona() {}
    persona(string nombre_persona) : nombre_persona(nombre_persona) {}

    int long long getId_persona()
    {
        return id_persona;
    }

    void setId_persona(int long long value)
    {
        id_persona = value;
    }

    string getNombre_persona()
    {
        return nombre_persona;
    }

    void setNombre_persona(string value)
    {
        nombre_persona = value;
    }

    list<viaje> getViajes_array()
    {
        return viajes_array;
    }

    void setViajes_array(list<viaje> value)
    {
        viajes_array = value;
    }
};
