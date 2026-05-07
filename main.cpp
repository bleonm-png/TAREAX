#include <iostream>
#include <fstream>
using namespace std;

struct Mascota {
    string nombre;
    string especie;
    string raza;
    int edad;
    float peso;
};

Mascota mascotas[100];
int totalMascotas = 0;

void registrarMascota() {

    Mascota m;

    cout << "\n===== REGISTRO DE MASCOTA =====\n";

    cin.ignore();

    cout << "Ingrese el nombre: ";
    getline(cin, m.nombre);

    cout << "Ingrese la especie: ";
    getline(cin, m.especie);

    cout << "Ingrese la raza: ";
    getline(cin, m.raza);

    cout << "Ingrese la edad: ";
    cin >> m.edad;

    cout << "Ingrese el peso (kg): ";
    cin >> m.peso;

    mascotas[totalMascotas] = m;
    totalMascotas++;

    ofstream archivo("mascotas.txt", ios::app);

    if (archivo.is_open()) {

        archivo << "Nombre: " << m.nombre << endl;
        archivo << "Especie: " << m.especie << endl;
        archivo << "Raza: " << m.raza << endl;
        archivo << "Edad: " << m.edad << endl;
        archivo << "Peso: " << m.peso << " kg" << endl;
        archivo << "--------------------------" << endl;

        archivo.close();

        cout << "\nMascota registrada correctamente.\n";
    }
    else {
        cout << "\nError al guardar archivo.\n";
    }
}

void mostrarMascotas() {

    if (totalMascotas == 0) {
        cout << "\nNo hay mascotas registradas.\n";
        return;
    }

    cout << "\n===== MASCOTAS REGISTRADAS =====\n";

    for (int i = 0; i < totalMascotas; i++) {

        cout << "\nMascota #" << i + 1 << endl;

        cout << "Nombre: " << mascotas[i].nombre << endl;
        cout << "Especie: " << mascotas[i].especie << endl;
        cout << "Raza: " << mascotas[i].raza << endl;
        cout << "Edad: " << mascotas[i].edad << endl;
        cout << "Peso: " << mascotas[i].peso << " kg" << endl;
    }
}

void calcularEdadHumana() {

    if (totalMascotas == 0) {
        cout << "\nNo hay mascotas registradas.\n";
        return;
    }

    cout << "\n===== EDAD EQUIVALENTE =====\n";

    for (int i = 0; i < totalMascotas; i++) {

        int edadHumana = mascotas[i].edad * 7;

        cout << mascotas[i].nombre
             << " -> "
             << edadHumana
             << " anos humanos\n";
    }
}

void clasificarPeso() {

    if (totalMascotas == 0) {
        cout << "\nNo hay mascotas registradas.\n";
        return;
    }

    cout << "\n===== MASCOTAS PEQUENAS =====\n";

    for (int i = 0; i < totalMascotas; i++) {

        if (mascotas[i].peso < 5) {
            cout << mascotas[i].nombre
                 << " - "
                 << mascotas[i].peso
                 << " kg\n";
        }
    }

    cout << "\n===== MASCOTAS MEDIANAS =====\n";

    for (int i = 0; i < totalMascotas; i++) {

        if (mascotas[i].peso >= 5 && mascotas[i].peso <= 20) {
            cout << mascotas[i].nombre
                 << " - "
                 << mascotas[i].peso
                 << " kg\n";
        }
    }

    cout << "\n===== MASCOTAS GRANDES =====\n";

    for (int i = 0; i < totalMascotas; i++) {

        if (mascotas[i].peso > 20) {
            cout << mascotas[i].nombre
                 << " - "
                 << mascotas[i].peso
                 << " kg\n";
        }
    }
}

void modificarDatos() {

    if (totalMascotas == 0) {
        cout << "\nNo hay mascotas registradas.\n";
        return;
    }

    int mascotaSeleccionada;
    int opcion;

    cout << "\n===== LISTA DE MASCOTAS =====\n";

    for (int i = 0; i < totalMascotas; i++) {
        cout << i + 1 << ". " << mascotas[i].nombre << endl;
    }

    cout << "\nSeleccione la mascota que desea modificar: ";
    cin >> mascotaSeleccionada;

    mascotaSeleccionada--;

    if (mascotaSeleccionada < 0 || mascotaSeleccionada >= totalMascotas) {
        cout << "\nMascota invalida.\n";
        return;
    }

    cin.ignore();

    cout << "\n===== MODIFICAR DATOS =====\n";
    cout << "1. Nombre\n";
    cout << "2. Especie\n";
    cout << "3. Raza\n";
    cout << "4. Edad\n";
    cout << "5. Peso\n";

    cout << "Seleccione una opcion: ";
    cin >> opcion;

    cin.ignore();

    switch(opcion) {

        case 1:
            cout << "Nuevo nombre: ";
            getline(cin, mascotas[mascotaSeleccionada].nombre);
            break;

        case 2:
            cout << "Nueva especie: ";
            getline(cin, mascotas[mascotaSeleccionada].especie);
            break;

        case 3:
            cout << "Nueva raza: ";
            getline(cin, mascotas[mascotaSeleccionada].raza);
            break;

        case 4:
            cout << "Nueva edad: ";
            cin >> mascotas[mascotaSeleccionada].edad;
            break;

        case 5:
            cout << "Nuevo peso: ";
            cin >> mascotas[mascotaSeleccionada].peso;
            break;

        default:
            cout << "\nOpcion invalida.\n";
            return;
    }

    cout << "\nDatos modificados correctamente.\n";
}

// Main
int main() {

    int opcion;

    do {

        cout << "\n===== REGISTRO DE MASCOTA =====\n";
        cout << "1. Registrar mascota\n";
        cout << "2. Mostrar mascota\n";
        cout << "3. Calcular edad equivalente\n";
        cout << "4. Clasificar por peso\n";
        cout << "5. Modificar datos\n";
        cout << "6. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                registrarMascota();
                break;

            case 2:
                mostrarMascotas();
                break;

            case 3:
                calcularEdadHumana();
                break;

            case 4:
                clasificarPeso();
                break;

            case 5:
                modificarDatos();
                break;

            case 6:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 6);

    return 0;
}