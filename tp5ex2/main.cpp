#include <iostream>
using namespace std;

class Produit {
private:
    string nom;
    float prixHT;
    static float tauxTVA;

public:
    Produit(string n, float p) : nom(n), prixHT(p) {}

    float getPrixTTC() {
        return prixHT * (1 + tauxTVA / 100);
    }

    static void modifierTVA(float nouveauTaux) {
        tauxTVA = nouveauTaux;
    }

    void afficher() {
        cout << nom << ": " << getPrixTTC() << " TTC" << endl;
    }
};

float Produit::tauxTVA = 20.0;

int main() {
    Produit p1("Stylo", 10.0);
    Produit p2("Cahier", 15.0);

    p1.afficher();
    p2.afficher();

    Produit::modifierTVA(10.0);

    p1.afficher();
    p2.afficher();

    return 0;
}
