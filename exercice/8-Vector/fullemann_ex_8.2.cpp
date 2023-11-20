#include <iostream>
#include <limits>
using namespace std;

int main() {
    int nombre;
    int minimum = numeric_limits<int>::max();
    int maximum = numeric_limits<int>::min();
    int occurrenceMinimum = 0;
    int occurrenceMaximum = 0;

    cout << "Entrez une suite de nombres entiers (terminer avec un caractère non numérique):" << endl;

    while (cin >> nombre) {
        if (nombre < minimum) {
            minimum = nombre;
            occurrenceMinimum = 1;
        } else if (nombre == minimum) {
            occurrenceMinimum++;
        }

        if (nombre > maximum) {
            maximum = nombre;
            occurrenceMaximum = 1;
        } else if (nombre == maximum) {
            occurrenceMaximum++;
        }
    }

    cout << "Valeur minimale : " << minimum << " (occurrence : " << occurrenceMinimum << " fois)" << endl;
    cout << "Valeur maximale : " << maximum << " (occurrence : " << occurrenceMaximum << " fois)" << endl;

    return 0;
}
