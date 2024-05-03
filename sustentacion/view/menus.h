#include "../controller/controller.h"

void valoracion_viajes(){};

void menu_principal(const persona &p)
{
    while (true)
    {
        int option;

        cout << "Bienvenido " << p.getNombre_persona() << endl;
        cout << "1. Crear viaje" << endl;
        cout << "2. Ver viajes" << endl;
        cout << "3. Ver personas con destino en común" << endl;
        cout << "4. Destinos mejor valorados" << endl;
        cout << "5. salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> option;

        if(option == 1){
            crear_viaje(const_cast<persona &>(p));
        }else if (option == 2){
            ver_viajes(p);
        }else if(option == 3){
            destinos auxDestD;
            string auxDest;
            cout << "Ingrese el destino a buscar: ";
            cin >> auxDest;
            auxDestD.setNombre_destino(auxDest);
            for (const destinos &d : destiny)
            {
                if (d.getNombre_destino() == auxDest)
                {
                    verPersonasConDestino(d);
                    break;
                }
            }
            cout << "Destino no encontrado" << endl;
        }else if(option == 4){
            
            valoracion_viajes();
            
        }else{
            return;
        }
    }
}


void iniciar_sesion()
{

    int long long id;
    cout << "ingrese su numero de identificacion: ";
    cin >> id;

    for (const persona &p : people)
    {
        if (p.getId_persona() == id)
        {
            menu_principal(p);
            return;
        }
    }
    cout << "Usuario no encontrado" << endl;
}



void registrarse()
{

    persona aux_persona;

    int long long id;
    string nombre;

    cout << "ingrese su numero de identificacion: ";
    cin >> id;

    for (const persona &p : people)
    {
        if (p.getId_persona() == id)
        {
            cout << "Usuario ya registrado" << endl;
            return;
        }
    }

    cout << "ingrese su nombre: ";
    cin >> nombre;

    aux_persona.setId_persona(id);
    aux_persona.setNombre_persona(nombre);

    people.insert(aux_persona);
}

void menu_inicial()
{

    while (true)
    {
        int option;

        cout << "Bienvenido a la aplicacion de viajes" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            iniciar_sesion();
            break;
        case 2:
            registrarse();
            break;
        case 3:
            return;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }
}

void valoracion_viajes(const persona &p){
    
    string nombre_lugar;
    int eleccion;
    int valoracion;
    
    cout << "//------------Menu-------------//" << endl;
    cout << "1. Ver listas de destinos valorados " << endl;
    cout << "2. Valorar un destino" << endl;
    cout << "3. volver" << endl
    
    if(eleccion == 1){
        
        cout << "Lista destinos mejor valorados: "<< endl
        valoracion.push_back(p.Calificacion);
        sort(valoracion.begin(),valoracion.end());
        for(const viaje v : p.getViajes_array())
        {
            cout << "Nombre del viaje: " << d.getNombre_destino() << endl;
            cout << "Calificacion: " << d.getCalificacion() << endl;
        }
        
    }else if(eleccion == 2){

        string nombre_lugar;
        
        cout << "Escriba el nombre del destino que desea valorar" << endl;
        cin >> nombre_lugar;
        
        for (const destinos &d : destiny)
        {
            if (d.getNombre_destino() == nombre_lugar)
            {
                cout << "El destino seleccionado es: " << nombre_lugar << endl;
                cout << "Del 1 al 5 que calificacion da al destino: " << endl;
                cin >> valoracion;
                
                aux.setCalifiacion.insert(valoracion);
                pp.setCalifiacion(aux);
                
                cout << "valoracion guardada" << endl;
                
            }else{
                cout << "El destino no se encuentra en tu lista de visitas" << endl;
            }
        }
        
    }else if(eleccion == 3){
        menu_principal(const persona &p);
    }
    
}