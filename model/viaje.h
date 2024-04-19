#include "destinos.h"

class viaje : destinos
{

private:
    int id_viaje;
    set<destinos> destinos_array;

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

    void setDestinos_array(set<destinos> newDestinos)
    {
        destinos_array = newDestinos;
    }

    set<destinos> getDestinos_array()
    {
        return destinos_array;
    }
};
