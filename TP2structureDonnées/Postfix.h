#pragma once

#include <string>
#include <stack>
#include <vector>

using namespace std;

template <class element>
class Postfix
{
    stack<element> pile_;
    vector<char> tableau_;

public:
    // Constructeur 
    Postfix(); // par defaut
    explicit Postfix(vector<char> tableau); // avec parametres

    // Destructeur
    ~Postfix();

    // Setters
    void setTableau(vector<char> tableau);

    // Fonctions
    void valider(vector<char> tableau);
    bool parentheses_equilibrees(vector<element> tableau);
    void transformer_en_nombres(vector<element> tableau);
    void transformer_en_postfixe(stack<element> pile, vector<element> tableau);
    int evaluer_expression(stack<element> pile, vector<element> tableau);
    int priorite(char signe);
};
