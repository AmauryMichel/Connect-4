#include <iostream>
#include "functions.h"
#include "IA.h"

using namespace std;

int main()
{
    int langue;
    cout<<"Quelle langue ? / What language ? / \u00BF Cual idioma ?"<<endl
        <<"1 : Francais"<<endl
        <<"2 : English"<<endl
        <<"3 : Espanol"<<endl;
    cin>>langue;
    vector<int> vecLangue = {1,2,3};
    while (langue!=vecLangue)
    {
        cout<<"Veuillez entrer soit 1, soit 3 / Please enter either 1 or 3 / Por favor elije un numero entre 1 y 3"<<endl
            <<"1 : Francais"<<endl
            <<"2 : English"<<endl
            <<"3 : Espanol"<<endl;
        cin>>langue;
    }
    vector<vector<int>> tableau;
    initTab(tableau);
    bool win=false;
    int caseJoue,numJoueur=1,gravity,caseTotal=0;
    int play=1;
    int nbPlayers;
    switch (langue)
    {
    case 1:
        cout<<"1 ou 2 joueurs ? "<<endl;
        break;
    case 2:
        cout<<"1 or 2 players? "<<endl;
        break;
    case 3:
        cout<<"1 or 2 jugador ? "<<endl;
        break;
    }
    cin>>nbPlayers;
    vector<int> vecNbPlayers = {1,2};
    while (nbPlayers!=vecNbPlayers)
    {
        switch (langue)
        {
        case 1:
            cout<<"Nombre de joueur incorrect, veuillez entrer 1 ou 2 : "<<endl;
            break;
        case 2:
            cout<<"Incorrect number of players, please enter 1 or 2: "<<endl;
            break;
        case 3:
            cout<<"Numero der jugador incorrecto, por favor enije un numero entre 1 y 2 : "<<endl;
            break;
        }
        cin>>nbPlayers;
    }

    if (nbPlayers==1)
    {
        int difficulty;
        switch (langue)
        {
        case 1:
            cout<<"Quelle difficulte ?"<<endl
                <<"1 : Facile"<<endl
                <<"2 : Moyen"<<endl
                <<"3 : Difficile"<<endl;
            break;
        case 2:
            cout<<"What difficulty?"<<endl
                <<"1: Easy"<<endl
                <<"2: Medium"<<endl
                <<"3: Hard"<<endl;
            break;
        case 3:
            cout<<"\u00BF Qual difficultad ?"<<endl
                <<"1 : Facil"<<endl
                <<"2 : Medio"<<endl
                <<"3 : Dificil"<<endl;
            break;
        }
        cin>>difficulty;

        vector<int> vecDifficulty = {1,2,3};
        while (difficulty!=vecDifficulty)
        {
            switch (langue)
            {
            case 1:
                cout<<"Difficulte incorrecte, veuillez entrer un nombre entre 1 et 3 : ";
                break;
            case 2:
                cout<<"Incorrect difficulty, please enter a number between 1 and 3: ";
                break;
            case 3:
                cout<<"Difficultad incorrecto, por favor enije un numero entre 1 y 3 : ";
                break;
            }
        }

        switch (difficulty)
        {
        case 1:
            difficulty1(tableau, win, caseJoue, numJoueur, gravity, caseTotal, langue);
            break;
        case 2:
            cout<<"WIP";
            break;
        case 3:
            cout<<"WIP";
            break;
        }
    }

    if (nbPlayers==2)
    {
        const int bot=0;
        while(!win && caseTotal<42)
        {
            drawTab(tableau);

            ///Disp player number
            switch (langue)
            {
            case 1:
                cout<<"Joueur "<<numJoueur<<" : ";
                break;
            case 2:
                cout<<"Player "<<numJoueur<<" : ";
                break;
            case 3:
                cout<<"Jugador "<<numJoueur<<" : ";
                break;
            }

            cin>>caseJoue;

            checkCase(tableau, caseJoue, langue);

            gravity = checkGravity(tableau, caseJoue, numJoueur);

            win=checkWin(tableau, gravity-1, caseJoue-1);

            if (numJoueur==1 && !win)
                numJoueur++;
            else if (!win)
                numJoueur--;
            caseTotal++;
        }
        winDisp(tableau, numJoueur, bot, langue, win);
    }
    cout<<endl<<endl;
    cout<<"Programmed by Amaury MICHEL"<<endl
        <<"Espagnol translation by Gabriel LAUZZANNA && Daniel DOS SANTOS LUCIO"<<endl;
}

/**
    switch (langue)
    {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
    }
**/
