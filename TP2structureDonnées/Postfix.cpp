#include "Postfix.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <regex>
#include <cctype>
#include <stdexcept>

using namespace std;

template <class element>
inline Postfix<element>::Postfix()
{
}

template <class element>
Postfix<element>::Postfix(vector<char> tableau) : tableau_(tableau)
{
}

template <class element>
Postfix<element>::~Postfix()
{
    tableau_.clear();
}

template <class element>
void Postfix<element>::setTableau(vector<char> tableau)
{
    this->Tableau = tableau;
}

template <class element>
void Postfix<element>::valider(vector<char> tableau)
{
    // Variable
    bool valider = true;
    regex infix_regex("^[0-9()*\\/\\-%]+$");
    string expression(tableau.begin(), tableau.end());

    if (!regex_match(expression, infix_regex))
    {
        cout << "\tL'expression est invalide !" << endl;
        cout << "\tEntrez une expression infix�e valide." << endl;
        valider = false;
    }
    else
    {
        cout << "L'expression est valide !" << endl;
    }
}

template <class element>
bool Postfix<element>::parentheses_equilibrees(vector<element> tableau)
{
    // Ainsi, ")(" n'est pas valide
    stack<char> parentheseOuvrante;
    for (char x : tableau)
    {
        if (x == '(')
        {
            parentheseOuvrante.push(x);
        }
        else if (x == ')')
        {
            if (parentheseOuvrante.empty())
            {
                return false; // Premi�re parenth�se est fermante alors non valide
            }
            parentheseOuvrante.pop();
        }
    }
    return parentheseOuvrante.empty();
}

template <class element>
void Postfix<element>::transformer_en_nombres(vector<element> tableau)
{
    for (int i = 0; i < tableau.size(); i++)
    {
        if (tableau[i].isDigit())
        {
            tableau[i] = stoi(string(tableau[i]));
        }
    }
}

template <class element>
int Postfix<element>::priorite(char signe)
{
    return (signe == '(')
               ? 3
               : (signe == '*' || signe == '/' || signe == '%')
               ? 2
               : (signe == '+' || signe == '-')
               ? 1
               : 0;
}

template <class element>
void Postfix<element>::transformer_en_postfixe(stack<element> pile, vector<element> tableau)
{
    // Vatiables
    vector<element> expressionPostfix;

    for (int x = 0; x < tableau.size(); x++)
    {
        if (isDigit(tableau[x]))
        {
            expressionPostfix.push_back(tableau[x]);
        }
        // Is symbole
        else
        {
            if (pile.empty() || pile.top() == "(")
            {
                pile.push(tableau[x]);
            }
            else
            {
                if (tableau[x] == "(")
                {
                    pile.push(tableau[x]);
                }
                else if (tableau[x] == ")")
                {
                    while (pile.top() != '(')
                    {
                        expressionPostfix.push_back(pile.top());
                        pile.pop();
                    }
                    pile.pop();
                }
                else if (Priorite(pile.top()) > Priorite(tableau[x]))
                {
                    pile.push(tableau[x]);
                }
                else
                {
                    expressionPostfix.push_back(pile.top());
                    pile.pop();
                    pile.push(tableau[x]);
                }
            }
        }
    }
    while (!pile.empty())
    {
        expressionPostfix.push_back(pile.top());
        pile.pop();
    }

    tableau = expressionPostfix;
    cout << tableau;
}

template <class element>
int Postfix<element>::evaluer_expression(stack<element> pile, vector<element> tableau)
{
    stack<int> resultat;
    int nb1, nb2 = 0;

    for (element x : tableau)
    {
        if (isdigit(x))
        {
            // Conversion char -> int
            resultat.push(x - '0');
        }
        else
        {
            if (resultat.size() < 2)
            {
                throw runtime_error("Pile contient moins de 2 éléments");
            }

            nb2 = resultat.top();
            resultat.pop();
            nb1 = resultat.top();
            resultat.pop();

            switch (x)
            {
            case '+':
                resultat.push(nb1 + nb2);
                break;

            case '-':
                resultat.push(nb1 - nb2);
                break;

            case '*':
                resultat.push(nb1 * nb2);
                break;

            case '/':
                resultat.push(nb1 / nb2);
                break;

            case '%':
                if (nb2 == 0)
                {
                    throw runtime_error("Modulo par zéro.");
                }
                resultat.push(nb1 % nb2);
                break;

            default:
                throw runtime_error("Opérateur non supporté.");
            }
        }
    }

    if (resultat.size() != 1)
    {
        throw runtime_error("Expression postfixée invalide : taille finale de la pile incorrecte.");
    }

    return resultat.top();
}
