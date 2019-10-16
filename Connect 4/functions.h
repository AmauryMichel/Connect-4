#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <vector>

using namespace std;

void initTab(vector<vector<int>>&);
void drawTab(vector<vector<int>>);
bool checkWin(vector<vector<int>>, int, int);
void checkCase(vector<vector<int>>, int&, int);
int checkGravity(vector<vector<int>>&, int, int);
int checkCaseAI(vector<vector<int>>&, vector<int>&, int&);
void winDisp(vector<vector<int>>, int, int, int, bool);

bool operator!=(int, vector<int>);

#endif // FUNCTIONS_H_INCLUDED
