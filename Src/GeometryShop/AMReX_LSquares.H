#ifndef AMREX_LSQUARES_H_
#define AMREX_LSQUARES_H_

#include <AMReX_Array.H>
#include <AMReX_Vector.H>
#include "AMReX_REAL.H"
#include "AMReX_RealVect.H"

using amrex::Real;
using amrex::Vector;
///
/**
   This class solves least squares problems
*/
class LSquares
{
public:
  void LeastSquares(Real** A,
                    Vector<Real>&x,
                    const Vector<Real>&rhs);

  /// gaussian elimination with partial pivoting
  int gaussElim(Real**A,
                Vector<Real>& rhs);

  void swapRows(Real** A,
                const int& rowi,
                const int& rowj,
                const int&numberOfCols);

  void swapRows(Vector<Real>& rhs,
                const int& currRow,
                const int& pivot);

  int findPivot(Real** A,
                const int& currCol,
                const int& currRow,
                const int& numRows,
                int& pivot);

  void addRows(Vector<Real>& rhs,
               const int& rowi,
               const Real& alpha,
               const int& rowj);

  void addRows(Real** A,
               const int& rowi,
               const Real& alpha,
               const int& rowj,
               const int& numberOfCols);

  void timesBeta(Vector<Real>&rhs,
                 const int& currRow,
                 const Real& Beta);

  void timesBeta(Real** A,
                 const int& rowi,
                 const Real& Beta,
                 const int& numberOfcols);

  void transpose(Real** a_A,
                 Real ** a_Atrans,
                 const int& a_numRows,
                 const int& a_numCols);

  void matMul(Real** a_A,
              Real** a_B,
              Real** a_C,
              const int& a_numRowsA,
              const int& a_numColsA,
              const int& a_numColsB);

  void backSolve(Real** a_A,
                 const Vector<Real>& a_rhs,
                 const int& a_numArows,
                 Vector<Real>& a_x);

  void AtimesX(Real** A,
               const Vector<Real>&x,
               const int& numRowsA,
               Vector<Real>& Ax);

  void allocArray(const int& rows,
                  const int& cols,
                  Real**& A);

  void freeArray(const int& rows,
                 const int& cols,
                 Real**& A);

};

#endif
