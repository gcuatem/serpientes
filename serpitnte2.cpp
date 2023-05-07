#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  // Inicialización del juego
  int num_jugadores;
  cout << "Bienvenido al juego de serpientes y escaleras." << endl;
  cout << "Por favor, ingrese el número de jugadores (2-4): ";
  cin >> num_jugadores;

  // Validación del número de jugadores
  while (num_jugadores < 2 || num_jugadores > 4) {
    cout << "Número de jugadores inválido. Por favor, ingrese un número entre 2 y 4: ";
    cin >> num_jugadores;
  }

  // Inicialización del tablero
  const int TAM_TABLERO = 100;
  int tablero[TAM_TABLERO];
  for (int i = 0; i < TAM_TABLERO; i++) {
    tablero[i] = i + 1;
  }
  tablero[2] = 21;
  tablero[4] = 7;
  tablero[10] = 25;
  tablero[19] = 28;
  tablero[26] = 0;
  tablero[31] = 14;
  tablero[33] = 11;
  tablero[37] = 17;
  tablero[40] = 43;
  tablero[52] = 29;
  tablero[57] = 40;
  tablero[62] = 22;
  tablero[66] = 45;
  tablero[71] = 19;
  tablero[80] = 99;
  tablero[87] = 36;
  tablero[93] = 68;
  tablero[95] = 24;
  tablero[98] = 78;

  // Inicialización de los jugadores
  const int MAX_JUGADORES = 4;
  string nombres_jugadores[MAX_JUGADORES];
  int posiciones_jugadores[MAX_JUGADORES];
  int turno_actual = 0;

  for (int i = 0; i < num_jugadores; i++) {
    cout << "Por favor, ingrese el nombre del jugador " << i + 1 << ": ";
    cin >> nombres_jugadores[i];
    posiciones_jugadores[i] = 0;
  }

  // Juego principal
  bool terminado = false;
  while (!terminado) {
    // Turno del jugador actual
    cout << endl << "Es el turno de " << nombres_jugadores[turno_actual] << "." << endl;

    // Tirada de los dados
    srand(time(NULL));
    int dado1 = rand() % 6 + 1;
    int dado2 = rand() % 6 + 1;
    cout << "Ha sacado " << dado1 << " y " << dado2 << "." << endl;

    // Movimiento del jugador
    int nueva_posicion = posiciones_jugadores[turno_actual] + dado1 + dado2;
    if (nueva_posicion >= TAM_TABLERO) {
      nueva_posicion = TAM_TABLERO - 1;
    }
    posiciones_jugadores[turno_actual] = tablero[nueva_posicion];

    // Verificación de si el jugador ha ganado
    if (posiciones_jugadores[turno_actual] == TAM_TABLERO) {
      // El jugador ha ganado
      cout << endl << nombres_jugadores[turno_actual] << " ha ganado el juego!" << endl;
      terminado = true;
    } else {
      // El jugador no ha ganado, pasar al siguiente turno
      turno_actual = (turno_actual + 1) % num_jugadores;
      cout << "Su nueva posición es " << posiciones_jugadores[turno_actual] << "." << endl;
    }
  }

  return 0;
}
