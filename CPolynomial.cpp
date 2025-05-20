/*! @file CPolynomial.cpp
    @brief Implementation of Polynomial class 
    @author Mattia De Lorenzi e Matteo Abrate

    Details.
*/ 

#include "CPolynomial.h"

/// @brief default constructor
Polynomial::Polynomial() {
    degree = -1;
    coeff = nullptr;
}

/// @brief constructor
///	@param coefficients array with the coefficients (format: c0+c1*x+ ...)
///	@param size size of the array
Polynomial::Polynomial(const double* coefficients, int size) {
    coeff = nullptr;
    SetPolynomial(coefficients, size);
}

/// @brief destructor
Polynomial::~Polynomial() {
    if (coeff != nullptr) {
        delete[] coeff;
        coeff = nullptr;
    }
}

/// @brief copy constructor
Polynomial::Polynomial(const Polynomial& p) {
    if (p.coeff == nullptr) {
        ErrorMessage("Copy constructor: the object to be copied has no coefficients");
        exit(-1);
    }

    degree = p.degree;
    coeff = new double[degree + 1];
    if (coeff == nullptr) {
        ErrorMessage("Copy constructor: cannot allocate memory");
        exit(-1);
    }

    for (int i = 0; i <= degree; i++)
        coeff[i] = p.coeff[i];
}

/// @brief overload operator =
Polynomial& Polynomial::operator=(const Polynomial& p) {
    if (this != &p) {
        if (coeff != nullptr) {
            delete[] coeff;
        }

        degree = p.degree;
        coeff = new double[degree + 1];
        if (coeff == nullptr) {
            ErrorMessage("Operator =: cannot allocate memory");
            exit(-1);
        }

        for (int i = 0; i <= degree; i++)
            coeff[i] = p.coeff[i];
    }
    return *this;
}

/// @brief overload operator +
Polynomial Polynomial::operator+(const Polynomial& p) {
    int newSize = std::max(degree, p.degree) + 1;
    double* newCoeff = new double[newSize];

    if (newCoeff == nullptr) {
        ErrorMessage("Operator +: cannot allocate memory");
        exit(-1);
    }

    for (int i = 0; i < newSize; ++i)
        newCoeff[i] = 0.0;

    for (int i = 0; i <= degree; ++i)
        newCoeff[i] += coeff[i];

    for (int i = 0; i <= p.degree; ++i)
        newCoeff[i] += p.coeff[i];

    Polynomial result(newCoeff, newSize);
    delete[] newCoeff;
    return result;
}

/// @brief overload operator ==
bool Polynomial::operator==(const Polynomial& p) {
    if (degree != p.degree)
        return false;

    for (int i = 0; i <= degree; i++) {
        if (coeff[i] != p.coeff[i])
            return false;
    }

    return true;
}

/// @brief sets the coefficients of the polynomial 
///	@param coefficients array with the coefficients (format: c0+c1*x+ ...)
///	@param size size of the array
void Polynomial::SetPolynomial(const double* coefficients, int size) {
    if (size < 1) {
        ErrorMessage("SetPolynomial: the degree of the Polynomial cannot be negative");
        exit(-1);
    }

    Reset();

    degree = size - 1;
    coeff = new double[size];
    if (coeff == nullptr) {
        ErrorMessage("SetPolynomial: cannot allocate memory");
        exit(-1);
    }

    for (int i = 0; i <= degree; i++)
        coeff[i] = coefficients[i];
}

/// @brief returns the value of the function, given an input
///	@param in the input
///	@return the value of the function
double Polynomial::GetValue(double in) const {
    if (coeff == nullptr || degree < 0)
        return 0.0;

    double x = in;
    double result = coeff[0];

    for (int i = 1; i <= degree; i++) {
        result += coeff[i] * x;
        x *= in;
    }

    return result;
}

/// @brief resets the polynomial 
void Polynomial::Reset() {
    degree = -1;
    if (coeff != nullptr) {
        delete[] coeff;
        coeff = nullptr;
    }
}

/// @brief writes an error message
/// @param string message to be printed 
void Polynomial::ErrorMessage(const char *string) {
    std::cout << "\nERROR -- Polynomial -- " << string << std::endl;
}

/// @brief writes a warning message 
/// @param string message to be printed
void Polynomial::WarningMessage(const char *string) {
    std::cout << "\nWARNING -- Polynomial -- " << string << std::endl;
}

/// @brief gives the status of the object 
void Polynomial::Dump() {
    if (degree == -1 || coeff == nullptr) {
        std::cout << "Uninitialized polynomial" << std::endl;
        return;
    }
    std::cout <<"Polynomial function: f(x) = ";
    for (int i = 0; i <= degree; ++i) {
        if (coeff[i] != 0.0) {
            if (i > 0 && coeff[i] > 0) std::cout << " + ";
            else if (coeff[i] < 0) std::cout << " ";
            std::cout << coeff[i];
            if (i >= 1) std::cout << "x";
            if (i > 1) std::cout << "^" << i;
        }
    }
    std::cout << std::endl;
}
