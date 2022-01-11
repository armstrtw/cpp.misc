#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <boost/math/distributions.hpp>
using std::cout;
using std::endl;

double norm_cdf(const double x) {
  static boost::math::normal phi;
  return boost::math::cdf(phi,x);
}

double european_call_price(const double S, const double K, const double T, const double r, const double V) {
  const double d1 = (log(S/K) + (r + V*V/2)*T)/ (V * sqrt(T));
  const double d2 = d1 - V * sqrt(T);
  //cout << d1 << endl;
  //cout << d2 << endl;
  //cout << S*norm_cdf(d1) << endl;
  //cout << K * exp(-r*T) * norm_cdf(d2) << endl;
  return S*norm_cdf(d1) - K * exp(-r*T) * norm_cdf(d2);
}

double european_put_price(const double S, const double K, const double T, const double r, const double V) {
  const double d1 = (log(S/K) + (r + V*V/2)*T)/ (V * sqrt(T));
  const double d2 = d1 - V * sqrt(T);
  //cout << d1 << endl;
  //cout << d2 << endl;
  //cout << S*norm_cdf(d1) << endl;
  //cout << K * exp(-r*T) * norm_cdf(d2) << endl;
  return K * exp(-r*T) * norm_cdf(-d2) - S*norm_cdf(-d1);
}

void test_cdf() {
  std::vector<double> sample {1.0,2.0,3.0};
  std::vector<double> hull_p294_sample {.7693, .6278, -.7693, -.6278};
  cout << "cdf test: (1,2,3)" << endl;
  std::transform(sample.begin(),sample.end(),std::ostream_iterator<double>( std::cout, " "),norm_cdf); cout << endl;
  cout << "cdf test: (hull values)" << endl;
  std::transform(hull_p294_sample.begin(),hull_p294_sample.end(),std::ostream_iterator<double>( std::cout, " "),norm_cdf); cout << endl;
}

int main() {
  test_cdf();
  // HULL p 294
  cout << "call price: " << european_call_price(42,40,.5,.10,.20) << endl;
  cout << "put price: " << european_put_price(42,40,.5,.10,.20) << endl;
}
