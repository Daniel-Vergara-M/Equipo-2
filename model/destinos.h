#include "actividades.h"
#include <set>

class destinos : actividades
{

private:
    int id_Destino;
    string nombre_destino;
    string fecha_ida;
    string fecha_regreso;
    set<actividades> actividades_array;

public:
    destinos() {}

    void setId_Destino(int newId)
    {
        id_Destino = newId;
    }

    int getId_Destino()
    {
        return id_Destino;
    }

    void setNombre_destino(string newNombre)
    {
        nombre_destino = newNombre;
    }

    string getNombre_destino()
    {
        return nombre_destino;
    }

    void setFecha_ida(string newFecha)
    {
        fecha_ida = newFecha;
    }

    string getFecha_ida()
    {
        return fecha_ida;
    }

    void setFecha_regreso(string newFecha)
    {
        fecha_regreso = newFecha;
    }

    string getFecha_regreso()
    {
        return fecha_regreso;
    }

    void setActividades_array(set<actividades> newActividades)
    {
        actividades_array = newActividades;
    }

    set<actividades> getActividades_array()
    {
        return actividades_array;
    }
};
