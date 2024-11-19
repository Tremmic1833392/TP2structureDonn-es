#include "Postfix.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <regex>
#include <cctype>
#include <stdexcept>

using namespace std;

template<class element>
inline Postfix<element>::Postfix() {}

template<class element>
Postfix<element>::Postfix(vector<char> Tableau) : Tableau(Tableau) {}

template<class element>
Postfix<element>::~Postfix()
{
	Tableau.clear();
}

template<class element>
void Postfix<element>::setTableau(vector<char> Tableau)
{
	this->Tableau = Tableau;
}

template<class element>
void Postfix<element>::Valider(vector<char> Tableau)
{
	// Variable
	bool valider = true;
	regex infix_regex("^[0-9()*\\/\\-%]+$");
	string expression(Tableau.begin(), Tableau.end());

	if (!regex_match(expression, infix_regex)) {
		cout << "\tL'expression est invalide !" << endl;
		cout << "\tEntrez une expression infix�e valide." << endl;
		valider = false;
	}
	else {
		cout << "L'expression est valide !" << endl;
	}
}

template<class element>
bool Postfix<element>::ParenthesesEquilibrees(vector<element> Tableau)
{
	// Ainsi, ")(" n'est pas valide
	stack<char> parentheseOuvrante;
	for (char x : Tableau) {
		if (x == '(') {
			parentheseOuvrante.push(x);
		}
		else if (x == ')') {
			if (parentheseOuvrante.empty()) {
				return false; // Premi�re parenth�se est fermante alors non valide
			}
			parentheseOuvrante.pop();
		}
	}
	return parentheseOuvrante.empty();

}

template<class element>
void Postfix<element>::TransformerEnNombres(vector<element> Tableau)
{
	for (int i = 0; i < Tableau.size(); i++)
	{
		if (Tableau[i].isDigit()) {
			Tableau[i] = stoi(string(Tableau[i]));
		}
	}
}

template<class element>
int Postfix<element>::Priorite(char signe)
{
	return(signe == '(')? 3:
	(signe == '*' || signe == '/' || signe == '%') ? 2 :
		(signe == '+' || signe == '-') ? 1 :
		0;
}

template<class element>
void Postfix<element>::TransformerEnPostfixe(stack<element> Pile, vector<element> Tableau)
{
	// Vatiables
	vector<element> expressionPostfix;

	for (int x = 0; x < Tableau.size(); x++)
	{
		if (isDigit(Tableau[x])) {
			expressionPostfix.push_back(Tableau[x]);
		}
		// Is symbole
		else
		{
			if (Pile.empty() || Pile.top() == "(") {
				Pile.push(Tableau[x]);
			}
			else
			{
				if (Tableau[x] == "(")
				{
					Pile.push(Tableau[x]);
				}
				else if (Tableau[x] == ")")
				{
					while (Pile.top() != '(') {
						expressionPostfix.push_back(Pile.top());
						Pile.pop();
					}
					Pile.pop();
				}
				else if (Priorite(Pile.top()) > Priorite(Tableau[x]))
				{
					Pile.push(Tableau[x]);
				}
				else
				{
					expressionPostfix.push_back(Pile.top());
					Pile.pop();
					Pile.push(Tableau[x]);
				}
			}
		}
	}
	while (!Pile.empty())
	{
		expressionPostfix.push_back(Pile.top());
		Pile.pop();
	}

	Tableau = expressionPostfix; 
	cout << Tableau;
}

template<class element>
int Postfix<element>::EvaluerExpression(stack<element> Pile, vector<element> Tableau)
{
	stack<int> resultat;
	int nb1, nb2 = 0;

	for (element x : Tableau) {
		if (isdigit(x)) {
			// Conversion char -> int
			resultat.push(x - '0'); 
		}
		else {
			
			if (resultat.size() < 2) {
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
				if (nb2 == 0) {
					throw runtime_error("Modulo par zéro.");
				}
				resultat.push(nb1 % nb2);
				break;

			default:
				throw runtime_error("Opérateur non supporté.");
			}
		}
	}

	if (resultat.size() != 1) {
		throw runtime_error("Expression postfixée invalide : taille finale de la pile incorrecte.");
	}

	return resultat.top();
}