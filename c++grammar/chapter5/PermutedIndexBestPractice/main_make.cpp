#include <string>               // std::string
#include <vector>               // std::vector
#include "read_lines.h"         // read_lines
#include "Permuted_index.h"     // Permuted_index
#include "split.h"              // split
#include "frame.h"              // frame
#include "hcat.h"               // hcat
#include "vcout.h"              // vcout
 
using std::string;
using std::vector;
 
int main()
{
 
    // read lines via standard console input and append to article
    vector<string> article = read_lines();
 
    // prepare an empty Permuted_index_collection
    vector<Permuted_index> Permuted_index_collection;
 
    // populate the Permuted_index_collection
    make_permuted_index_collection(article, Permuted_index_collection);
 
    // sort the Permuted_index_collection by the rotated_line string (i.e. the permuted index word)
    sort_permuted_index_collection(Permuted_index_collection);
 
    // extract and frame the left_block (left align)
    vector<string> left_block = frame(get_left_hand_side(Permuted_index_collection),"right",'*');
 
    // extract and frame the right block (right align)
    vector<string> right_block = frame(get_right_hand_side(Permuted_index_collection),"left",'*');
 
    // extract and frame the line_number block (left align)
    vector<string> line_number_block = frame(get_line_numbers(Permuted_index_collection),"left",'*');
 
    // extract and frame the word_number block (left align)
    vector<string> word_number_block = frame(get_word_numbers(Permuted_index_collection),"left",'*');
 
    // horizontal concatenate the blocks to form a permuted index page
    vector<string> Permuted_index_collection2 = hcat(left_block, right_block);
    vector<string> Permuted_index_collection3 = hcat(Permuted_index_collection2, line_number_block);
    vector<string> Permuted_index_collection4 = hcat(Permuted_index_collection3, word_number_block);
 
    // visualise the output
    vcout(Permuted_index_collection4);
 
    return 0;
}