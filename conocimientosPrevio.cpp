#include <iostream>
#include <string.h>



struct CD
{
    int codigo;
    char artista[30];
    char album[30];
    int no_canciones;
    float precio;
    int existencias;
};


CD cds[50];
int num_cds = 0;

void agregarCD()
{
    if (num_cds < 50)
    {
        std::cout << "Ingrese el codigo: ";
        std::cin >> cds[num_cds].codigo;
        std::cout << "Ingrese el artista: ";
        std::cin.ignore();
        std::cin.getline(cds[num_cds].artista, 30);
        std::cout << "Ingrese el album: ";
        std::cin.getline(cds[num_cds].album, 30);
        std::cout << "Ingrese el numero de canciones: ";
        std::cin >> cds[num_cds].no_canciones;
        std::cout << "Ingrese el precio: ";
        std::cin >> cds[num_cds].precio;
        std::cout << "Ingrese las existencias: ";
        std::cin >> cds[num_cds].existencias;

        num_cds++;
    }
    else
    {
        std::cout << "El arreglo de CDs está lleno." << std::endl;
    }
}

void mostrarCDs()
{
    if (num_cds > 0)
    {
        std::cout << "Lista de CDs:" << std::endl;
        for (int i = 0; i < num_cds; i++)
        {
            std::cout << "codigo: " << cds[i].codigo << std::endl;
            std::cout << "Artista: " << cds[i].artista << std::endl;
            std::cout << "album: " << cds[i].album << std::endl;
            std::cout << "Numero de canciones: " << cds[i].no_canciones << std::endl;
            std::cout << "Precio: " << cds[i].precio << std::endl;
            std::cout << "Existencias: " << cds[i].existencias << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    }
    else
    {
        std::cout << "No hay CDs almacenados." << std::endl;
    }
}

void buscarPorCodigo()
{
    int codigo;
    std::cout << "Ingrese el codigo a buscar: ";
    std::cin >> codigo;

    for (int i = 0; i < num_cds; i++)
    {
        if (cds[i].codigo == codigo)
        {
            std::cout << "Informacion del CD encontrado:" << std::endl;
            std::cout << "codigo: " << cds[i].codigo << std::endl;
            std::cout << "Artista: " << cds[i].artista << std::endl;
            std::cout << "album: " << cds[i].album << std::endl;
            std::cout << "Numero de canciones: " << cds[i].no_canciones << std::endl;
            std::cout << "Precio: " << cds[i].precio << std::endl;
            std::cout << "Existencias: " << cds[i].existencias << std::endl;
            return;
        }
    }

    std::cout << "No se encontro ningun CD con ese codigo." << std::endl;
}

void modificarCD()
{
    int codigo;
    std::cout << "Ingrese el codigo del CD a modificar: ";
    std::cin >> codigo;

    for (int i = 0; i < num_cds; i++)
    {
        if (cds[i].codigo == codigo)
        {
            std::cout << "Ingrese nuevos valores para el CD:" << std::endl;
            std::cout << "Ingrese el nuevo codigo: ";
            std::cin >> cds[i].codigo;
            std::cout << "Ingrese el nuevo artista: ";
            std::cin.ignore();
            std::cin.getline(cds[i].artista, 30);
            std::cout << "Ingrese el nuevo album: ";
            std::cin.getline(cds[i].album, 30);
            std::cout << "Ingrese el nuevo numero de canciones: ";
            std::cin >> cds[i].no_canciones;
            std::cout << "Ingrese el nuevo precio: ";
            std::cin >> cds[i].precio;
            std::cout << "Ingrese las nuevas existencias: ";
            std::cin >> cds[i].existencias;

            std::cout << "CD modificado exitosamente." << std::endl;
            return;
        }
    }

    std::cout << "No se encontró ningun CD con ese codigo." << std::endl;
}

void realizarVenta()
{
    int codigo;
    std::cout << "Ingrese el codigo del CD a vender: ";
    std::cin >> codigo;

    for (int i = 0; i < num_cds; i++)
    {
        if (cds[i].codigo == codigo)
        {
            if (cds[i].existencias > 0)
            {
                cds[i].existencias--;
                std::cout << "Venta realizada con exito." << std::endl;
                return;
            }
            else
            {
                std::cout << "No hay existencias disponibles para este CD." << std::endl;
                return;
            }
        }
    }

    std::cout << "No se encontro ningun CD con ese codigo." << std::endl;
}

int main()
{
    int opcion;

    do
    {
        std::cout << "\t ==== Menu ==== " << std::endl;
        std::cout << "[1]. Agregar CD" << std::endl;
        std::cout << "[2]. Mostrar todos los CD's" << std::endl;
        std::cout << "[3]. Buscar por codigo" << std::endl;
        std::cout << "[4]. Modificar" << std::endl;
        std::cout << "[5]. Realizar una venta" << std::endl;
        std::cout << "[6]. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarCD();
            break;
        case 2:
            mostrarCDs();
            break;
        case 3:
            buscarPorCodigo();
            break;
        case 4:
            modificarCD();
            break;
        case 5:
            realizarVenta();
            break;
        case 6:
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "Opcion invalida. Por favor, ingrese una opcion valida." << std::endl;
        }

    } while (opcion != 6);

    return 0;
}
