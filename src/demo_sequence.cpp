#include <Rcpp.h>
#include "Sequence.h"
using namespace Rcpp;

double f(double x) {
  return sin(x);
}

// [[Rcpp::export]]
NumericVector demo_sequence(double a, double b, double n) {
  NumericVector resultat(n);
  Sequence A(f, a, b, resultat);
  parallelFor(0, n, A);
  return resultat;
}
