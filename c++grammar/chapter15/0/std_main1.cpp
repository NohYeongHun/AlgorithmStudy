#include "Pic.h"

using namespace std;

int main() {
  Vec<Str> vs;
  vs.push_back("hello");
  vs.push_back("world");

  Picture p(vs);
  Picture q = frame(p);
  Picture r = hcat(q, q);
  Picture s = vcat(q, q);

  cout << "Picture = \n" << p << '\n';
  cout << "Picture frame = \n" << q << '\n';
  cout << "Picture hcat = \n" << r << '\n';
  cout << "Picture vcat = \n" << s << '\n';

  cout << frame(hcat(s, vcat(r, r))) << endl;

  cout << "----------여러가지------------ \n" << endl;

  q = frame(p);
  r = hcat(p, q);
  s = vcat(q, r);

  cout << "Picture = \n" << p << '\n';
  cout << "Picture frame = \n" << q << '\n';
  cout << "Picture hcat = \n" << r << '\n';
  cout << "Picture vcat = \n" << s << '\n';

  cout << frame(hcat(s, vcat(r, q))) << endl;

  return 0;
}