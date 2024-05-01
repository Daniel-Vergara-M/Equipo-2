#include "destinos.h"

class viaje : public destinos
{

private:
    int id_viaje;
    set<destinos> destinos_array;

public:
    viaje() {}

    void setId_viaje(const int newId)
    {
        id_viaje = newId;
    }

    int getId_viaje() const
    {
        return id_viaje;
    }

    void setDestinos_array(const set<destinos> newDestinos)
    {
        destinos_array = newDestinos;
    }

    set<destinos> getDestinos_array() const
    {
        return destinos_array;
    }
};
