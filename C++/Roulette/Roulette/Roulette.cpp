#include <iostream>
using namespace std;

int wallet = 1000;
int bet;
int valSiffra;

string valColor;

int main()
{
    cout << "V�lkommen till GaZoline Casino och Bar.\n";
    cout << "Du har 1000kr v�rt av chips.\n";
    cout << "Du kan satsa 100kr, 200kr eller 500kr f�r en chans att vinna!\n";

    cout << "Din sats: ";
    cin >> bet;

    if (bet == 100 || bet == 300 || bet == 500)
    {
        cout << "Din sats: " << bet << "kr" << endl;
    }
    else
    {
        cout << "Du m�ste satsa 100kr, 300kr eller 500kr";
    }
    
    cout << "Vill du satsa p� ett nummer eller en f�rg?\n";
    cout << "Du kan satsa p� ett nummer mellan 1 och 36 eller svart eller r�d f�rg\n";

    cout << "Ditt val (siffra): ";
    cin >> valSiffra;
    cout << "Ditt val (f�rg): ";
    cin >> valColor; 

    if (valSiffra >= 1 && valSiffra <= 36)
    {
        cout << "Du satsar p�>>: " << valSiffra;

    }
    else if (valColor == "svart" || valColor == "r�tt" || valColor == "r�d" || valColor == "Svart" || valColor == "R�tt" || valColor == "R�d")
    {
        cout << "Du satsar p�--: " << valColor;
    }
    else if (valSiffra == 0)
    {
        cout << "Du har fel >:(";
    }
    else
    {
        cout << "Du har fel >:)";
    }
}

