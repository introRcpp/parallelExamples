/* 
 * Légèrement modifié de l'exemple donné par  
 * RcppParallel.package.skeleton()
 */
#include <Rcpp.h>
#include <RcppParallel.h>

using namespace Rcpp;
using namespace RcppParallel;

struct Sum : public Worker
{   
   // source vector
   const RVector<double> vec;
   
   // accumulated value
   double value;
   
   // constructors
   Sum(const NumericVector x) : vec(x), value(0) {}
   Sum(const Sum & A, Split) : vec(A.vec), value(0) {}
   
   // accumulate just the element of the range I've been asked to
   void operator()(std::size_t begin, std::size_t end) {
      for(size_t i = begin; i < end; i++)
         value += vec[i];
   }
   
   // join my value with that of another Sum
   void join(const Sum & A) { 
      value += A.value; 
   }
};