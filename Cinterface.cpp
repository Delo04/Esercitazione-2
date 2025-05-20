/*! @file interface.cpp
    @brief Implementation of command-line interface functions.
	@author Mattia De Lorenzi e Matteo Abrate

    Details.
 */

#include "Cinterface.h"
#include "CPower.h"
#include "CPolynomial.h"
#include "CExponential.h"
#include <iostream>

using namespace std;

/// @brief menu implementation
void Menu() {
    cout << "\nMenu:\n";
    cout << "0 - Exit from the menu\n";
    cout << "1 - View all the functions\n";
    cout << "2 - Insert a new function\n";
    cout << "3 - Delete one function\n";
    cout << "4 - Delete all the functions\n";
    cout << "5 - Select one function\n";
    cout << "Choose: ";
}

/// @brief visualisation function
///	@param funzioni
void VisualizzaFunzioni(const std::vector<Function*>& funzioni) {
    if (funzioni.empty()) {
        cout << "there aren't any functions available.\n";
        return;
    }

    for (size_t i = 0; i < funzioni.size(); ++i) {
        cout << "ID " << i << ": ";
        funzioni[i]->Dump();
    }
}

/// @brief insertion function
///	@param funzioni
void InserisciFunzione(std::vector<Function*>& funzioni) {
    int scelta;
    cout << "Type of function:\n";
    cout << "1 - Power (k * x^e)\n";
    cout << "2 - Polynomial\n";
    cout << "3 - Exponential (k * b^cx)\n";
    cout << "Choose: ";
    cin >> scelta;

    if (scelta == 1) {
        double k, e;
        cout << "insert coefficient k: ";
        cin >> k;
        cout << "Insert exponent e: ";
        cin >> e;

        Power* f = new Power(k, e);
        cout << "you've inserted: ";
        f->Dump();

        char conferma;
        cout << "confirm? (y/n): ";
        cin >> conferma;
        if (conferma == 'y' || conferma == 'Y')
            funzioni.push_back(f);
        else
            delete f;

    } else if (scelta == 2) {
        int grado;
        cout << "degree of the polynomial function: ";
        cin >> grado;

        double* coeff = new double[grado + 1];
        for (int i = 0; i <= grado; ++i) {
            cout << "Coeff. x^" << i << ": ";
            cin >> coeff[i];
        }

        Polynomial* f = new Polynomial(coeff, grado + 1);
        cout << "you've inserted: ";
        f->Dump();

        char conferma;
        cout << "confirm? (y/n): ";
        cin >> conferma;
        if (conferma == 'y' || conferma == 'Y')
            funzioni.push_back(f);
        else
            delete f;

        delete[] coeff;

    } else if (scelta == 3) {
        double k, b, c;
        cout << "Insert coefficient k: ";
        cin >> k;
        cout << "Insert exponential b: ";
        cin >> b;
        cout << "Insert exponential c: ";
        cin >> c;

        Exponential* f = new Exponential(b, k, c);
        cout << "You've inserted: ";
        f->Dump();

        char conferma;
        cout << "Confirm? (y/n): ";
        cin >> conferma;
        if (conferma == 'y' || conferma == 'Y')
            funzioni.push_back(f);
        else
            delete f;
    }
    else {
        cout << "Invalid type.\n";
    }
}


/// @brief delete function
///	@param funzioni
void EliminaFunzione(std::vector<Function*>& funzioni) {
    if (funzioni.empty()) {
        cout << "There aren't any instructions to delete.\n";
        return;
    }

    int id;
    cout << "Insert the ID of the function to delete: ";
    cin >> id;

    if (id >= 0 && static_cast<size_t>(id) < funzioni.size()) {
        cout << "Function to delete: ";
        funzioni[id]->Dump();

        char conferma;
        cout << "Confirm extermination? (y/n): ";
        cin >> conferma;
        if (conferma == 'y' || conferma == 'Y') {
            delete funzioni[id];
            funzioni.erase(funzioni.begin() + id);
        }
    } else {
        cout << "ID not valid.\n";
    }
}

/// @brief delete all function
///	@param funzioni
void EliminaTutte(std::vector<Function*>& funzioni) {
    for (auto* f : funzioni)
        delete f;
    funzioni.clear();
    cout << "All functions exterminated.\n";
}
/// @brief selection function
///	@param funzioni
void SelezionaFunzione(const std::vector<Function*>& funzioni) {
    if (funzioni.empty()) {
        cout << "There aren't any instructions to delete.\n";
        return;
    }

    int id;
    cout << "Insert the ID of the function you want to select: ";
    cin >> id;

    if (id >= 0 && static_cast<size_t>(id) < funzioni.size()) {
        cout << "You've selected: ";
        funzioni[id]->Dump();

        double x;
        cout << "Insert the value x: ";
        cin >> x;

        double y = funzioni[id]->GetValue(x);
        cout << "f(" << x << ") = " << y << "\n";
    } else {
        cout << "ID not valid.\n";
    }
}
