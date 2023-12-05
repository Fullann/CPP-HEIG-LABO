#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // Enregistrez le temps de début
    auto start = std::chrono::high_resolution_clock::now();

    // Attendez 2,678003 secondes
    std::this_thread::sleep_for(std::chrono::microseconds(static_cast<long long>(2.678003 * 1e6)));

    // Enregistrez le temps à la fin de l'attente
    auto end = std::chrono::high_resolution_clock::now();

    // Calculez la durée écoulée
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    // Affichez la durée écoulée en secondes avec précision
    std::cout << "Attente de 2,678003 secondes. Durée : " << duration.count() << " secondes." << std::endl;

    return 0;
}
