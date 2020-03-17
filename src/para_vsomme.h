#include <Rcpp.h>
#include <RcppParallel.h>
using namespace Rcpp;
using namespace RcppParallel;

class para_vsomme : public Worker {
public:
   const RVector<double> a, b;
   RVector<double> s;

   para_vsomme(const NumericVector a_, NumericVector b_, NumericVector s_)
      : a(a_), b(b_), s(s_) { }

   void operator()(size_t beg, size_t end) {
     for(size_t i = beg; i < end; i++)
       s[i] = a[i] + b[i];
   }
};
