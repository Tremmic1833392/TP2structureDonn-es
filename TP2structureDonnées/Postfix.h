#pragma once

#include <string>
#include <stack>
#include <vector>

using namespace std;

template <class Element>
class Postfix
{
    stack<Element> pile_;
    vector<char> tableau_;

public:
    // Constructeur 
    Postfix(); // par defaut
    explicit Postfix(const vector<char>& tableau); // avec parametres

    // Destructeur
    ~Postfix();

    // Setters
    void set_tableau(const vector<char>& tableau);

    // Fonctions
    void valider(vector<char> tableau);
    bool parentheses_equilibrees(vector<Element> tableau);
    void transformer_en_nombres(vector<Element> tableau);
    void transformer_en_postfixe(stack<Element> pile, vector<Element> tableau);
    int evaluer_expression(stack<Element> pile, vector<Element> tableau);
    int priorite(char signe);
};
