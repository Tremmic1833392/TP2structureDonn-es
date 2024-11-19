#pragma once

#include <string>
#include <stack>
#include <vector>

using namespace std;
template <class element>
class Postfix
{
private:
	stack<element> Pile;
	vector<string> Tableau;

public:

	// Constructeur 
	Postfix();						// par d�faut
	Postfix(vector<char> Tableau);	// avec param�tres

	// Destructeur
	~Postfix();

	// Setters
	void setTableau(vector<char> Tableau);

	// Fonctions
	void Valider(vector<char> Tableau);
	bool ParenthesesEquilibrees(vector<element> Tableau);
	void TransformerEnNombres(vector <element> Tableau);
	void TransformerEnPostfixe(stack<element> Pile, vector <element> Tableau);
	int EvaluerExpression(stack<element> Pile, vector<element> Tableau);
	int Priorite(char signe);

};


