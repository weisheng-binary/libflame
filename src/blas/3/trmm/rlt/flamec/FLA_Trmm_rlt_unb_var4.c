/*

    Copyright (C) 2014, The University of Texas at Austin

    This file is part of libflame and is available under the 3-Clause
    BSD license, which can be found in the LICENSE file at the top-level
    directory, or at http://opensource.org/licenses/BSD-3-Clause

*/

#include "FLAME.h"

#ifdef FLA_ENABLE_NON_CRITICAL_CODE

FLA_Error FLA_Trmm_rlt_unb_var4( FLA_Diag diagA, FLA_Obj alpha, FLA_Obj A, FLA_Obj B )
{
  FLA_Obj BT,              B0,
          BB,              b1t,
                           B2;

  FLA_Scal_external( alpha, B );

  FLA_Part_2x1( B,    &BT, 
                      &BB,            0, FLA_BOTTOM );

  while ( FLA_Obj_length( BB ) < FLA_Obj_length( B ) ){

    FLA_Repart_2x1_to_3x1( BT,                &B0, 
                                              &b1t, 
                        /* ** */            /* *** */
                           BB,                &B2,        1, FLA_TOP );

    /*------------------------------------------------------------*/

    /* b1t = b1t * tril( A )'; */
    FLA_Trmv_external( FLA_LOWER_TRIANGULAR, FLA_NO_TRANSPOSE, diagA, A, b1t );

    /*------------------------------------------------------------*/

    FLA_Cont_with_3x1_to_2x1( &BT,                B0, 
                            /* ** */           /* *** */
                                                  b1t, 
                              &BB,                B2,     FLA_BOTTOM );

  }

  return FLA_SUCCESS;
}

#endif
