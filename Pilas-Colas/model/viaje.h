#include "destinos.h"

class viaje : public destinos
{

private:
    int id_viaje;
    queue<destinos> destinos_array;

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

    void setDestinos_array(const queue<destinos> newDestinos)
    {
        destinos_array = newDestinos;
    }

    queue<destinos> getDestinos_array() const
    {
        return destinos_array;
    }
};
