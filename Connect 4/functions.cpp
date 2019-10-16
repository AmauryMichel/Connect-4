#include <iostream>
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void initTab(vector<vector<int>>& tableau)
{
    tableau=
    {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };
}

void drawTab(vector<vector<int>> tableau)
{
    int i,j;
    for (int i=0; i<7; i++)
        cout<<"    "<<i+1<<"\t";
    cout<<endl;
    for (int i=0; i<6; i++)
    {
        cout<<"---------------------------------------------------------"<<endl;
        for(j=0; j<7; j++)
        {
            cout<<"|";
            if (tableau[i][j]==0)
                cout<<"\t";
            else if (tableau[i][j]==1)
                cout<<"   /\\  ";
            else
                cout<<"   \\/  ";
        }
        cout<<"|"<<endl<<"|";
        for(j=0; j<7; j++)
        {
            if (tableau[i][j]==0)
                cout<<"\t";
            else if (tableau[i][j]==1)
                cout<<"   \\/  ";
            else
                cout<<"   /\\  ";
            cout<<"|";
        }
        cout<<endl;
    }
    cout<<"---------------------------------------------------------"<<endl;
}

bool checkWin(vector<vector<int>> tableau, int ligne, int colonne)
{
    int checkDiag1=0, checkDiag2=0, checkBas=0, checkLigne=0;
    int x=1;

    while (colonne-x>=0 && tableau[ligne][colonne]==tableau[ligne][colonne-x])
    {
        checkLigne++;
        x++;
    }
    x=1;
    while (colonne+x<=6 && tableau[ligne][colonne]==tableau[ligne][colonne+x])
    {
        checkLigne++;
        x++;
    }
    if (checkLigne>=3)
        return true;


    x=1;
    while (colonne-x>=0 && ligne-x>=0 && tableau[ligne][colonne]==tableau[ligne-x][colonne-x])
    {
        checkDiag1++;
        x++;
    }
    x=1;
    while (colonne+x<=6 && ligne+x<=5 && tableau[ligne][colonne]==tableau[ligne+x][colonne+x])
    {
        checkDiag1++;
        x++;
    }
    if (checkDiag1>=3)
        return true;


    x=1;
    while (colonne+x<=6 && ligne-x>=0 && tableau[ligne][colonne]==tableau[ligne-x][colonne+x])
    {
        checkDiag2++;
        x++;
    }
    x=1;
    while (colonne-x>=0 && ligne+x<=5 && tableau[ligne][colonne]==tableau[ligne+x][colonne-x])
    {
        checkDiag2++;
        x++;
    }
    if (checkDiag2>=3)
        return true;


    x=1;
    while (ligne-x>=0 && tableau[ligne][colonne]==tableau[ligne-x][colonne])
    {
        checkBas++;
        x++;
    }
    x=1;
    while (ligne+x<=5 && tableau[ligne][colonne]==tableau[ligne+x][colonne])
    {
        checkBas++;
        x++;
    }
    if (checkBas>=3)
        return true;
}

void checkCase(vector<vector<int>> tableau, int& caseJoue, int langue)
{
    ///Check if the given value works
    while ((caseJoue>7 || caseJoue<1) || (tableau[0][caseJoue-1]!=0))
    {
        ///Check if the given value is in the array
        if ((caseJoue>7 || caseJoue<1))
        {
            switch (langue)
            {
            case 1:
                cout<<"Veuillez entrer un nombre entre 1 et 7 : ";

                break;
            case 2:
                cout<<"Please enter a number between 1 and 7: ";

                break;
            case 3:
                cout<<"Elije un numero entre 1 y 7 : ";

                break;
            }

            cin>>caseJoue;
        }

        ///Check if the column isn't already full
        if (tableau[0][caseJoue-1]!=0)
        {
            switch (langue)
            {
            case 1:
                cout<<"Colonne "<<caseJoue<<" est remplie, veuillez sélectionner une autre colonne : ";
                break;
            case 2:
                cout<<"Column "<<caseJoue<<" is full, please enter another colum: ";
                break;
            case 3:
                cout<<"Columna "<<caseJoue<<" es llena, por favor elije una otra columna : ";
                break;
            }

            cin>>caseJoue;
        }
    }
}

int checkGravity(vector<vector<int>>& tableau, int caseJoue, int numJoueur)
{
    ///Check the line
    bool empty=true;
    int gravity=0;
    while(empty && gravity<5)
    {
        empty=tableau[gravity+1][caseJoue-1]==0;
        gravity++;
    }
    if (empty)
        gravity++;
    tableau[gravity-1][caseJoue-1]=numJoueur;

    return gravity;
}

bool operator!=(int langue, vector<int> vecLangue)
{
    for (int i=0; i<vecLangue.size(); i++)
        if (langue==vecLangue[i])
            return false;
    return true;
}

int checkCaseAI(vector<vector<int>>& tableau, vector<int>& valJouable, int& i)
{
    int gravity;
    bool check=false;
    while (!check)
    {
        srand (time(NULL));
        i = rand() % valJouable.size();
        if (tableau[0][valJouable[i]-1]==0)
        {
            cout<<valJouable[i];
            gravity=checkGravity(tableau, valJouable[i], 2);
            check=true;
        }
        else
            valJouable.erase(valJouable.begin() + i);
    }
    return gravity;
}

void winDisp(vector<vector<int>> tableau, int numJoueur, int bot, int langue, bool win)
{
    drawTab(tableau);
    if (win)
    {
        if (bot==0 || numJoueur==1)
        {
            switch (langue)
            {
            case 1:
                cout<<"Joueur "<<numJoueur<<" a gagne";
                break;
            case 2:
                cout<<"Player "<<numJoueur<<" won";
                break;
            case 3:
                cout<<"Jugador "<<numJoueur<<" gano";
                break;
            }
        }
        else
            switch (langue)
            {
            case 1:
                cout<<"L'IA a gagne";
                break;
            case 2:
                cout<<"The AI won";
                break;
            case 3:
                cout<<"AI gano";
                break;
            }
    }
    else
        switch (langue)
        {
        case 1:
            cout<<"Match nul";
            break;
        case 2:
            cout<<"Tie";
            break;
        case 3:
            cout<<"Equalidad";
            break;
        }
 /**   switch(langue)
    {
    case 1:
        cout<<"Voulez-vous jouer à nouveau ?";
        break;
    case 2:
        cout<<"Do you want to play again?";
        break;
    case 3:
        cout<<"Je connais pas cette langue";
        break;
    }
    **/
}
