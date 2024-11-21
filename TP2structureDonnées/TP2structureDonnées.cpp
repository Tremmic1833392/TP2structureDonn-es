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
    vector<char> tableau;
    stack<char> pile;

    cout << "Entrez une expression infix :\n>";     // Input de l'utilisateur pour l'expression
    getline(cin, expression);
    for (char c : expression) {
        tableau.push_back(c);
    }

    // Appel des fonctions pour valider,transfomer et evaluer l'expression donnée
    Postfix<char> postfix(tableau);
    postfix.valider(tableau);
    postfix.parenthesesEquilibrees(tableau);
    //postfix.transformerEnNombres(tableau);
    postfix.transformerEnPostfixe(pile, tableau);
    cout << postfix.evaluerExpression(pile, tableau);



    return 0;
}
