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
void Postfix<element>::TransformerEnPostfixe(stack<element> Pile, vector<element> Tableau)
{
}

template<class element>
int Postfix<element>::EvaluerExpression(stack<element> Pile, vector<element> Tableau)
{
	return 0;
}


/*

void transformerennombres(vector <element> Tableau) { // transforme les nombres lus encaractères en valeurs numériques.
	for (int i = 0; i < Tableau.size(); i++)
	{
		if (Tableau[i].isDigit()) {

		}
	}
};
void transformerenpostfixe(stack<element> Pile, vector <element> Tableau) { // transformel’expression lue en une expression postfixée et l’afficher sur écran.
};
int evaluer_expression(stack<element> Pile, vector<element> Tableau) { // évalue l’expressionpostfixée et affiche sa valeur sur écran.
};
*/
