#ifndef DYNSOCC_FUNDAMENTAL_STDEX_META_HPP_
#define DYNSOCC_FUNDAMENTAL_STDEX_META_HPP_

#include <algorithm>
#include <string>
#include <vector>

// Header Only Library
namespace dynsocc::meta
{
    inline int METAN = 0;
    inline char METABUFFER[10000];
    inline 
        std::vector<std::string> vLabel;

    void Label(const char* label, const char* address);
    void Sum(const char* variable, const char* Relation);
    void ParseToken(char* szText, int len);
    void CostFunction(char* szText);
    void SumQuality();

    inline void Label(const char* label, const char* address) {
        vLabel.push_back(label);
        std::sort(vLabel.begin(), vLabel.end());
    }

    inline void Sum(const char* variable, const char* Relation) {
        // Range relation
        std::string rstart;
        std::string rend;
        std::string op("+");

        
    }

    inline void ParseToken(char* szText, int len) {
        int i = 0;
        char ch;
        char seps[] { ' ', '\t', '\r', '\n'};
        while (i < len) {
            ch = szText[i];
            i++;
            // If seps is a character
        }
    }

    inline void SumQuality() {
        // 
        std::string orderless("orderless");
    }
}

#endif