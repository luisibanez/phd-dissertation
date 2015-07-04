/**************************************************************
 *
 *
 *      Line Tracer Class
 *
 *      Luis Ibanez
 *      Medical Image Analysis and Display Group
 *      University of North Carolina at Chapel Hill
 *      Chapel Hill, NC 27599-3175, USA
 *      ibanez@cs.unc.edu
 *      http://www.cs.unc.edu/~ibanez
 *
 *
 **************************************************************/

/**************************************************************
 * 
 *   This code uses the (Matrix Template Library )  MTL 
 *   Authors: Andrew Lumsdaine, Jeremy G. Siek, Lie-Quan Lee
 *   Copyright 1997, 1998, 1999 University of Notre Dame.
 *   http://www.lsc.nd.edu/research/mtl
 *
 **************************************************************/

#ifndef LINE_TRACER_CLASS
#define LINE_TRACER_CLASS

#include <mtl/matrix.h>
#include <mtl/mtl.h>
#include <mtl/lu.h>

using namespace mtl;



/**************************************************************
 * 
 *    This class implements a line tracing algorithm  
 *    designed for arbitrary regular grids of any dimension
 *
 *************************************************************/
class LineTracer 
{
 
public:
  typedef matrix<double,
                 rectangle<>,
                 dense<> >::type Matrix;

  typedef dense1D<double> Vector;

public:  
  LineTracer( const Matrix & inputBasis,
              const Vector & line):
    N(inputBasis.ncols()),
    subSpaceProjection(inputBasis.ncols(),inputBasis.ncols()-1),
    thetaMatrix(inputBasis.ncols(),inputBasis.ncols()),
    theta2(inputBasis.ncols(),inputBasis.ncols()),
    MT(inputBasis.ncols()),
    MR(inputBasis.ncols()),
    TD(inputBasis.ncols()),
    Position(inputBasis.ncols())

  {

    if( line.size() != N  ) 
    {
      cerr << "The line vector dimension is inconsistent";
      cerr << " with the matrix dimension " << endl;
      return;
    }

    distanceToLine = 0;
    
    mtl::set(subSpaceProjection,0);
    
    for(unsigned int i=0; i<N-1; i++) 
    {
      subSpaceProjection(i,i)        = line[N-1];
      subSpaceProjection(N-1,i) = -line[i];
    }


    cout << "N = " << N << endl;

    cout << "inputBasis" << endl;
    print_all_matrix( inputBasis );

    cout << "line" << endl;
    print_vector( line );


    // compute ((MvMv)^-1)Msp = solving linear system
    Matrix basisMetric(N,N);
    mult( trans(inputBasis), inputBasis, basisMetric );

    cout << "basisMetric" << endl;
    print_all_matrix( basisMetric );

    cout << "subSpaceProjection" << endl;
    print_all_matrix( subSpaceProjection );

    Matrix subSpaceMetric(N-1,N-1);
    mapping(basisMetric,subSpaceProjection,subSpaceMetric);

    cout << "subSpaceMetric" << endl;
    print_all_matrix( subSpaceMetric );

    Matrix coSubSpaceProjection(N-1,N);
    transpose(subSpaceProjection,coSubSpaceProjection);
    mapping(subSpaceMetric,coSubSpaceProjection,thetaMatrix);

    cout << "coSubSpaceProjection" << endl;
    print_all_matrix( coSubSpaceProjection );

    cout << "theta Matrix" << endl;
    print_all_matrix( thetaMatrix );

    cout << "MT Vector" << endl;
    print_vector( MT );

    cout << "MR Vector" << endl;
    print_vector( MR );

    for(unsigned int i=0; i<N; i++) 
    {
       TD[i] = thetaMatrix(i,i);
    }

    copy(thetaMatrix,theta2);
    scale(theta2,2.0);

    cout << "TD Vector" << endl;
    print_vector( TD );

    selectedDirection = N-1;

  }

  ~LineTracer() 
  {
  };

  
private:
  void inverse(const Matrix & A, Matrix & AInv)
  {
    Matrix LU(A.nrows(),A.ncols());
    dense1D<int> pvector(A.ncols());
    copy(A,LU);
    lu_factor(LU,pvector);
    lu_inverse(LU,pvector,AInv);
  }

  void mapping(const Matrix & A, const Matrix & B, Matrix & C)
  {
    Matrix AInv(A.nrows(),A.ncols());
    Matrix AInvB(A.nrows(),B.ncols());
    inverse(A,AInv);
    mult(AInv,B,AInvB);
    mult(trans(B),AInvB,C);
  }

public:

  void step(void) 
  {
     add( MR, TD, MT);
     unsigned int k = min_index(MT);
     Position[k]++;
     distanceToLine += MR[k] + TD[k];
     add( theta2[k], MR );
     selectedDirection = k;
  }

  void print_step(void) 
  {
     cout << "selectedDirection = " << selectedDirection << endl;

     cout << "MT Vector" << endl;
     print_vector( MT );

     cout << "MR Vector" << endl;
     print_vector( MR );

     cout << "Position Vector" << endl;
     print_vector( Position );

     cout << "Distance to line = " << distanceToLine << endl;

     cout << endl;
  }


 
private:

  unsigned int N;
  double distanceToLine;
  unsigned int selectedDirection;

  Matrix subSpaceProjection;
  Matrix thetaMatrix;
  Matrix theta2;

  Vector MT;
  Vector MR;
  Vector TD;
  Vector Position;

};

#endif




