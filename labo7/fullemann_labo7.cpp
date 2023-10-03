/**
 * Laboratoire 7
 * Author : Nathan Füllemann
 * Date : 02.10.2023
 *
 * Name:    Calcul de la moyenne et de la variance  
 * Desc :   Programme qui calcule la moyenne et la variance d'une série de nombres positifs
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<double> valeurs;
    double valeur;

    // Lire les valeurs non négatives
    while (true) {
        cout << "Entrez une valeur (nombre négatif pour terminer) : ";
        cin >> valeur;

        if (valeur < 0) {
            break; // Sortir de la boucle si la valeur est négative
        }

        valeurs.push_back(valeur);
    }

    // Calculer la moyenne
    double somme = 0.0;
    for (double val : valeurs) {
        somme += val;
    }
    double moyenne = somme / valeurs.size();

    // Calculer la variance
    double variance = 0.0;
    for (double val : valeurs) {
        variance += pow(val - moyenne, 2);
    }
    variance /= valeurs.size();

    // Afficher la moyenne et la variance
    cout << "Moyenne : " << moyenne << endl;
    cout << "Variance : " << variance << endl;

    return 0;
}
