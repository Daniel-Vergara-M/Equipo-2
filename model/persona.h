#include "viaje.h"

class persona : viaje
{

private:
    int id_persona;
    string nombre_persona;
    set<viaje> viajes_array;

public:
    persona() {}

    int getId_persona()
    {
        return id_persona;
    }

    void setId_persona(int value)
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

    set<viaje> getViajes_array()
    {
        return viajes_array;
    }

    void setViajes_array(set<viaje> value)
    {
        viajes_array = value;
    }
};
