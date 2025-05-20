/*! @file CPower.h
    @brief Derived class implementing a power function
    @author Mattia De Lorenzi e Matteo Abrate

    Details.
*/

#ifndef CPOWER_H
#define CPOWER_H

#include "CFunction.h"

using namespace std;

class Power : public Function {
private:
    double k_coeff;
    double e_coeff;

public:
    /// @name CONSTRUCTORS/DESTRUCTOR
    /// @{
    Power();                                        // costruttore di default
    Power(double k, double e);                      // costruttore con parametri
    Power(const Power& other);                      // costruttore di copia
    virtual ~Power();                               // distruttore
    /// @}

    /// @name OPERATORS
    /// @{
    Power& operator=(const Power& other);           // operatore di assegnazione
    bool operator==(const Power& other) const;      // operatore di confronto
    /// @}

	void SetParameters(double e, double k);
    double GetValue(double in) const override;

    /// @name DEBUG
    /// @{
	void ErrorMessage(const char* string);
    void WarningMessage(const char* string);
    bool infiniteOrNaN(double val) const;
	void Dump() override;
    /// @}
};

#endif
