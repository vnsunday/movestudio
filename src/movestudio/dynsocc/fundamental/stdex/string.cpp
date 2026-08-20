#include "string.hpp"
#include <cmath>
#include <cstring>
#include <vector>

using namespace dynsocc;
using namespace std;

int stringutil::find(std::string src, std::string tofind, std::vector<int>& vres)
{
    bool bCaseSensitive = true;
    int nstart = 0;
    int nend = 0;
    int i = 0;
    int j = 0;
    int nlen_tofind = tofind.length();
	int nstart_range = src.length() - nlen_tofind;

    vres.clear();
   
    while (nstart <= nstart_range)	// The - last position.
    {
        i = nstart;
        j = 0;

        while (src[i] == tofind[j] && j < nlen_tofind)
        {
            i++; j++;
        }

        if (j==nlen_tofind)
        {
            // Found 
            vres.push_back(nstart); // Found
        }
        nstart++; // Found  
	}	
    return 0;
}

int stringutil::compare(unsigned int* p1, int n1, unsigned int* p2, int n2)
{
    /* */
    /* diffrent = total operator to convert from p1 to p2 */
    /* 
        lev(a,b)=
		max(
			lev(a-1,b-1) + match (s1[a],s2[b])
			lev(a,b-1) 
			lev(a-1,b)
    */

	int nbuffsz = sizeof(int)*n1;
	int* plev1 = (int*)malloc(nbuffsz);
	int* plev2 = (int*)malloc(nbuffsz);

	memset(plev1, 0, nbuffsz);
	memset(plev2, 0, nbuffsz);

	int* plev = plev2;			// 
	int* plev_prev = plev1;		// 
	int nMatch = 1;
	int diff = 0;

	for (int i = 1; i < n2; ++i)
	{
		for (int j = 0; j < n1; ++j)
		{
			// In this Loop 
			//		plev[j] = lev[i,j]
			//		plev_pre[j] = lev[i-1,j]
			nMatch = p1[i] == p1[j] ? 1 : 0;
		}
	}

	return 0;
}

int stringutil::fuzzy_search(unsigned int* str, int n)
{
	return 0;
}

string stringutil::format_number_thousand_separator(double number, int& res, char ch_separator)
{
	string str;
	res = 0;
    char chDot = '.';

    char szBuff[100];
    char szIntPart[100];
    sprintf(szBuff, "%f",number);

    double dIntPart = floor(number);

    int nlen = strlen(szBuff);
    int ndotIdx = 0;
    int nfirstNumIdx = 0;

    while (ndotIdx < nlen &&  szBuff[ndotIdx] != chDot)
    {
        ndotIdx++;
    }

    while (nfirstNumIdx < nlen && (szBuff[nfirstNumIdx] < '0' || szBuff[nfirstNumIdx] > '9') )
    {
        nfirstNumIdx++;
    }

    int nIntegerPartLen = ndotIdx - nfirstNumIdx;
    int arr_sep[20];
	int nSep = floor((double)(nIntegerPartLen-1) / 3);

	str = szBuff;
	// Insert 
	for (int i = 1; i <= nSep; ++i)
	{
		str.insert(ndotIdx - i * 3, 1, ch_separator);
	}

	return str;
}

std::string stringutil::tolower(std::string str1)
{
    std::string str2 = str1;

    for (int i=0;i<str2.length();++i)
    {
        if (str2[i] >= 'A' && str2[i] <= 'Z')
        {
            str2[i] = 'a' + str2[i] - 'A';
        }
    }

    return str2;
}

std::string stringutil::trim(std::string str)
{
    while (str.length() > 0 && (str[0] == ' ' || str[0] == '\t' || str[0] == '\r' || str[0] == '\n'))
    {
        str.erase(0, 1);
    }

    while (str.length() > 0 && (str[str.length()-1] == ' ' || str[str.length()-1] == '\t' || str[str.length()-1] == '\r' || str[str.length()-1] == '\n'))
    {
        str.erase(str.length()-1, 1);
    }
    
    return str;
}

double stringutil::approximate_match(std::string str1, std::string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    

    return 0.0;
}

int stringutil::split(string str1, char ch_separator, vector<string> &vsep)
{
    vsep.clear();
    int nprev = -1;                         // Previous Position 
    int nlen = str1.length();
    for (int i=0;i<nlen;++i)       // 
    {
        if (str1[i] == ch_separator)
        {
            if (i >= nprev + 1)
            {
                vsep.push_back(str1.substr(nprev+1, i-nprev-1));    
            }
            nprev = i;
        }
    }
    if (nlen >= nprev + 1)
    {
        vsep.push_back(str1.substr(nprev+1, nlen-nprev-1));    
    }
    return 0;
}
