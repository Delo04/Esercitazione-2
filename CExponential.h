/*! @file CExponential.h
    @brief Derived class implementing a exponential function
    @author Mattia De Lorenzi e Matteo Abrate

    Details.
*/

#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include <iostream>
#include <cmath>
#include "CFunction.h"

using namespace std;

class Exponential : public Function {
private:
    double b_coeff;  // base > 0
    double k_coeff;  // costante di moltiplicazione
    double c_coeff;  // moltiplicatore dell'esponente

public:
    /// @name CONSTRUCTORs and DESTRUCTOR 
    /// @{
    Exponential();										// costruttore di default
    Exponential(double b, double k, double c);			// costruttore con parametri
    Exponential(const Exponential& e);					// costruttore di copia
    ~Exponential();										// distruttore
	/// @}

    /// @name OPERATORS 
	/// @{
    Exponential& operator=(const Exponential& e);		// operatore di assegnazione
    bool operator==(const Exponential& e);				// operatore di confronto
	/// @}

    void SetParameters(double b, double k, double c);
    double GetValue(double in) const override;

    /// @name DEBUG and SERIALIZATION 
	/// @{
    void ErrorMessage(const char* string);
    void WarningMessage(const char* string);
	void Dump() override;
	/// @}

};

#endif
