/*! @file CExponential.cpp
    @brief Derived class implementing a exponential function
    @author Mattia De Lorenzi e Matteo Abrate

    Details.
*/

#include "CExponential.h"

/// @brief default constructor
Exponential::Exponential() {
    b_coeff = 2.0; // default base > 0
    k_coeff = 1.0;
    c_coeff = 1.0;
}

/// @brief constructor
///	@param b base of exponential
///	@param k base coefficent
///	@param c exponential coefficent
Exponential::Exponential(double b, double k, double c) {
    if (b <= 0) {
        ErrorMessage("Constructor: base b must be > 0. Setting b = 2.0");
        b = 2.0;
    }
    b_coeff = b;
    k_coeff = k;
    c_coeff = c;
}

/// @brief copy constructor
Exponential::Exponential(const Exponential& e) {
    b_coeff = e.b_coeff;
    k_coeff = e.k_coeff;
    c_coeff = e.c_coeff;
}
/// @brief destructor
Exponential::~Exponential() {}

/// @brief overload operator =
Exponential& Exponential::operator=(const Exponential& e) {
    if (this != &e) {
        b_coeff = e.b_coeff;
        k_coeff = e.k_coeff;
        c_coeff = e.c_coeff;
    }
    return *this;
}

/// @brief overload operator ==
bool Exponential::operator==(const Exponential& e) {
    return (b_coeff == e.b_coeff && k_coeff == e.k_coeff && c_coeff == e.c_coeff);
}

/// @brief returns the value of the function, given an input 
///	@param in the input
///	@return the value of the function
double Exponential::GetValue(double in) const {
    return k_coeff * pow(b_coeff, c_coeff * in);
}

/// @brief gives the status of the object
void Exponential::Dump() {
    cout << "Exponential function: f(x) = " << k_coeff << " * " << b_coeff << "^( " << c_coeff << " * x )" << endl;
}

/// @brief sets the parameters
///	@param b base of exponential
///	@param k base coefficent
///	@param c exponential coefficent
void Exponential::SetParameters(double b, double k, double c) {
    if (b <= 0) {
        ErrorMessage("SetParameters: base b must be > 0. No changes made.");
        return;
    }
    b_coeff = b;
    k_coeff = k;
    c_coeff = c;
}

/// @brief writes an error message 
/// @param string message to be printed
void Exponential::ErrorMessage(const char* string) {
    cout << endl << "ERROR -- Exponential -- " << string << endl;
}

/// @brief writes a warning message 
/// @param string message to be printed
void Exponential::WarningMessage(const char* string) {
    cout << endl << "WARNING -- Exponential -- " << string << endl;
}
