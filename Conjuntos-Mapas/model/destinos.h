#include <set>
#include "actividades.h"

class destinos : public actividades
{

private:
    int id_Destino;
    string nombre_destino;
    string fecha_ida;
    string fecha_regreso;
    set<actividades> actividades_array;

public:
    destinos() {}

    void setId_Destino(const int newId)
    {
        id_Destino = newId;
    }

    int getId_Destino() const
    {
        return id_Destino;
    }

    void setNombre_destino(const string &nombre_destino)
    {
        this->nombre_destino = nombre_destino;
    }

    string getNombre_destino() const
    {
        return nombre_destino;
    }

    void setFecha_ida(const string newFecha)
    {
        fecha_ida = newFecha;
    }

    string getFecha_ida() const
    {
        return fecha_ida;
    }

    void setFecha_regreso(const string newFecha)
    {
        fecha_regreso = newFecha;
    }

    string getFecha_regreso() const
    {
        return fecha_regreso;
    }

    void setActividades_array(const set<actividades> newActividades)
    {
        actividades_array = newActividades;
    }

    set<actividades> getActividades_array() const
    {
        return actividades_array;
    }
};
