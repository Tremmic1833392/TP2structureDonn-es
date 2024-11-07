#pragma once
template <element class>
class Postfix
{
private:
	Stack <element> Pile;
	Vector <element> Tableau;

public:

	Postfix(vector<char> Tableau); // introduit l�expression � �valuer, � partir du clavier, dans Tableau.
	~Postfix(); // supprime le tableau et la pile si leur d�claration est dynamique (comme expliqu� dansle point(2) ci - dessous.
	Valider(vector<char> Tableau); // valide si l�expression contenue dans Tableau ne contient que lescaract�res list�s ci - dessus, � savoir les nombres entiers compos�s de caract�res nombres, et lesop�rateurs(, ), *, / , %, +, et - .
	bool parentheses(vector<element> Tableau); // teste si l�expression lue contient un nombre valide de parenth�ses(le nombre de parenth�ses ouvrantes doit �tre �gal au nombre de parenth�sesfermantes).		void transformerennombres(vector <element> Tableau); // transforme les nombres lus encaract�res en valeurs num�riques.
	void transformerenpostfixe(stack<element> Pile, vector <element> Tableau); // transformel�expression lue en une expression postfix�e et l�afficher sur �cran.
	int evaluer_expression(stack<element> Pile, vector<element> Tableau); // �value l�expressionpostfix�e et affiche sa valeur sur �cran.
};

