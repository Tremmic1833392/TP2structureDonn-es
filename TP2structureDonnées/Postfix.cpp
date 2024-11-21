#include "Postfix.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<class element>
inline Postfix<element>::Postfix() {}

template<class element>
Postfix<element>::Postfix(vector<char> Tableau) : Tableau(Tableau) {}

template<class element>
Postfix<element>::~Postfix()
{
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
		cout << "\tEntrez une expression infixée valide." << endl;
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
				return false; // Première parenthèse est fermante alors non valide
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
int Postfix<element>::Priorite(char signe) {
	 if (signe == "*" || "/" || "%")
	{
		return 2;
	}
	else if (signe == "+" || "-")
	{
		return 1;
	}
	return 0;
}

template<class element>
void Postfix<element>::TransformerEnPostfixe(stack<element> Pile, vector<element> Tableau)
{
	vector<element> expressionPostfix;

	for (int i = 0; i < Tableau.size(); i++)
	{
		if (Tableau[i].isDigit())
		{
			expressionPostfix.push_back();
		}
		else
		{
			if (Pile.empty() || Pile.top() == "(") {
				Pile.push(Tableau[i]);
			}
			else
			{
				if (Tableau[i] == "(")
				{
					Pile.push(Tableau[i]);
				}
				else if (Tableau[i] == ")")
				{
					while (pileOperateurs.top() != '(') {
						expressionPostFix.push_back(Pile.top());
						Pile.pop();
					}
				}
				else if (Priorite(Pile.top()) > Priorite(Tableau[i]))
				{
					Pile.push(Tableau[i]);
				}
				else
				{
					expressionPostFix.push_back(Pile.top());
					Pile.pop();
					Pile.push(Tableau[i]);
				}
			}
		}
	}
	while (!Pile.empty())
	{
		expressionPostfix.push_back(Pile.top());
		Pile.pop();
	}
}

template<class element>
int Postfix<element>::EvaluerExpression(stack<element> Pile, vector<element> Tableau)
{
	return 0;
}



