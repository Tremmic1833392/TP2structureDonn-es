#pragma once
template <element class>
class Postfix
{
private:
	Stack <element> Pile;
	Vector <element> Tableau;

public:

	Postfix(vector<char> Tableau); // introduit l’expression à évaluer, à partir du clavier, dans Tableau.
	~Postfix(); // supprime le tableau et la pile si leur déclaration est dynamique (comme expliqué dansle point(2) ci - dessous.
	Valider(vector<char> Tableau); // valide si l’expression contenue dans Tableau ne contient que lescaractères listés ci - dessus, à savoir les nombres entiers composés de caractères nombres, et lesopérateurs(, ), *, / , %, +, et - .
	bool parentheses(vector<element> Tableau); // teste si l’expression lue contient un nombre valide de parenthèses(le nombre de parenthèses ouvrantes doit être égal au nombre de parenthèsesfermantes).		void transformerennombres(vector <element> Tableau); // transforme les nombres lus encaractères en valeurs numériques.
	void transformerenpostfixe(stack<element> Pile, vector <element> Tableau); // transformel’expression lue en une expression postfixée et l’afficher sur écran.
	int evaluer_expression(stack<element> Pile, vector<element> Tableau); // évalue l’expressionpostfixée et affiche sa valeur sur écran.
};

