#include <stdexcept>    // std::domain_error
#include <cstdlib>      // rand(), RAND_MAX
 
using std::domain_error;
using std::rand;
 
 
// return a random integer in the range [0, n)
// (S7.4.4/135)
int nrand(int n)
{
  if (n <= 0 || n > RAND_MAX)
    throw domain_error("Argument to nrand is out of range");
 
  const int bucket_size = RAND_MAX / n;
  int r;
 
  do r = rand() / bucket_size;
  while (r >= n);
 
  return r;
}