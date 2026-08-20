#ifndef DYNSOCC_FUNDAMENTAL_STDEX_STRING_HPP_
#define DYNSOCC_FUNDAMENTAL_STDEX_STRING_HPP_

#include <string>
#include <vector>

/*
#define SPLIT(string1, ch_separator, v_separate) {\
    v_separate.clear();\
    int nprev=-1;\
    for (int i=0;i<string1.length();++i) { if (string1[i]==ch_separator) { if (i>n_prev+1) {v_separate.push_back(nprev, ); }  }\
}
*/

namespace dynsocc
{

    class stringutil
    {
    public:
        static int find(std::string src, std::string tofind, std::vector<int>& vres);

		static int compare(unsigned int* p1, int n1, unsigned int* p2, int n2);

		static int fuzzy_search(unsigned int* str, int n);

		static std::string format_number_thousand_separator(double number, int& res, char ch_separator = '\'');

        static std::string tolower(std::string );

        static std::string trim(std::string);

        static double approximate_match(std::string str1, std::string str2);    // Approximate matching 

        static int split(std::string str1, char ch_separator, std::vector<std::string> &vsep);
    };
}

#endif