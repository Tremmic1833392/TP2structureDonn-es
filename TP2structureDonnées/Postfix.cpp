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

	Postfix(vector<char> Tableau) { // introduit l�expression � �valuer, � partir du clavier, dans Tableau.
		Postfix.Tableau = Tableau;
	};

	~Postfix() { // supprime le tableau et la pile si leur d�claration est dynamique (comme expliqu� dansle point(2) ci - dessous.

	};

	Valider(vector<char> Tableau) {// valide si l�expression contenue dans Tableau ne contient que lescaract�res list�s ci - dessus, � savoir les nombres entiers compos�s de caract�res nombres, et lesop�rateurs(, ), *, / , %, +, et - .
		for (int i = 0; i < Tableau.size(); i++)
		{
			if (Tableau[i] != '0' && Tableau[i] != '1' && Tableau[i] != '2' && Tableau[i] != '3' && Tableau[i] != '4' && Tableau[i] != '5' && Tableau[i] != '6' && Tableau[i] != '7' && Tableau[i] != '8' && Tableau[i] != '9' && Tableau[i] != '(' && Tableau[i] != ')' && Tableau[i] != '*' && Tableau[i] != '/' && Tableau[i] != '%' && Tableau[i] != '+' && Tableau[i] != '-') {
				cout << "Expression non valide"
					return;
			}
		}
	};
		bool parentheses(vector<element> Tableau) {// teste si l�expression lue contient un nombre valide de parenth�ses(le nombre de parenth�ses ouvrantes doit �tre �gal au nombre de parenth�sesfermantes).
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
		void transformerennombres(vector <element> Tableau) { // transforme les nombres lus encaract�res en valeurs num�riques.
			for (int i = 0; i < Tableau.size(); i++)
			{
				if (Tableau[i].isDigit()) {

				}
			}
		};
		void transformerenpostfixe(stack<element> Pile, vector <element> Tableau) { // transformel�expression lue en une expression postfix�e et l�afficher sur �cran.
		};
		int evaluer_expression(stack<element> Pile, vector<element> Tableau) { // �value l�expressionpostfix�e et affiche sa valeur sur �cran.
		};
};
