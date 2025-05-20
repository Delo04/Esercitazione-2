/*! @file CPower.cpp
    @brief Derived class implementing a power function
    @author Mattia De Lorenzi e Matteo Abrate

    Details.
*/

#include "CPower.h"
#include <cmath>
#include <iostream>

using namespace std;

/// @brief default constructor
Power::Power() {
    k_coeff = 1.0;
    e_coeff = 1.0;
}

/// @brief constructor
/// @param k coefficient
/// @param e exponent
Power::Power(double k, double e) {
    k_coeff = k;
    e_coeff = e;
}

/// @brief copy constructor
Power::Power(const Power& p) {
    k_coeff = p.k_coeff;
    e_coeff = p.e_coeff;
}

/// @brief destructor
Power::~Power() {}

/// @brief overload operator =
Power& Power::operator=(const Power& p) {
    if (this != &p) {
        k_coeff = p.k_coeff;
        e_coeff = p.e_coeff;
    }
    return *this;
}

/// @brief overload operator ==
bool Power::operator==(const Power& p) const {
    return (k_coeff == p.k_coeff && e_coeff == p.e_coeff);
}

/// @brief returns the value of the function, given an input 
/// @param in the input
/// @return the value of the function
double Power::GetValue(double in) const {
    return k_coeff * pow(in, e_coeff);
}

/// @brief gives the status of the object
void Power::Dump() {
    cout << "Power function: f(x) = " << k_coeff << " * x^" << e_coeff << endl;
}

/// @brief sets the parameters
/// @param e exponent
/// @param k coefficient
void Power::SetParameters(double e, double k) {
    if (infiniteOrNaN(e) || infiniteOrNaN(k)) {
        WarningMessage("SetParameters: one of the parameters is not valid. No changes made.");
        return;
    }
    e_coeff = e;
    k_coeff = k;
}

/// @brief writes an error message 
/// @param string message to be printed
void Power::ErrorMessage(const char* string) {
    cout << endl << "ERROR -- Power -- " << string << endl;
}

/// @brief writes a warning message 
/// @param string message to be printed
void Power::WarningMessage(const char* string) {
    cout << endl << "WARNING -- Power -- " << string << endl;
}

/// @brief check if value is infinite or NaN
/// @param val value to check
/// @return true if invalid
bool Power::infiniteOrNaN(double val) const {
    return isnan(val) || isinf(val);
}
