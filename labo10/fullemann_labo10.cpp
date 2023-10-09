/**
 * Laboratoire 10
 * Author : Nathan Füllemann
 * Date : 09.10.2023
 *
 * Name:   Calcul de la racine carrée d'un nombre entier positif
 * Desc :  Ce programme calcule la racine carrée d'un nombre entier positif en utilisant la méthode de Héron
 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Fonction pour calculer la racine carrée d'un nombre en utilisant la méthode de Héron
double heron_sqrt(double x, double epsilon = 1e-10)
{
    // Vérification que le nombre est positif
    if (x < 0)
    {
        cerr << "Erreur : La racine carrée d'un nombre négatif n'est pas définie." << endl;
        return -1.0;
    }

    // Initialisation de la valeur de départ pour la méthode de Héron
    double r = x / 2.0;

    // Boucle pour calculer la racine carrée en utilisant la méthode de Héron
    while (fabs(r * r - x) > epsilon)
    {
        r = 0.5 * (r + x / r);
    }

    // Retourne la valeur de la racine carrée calculée
    return r;
}

int main()
{
    // Déclaration de la variable pour stocker le nombre dont on veut calculer la racine carrée
    double x;

    // Demande à l'utilisateur d'entrer un nombre positif
    cout << "Entrez un nombre positif : ";
    cin >> x;

    // Calcul de la racine carrée en utilisant la méthode de Héron
    double sqrt_x = heron_sqrt(x);

    // Affichage de la racine carrée calculée avec une précision de 10 décimales
    cout << "La racine carrée de " << x << " est : " << setprecision(10) << sqrt_x << endl;

    // Fin du programme
    return 0;
}