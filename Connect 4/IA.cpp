#include <iostream>
#include "functions.h"
#include "IA.h"

using namespace std;

const int bot=1;

void difficulty1(vector<vector<int>> tableau, bool win, int caseJoue, int numJoueur, int gravity, int caseTotal, int langue)
{
    int i;
    vector<int> valJouable = {1,2,3,4,5,6,7};
    while (!win && caseTotal<42)
    {
        numJoueur=1;
        drawTab(tableau);
        switch (langue)
        {
        case 1:
            cout<<"Colonne : ";
            break;
        case 2:
            cout<<"Column: ";
            break;
        case 3:
            cout<<"Columna : ";
            break;
        }
        cin>>caseJoue;
        caseTotal++;

        checkCase(tableau, caseJoue, langue);

        gravity = checkGravity(tableau, caseJoue, numJoueur);

        win = checkWin(tableau, gravity-1, caseJoue-1);

        if (!win)
        {
            numJoueur = 2;
            gravity = checkCaseAI(tableau, valJouable, i);
            win = checkWin(tableau, gravity-1, valJouable[i]-1);

            caseTotal++;
        }
    }
    winDisp(tableau, numJoueur, bot, langue, win);
}
