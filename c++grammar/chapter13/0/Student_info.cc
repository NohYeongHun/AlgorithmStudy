#include <iostream>
#include <stdexcept>

#include "core.h"
#include "Student_info.h"

using namespace std;

istream& Student_info::read(istream& is) {
  delete cp;

  // Check if input stream is in a failed state
  if (!is) {
    return is;
  }

  char ch;
  
  if (is >> ch) {
    // Read student information based on the type
    switch (ch) {
      case 'U':
        cp = new Core(is);
        break;
      case 'G':
        cp = new Grad(is);
        break;
      case 'P':
        cp = new PassFail(is);
        break;
      case 'A':
        cp = new Audit(is);
        break;
      default:
        // Unknown type
        throw runtime_error("read invalid student type");
    }
  } else {
    // No input
    cp = nullptr;
  }

  return is;
}

Student_info::Student_info(const Student_info& s): cp(0) {
  if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s) {
  if (&s != this) {
    delete cp;
    if (s.cp) cp = s.cp->clone();
    else cp = 0;
  }

  return *this;
}
