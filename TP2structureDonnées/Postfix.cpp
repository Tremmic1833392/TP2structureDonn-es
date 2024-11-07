#include "Postfix.h"
#include <iostream>
#include <stack>
#include <vector>
#include <cctype>
#include <stdexcept>

using namespace std;
template <element class>
class Postfix
{
private:
	Stack <element> Pile;
	Vector <element> Tableau;

public:

	Postfix(vector<char> Tableau) { // introduit l’expression à évaluer, à partir du clavier, dans Tableau.
		Postfix.Tableau = Tableau;
	};

	~Postfix() { // supprime le tableau et la pile si leur déclaration est dynamique (comme expliqué dansle point(2) ci - dessous.

	};

	Valider(vector<char> Tableau) {// valide si l’expression contenue dans Tableau ne contient que lescaractères listés ci - dessus, à savoir les nombres entiers composés de caractères nombres, et lesopérateurs(, ), *, / , %, +, et - .
		for (int i = 0; i < Tableau.size(); i++)
		{
			if (Tableau[i] != '0' && Tableau[i] != '1' && Tableau[i] != '2' && Tableau[i] != '3' && Tableau[i] != '4' && Tableau[i] != '5' && Tableau[i] != '6' && Tableau[i] != '7' && Tableau[i] != '8' && Tableau[i] != '9' && Tableau[i] != '(' && Tableau[i] != ')' && Tableau[i] != '*' && Tableau[i] != '/' && Tableau[i] != '%' && Tableau[i] != '+' && Tableau[i] != '-') {
				cout << "Expression non valide"
					return;
			}
		}
	};
		bool parentheses(vector<element> Tableau) {// teste si l’expression lue contient un nombre valide de parenthèses(le nombre de parenthèses ouvrantes doit être égal au nombre de parenthèsesfermantes).
			int countOuverte;
			int countFermer;
			for (int i = 0; i < Tableau.size(); i++)
			{
				if (Tableau[i] == '(')
				{
					countOuverte++;
				}
				else if (Tableau[i] == ')')
				{
					countFermer++;
				}
			}
			if (countOuverte == countFermer) {
				return true;
			}
			else
			{
				return false;
			}
		};
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
};
