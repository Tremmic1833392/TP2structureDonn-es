// TP2structureDonnées.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include "Postfix.h"
using namespace std;
int main()
{
    // Variables
    string expression;
    vector<char> Tableau;
    stack<char> Pile;

    cout << "Entrez une expression infixee :\n>";
    getline(cin, expression);
    for (char c : expression) {
        Tableau.push_back(c);
    }
    
    /*
    Postfix<char> postfix(Tableau);
    postfix.Valider(Tableau);
    postfix.ParenthesesEquilibrees(Tableau);
    postfix.TransformerEnNombres(Tableau);
    postfix.TransformerEnPostfixe(Pile, Tableau);
*/

    
    return 0;
}