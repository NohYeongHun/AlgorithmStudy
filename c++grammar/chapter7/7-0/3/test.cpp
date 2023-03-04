#include <iostream>          // std::cin, std::cout, std::endl
#include <string>            // std::string
#include <vector>            // std::vector
#include <ctime>             // Added. std::time
#include <cstdlib>           // Added. std::srand

#include "read_grammar.h"    // read_grammar
#include "gen_sentence.h"    // gen_sentence
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
 
using std::srand;
using std::time;
 
int main()
{
  srand(time(NULL));   // Added. Seed new form of randomness.
 
  Grammar grammar = read_grammar(cin);
 
  for (int i = 0; i != 100; ++i) {
 
    // generate the sentence
    vector<string> sentence = gen_sentence(grammar);
 
    // write the first word, if any
    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
      cout << *it;
      ++it;
    }
 
    // write the rest of the words, each preceded by a space
    while (it != sentence.end()) {
      cout << " " << *it;
      ++it;
    }
 
    cout << endl;
  }
 
  return 0;
}
