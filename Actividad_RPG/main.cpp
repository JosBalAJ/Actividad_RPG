/*
 Buen día profesor, dejo este mensaje para aclarar algunos detalles sobre la actividad y otras cosas en general
 Honestamente, el programa lo realicé con ayuda de ChatGPT, sin embargo, no de la manera deshonesta, me parece.
 Una vez realizado el programa le pido a la IA que me explique cada detalle del que tenga duda sobre cualquier cosa.
 La verdad es que, no sé si soy el único, (al menos yo no he notado que algún otro compañero esté teniendo problemas)
 pero yo sí siento que me falta reforzar ciertas cosas respecto a la POO y respecto al lenguaje C++ que no he usado y
 no conozco mucho la sintaxis. No es muy difícil familiarizarme, pero me toma un poco de tiempo.
 Además, me veo en la necesidad de trabajar saliendo de la escuela y no me da mucho tiempo de hacer otras cosas
 (Procuro siempre llevarme a casa la mínima tarea posible).
 Es por eso que usé ChatGPT para la actividad, pero como mencioné, creo que uso la herramienta del modo correcto...
 Dejaré notas en el código con las partes que fueron obtenidas con la IA, pero que definitivamente todas fueron
 explicadas y comprendidas en medida de lo posible.
 Dejo también el link al chat por si desea revisar la conversación que tuve: https://chat.openai.com/share/36ec2601-2a81-42bc-8699-87aee1b2034e
 Muchas gracias.
*/


#include <iostream>
#include <string>
#include <cstdlib>  // Comprendido con IA (incluye función para establecer una semilla de aleatoriedad en base a un valor)
#include <ctime>    // Comprendido con IA (incluye función para obtener el número de segundos desde el 1 de Enero de 1970 hasta la ejecución)
                    // Se usan ambas para obtener aleatoriedad

using namespace std;

class Personaje {
protected:
    string nombre;
    int salud;
    int ataque;
public:
    Personaje(string _nombre, int _salud, int _ataque) : nombre(_nombre), salud(_salud), ataque(_ataque) {}
    virtual ~Personaje() {}                             // Comprenido con IA y recuerdo de la clase de la importancia del destructor
    virtual void atacar(Personaje& objetivo) = 0;       // Comprendido con IA y recuerdo de la clase de la diferencia de pasar valores por referencia (Además es la función que se sobreescribe más abajo, tabién es una función virtual pura)
    void recibirAtaque(int cantidad) {
        salud -= cantidad;
        if (salud < 0) salud = 0;
    }
    bool estaVivo() const {
        return salud > 0;
    }
    string getNombre() const {
        return nombre;
    }
    int getSalud() const {
        return salud;
    }
};

class Jugador : public Personaje {
public:
    Jugador(string _nombre) : Personaje(_nombre, 100, 10) {}    // Comprendido con IA (el constructor llama al otro constructor)
    void atacar(Personaje& objetivo) override {                                     // Comprendido con IA (la palabra clave Override sirve para sobreescribir una función de la clase base)
        cout << nombre << " ataca a " << objetivo.getNombre() << "!\n";
        objetivo.recibirAtaque(ataque);                                     // Comprendido con Ia (se aplica el concepto de polimorfismo, al usar un método de la clase base con el objeto especícifo se usan sus variables correspondientes)
        cout << objetivo.getNombre() << " tiene " << objetivo.getSalud() << " de salud.\n";
    }
};

class Enemigo : public Personaje {
public:
    Enemigo(string _nombre) : Personaje(_nombre, 80, 8) {} // Es exactamente lo mismo que la clase jugador pero con otros valores
    void atacar(Personaje& objetivo) override {
        cout << nombre << " ataca a " << objetivo.getNombre() << "!\n";
        objetivo.recibirAtaque(ataque);
        cout << objetivo.getNombre() << " tiene " << objetivo.getSalud() << " de salud.\n";
    }
};

int main() {
    srand(time(0)); // Comprendido con IA (es la generación de la aleatoriedad, se crea la semilla de aleatoriedad en base al resultado de la función time)

    cout << "Tu combate está por empezar.\n";

    Jugador jugador("Jugador");
    Enemigo enemigo("Enemigo");

    while (jugador.estaVivo() && enemigo.estaVivo()) {
        cout << "\nOpciones de acciones:\n";
        cout << "1. Atacar\n";
        cout << "Selecciona una acción: ";
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugador.atacar(enemigo);
                if (enemigo.estaVivo()) {
                    enemigo.atacar(jugador);
                }
                break;
            default:
                cout << "Opción inválida. Intenta de nuevo.\n";
                break;
        }
    }

    if (!jugador.estaVivo()) {
        cout << "Game Over. Has sido derrotado.\n";
    } else {
        cout << "¡Felicidades! Has derrotado al enemigo.\n";
    }

    return 0;
}