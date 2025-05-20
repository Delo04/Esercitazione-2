/*! @file main.cpp
 *  @brief Entry point for the function manager program.
 */

#include "Cinterface.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<Function*> funzioni;
    int scelta;

    do {
        Menu();
        cin >> scelta;

        switch (scelta) {
            case 1: VisualizzaFunzioni(funzioni); break;
            case 2: InserisciFunzione(funzioni); break;
            case 3: EliminaFunzione(funzioni); break;
            case 4: EliminaTutte(funzioni); break;
            case 5: SelezionaFunzione(funzioni); break;
            case 0: break;
            default: cout << "Not a valid option.\n"; break;
        }

    } while (scelta != 0);

    EliminaTutte(funzioni);  // pulizia finale
    cout << "Programm terminated.\n";
    return 0;
}
