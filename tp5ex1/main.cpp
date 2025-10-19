#include <iostream>
using namespace std;

class Boite {
private:
    double longueur;
    double largeur;
    double hauteur;
    static int nbBoites;

public:
    Boite(double l, double L, double h) : longueur(l), largeur(L), hauteur(h) {
        nbBoites++;
    }

    ~Boite() {
        nbBoites--;
    }

    static int getNombreBoites() {
        return nbBoites;
    }

    void afficher() {
        cout << "Boite: " << longueur << " x " << largeur << " x " << hauteur << endl;
    }
};

int Boite::nbBoites = 0;

int main() {
    cout << Boite::getNombreBoites() << endl;

    Boite b1(2.0, 3.0, 4.0);
    Boite b2(5.0, 6.0, 7.0);

    cout << Boite::getNombreBoites() << endl;

    {
        Boite b3(1.0, 1.0, 1.0);
        cout << Boite::getNombreBoites() << endl;
    }

    cout << Boite::getNombreBoites() << endl;

    return 0;
}
