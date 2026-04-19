 

#include <iostream>
using namespace std;

int main() {
    int n;
    float notas[20][4];
    float promedioEstudiante[20];
    float sumaGeneral = 0;
    float mayor = 0, menor = 100;
    int aprobados = 0, reprobados = 0;

    cout << "Ingrese la cantidad de estudiantes (max 20): ";
    cin >> n;

    // Validar cantidad
    while (n < 1 || n > 20) {
        cout << "Cantidad invalida. Intente de nuevo: ";
        cin >> n;
    }

    // Entrada de datos
    for (int i = 0; i < n; i++) {
        float suma = 0;
        cout << "\nEstudiante " << i + 1 << endl;

        for (int j = 0; j < 4; j++) {
            do {
                cout << "Ingrese nota " << j + 1 << ": ";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 100);

            suma += notas[i][j];

            // Mayor y menor
            if (notas[i][j] > mayor) mayor = notas[i][j];
            if (notas[i][j] < menor) menor = notas[i][j];
        }

        promedioEstudiante[i] = suma / 4;
        sumaGeneral += promedioEstudiante[i];

        // Aprobados o reprobados
        if (promedioEstudiante[i] >= 70)
            aprobados++;
        else
            reprobados++;
    }

    // Mostrar resultados
    cout << "\n--- RESULTADOS ---\n";

    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            cout << notas[i][j] << " ";
        }
        cout << " | Promedio: " << promedioEstudiante[i];
    }

    cout << "\n\nPromedio general: " << sumaGeneral / n;
    cout << "\nNota mas alta: " << mayor;
    cout << "\nNota mas baja: " << menor;
    cout << "\nAprobados: " << aprobados;
    cout << "\nReprobados: " << reprobados;

    return 0;
}