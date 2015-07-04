/**************************************************************
 *
 *
 *      Line Tracer Example
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
 *    This code is intended to illustrate the use of our
 *    line tracing algorithm designed for arbitrary regular
 *    grids of any dimension
 *
 *************************************************************/

/**************************************************************
 * 
 *   This code uses the (Matrix Template Library )  MTL 
 *   Authors: Andrew Lumsdaine, Jeremy G. Siek, Lie-Quan Lee
 *   Copyright 1997, 1998, 1999 University of Notre Dame.
 *   http://www.lsc.nd.edu/research/mtl
 *
 **************************************************************/

#include <LineTracer.h>


int main() 
{

  const int spaceDimension = 3;
  const int lineDimension  = 3;

  LineTracer::Matrix vectorBasis(spaceDimension,lineDimension);

  vectorBasis(0,0)=1;
  vectorBasis(0,1)=0;
  vectorBasis(0,2)=0;
  
  vectorBasis(1,0)=0;
  vectorBasis(1,1)=1;
  vectorBasis(1,2)=0;
  
  vectorBasis(2,0)=0;
  vectorBasis(2,1)=0;
  vectorBasis(2,2)=1;

  LineTracer::Vector line(lineDimension);

  line[0] = 2;
  line[1] = 3;
  line[2] = 5;
  
  LineTracer tracer(vectorBasis,line);


  unsigned int numSteps = 10;

  for(unsigned int i=0; i<numSteps; i++)
  {
    tracer.step();
    tracer.print_step();
  }

  return 0;

}




