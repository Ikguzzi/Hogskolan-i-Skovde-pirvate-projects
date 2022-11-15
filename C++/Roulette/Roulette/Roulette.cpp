#include <iostream>;
#include <ctime>; 
using namespace std;

int gambleAge;
int winPrize;
int wallet = 1000 + winPrize;
int bet;
int valNumber = 0;
int valColorVar;
int spinRand;
int spinRandNumber;
int winNumber = bet * 10;
int winColor;
int replay = 0;

char spinConfirm;
char replayQuestion;

string valType;
string valColor = "0";
string spinRandColor;

int main()
{
    while ( replay != '1' || replay != 'y')
    {
        replay = 0;
        bet = 0;

        cout << "You have to be over 18 to play this game.\n";

        cout << "How old are you?\n";
        cin >> gambleAge;

        if (gambleAge < 18)                                                                             // �ldersgr�ns
        {
            cout << "You have to be over 18 to play this game.\n";
            return 0;
        }

        cout << "Welcome to GaZoline Energy bar and casino!\n";
        cout << "You have " << wallet << " kr worth of chips.\n";                                            // Definerar regler osv.
        cout << "You can place bets worth 100, 300 or 500 kr to win amazing prices!\n";

        while (bet != 100 && bet != 300 && bet != 500)
        {
            cout << "Your bet: ";
            cin >> bet;

            if (bet == 100 || bet == 300 || bet == 500)                                                     // Satsning
            {
                cout << "Your bet: " << bet << "kr" << endl;
            }
            else
            {
                cout << "You have to bet 100, 300 or 500 kr to play.\n";
            }
        }

        /*  H�r f�r spelaren best�mma vad de vill satsa p�.
            Valen �r mellan ett nummer mellan 1 - 36 eller en svart eller r�d f�rg.

            Mina while loops fastnade d�r �ven om jag satte vilkoret p� att loopa s� l�nge valColor != Black.
            Tanken var att n�r anv�ndaren skriver in "Black" att iterationen slutar d� valColor = "Black", men det funkar inte.
            Funkar n�r jag gav valColor och valNumber ett v�rde p� 0 och satte iterationens vilkor p� != 0 */

        cout << "Do you want ot bet on a color or a number?\n";
        cin >> valType;

        if (valType == "Color" || valType == "color" || valType == "COLOR")                             // val mellan f�rg eller nummer
        {
            while (valColor == "0")
            {
                cout << "You're betting on a " << valType << ". Do you want to bet on red or black?\n";
                cin >> valColor;

                if (valColor == "Black" || valColor == "black" || valColor == "BLACK")
                {
                    cout << "You've placed a bet on " << bet << " kr on " << valColor << endl;
                    valColorVar = 0;
                }
                else if (valColor == "Red" || valColor == "red" || valColor == "RED")
                {
                    cout << "You've placed a bet on " << bet << " kr on " << valColor << endl;
                    valColorVar = 1;
                }
                else if (valColor != "Black" || valColor != "black" || valColor != "BLACK" || valColor != "Red" || valColor != "red" || valColor != "RED")
                {
                    cout << "You have to choose between red or black to place a bet.\n";
                }
            }
        }
        else if (valType == "Number" || valType == "number" || valType == "Number")
        {
            while (valNumber == 0)
            {
                cout << "Place a bet on a number between 1-36.\n";
                cin >> valNumber;

                if (valNumber >= 1 && valNumber <= 36)
                {
                    cout << "You've placed a bet on " << bet << " kr on number " << valNumber << endl;
                }
                else if (valNumber <= 1 && valNumber >= 36)
                {
                    cout << "This number does not exist on the roulette wheel.\n";
                }
            }
        }
        else
        {
            return 0;
        }

        /* H�r sker sj�lvaste roulettespelet d�r koden nedan, beroende p� om spelaren valt att satsa p� en f�rg eller ett nummer, ger ett slumpvalt resultat.
        */

        while (spinConfirm != 'Y' && spinConfirm != 'y')
        {
            cout << "Are you ready to spin? Y/N\n";
            cin >> spinConfirm;

            if (spinConfirm == 'Y' || spinConfirm == 'y')
            {
                if (valColor == "Black" || valColor == "black" || valColor == "BLACK" || valColor == "Red" || valColor == "red" || valColor == "RED")
                {
                    srand(time(0));
                    spinRand = rand() % 2;

                    if (spinRand == 0)          // rand() v�ljer antingen 0 eller 1, vilket beroende p� v�rde spottar ut "Black" eller "Red".
                    {
                        spinRandColor = "black";
                    }
                    else if (spinRand == 1)
                    {
                        spinRandColor = "red";
                    }
                    cout << "The ball landed on a " << spinRandColor << " square." << endl;
                }
                else if (valNumber >= 1 && valNumber <= 36)             // rand() v�ljer en siffra mellan 1 - 36 och ger en siffra spinRand.
                {
                    srand(time(0));
                    spinRandNumber = rand() % 36 + 1;

                    cout << "The ball landed on a " << spinRandNumber << endl;
                }
            }
            else if (spinConfirm != 'Y' || spinConfirm != 'y')
            {
                cout << "You need to type Y to play.\n";
            }
        }

        if (spinRand == valColorVar || spinRandNumber == valNumber)
        {
            cout << "Congrats! You've won home the full prize!";
            if (spinRand == valColorVar)
            {
                winPrize = bet * 3;
                cout << "You've won " << winPrize << " kr!";
                wallet += winPrize;
            }
            else if (spinRandNumber == valNumber)
            {
                winPrize = bet * 10;
                cout << "You've won " << winNumber << " kr!";
                wallet += winPrize;
            }
        }
        else
        {
            cout << "Sorry, you didn't win this time.";
            wallet -= bet;
        }

        cout << "Do you want to play again? Y/N";
        cin >> replayQuestion;

        if (replayQuestion == 'Y' || replayQuestion == 'y')
        {
            replayQuestion = 1;
        }
        else if (replayQuestion == 'N' || replayQuestion == 'n')
        {
            return 0;
        }
    }
}

