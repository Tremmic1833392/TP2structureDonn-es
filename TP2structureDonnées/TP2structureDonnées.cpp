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
    vector<char> tableau = {'3', '4', '+', '2', '*'};
    const vector<char>& tab = {'3', '4', '+', '2', '*'};
    stack<char> pile;

    cout << "Entrez une expression infixee :\n>";
    getline(cin, expression);
    for (char c : expression)
    {
        tableau.push_back(c);
    }
Postfix<char> postfixInt(tableau);
    

    /*
    postfixInt.transformer_en_postfixe(postfixInt.pile_, tableau);  // Utiliser une méthode pour transformer
    int resultat = postfixInt.evaluer_expression(postfixInt.pile_, tableau);  // Évaluer l'expression
    cout << "Résultat : " << resultat << endl;  // Afficher le résultat
*/
    /*
    Postfix<char> postfix(Tableau);
    postfix.Valider(Tableau);
    postfix.ParenthesesEquilibrees(Tableau);
    postfix.TransformerEnNombres(Tableau);
    postfix.TransformerEnPostfixe(Pile, Tableau);
*/


    return 0;
}
