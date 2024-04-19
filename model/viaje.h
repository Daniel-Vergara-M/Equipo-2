#include "destinos.h"

class viaje : destinos
{

private:
    int id_viaje;
    list<destinos> destinos_array;

public:
    viaje() {}

    void setId_viaje(int newId)
    {
        id_viaje = newId;
    }

    int getId_viaje()
    {
        return id_viaje;
    }

    void setDestinos_array(list<destinos> newDestinos)
    {
        destinos_array = newDestinos;
    }

    list<destinos> getDestinos_array()
    {
        return destinos_array;
    }
};
