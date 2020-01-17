#include <cmath>
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]

double OptionPricer(double S, double r, double v, double t, double b, double k)
{
  
  
  double x;
  double y;
  
  double sizeSquared;
  do
  {
    x = 2.0*rand()/static_cast<double>(RAND_MAX)-1;
    y = 2.0*rand()/static_cast<double>(RAND_MAX)-1;
    sizeSquared = x*x + y*y;
  }
  while
    ( sizeSquared >= 1.0);
  
  double normal_distribution = x*sqrt(-2*log(sizeSquared)/sizeSquared);
  
  
  
  long sum=0;
  for(int i = 0; i < 20000000; i++){
    sum += S*exp((r-0.5*pow(v,2))*t + v*pow(t,0.5)*normal_distribution);
  }
  
  double avg = sum/20000000;
  double multiplied_avg = avg*exp(-1*r*t);
  
  if(multiplied_avg > b){multiplied_avg = b;}
  
  return multiplied_avg;
  
}
// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//
