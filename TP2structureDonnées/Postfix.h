#pragma once

#include <string>
#include <stack>
#include <vector>

using namespace std;

/*
### Structure du programme
Ton programme devra inclure une **classe `Postfix`** qui contient les fonctions n�cessaires pour effectuer ces transformations et calculs. Voici un r�sum� de chaque m�thode que tu dois coder dans cette classe :

1. Constructeur "Postfix(vector<char> Tableau)" : Prend l�expression en notation infix�e que tu saisis via le clavier et la stocke dans un tableau.

2. Destructeur "~Postfix()" : D�truit la pile et le tableau, mais uniquement si tu as utilis� une d�claration dynamique (comme un bonus potentiel).

3. "Valider(vector<char> Tableau)" : V�rifie que l�expression ne contient que les caract�res autoris�s (chiffres, op�rateurs `+`, `-`, `*`, `/`, `%`, et les parenth�ses).

4. "parentheses(vector<element> Tableau)" : V�rifie que les parenth�ses sont bien appari�es, c'est-�-dire que chaque parenth�se ouvrante a une parenth�se fermante correspondante.

5. "transformerennombres(vector<element> Tableau)" : Transforme les caract�res repr�sentant des chiffres en valeurs num�riques pour faciliter le calcul.

6. "transformerenpostfixe(stack<element> Pile, vector<element> Tableau)" : Transforme l�expression en notation infix�e en notation postfix�e.

7. "evaluer_expression(stack<element> Pile, vector<element> Tableau)" : �value l�expression en notation postfix�e et affiche le r�sultat.
*/
/*
template <class MyType>
class MyClass {
public:
	MyType first;
	MyType second;

	MyClass(MyType f, MyType s) {
		first = f;
		second = s;
	}
};


// Use MyClass with strings
  MyClass<string> stringObj( "Hello", "World" );
  cout << stringObj.first << " " << stringObj.second << "\n";

  // Use MyClass with integers
  MyClass<int> intObj( 4, 5 );
  cout << intObj.first << " " << intObj.second << "\n";

  return 0;
*/

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
	int Postfix<element>::Priorite(char signe) {}

};


