#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;
string melangerMot(string mot)
{
    string motMelange;
    int position;

    do
    {
        position = rand() % mot.size();
        char lettre(mot[position]);
        motMelange += lettre;
        mot.erase(position, 1);
    }while (mot.size() > 0);
    return motMelange;

}
int main()
{
    srand(time(0));
    char quitter;
    int nbJoueurs;
    do
    {
        cout << "Choose the number of players (1/2): ";
        cin >> nbJoueurs;
    }while (nbJoueurs != 1 && nbJoueurs != 2);

    if (nbJoueurs == 2)
    {
        do
        {
            //1:Saisie du mot par J1
            string motJ1;
            cout << "Player 1, choose a word : " << endl;
            cin >> motJ1;
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            //2:Mélange des lettres du mot
            string motMelange(melangerMot(motJ1));
            //3:On demande a J2 de trouver le mot
            string motJ2;
            int nbEssais(5);
            do
            {
                cout << "Player 2, you have " << nbEssais << " trial(s)." << endl;
                cout << "Guess that word ! " << motMelange << endl;
                cin >> motJ2;
                nbEssais -= 1;
            }while (nbEssais > 0 && motJ2 != motJ1);

            if (nbEssais > 0)
            {
                cout << "GG ! Do you want to play again ? (Y/N)";
                cin >> quitter;
            }
            else
            {
                cout << "Game over ! The answer was " << motJ1 << ". Do you want to play again ? (Y/N)" << endl;
                cin >> quitter;
            }


        }while (quitter != 'n' && quitter != 'N');
    }
    else
    {
        //On importe le fichier dictionnaire
        ifstream dico("dicoEN.txt");
        istream_iterator<string> itDico(dico);
        if (*itDico != "")
        {
            do
            {
                //1: On choisit un mot aleatoirement dans le fichier dictionnaire
                string motPC;
                cout << "Loading, please wait..." << endl;

                int numLigne(rand() % 1000);
                for (int k(0); k != numLigne; k++)
                {
                    itDico++;
                }
                motPC = *itDico;
                //2: On melange les lettres du mot
                string motMelange(melangerMot(motPC));
                //3: On fait deviner le mot au joueur
                string motJoueur;
                int nbEssais(7);
                do
                {
                    cout << "You have " << nbEssais << " trial(s)." << endl;
                    cout << "Guess that word ! " << motMelange << endl;
                    cin >> motJoueur;
                    nbEssais -= 1;
                }while (nbEssais > 0 && motPC != motJoueur);

                if (nbEssais > 0)
                {
                    cout << "GG ! Do you want to play again ? (Y/N)";
                    cin >> quitter;
                }
                else
                {
                    cout << "Game over ! The answer was " << motPC << ". Do you want to play again ? (Y/N)" << endl;
                    cin >> quitter;
                }


            }while (quitter != 'n' && quitter != 'N');
        }
        else
        {
            cout << "Error : dictionary file could not be opened." << endl;
        }


    }

    return 0;
}
