#include <Rcpp.h>
#include "Sum.h"

// [[Rcpp::export]]
double demo_somme(NumericVector x) {
   Sum A(x);
   parallelReduce(0, x.size(), A);
   return A.value;
}
