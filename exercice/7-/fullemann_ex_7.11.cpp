/**
 * Laboratoire sur l'exercice 7.11
 * Author : Nathan Füllemann
 * Date : 14.11.2023
 * Updated on :
 *
 * Name: Extraction d'un fichier caché
 * Desc : Ce programme extrait un fichier caché dans une image BMP au moyen de la stéganographie
 */
#include <iostream>
#include <fstream>
#include <bitset>
#include <cstdint>

using namespace std;

// Fonction pour extraire un caractère du fichier image BMP
char extractChar(ifstream &imageFile) {
    char character = 0;

    for (int i = 0; i < 8; ++i) {
        char pixel;
        imageFile.read(&pixel, sizeof(char));
        character |= (pixel & 1) << i;
    }

    return character;
}

// Fonction pour extraire un entier 32 bits du fichier image BMP
uint32_t extractInt(ifstream &imageFile) {
    uint32_t value = 0;

    for (int i = 0; i < 32; ++i) {
        char pixel;
        imageFile.read(&pixel, sizeof(char));
        value |= (pixel & 1) << i;
    }

    return value;
}

int main() {
    // Demander à l'utilisateur le nom du fichier image BMP
    string imageFileName;
    cout << "Entrez le nom du fichier image BMP : ";
    cin >> imageFileName;

    // Ouvrir le fichier image en mode binaire
    ifstream imageFile(imageFileName, ios::binary);

    // Vérifier si le fichier image est ouvert correctement
    if (!imageFile.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier image." << endl;
        return 1;
    }

    // Récupérer le nom du fichier caché
    string hiddenFileName;
    char currentChar;

    do {
        currentChar = extractChar(imageFile);
        hiddenFileName += currentChar;
    } while (currentChar != '\0');

    // Récupérer la taille du fichier caché
    uint32_t hiddenFileSize = extractInt(imageFile);

    // Demander confirmation à l'utilisateur pour créer ou écraser le fichier caché
    cout << "Un fichier caché a été trouvé : " << hiddenFileName << endl;
    cout << "Taille du fichier caché : " << hiddenFileSize << " octets." << endl;

    char confirm;
    cout << "Voulez-vous extraire le fichier ? (o/n) : ";
    cin >> confirm;

    if (confirm == 'o' || confirm == 'O') {
        // Créer le fichier caché
        ofstream hiddenFile(hiddenFileName, ios::binary);
        cout << hiddenFileName;
        if (!hiddenFile.is_open()) {
            cerr << "Erreur : Impossible de créer le fichier caché." << endl;
            return 1;
        }

        // Copier le contenu du fichier caché
        for (uint32_t i = 0; i < hiddenFileSize; ++i) {
            char pixel;
            imageFile.read(&pixel, sizeof(char));
            hiddenFile.write(&pixel, sizeof(char));
        }

        hiddenFile.close();

        cout << "Le fichier caché a été extrait avec succès." << endl;
    } else {
        cout << "Opération annulée." << endl;
    }

    // Fermer le fichier image
    imageFile.close();

    return 0;
}
