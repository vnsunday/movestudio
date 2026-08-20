#include "textview.h"

#include <cstring>
#include <string>
#include <vector>
#include <assert.h>
#include <string.h>
using namespace dynsocc;
using namespace std;

std::string TextView::column_print(
            std::vector<int> vcol_size,
            std::vector<int> vformat, 
            std::vector<std::string> vcol_value,
			char ch_column_separator
        )
{
    char szBuff[500];
    char szColumn[100];
    char ch_space = ' '; 
    int arr_column_start[50];
    int nspace_between_col = 2;

    

    assert(vcol_size.size() == vformat.size());
    assert(vformat.size() == vcol_value.size());
	
    int n = vcol_size.size();
    arr_column_start[0] = 0;
    for (int i=1; i<n;++i)
    {
        arr_column_start[i] = nspace_between_col + arr_column_start[i-1] + vcol_size[i-1];
    }

    arr_column_start[n] = arr_column_start[n-1] + vcol_size[n-1] + nspace_between_col;
    memset(szBuff, ch_space, arr_column_start[n]);
    szBuff[arr_column_start[n]] = NULL;

    for (int i=0; i<n;++i)
    {
        int nsize = vcol_size[i];
		int ncontentlen = vcol_value[i].length();
        int ndisplaylen = ncontentlen > nsize ? nsize : ncontentlen;

        if (vformat[i] & DYNSOCC_TEXT_ALIGN_LEFT)
        {            
            memcpy(
                szBuff + arr_column_start[i], 
                vcol_value[i].data(), 
                // 0, 
                ndisplaylen
            );
        }
        else if (vformat[i] & DYNSOCC_TEXT_ALIGN_RIGHT)
        {
            memcpy(
                szBuff + arr_column_start[i+1] - nspace_between_col - ndisplaylen,
                vcol_value[i].data(), 
                // 0, 
                ndisplaylen
            );
        }
        else if (vformat[i] & DYNSOCC_TEXT_ALIGN_CENTER)
        {
            memcpy(
                szBuff + arr_column_start[i] + (vcol_size[i] - ndisplaylen)/2,
                vcol_value[i].data(), 
                // 0, 
                ndisplaylen
            );
        }
        else if (vformat[i] & DYNSOCC_TEXT_ALIGN_JUSTIFY)
        {
            throw "UnImplementation";
        }

        // Character border 
        // if (i < n-1)
		if (ch_column_separator)
        {
            szBuff[arr_column_start[i+1]-nspace_between_col]=ch_column_separator;
        }
    }

    string str_print = szBuff;
    return str_print;
}        


std::string TextView::table_print(
	std::vector<int> vcol_size,
	std::vector<int> vformat,
	std::vector<std::vector<std::string>> vtable_data,
	char ch_column_separator)
{
	string strcontent = "";
	char szBuff[500];
	char szColumn[100];
	char ch_space = ' ';
	int arr_column_start[50];
	int nspace_between_col = 2;


	// Validation
	assert(vcol_size.size() == vformat.size());
	for (int i = 0; i < vtable_data.size(); ++i)
	{
		assert(vformat.size() == vtable_data[i].size());
	}
	

	int n = vcol_size.size();
	arr_column_start[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		arr_column_start[i] = nspace_between_col + arr_column_start[i - 1] + vcol_size[i - 1];
	}
	arr_column_start[n] = arr_column_start[n - 1] + vcol_size[n - 1] + nspace_between_col;

	for (int row = 0; row < vtable_data.size(); ++row)
	{
		memset(szBuff, ch_space, arr_column_start[n]);
		szBuff[arr_column_start[n]] = NULL;

		for (int i = 0; i < n; ++i)
		{
			int nsize = vcol_size[i];
			int ncontentlen = vtable_data[row][i].length();
			int ndisplaylen = ncontentlen > nsize ? nsize : ncontentlen;

			if (vformat[i] & DYNSOCC_TEXT_ALIGN_LEFT)
			{
				memcpy(
					szBuff + arr_column_start[i],
					vtable_data[row][i].data(),
					//0,
					ndisplaylen
				);
			}
			else if (vformat[i] & DYNSOCC_TEXT_ALIGN_RIGHT)
			{
				memcpy(
					szBuff + arr_column_start[i + 1] - nspace_between_col - ndisplaylen,
					vtable_data[row][i].data(),
					//0,
					ndisplaylen
				);
			}
			else if (vformat[i] & DYNSOCC_TEXT_ALIGN_CENTER)
			{
				memcpy(
					szBuff + arr_column_start[i] + (vcol_size[i] - ndisplaylen) / 2,
					vtable_data[row][i].data(),
					// 0,
					ndisplaylen
				);
			}
			else if (vformat[i] & DYNSOCC_TEXT_ALIGN_JUSTIFY)
			{
				throw "UnImplementation";
			}

			// Character border 
			// if (i < n-1)
			if (ch_column_separator)
			{
				szBuff[arr_column_start[i + 1] - nspace_between_col] = ch_column_separator;
			}
		}

		string strline = szBuff;

		if (row > 0)
		{
			strcontent += "\r\n";
		}
		strcontent += strline;

	}
	return strcontent;
}