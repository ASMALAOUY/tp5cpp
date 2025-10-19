#include <iostream>
using namespace std;

class Utilisateur {
private:
    string nom;
    string role;
    static int nbUtilisateursConnectes;

public:
    Utilisateur(string n, string r) : nom(n), role(r) {
        nbUtilisateursConnectes++;
    }

    ~Utilisateur() {
        nbUtilisateursConnectes--;
    }

    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }

    void afficher() {
        cout << nom << " (" << role << ")" << endl;
    }
};

int Utilisateur::nbUtilisateursConnectes = 0;

int main() {
    cout << "Connectes: " << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur u1("Alice", "admin");
    cout << "Connectes: " << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur u2("Bob", "visiteur");
    cout << "Connectes: " << Utilisateur::getNbUtilisateursConnectes() << endl;

    {
        Utilisateur u3("Charlie", "visiteur");
        cout << "Connectes: " << Utilisateur::getNbUtilisateursConnectes() << endl;
    }

    cout << "Connectes: " << Utilisateur::getNbUtilisateursConnectes() << endl;

    return 0;
}
