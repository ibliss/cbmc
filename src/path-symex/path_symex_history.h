/*******************************************************************\

Module: History for path-based symbolic simulator

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#ifndef CPROVER_PATH_SYMEX_HISTORY_H
#define CPROVER_PATH_SYMEX_HISTORY_H

#include <util/std_expr.h>

#include "loc_ref.h"

class path_symex_stept
{
public:
  unsigned thread_nr;
  std::vector<loc_reft> pc_vector;

  exprt guard, ssa_rhs;
  exprt lhs;
  symbol_exprt ssa_lhs;

  bool ignore; 
  
  path_symex_stept():
    guard(nil_exprt()),
    ssa_rhs(nil_exprt()),
    lhs(nil_exprt()),
    ignore(false)
  {
  }
  
  inline loc_reft pc() const
  {
    return pc_vector[thread_nr];
  }
};

class path_symex_historyt
{
  typedef std::vector<path_symex_stept> stepst;
  stepst steps;
  
  // output  
  void output(std::ostream &out) const;
};

#endif
