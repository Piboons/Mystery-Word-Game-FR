#include <iostream>
#include <ctime>
#include <cstdlib>

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
    do
    {
        //1:Saisie du mot par J1
        string motJ1;
        cout << "Joueur 1, entrez un mot : " << endl;
        cin >> motJ1;
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        //2:Mélange des lettres du mot
        string motMelange(melangerMot(motJ1));
        //3:On demande a J2 de trouver le mot
        string motJ2;
        int nbEssais(5);
        do
        {
            cout << "Joueur 2, vous avez " << nbEssais << " essai(s)." << endl;
            cout << "Quel est ce mot ? " << motMelange << endl;
            cin >> motJ2;
            nbEssais -= 1;
        }while (nbEssais > 0 && motJ2 != motJ1);

        if (nbEssais > 0)
        {
            cout << "Bravo ! Voulez vous faire une autre partie ? (O/N)";
            cin >> quitter;
        }
        else
        {
            cout << "Perdu ! Le mot etait " << motJ1 << ". Voulez vous faire une autre partie ? (O/N)" << endl;
            cin >> quitter;
        }


    }while (quitter != 'n' && quitter != 'N');
}
