// TP2structureDonnées.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <regex>
#include <fstream>
#include <string>

#include "Postfix.h"

using namespace std;

/*
Objectifs principaux : Le devoir consiste à écrire un programme C++ qui fait deux choses :

1. **Transformer une expression en notation infixée** (exemple : `(x + y) * z - x / y`) **en notation postfixée** (aussi appelée notation polonaise inversée) où l’opérateur vient après ses opérandes.
   - Exemple : l’expression `(x + y) * z - x / y` se transformerait en `xy + z * xy / -`.

2. **Évaluer l’expression postfixée** pour obtenir le résultat final.

### Bonus possible (10% supplémentaire)
- **5%** si tu prends en compte des nombres à plusieurs chiffres (comme `23` ou `105`). Tu devras modifier les types de `Stack` et `Vector` pour cela.
- **5%** si tu déclares la pile et le tableau de manière dynamique, ce qui nécessite l’utilisation d’un destructeur et d’itérateurs.

### Explications supplémentaires
- **Notion de notation postfixée** : Les opérateurs sont placés après leurs opérandes. Par exemple, `3 + 4` devient `3 4 +`.
- **Priorité des opérateurs** : Les opérateurs ont une priorité, donc ton programme doit gérer les parenthèses, puis les opérations `*`, `/`, `%` avant les additions et soustractions.

En gros, ce devoir demande d'implémenter un système pour lire, transformer et évaluer des expressions mathématiques en respectant des règles de priorité et d'écriture postfixée. Tu vas beaucoup utiliser les piles (stack) pour gérer la transformation et l’évaluation de ces expressions.
*/

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

int main()
{
    // Variables
    string expressionInfixee;

    cout << "Entrez une expression infixee :\n>";
    getline(cin, expressionInfixee);

    // Use MyClass with strings
    MyClass<string> stringObj("Hello", "World");
    cout << stringObj.first << " " << stringObj.second << "\n";

    // Use MyClass with integers
    MyClass<int> intObj(4, 5);
    cout << intObj.first << " " << intObj.second << "\n";

    return 0;
}