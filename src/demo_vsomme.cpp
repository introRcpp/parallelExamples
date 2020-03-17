#include <Rcpp.h>
#include "para_vsomme.h"
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector demo_vsomme(NumericVector x, NumericVector y) {
  if(x.size() != y.size())
    stop("Dimensions mismatch");
  
  NumericVector resultat = no_init(x.size()); // ! attention au no_init !
  para_vsomme A(x, y, resultat);
  parallelFor(0, x.size(), A);
  return resultat;
}
