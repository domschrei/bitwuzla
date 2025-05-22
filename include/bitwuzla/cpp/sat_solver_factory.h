/***
 * Bitwuzla: Satisfiability Modulo Theories (SMT) solver.
 *
 * Copyright (C) 2023 by the authors listed in the AUTHORS file at
 * https://github.com/bitwuzla/bitwuzla/blob/main/AUTHORS
 *
 * This file is part of Bitwuzla under the MIT license. See COPYING for more
 * information at https://github.com/bitwuzla/bitwuzla/blob/main/COPYING
 */

#ifndef BZLA_SAT_SAT_SOLVER_FACTORY_H_INCLUDED
#define BZLA_SAT_SAT_SOLVER_FACTORY_H_INCLUDED

#include <functional>

#include "option.h"
#include "sat_solver.h"

namespace bzla::sat {
struct ExternalSatSolver {
    static std::function<SatSolver*(void)> new_sat_solver;
};

SatSolver* new_sat_solver(const option::Options& options);
SatSolver* new_default_sat_solver();
}

#endif
