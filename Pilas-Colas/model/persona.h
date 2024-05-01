#include "viaje.h"

class persona : public viaje
{

private:
    int long long id_persona;
    string nombre_persona;
    queue<viaje> viajes_array;

public:
    persona() {}
   // persona(string nombre_persona) : nombre_persona(nombre_persona) {}

    int long long getId_persona() const
    {
        return id_persona;
    }

    void setId_persona(const int long long value)
    {
        id_persona = value;
    }

    string getNombre_persona() const
    {
        return nombre_persona;
    }

    void setNombre_persona(const string value)
    {
        nombre_persona = value;
    }

    queue<viaje> getViajes_array() const
    {
        return viajes_array;
    }

    void setViajes_array(const queue<viaje> value)
    {
        viajes_array = value;
    }

};
