%
%
%   Copyright (C) 2014, The University of Texas at Austin
%
%   This file is part of libflame and is available under the 3-Clause
%   BSD license, which can be found in the LICENSE file at the top-level
%   directory, or at http://opensource.org/licenses/BSD-3-Clause
%
%
                                                  1, 1, 'FLA_BR' );

    %------------------------------------------------------------%

    [ alpha11, ...
      a21, tau11 ] = FLA_Househ2_UT( alpha11, ...
                                     a21 );

    t01 = a10t' + A20' * a21;
    
    [ a12t, ...
      A22 ] = FLA_Apply_H_UT( tau11, a21, a12t, ...
                                          A22 );
    
    %------------------------------------------------------------%

    [ ATL, ATR, ...
      ABL, ABR ] = FLA_Cont_with_3x3_to_2x2( A00,  a01,     A02,  ...
                                             a10t, alpha11, a12t, ...
                                             A20,  a21,     A22, ...
                                             'FLA_TL' );

    [ TTL, TTR, ...
      TBL, TBR ] = FLA_Cont_with_3x3_to_2x2( T00,  t01,   T02,  ...
                                             t10t, tau11, t12t, ...
                                             T20,  t21,   T22, ...
                                             'FLA_TL' );

  end

  A_out = [ ATL, ATR
            ABL, ABR ];

  T_out = [ TTL, TTR
            TBL, TBR ];

return
