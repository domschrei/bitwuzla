/***
 * Bitwuzla: Satisfiability Modulo Theories (SMT) solver.
 *
 * Copyright (C) 2023 by the authors listed in the AUTHORS file at
 * https://github.com/bitwuzla/bitwuzla/blob/main/AUTHORS
 *
 * This file is part of Bitwuzla under the MIT license. See COPYING for more
 * information at https://github.com/bitwuzla/bitwuzla/blob/main/COPYING
 */

#include "sat/sat_solver_factory.h"

namespace bzla::sat {

std::function<SatSolver*(void)> ExternalSatSolver::new_sat_solver;

SatSolver*
new_default_sat_solver()
{
  return ExternalSatSolver::new_sat_solver();
}

SatSolver*
new_sat_solver(const option::Options& options)
{
  (void) options;
  return new_default_sat_solver();
}

bool
has_sat_solver_terminator_support(const option::Options& options)
{
  (void) options;
#ifdef BZLA_USE_KISSAT
  if (options.sat_solver() == option::SatSolver::KISSAT)
  {
    return false;
  }
#endif
#ifdef BZLA_USE_CMS
  if (options.sat_solver() == option::SatSolver::CRYPTOMINISAT)
  {
    return false;
  }
#endif
  return true;
}

}  // namespace bzla::sat
