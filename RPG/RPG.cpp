
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

/* Menú principal */
void menuPrincipal()
{
    cout << "\n" << endl;
    cout << "=== Minijuego RPG ===" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Salir" << endl;
}

/* Game Over */
void gameOver()
{
    cout << "\n\n\n" << endl;
    cout << "=== Has perdido ===" << endl;
    cout << "¡Roberto Martinez te ha eliminado!" << endl;
    cout << "\n\n\n" << endl;
}

/* Victoria */
void hasGanado()
{
    cout << "\n\n\n" << endl;
    cout << "=== Has ganado ===" << endl;
    cout << "¡Felicidades, has destruido a Roberto Martinez!" << endl;
    cout << "\n\n\n" << endl;
}

/* Ataques */
int ataquePoderso()
{
    return (rand() % 11) + 50; // Realiza entre 50 y 60 de daño
}

int ataqueMedio()
{
    return (rand() % 11) + 30; // Realiza entre 30 y 40 de daño
}

int ataqueFlojo()
{
    return (rand() % 11) + 10; // Realiza entre 10 y 20 de daño
}

int main()
{
    // Variables
    srand(time(0));
    string nombre;
    
    char continuar;

    bool salir = false;

    int jugar;
    int vidaJugador = 100;
    int vidaJefe = 100;
    int dañoJugador;

    while (!salir && vidaJefe > 0 && vidaJugador > 0)
    {
        menuPrincipal();
        cout << "\nElige → ";
        cin >> jugar;

        switch (jugar)
        {
        case 1:
            cout << "\n¿Cuál es tu nombre aventurero/a?" << endl;
            cout << "→ ";
            cin >> nombre;

            cout << "\n¿Desea atacar ya a Roberto Martinez? (s/n)" << endl;
            cout << "→ ";
            cin >> continuar;

            do
            {
                /* Lógica del juego */

                // Ataques de Roberto
                int opcionRoberto = (rand() % 4) + 1; // 1 ataque flojo, 2 ataque medio, 3 ataque poderoso, 4 curarse
                
                if (opcionRoberto == 1)
                {
                    int dañoRoberto = ataqueFlojo();
                    cout << "\nRoberto Martinez te ha atacado y te hizo: " << dañoRoberto << " de daño." << endl;
                    vidaJugador -= dañoRoberto;

                // Saber si alguien a ganado
                if (vidaJefe <= 0)
                {
                    hasGanado();
                    break;
                }
                else if (vidaJugador <= 0)
                {
                    gameOver();
                    break;
                }

                }
                else if (opcionRoberto == 2)
                {
                    int dañoRoberto = ataqueMedio();
                    cout << "\nRoberto Martinez te ha atacado con fuerza y te hizo: " << dañoRoberto << " de daño." << endl;
                    vidaJugador -= dañoRoberto;

                // Saber si alguien a ganado
                if (vidaJefe <= 0)
                {
                    hasGanado();
                    break;
                }
                else if (vidaJugador <= 0)
                {
                    gameOver();
                    break;
                }

                }
                else if (opcionRoberto == 3)
                {
                    int dañoRoberto = ataquePoderso();
                    cout << "\nRoberto Martinez te ha atacado violentamente y te hizo: " << dañoRoberto << " de daño." << endl;
                    vidaJugador -= dañoRoberto;
               
                // Saber si alguien a ganado
                if (vidaJefe <= 0)
                {
                    hasGanado();
                    break;
                }
                else if (vidaJugador <= 0)
                {
                    gameOver();
                    break;
                }

                }
                else if (opcionRoberto == 4 && vidaJefe >= 200)
                {
                    cout << "\n¡Roberto Martinez utilizó poción de curación sin ningún efecto!" << endl;
                }
                else
                {
                    cout << "\n¡Roberto Martinez utilizó poción de curación y ha recuperado vida!" << endl;
                    vidaJefe += 20;
                }

                // Estado actual de la batalla
                cout << nombre << ": " << vidaJugador << "                                   " << "Roberto Martinez: " << vidaJefe << endl;
                
                // Ataques del Jugador
                int opcionJugador;

                cout << "\n¡Tu turno! ¿Qúe deseas hacer?" << endl;
                cout << "1. Ataque poderoso   2. Ataque medio" << endl;
                cout << "3. Ataque flojo      4. Poción de curación" << endl;
                cout << "→ ";

                cin >> opcionJugador;

                switch (opcionJugador)
                {
                case 1:
                    dañoJugador = ataquePoderso();
                    cout << "\n¡Has atacado a Roberto Martinez violentamente y le hiciste! " << dañoJugador << " de daño." << endl;
                    vidaJefe -= dañoJugador;
                
                    // Saber si alguien a ganado
                    if (vidaJefe <= 0)
                    {
                        hasGanado();
                        break;
                    }
                    else if (vidaJugador <= 0)
                    {
                        gameOver();
                        break;
                    }
                    break;
                
                case 2:
                    dañoJugador = ataqueMedio();
                    cout << "\n¡Has atacado a Roberto Martinez con fuerza y le hiciste! " << dañoJugador << " de daño." << endl;
                    vidaJefe -= dañoJugador;
                                    
                    // Saber si alguien a ganado
                    if (vidaJefe <= 0)
                    {
                        hasGanado();
                        break;
                    }
                    else if (vidaJugador <= 0)
                    {
                        gameOver();
                        break;
                    }
                    break;

                case 3:
                    dañoJugador = ataqueFlojo();
                    cout << "\n¡Has atacado a Roberto Martinez y le hiciste! " << dañoJugador << " de daño." << endl;
                    vidaJefe -= dañoJugador;

                    // Saber si alguien a ganado
                    if (vidaJefe <= 0)
                    {
                        hasGanado();
                        break;
                    }
                    else if (vidaJugador <= 0)
                    {
                        gameOver();
                        break;
                    }
                    break;

                case 4:
                    if (vidaJugador >= 200)
                    {
                        cout << "\n¡Has utilizado poción de curación sin ningún efecto!" << endl;
                    }
                    else
                    {
                        cout << "\n¡Has utilizado poción de curación y has recuperado vida!" << endl;
                        vidaJugador += 20;
                    }
                    break;

                default:
                    cout << "\nOpción inválida. Por favor, introduzca una opción válida" << endl;
                    break;
                }
                
                // Estado actual de la batalla
                cout << nombre << ": " << vidaJugador << "                                   " << "Roberto Martinez: " << vidaJefe << endl;

            } while (continuar == 's' || continuar == 'S');
            break;
        
        case 2:
            cout << "\nCerrando Minijuego" << endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("./script.sh");

            cout << "\nGracias por jugar\n" << endl;
            salir = true;
            break;

        default:
            cout << "\nIntroduzca 1 o 2" << endl; 
            break;
        }
    }
    return 0;
}

/*
    Developed by:
        -Andrew. (tastelesstree in Discord)
*/