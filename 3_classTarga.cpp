#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class TargaCasuale {
private:
    string parola = "fiorentina";
    string targa;

    bool contrVoc(char c){
    c = toupper(c);
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    return true;
    else
        return false;

}


    bool contrLet(char c){
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
        else
            return false;
    }


    bool contrNum(char c){
        if(c >= '0' && c <= '9')
        return true;
        else
            return false;

    }

    char trovaCon(int indice) {
        while (indice < parola.size()) {
            char c = parola[indice];
            if (contrLet(c) && !contrVoc(c)) {
                return toupper(c);
            }
            indice++;
        } return 0;
    }

public:
    void generaTarga() {
        char gen[4];
        int numRandom = 0;
        for(int i = 0; i < 4; i++){
            numRandom = rand() % 26 + 65;
            gen[i] = char(numRandom);
        }

        char prima = parola[3];
        if (contrVoc(prima) || contrNum(prima)) {
            prima = trovaCon(3);
        }

        char seconda = gen[1];
        while(contrVoc(seconda)) {
            seconda = char(rand() % 26 + 65);
        }

        char terza = gen[2];
        char quarta = gen[3];
        int numero = rand() % 900 + 100;

        targa = "";
        targa.append(string(1, prima));
        targa.append(string(1, seconda));
        targa.append(to_string(numero));
        targa.append(string(1, terza));
        targa.append(string(1, quarta));

        cout << "Targa generata: " << targa << endl;
    }

    string sostituisciNum() {
        string nuovaTarga = targa;
        for(int i = 0; i < nuovaTarga.size(); i++){
            if(contrNum(nuovaTarga[i])) {
                nuovaTarga[i] = 'X';
            }
        }
        return nuovaTarga;
    }

    string invertiTarga() {
        string targaInv = targa;
        int n = targa.size();
        for(int i = 0; i < n; i++){
            targaInv[i] = targa[n - 1 - i];
        }
        return targaInv;
    }

    void cercaNumero() {
        string n;
        cout << "Inserisci numero da cercare: ";
        cin >> n;
        if(targa.find(n) >=0 && targa.find(n) <=9) {
            cout << "Il numero " << n << " e' presente nella targa." << endl;
        } else {
            cout << "Il numero " << n << " non e' presente nella targa." << endl;
        }
    }


};

void menu(){
    cout << "\n---Menu'---" << endl;
    cout << "1: sostituzione numeri con 'X'" << endl;
    cout << "2: inversione targa" << endl;
    cout << "3: ricerca numero nella targa" << endl;
    cout << "4: esci" << endl;
}

int main() {
    srand(time(NULL));

    TargaCasuale t;
    t.generaTarga();

    int scelta;
    do {
        menu();
        cin >> scelta;
        switch(scelta){
            case 1: {
                string nuova = t.sostituisciNum();
                cout << "Targa modificata: " << nuova << endl;
                break;
            }
            case 2: {
                string inv = t.invertiTarga();
                cout << "Targa invertita: " << inv << endl;
                break;
            }
            case 3:
                t.cercaNumero();
                break;
            case 4:
                cout << "Uscita." << endl;
                break;
            default:
                cout << "scegli una delle opzioni presenti" << endl;
        }
    } while(scelta != 4);

    return 0;
}
