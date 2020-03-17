#include <Rcpp.h>
#include <RcppParallel.h>
using namespace Rcpp;
using namespace RcppParallel;

class Sequence : public Worker {
public:
   // Pointeur vers fonction à appliquer
   double (*F) (double);
   // point de départ
   double debut;
   // step
   double step;

   // resultat
   RVector<double> r;

   Sequence(double (*F_) (double), double debut_, double fin, NumericVector resultat) :
     F(F_), debut(debut_), step((fin-debut)/(resultat.size() -1)), r(resultat) {
     if(resultat.size() < 2)
       step = 0;
   }

   void operator()(size_t beg, size_t end) {
     double x = debut + beg*step;
     for(size_t i = beg; i < end; i++) {
       r[i] = F(x);
       x += step;
     }
   }
};
