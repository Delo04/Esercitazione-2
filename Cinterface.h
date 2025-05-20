/*! @file interface.h
    @brief Functions for command-line user interface management.
	@author Mattia De Lorenzi e Matteo Abrate
	
	Details.
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "CFunction.h"

/// @name FUNCTIONS
/// @{
void Menu();
void VisualizzaFunzioni(const std::vector<Function*>&);
void InserisciFunzione(std::vector<Function*>&);
void EliminaFunzione(std::vector<Function*>&);
void EliminaTutte(std::vector<Function*>&);
void SelezionaFunzione(const std::vector<Function*>&);
/// @}

#endif
