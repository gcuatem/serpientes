#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;
const int NUM_SNAKES = 3;
const int NUM_LADDERS = 3;
const int MAX_MOVES = 100;

// Función para imprimir la cuadrícula
void printGrid(int grid[NUM_ROWS][NUM_COLS], int player1Pos, int player2Pos) {
    for (int i = NUM_ROWS - 1; i >= 0; i--) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (i == player1Pos / NUM_COLS && j == player1Pos % NUM_COLS) {
                cout << "P1\t";
            } else if (i == player2Pos / NUM_COLS && j == player2Pos % NUM_COLS) {
                cout << "P2\t";
            } else {
                cout << grid[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

// Función para determinar la posición del jugador después de moverse
int newPosition(int currentPos, int moveAmt, int snakes[NUM_SNAKES][2], int ladders[NUM_LADDERS][2]) {
    int newPos = currentPos + moveAmt;
    if (newPos >= NUM_ROWS * NUM_COLS) {
        return NUM_ROWS * NUM_COLS - 1;
    }
    for (int i = 0; i < NUM_SNAKES; i++) {
        if (newPos == snakes[i][0]) {
            return snakes[i][1];
        }
    }
    for (int i = 0; i < NUM_LADDERS; i++) {
        if (newPos == ladders[i][0]) {
            return ladders[i][1];
        }
    }
    return newPos;
}

int main() {
    srand(time(NULL)); // Inicializar el generador de números aleatorios

    int grid[NUM_ROWS][NUM_COLS]; // Crear la cuadrícula
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            grid[i][j] = i * NUM_COLS + j;
        }
    }

    int snakes[NUM_SNAKES][2] = {{17, 7}, {54, 34}, {62, 19}}; // Crear las serpientes
    int ladders[NUM_LADDERS][2] = {{3, 21}, {27, 53}, {42, 77}}; // Crear las escaleras

    int player1Pos = 0; // Inicializar la posición de los jugadores
    int player2Pos = 0;

    int turn = 1; // Inicializar el turno

    for (int i = 0; i < MAX_MOVES; i++) {
        system("clear"); // Limpiar la pantalla
        cout << "Turno de jugador " << turn << endl;
        printGrid(grid, player1Pos, player2Pos); // Imprimir la cuadrícula

        int moveAmt = rand() % 6 + 1; // Tirar el dado
        cout << "Tiraste un " << moveAmt << endl;

        if (turn == 1) { // Actualizar la posición del jugador 1
            player1Pos = newPosition(player1Pos, moveAmt, snakes, ladders);
        } else { // Actualizar la posición del jugador 2
            player2Pos = newPosition(player2Pos, moveAmt, snakes, ladders);
        }

        if (player1Pos == NUM_ROWS * NUM_COLS - 1) { // Verificar si el jugador 1 ha ganado
            cout << "¡Jugador 1 ha ganado!" << endl;
            break;
        } else if (player2Pos == NUM_ROWS * NUM_COLS - 1) { // Verificar si el jugador 2 ha ganado
            cout << "¡Jugador 2 ha ganado!" << endl;
            break;
        }

        // Cambiar el turno
        if (turn == 1) {
            turn = 2;
        } else {
            turn = 1;
        }

        // Esperar un momento antes de continuar
        system("sleep 1");
    }

    return 0;
}
