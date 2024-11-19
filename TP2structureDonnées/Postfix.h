#pragma once

#include <string>
#include <stack>
#include <vector>

using namespace std;

/*
### Structure du programme
Ton programme devra inclure une **classe `Postfix`** qui contient les fonctions nécessaires pour effectuer ces transformations et calculs. Voici un résumé de chaque méthode que tu dois coder dans cette classe :

1. Constructeur "Postfix(vector<char> Tableau)" : Prend l’expression en notation infixée que tu saisis via le clavier et la stocke dans un tableau.

2. Destructeur "~Postfix()" : Détruit la pile et le tableau, mais uniquement si tu as utilisé une déclaration dynamique (comme un bonus potentiel).

3. "Valider(vector<char> Tableau)" : Vérifie que l’expression ne contient que les caractères autorisés (chiffres, opérateurs `+`, `-`, `*`, `/`, `%`, et les parenthèses).

4. "parentheses(vector<element> Tableau)" : Vérifie que les parenthèses sont bien appariées, c'est-à-dire que chaque parenthèse ouvrante a une parenthèse fermante correspondante.

5. "transformerennombres(vector<element> Tableau)" : Transforme les caractères représentant des chiffres en valeurs numériques pour faciliter le calcul.

6. "transformerenpostfixe(stack<element> Pile, vector<element> Tableau)" : Transforme l’expression en notation infixée en notation postfixée.

7. "evaluer_expression(stack<element> Pile, vector<element> Tableau)" : Évalue l’expression en notation postfixée et affiche le résultat.
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
	Postfix();						// par défaut
	Postfix(vector<char> Tableau);	// avec paramètres

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


