#pragma once

#include <string>
#include <stack>
#include <vector>

using namespace std;
template <class Element>
class Postfix
{
private:
	stack<Element> Pile;
	vector<Element> Tableau;

public:

	// Constructeur 
	Postfix();						// par d�faut
	Postfix(vector<Element> Tableau);	// avec param�tres

	// Destructeur
	~Postfix();

	// Setters
	void setTableau(vector<Element> Tableau);

	// Fonctions
	void valider(vector<Element>& Tableau);					//	valider l'expression
	bool parenthesesEquilibrees(vector<Element>& Tableau);	// Verifier les parentheses
	void transformerEnNombres(vector <Element>& Tableau);	// Transformer les char en nombre
	void transformerEnPostfixe(stack<Element>& Pile, vector <Element>& Tableau);	// Transformer Tableau en postFixe
	int evaluerExpression(stack<Element>& Pile, vector<Element>& Tableau);			// evaluer l'expreession postfixe	
	int priorite(char signe);														// Donner les priorite des operations pour la transformation
};
