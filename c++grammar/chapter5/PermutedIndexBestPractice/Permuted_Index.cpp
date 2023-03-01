#include "split.h"
#include "Permuted_index.h"
 
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::tolower;
using std::sort;
using std::ostringstream;
using std::accumulate;
// 문자열 배열 회전.
vector<string> rotate_line_elements(const vector<string>& words)
{
    vector<string> ret;
    typedef vector<string>::size_type vc_sz;
    vc_sz size = words.size();
 
    for (vc_sz i = 0; i != size; ++i)
    {
        if (i == size - 1)
            ret.push_back(words[0]);
        else
            ret.push_back(words[i + 1]);
    }
 
    return ret;
}
 
// vector의 string 집합을 sentence로 변환.
string string_from_vec_str(const vector<string>& words)
{
    string ret;
    typedef vector<string>::const_iterator vc_citer;
    for (vc_citer iter = words.begin(); iter != words.end(); ++iter)
        if (iter == words.begin())
            ret += *iter;
        else
            ret += (" " + *iter);
 
    return ret;
}

// permuted_index_collection 생성.
void make_permuted_index_collection(const vector<string>& line_collection,
                                    vector<Permuted_index>& permuted_index_collection)
{
    // Input: line_collection
    // Output: permuted_index_collection
 
    vector<string>::size_type birth_count = 0;
    vector<string>::size_type line_number = 0;
 
    // create Permuted_index object fred one-by-one and parse to the permuted_index_collection
    for (vector<string>::size_type i = 0; i != line_collection.size(); ++i)
    {
        string line = line_collection[i];
        vector<string> words = split(line);
 
        // initialise fred's properties before we perform line element rotations
        std::vector<std::string>::size_type rotations = 0;
        vector<string> ro_words = words;
 
        for (vector<string>::size_type j = 0; j != words.size(); ++j)
        {
            // Create permuted_index object fred
            Permuted_index fred;
            // 탄생 번호.
            fred.birth_id = birth_count;
            // 문장 순서 번호.
            fred.line_number = line_number;
            // 전체 문장.
            fred.line_elements = words;
            // 문장에서 시작 색인 번호.
            fred.position_in_line = rotations;
            // 회전 문장 vector
            fred.rotated_line_elements = ro_words;
            // 회전 문장 string
            fred.rotated_line = string_from_vec_str(ro_words);
 
            // append to the permuted_index_collection
            permuted_index_collection.push_back(fred);
 
            // re-initialise
            ro_words = rotate_line_elements(ro_words);
            ++rotations;
            ++birth_count;
        }
        ++line_number;
    }
}
 
string lowcase(const string& s)
{
    string ret;
    for (string::size_type i = 0; i != s.size(); ++i)
    {
        ret.push_back(tolower(s[i]));
    }
    return ret;
}
 
bool compare(const Permuted_index& x, const Permuted_index& y)
{
    return lowcase(x.rotated_line) < lowcase(y.rotated_line);
}
 
void sort_permuted_index_collection(vector<Permuted_index>& x)
{
    sort(x.begin(), x.end(), compare);
}
 
// (for quick test purpose) use this function to visualise the vector<Permuted_index> collection quickly
void print_permuted_index_collection(const vector<Permuted_index>& collection)
{
    for (vector<Permuted_index>::const_iterator iter = collection.begin(); iter != collection.end(); ++iter)
        cout << " Permuted_index: " << iter->birth_id
             << " | " << iter->line_number
             << " | " << string_from_vec_str(iter->line_elements)
             << " | " << iter->position_in_line
             << " | " << string_from_vec_str(iter->rotated_line_elements)
             << " | " << iter->rotated_line
             << " | " << iter->line_elements[iter->position_in_line]
             << endl;
}
 
vector<string> get_left_hand_side(const vector<Permuted_index>& v)
{
    vector<string> ret;
 
    for (vector<Permuted_index>::const_iterator iter1 = v.begin();
            iter1 != v.end(); ++iter1)
    {
        vector<string> words = iter1->line_elements;
        vector<string>::size_type permuted_index_pos = iter1->position_in_line;
        string s, temp;
        cout << "작업 구문 = " << accumulate(words.begin(), words.end(), temp) << "\n";
        for (vector<string>::size_type i = 0; i != permuted_index_pos; ++i)
        {
            if (i == 0)
                s += words[i];
            else
                s += (" " + words[i]);
        }
        cout << "생성 과정 left = " << s << "\n";
        ret.push_back(s);
    }
    return ret;
}
 
vector<string> get_right_hand_side(const vector<Permuted_index>& v)
{
    vector<string> ret;
 
    for (vector<Permuted_index>::const_iterator iter1 = v.begin();
            iter1 != v.end(); ++iter1)
    {
        vector<string> words = iter1->line_elements;
        vector<string>::size_type permuted_index_pos = iter1->position_in_line;
        string s;
        string temp;
        for (vector<string>::size_type i = permuted_index_pos; i != words.size(); ++i)
        {
            if (i == permuted_index_pos)
                s += words[i];
            else
                s += (" " + words[i]);
        }
        cout << "생성 과정 right = " << s << "\n";
        ret.push_back(s);
    }
    return ret;
}
 
// convert from number to string (http://www.cplusplus.com/articles/D9j2Nwbp/)
string string_from_int(int any_integer)
{
    string ret;              // string which will contain the result
    ostringstream convert;   // stream used for the conversion
    convert << any_integer;      // insert the textual representation of 'Number' in the characters in the stream
    ret = convert.str();        // set 'any_integer' to the contents of the stream
    return ret;
}
 
// clone from the same technique. i.e. convert from number to string (http://www.cplusplus.com/articles/D9j2Nwbp/)
// except i have replaced the parameter type from int, to const vector<string>::size_type&
string string_from_vec_str_size_type(const vector<string>::size_type& any_size_type)
{
    string ret;              // string which will contain the result
    ostringstream convert;   // stream used for the conversion
    convert << any_size_type;      // insert the textual representation of 'Number' in the characters in the stream
    ret = convert.str();        // set 'any_integer' to the contents of the stream
    return ret;
}
 
vector<string> get_line_numbers(const vector<Permuted_index>& v)
{
    vector<string> ret;
 
    for (vector<Permuted_index>::const_iterator iter1 = v.begin();
            iter1 != v.end(); ++iter1)
    {
        string s = "Line " + string_from_vec_str_size_type((iter1->line_number));
        ret.push_back(s);
    }
    return ret;
}
 
vector<string> get_word_numbers(const vector<Permuted_index>& v)
{
    vector<string> ret;
 
    for (vector<Permuted_index>::const_iterator iter1 = v.begin();
            iter1 != v.end(); ++iter1)
    {
        string s = "Word " + string_from_vec_str_size_type((iter1->position_in_line));
        ret.push_back(s);
    }
    return ret;
}