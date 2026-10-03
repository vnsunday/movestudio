#ifndef DYNSOCC_FUNDAMENTAL_STDEX_META_HPP_
#define DYNSOCC_FUNDAMENTAL_STDEX_META_HPP_


// Header Only Library
namespace dynsocc::meta
{
    inline int METAN = 0;
    inline char METABUFFER[10000];

    void Label(const char* label, const char* address);

    
    inline void Label(const char* label, const char* address) {
    }
}


#endif