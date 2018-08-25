/*
 * stringproblems.cpp
 *
 *  Created on: 25-Aug-2018
 *      Author: mani
 */

#include <stringproblems.h>

using namespace std;

namespace PFF {

/*
StringProblems::StringProblems() {
  // TODO Auto-generated constructor stub

}

StringProblems::~StringProblems() {
  // TODO Auto-generated destructor stub
}
 */


string find_n_replace(string str_i, string str_f, string str_r) {
  string str_o;
#if USE_C_CODE
  str_o = string(find_n_replace(str_i.c_str(), str_f.c_str(), str_r.c_str()));
#else
  size_t sub_pos = str_i.find(str_f);
  if (string::npos != sub_pos) {
    size_t str_i_cur_pos = 0;
    size_t str_o_cur_pos = 0;
    do {
      //cout << endl << "sub_pos: " << sub_pos << endl << endl;

      // append the string before str_f from str_i
      str_o.append(str_i, str_i_cur_pos, (sub_pos - str_i_cur_pos));
      //cout << "str_o: " << str_o << endl;

      // append the string str_f at sub_pos
      str_o.append(str_r);
      //cout << "str_o: " << str_o << endl;

      // update string pos's
      str_i_cur_pos = sub_pos + str_f.size();
      //cout << "str_i_cur_pos: " << str_i_cur_pos << endl;

      sub_pos = str_i.find(str_f, str_i_cur_pos);
    } while (string::npos != sub_pos);
  } else {
    str_o = str_i;
  }
#endif
  return str_o;
}

// Cpp like C APIs
void str_append(const char* src, const char* dst, size_t len) {
  dst = (const char*) malloc(len);
  memcpy((void*) src, (void*) dst, len);
}

size_t str_find(const char* str_i, const char* str_f, size_t init_len) {
  size_t found_pos = (strstr(str_i, str_f) - str_i + init_len);
  cout << "found_pos: " << found_pos << endl;
  return found_pos;
}

const char* find_n_replace(const char* str_i, const char* str_f,
                           const char* str_r) {
  const char* str_o = NULL;

  size_t str_i_consumed_len = 0;
  size_t sub_pos = str_find(str_i, str_f, str_i_consumed_len);
  if (0 != sub_pos) {
    size_t str_f_len = strlen(str_f);
    size_t str_r_len = strlen(str_r);
    size_t str_i_cur_pos = 0;
    size_t str_o_cur_pos = 0;
    do {
      //cout << endl << "sub_pos: " << sub_pos << endl << endl;

      // append the string before str_f from str_i
      //str_o.append(str_i, str_i_cur_pos, (sub_pos - str_i_cur_pos));
      str_append(str_i + str_i_cur_pos, str_o + str_o_cur_pos,
                 (sub_pos - str_i_cur_pos));
      str_o_cur_pos += (sub_pos - str_i_cur_pos);
      //cout << "str_o: " << str_o << endl;

      // append the string str_f at sub_pos
      //str_o.append(str_r);
      str_append(str_o + str_o_cur_pos, str_r, str_r_len);
      str_o_cur_pos += str_r_len;
      //cout << "str_o: " << str_o << endl;

      // update string pos's
      //str_i_cur_pos = sub_pos + str_f.size();
      str_i_cur_pos += sub_pos + str_f_len;
      str_i_consumed_len = str_i_cur_pos;
      //cout << "str_i_cur_pos: " << str_i_cur_pos << endl;

      //sub_pos = str_i.find(str_f, str_i_cur_pos);
      sub_pos = str_find(str_i + str_i_cur_pos, str_f, str_i_consumed_len);
    } while (0 != sub_pos);
  } else {
    str_o = str_i;
  }

  return str_o;
}


} /* namespace PFF */