#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const string STR_GLOBALE = "fiorentina";

/* qua cotrollo se ci sono vocali usando il toupper per renderla mauiscola */
bool isVocale(char c) //is sta per ispezione
{
    c = toupper (c);
    return (c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

/* qua genero una consonante, utilizzando la funzione isVocale per verificare che non abbia generato una vocale, ho utilizzato il cast per convertire il codice ascii */
char consonanteCasuale()
{
    char c;
    do
    {
        int num = rand() % 26 + 65; // ASCII A-Z
        c = (char)num;
    }
    while(isVocale(c));
    return c;
}

/* qui genera un numero casuale da 1 a 9 come carattere */
char numeroCasuale()
{
    int n = rand() % 9 + 1;
    return (char)(n + 48);
}



string generaTarga()
{
    string targa = "";

    /* elemento 1 */
    char e1 = STR_GLOBALE.at(3);

    // se è vocale o numero, sostituisco con una consonante casuale
    if(isVocale(e1) || (e1 >= '0' && e1 <= '9'))
        e1 = consonanteCasuale();

    // Conversione manuale in maiuscolo
    e1=toupper(e1);
    targa = targa.append(1, e1);

    /* Elemento 2 */
    char e2 = consonanteCasuale();
    targa = targa.append(1, e2);

    /* Elementi 3,4,5 */
    targa = targa.append(1, numeroCasuale());
    targa = targa.append(1, numeroCasuale());
    targa = targa.append(1, numeroCasuale());

    /* Elementi 6,7*/
    char e6 = (char)(rand() % 26 + 65);
    char e7 = (char)(rand() % 26 + 65);

    targa = targa.append(1, e6);
    targa = targa.append(1, e7);

    return targa;
}



/* metto le X al posto dei nunmeri*/
string numeriInX(string t)
{
    string nuova = t;
    for(int i=0; i<nuova.length(); i++)
    {
        if(nuova.at(i) >= '0' && nuova.at(i) <= '9')
            nuova.at(i) = 'X';
    }
    return nuova;
}

/* inverto usando at() */
string invertiTarga(string t)
{
    string inv = "";
    for(int i=t.length()-1; i>=0; i--)
        inv = inv.append(1, t.at(i));
    return inv;
}

/* verifica presenza di un numero */
bool contieneNumero(string t, int n)
{
    string s=to_string(n);    // converto num in stringa
       int pos=t.find(s);
       if(pos!=-1)
           return true;
       else
           return false;
}



int main()
{
    srand(time(NULL));

    string targa = generaTarga();
    cout << "Targa generata: " << targa << endl;

    int scelta;
    do
    {
        cout << "\nMENU\n";
        cout << "1 - Sostituisci numeri con X\n";
        cout << "2 - Inverti targa\n";
        cout << "3 - Cerca numero\n";
        cout << "0 - Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        if(scelta == 1)
            cout << numeriInX(targa) << endl;

        else if(scelta == 2)
            cout << invertiTarga(targa) << endl;

        else if(scelta == 3)
        {
            int n;
            cout << "Inserisci numero da cercare: ";
            cin >> n;
            if(contieneNumero(targa, n))
                cout << "Numero presente\n";
            else
                cout << "Numero NON presente\n";
        }

    } while(scelta != 0);

    return 0;
}
