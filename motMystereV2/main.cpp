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
        cout << "Entrez le nombre de joueurs (1/2): ";
        cin >> nbJoueurs;
    }while (nbJoueurs != 1 && nbJoueurs != 2);

    if (nbJoueurs == 2)
    {
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
    else
    {
        //On importe le fichier dictionnaire
        ifstream dico("dico.txt");
        vector<string> dictionnaire;
        istream_iterator<string> itDico(dico);
        istream_iterator<string> finDico;
        back_insert_iterator<vector<string> > itDicoCopie(dictionnaire);
        copy(itDico, finDico, itDicoCopie);

        if (dictionnaire.size()!=0)
        {
            do
            {
                //1: On choisit un mot aleatoirement dans le fichier dictionnaire
                string motPC;
                cout << "Generation du mot a deviner en cours, veuillez patienter..." << endl;

                dictionnaire.begin();
                int numLigne(rand() % 323577);
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
                    cout << "Vous avez " << nbEssais << " essai(s)." << endl;
                    cout << "Quel est ce mot ? " << motMelange << endl;
                    cin >> motJoueur;
                    nbEssais -= 1;
                }while (nbEssais > 0 && motPC != motJoueur);

                if (nbEssais > 0)
                {
                    cout << "Bravo ! Voulez vous faire une autre partie ? (O/N)";
                    cin >> quitter;
                }
                else
                {
                    cout << "Perdu ! Le mot etait " << motPC << ". Voulez vous faire une autre partie ? (O/N)" << endl;
                    cin >> quitter;
                }


            }while (quitter != 'n' && quitter != 'N');
        }
        else
        {
            cout << "Erreur : impossible d'ouvrir le fichier dictionnaire." << endl;
        }


    }

    return 0;
}
