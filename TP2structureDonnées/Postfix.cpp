#include "Postfix.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <regex>
#include <cctype>
#include <stdexcept>

using namespace std;
template class Postfix<char>;

// Constructeur par default
template<class Element>
Postfix<Element>::Postfix() {}

// Constructeur avec parametre
template<class Element>
Postfix<Element>::Postfix(vector<Element> Tableau) : Tableau(Tableau) {}

// Destructeur
template<class Element>
Postfix<Element>::~Postfix()
{
	Tableau.clear();
}

// Setter de tableau
template<class Element>
void Postfix<Element>::setTableau(vector<Element> Tableau)
{
	this->Tableau = Tableau;
}

// Validation de l'expression fournis par l'utilisateur a l'aide d'une regex
template<class Element>
void Postfix<Element>::valider(vector<Element>& Tableau)
{
	// Variable
	bool valider = true;
	regex infix_regex("^[0-9+*/()-]*$");
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


// Verification des parentheses 
template<class Element>
bool Postfix<Element>::parenthesesEquilibrees(vector<Element>& Tableau)
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

// Tranformation des nombre(charactere) en nombre(int)
template<class Element>
void Postfix<Element>::transformerEnNombres(vector<Element>& Tableau)
{
	for (int i = 0; i < Tableau.size(); i++)
	{
		if (isdigit(Tableau[i]))
		{
			Tableau[i] = Tableau[i] - '0';
		}
	}
}


// Priorote des signes pour savoir quoi faire losrque deux signe se rencontre dans le stack 
template<class Element>
int Postfix<Element>::priorite(char signe)
{
	return(signe == '(')? 3:								// Si ( retourne priorite 3
	(signe == '*' || signe == '/' || signe == '%') ? 2 :	// Si *,/,% retourne priorite 2
		(signe == '+' || signe == '-') ? 1 :				// Si +,- retourne priorite 1
		0;
}

// Transformation de l'expression entrer par l'utilisateur en postfix
template<class Element>
void Postfix<Element>::transformerEnPostfixe(stack<Element>& Pile, vector<Element>& Tableau)
{
	// Vatiables
	vector<Element> expressionPostfix;

	for (int x = 0; x < Tableau.size(); x++)
	{
		if (isdigit(Tableau[x])) {							// Si Tableau[x] est un chiffre on le met dans l'expressionPostFix
			expressionPostfix.push_back(Tableau[x]);
		}
		else
		{
			if (Pile.empty()) {					
				Pile.push(Tableau[x]);						// Si Tableau[x] est un operateur et que le stack est empty, alors on l'ajoute au stack
			}
			else
			{
				if (Tableau[x] == '(')				
				{
					Pile.push(Tableau[x]);					// Si Tableau[x] est une ( alors on l'ajoute dans le stack 
				}
				else if (Tableau[x] == ')')					// Si le Tableau[x] est une ) tant que le top du stack n'est pas un (, on ajoute et pop le top du stack a expresssionPostfix
				{
					while (Pile.top() != '(') {
						expressionPostfix.push_back(Pile.top());
						Pile.pop();
					}
					Pile.pop();
				}
				else if (priorite(Pile.top()) > priorite(Tableau[x]))		// Si c'est un operateur et que le stack n'est pas vide on verifie leurs prioriye
				{
					Pile.push(Tableau[x]);										// Si la priorite dans le stack est plus haute on ajoute Tableau[x] au stack
				}
				else
				{
					expressionPostfix.push_back(Pile.top());				// Si le top est plus petit ou égal on push le top du stack, ensuite on le pop et on push Tableau[x] dans le stack
					Pile.pop();
					Pile.push(Tableau[x]);
				}
			}
		}
	}
	while (!Pile.empty())								// Au final on push,pop le stack dans l'expressionPostfix tant qu'elle n'est pas vide			
	{
		expressionPostfix.push_back(Pile.top());
		Pile.pop();
	}

	Tableau = expressionPostfix;						// Affichage de l'expressionPostfix
	cout << "Expression Postfix : ";
	for (const auto& element : Tableau) {
		cout << element << " ";
	}
	cout << endl;}

template<class Element>
int Postfix<Element>::evaluerExpression(stack<Element>& Pile, vector<Element>& Tableau)
{
	stack<int> resultat;
	int nb1, nb2 = 0;

	for (Element x : Tableau) {
		if (isdigit(x)) {				
			// Conversion char -> int
			resultat.push(x - '0'); 
		}
		else {
			
			if (resultat.size() < 2) {													// Verification si l'expression est plus grande que 2 ex: 2+
				throw runtime_error("Pile contient moins de 2 éléments");	
			}

			nb2 = resultat.top();					// Prend le top de stack et le met dans nb2 ensuite pop
			resultat.pop();				
			nb1 = resultat.top();					// Prend le top du stack et le met dans le nb1 ensuite pop
			resultat.pop();

			switch (x)								// Verifie qu,est ce que x repreésente commme operateur et applique l'operation nécéssaire
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
					throw runtime_error("Modulo par zéro.");	// Verification du modulo 0
				}
				resultat.push(nb1 % nb2);
				break;

			default:
				throw runtime_error("Opérateur non supporté.");
			}
		}
	}

	if (resultat.size() != 1) {
		throw runtime_error("Expression postfixée invalide : taille finale de la pile incorrecte.");	// Verification probleme si le resultat dépasse une taille de 1
	}

	return resultat.top();
}