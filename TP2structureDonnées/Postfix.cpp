#include "Postfix.h"
#include <iostream>
#include <stack>
#include <vector>
#include <regex>
#include <cctype>
#include <stdexcept>

using namespace std;

template class Postfix<char>;

template <class Element>
Postfix<Element>::Postfix()
{
}

template <class Element>
Postfix<Element>::Postfix(const vector<char>& tableau) : tableau_(tableau)
{
}
/*
template <class Element>
Postfix<Element>::~Postfix()
{
    tableau_.clear();
}
*/
//template <>
Postfix<char>::~Postfix()
{
    tableau_.clear();
}

template <class Element>
void Postfix<Element>::set_tableau(const vector<char>& tableau)
{
    tableau_ = tableau;
}

template <class Element>
void Postfix<Element>::valider(vector<char> tableau)
{
    // Variable
    bool valider = true;
    const regex infix_regex("^[0-9()*\\/\\-%]+$");
    const string expression(tableau.begin(), tableau.end());

    if (!regex_match(expression, infix_regex))
    {
        cout << "\tL'expression est invalide !" << endl;
        cout << "\tEntrez une expression infixee valide." << endl;
        valider = false;
    }
    else
    {
        cout << "L'expression est valide !" << endl;
    }
}

template <class Element>
bool Postfix<Element>::parentheses_equilibrees(vector<Element> tableau)
{
    stack<char> parenthese_ouvrante;
    for (char x : tableau)
    {
        if (x == '(')
        {
            parenthese_ouvrante.push(x);
        }
        else if (x == ')')
        {
            if (parenthese_ouvrante.empty())
            {
                return false; // Premiere parenthese est fermante alors non valide
            }
            parenthese_ouvrante.pop();
        }
    }
    return parenthese_ouvrante.empty();
}

template <class Element>
void Postfix<Element>::transformer_en_nombres(vector<Element> tableau)
{
    for (int i = 0; i < tableau.size(); i++)
    {
        if (isdigit(tableau[i]))
        {
            tableau[i] = stoi(string(1, tableau[i]));
        }
    }
}

template <class Element>
int Postfix<Element>::priorite(const char signe)
{
    return (signe == '(')
               ? 3
               : (signe == '*' || signe == '/' || signe == '%')
               ? 2
               : (signe == '+' || signe == '-')
               ? 1
               : 0;
}

template <class Element>
void Postfix<Element>::transformer_en_postfixe(stack<Element> pile, vector<Element> tableau)
{
    // Variables
    vector<Element> expression_postfix;

    for (int x = 0; x < tableau.size(); x++)
    {
        if (isdigit(tableau[x]))
        {
            expression_postfix.push_back(tableau[x]);
        }
        // Is symbole
        else
        {
            if (pile.empty() || pile.top() == '(')
            {
                pile.push(tableau[x]);
            }
            else
            {
                if (tableau[x] == '(')
                {
                    pile.push(tableau[x]);
                }
                else if (tableau[x] == ')')
                {
                    while (pile.top() != '(')
                    {
                        expression_postfix.push_back(pile.top());
                        pile.pop();
                    }
                    pile.pop();
                }
                else if (priorite(pile.top()) > priorite(tableau[x]))
                {
                    pile.push(tableau[x]);
                }
                else
                {
                    expression_postfix.push_back(pile.top());
                    pile.pop();
                    pile.push(tableau[x]);
                }
            }
        }
    }
    while (!pile.empty())
    {
        expression_postfix.push_back(pile.top());
        pile.pop();
    }

    tableau = expression_postfix;
    //cout << tableau; // '<<' binaire    : aucun opérateur trouvé qui accepte un opérande de partie droite de type 'vector<char,allocator<char>>' (ou il n'existe pas de conversion acceptable)
}

template <class Element>
int Postfix<Element>::evaluer_expression(stack<Element> pile, vector<Element> tableau)
{
    stack<int> resultat;
    int nb1 = 0, nb2 = 0;

    for (Element x : tableau)
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


