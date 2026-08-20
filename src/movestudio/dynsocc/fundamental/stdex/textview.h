#ifndef DYNSOCC_FUNDAMENTAL_STDEX_TEXTVIEW_H_
#define DYNSOCC_FUNDAMENTAL_STDEX_TEXTVIEW_H_

#include <vector>
#include <string>

#define DYNSOCC_TEXT_ALIGN_LEFT         0x00000001
#define DYNSOCC_TEXT_ALIGN_RIGHT        0x00000002
#define DYNSOCC_TEXT_ALIGN_CENTER       0x00000004
#define DYNSOCC_TEXT_ALIGN_JUSTIFY      0x00000008


namespace dynsocc
{

    class TextView 
    {
    public:
        static std::string column_print(
            std::vector<int> vcol_size,
            std::vector<int> vformat, 
            std::vector<std::string> vcol,
			char ch_column_separator=0
        );

		static std::string table_print(
			std::vector<int> vcol_size,
			std::vector<int> vformat,
			std::vector<std::vector<std::string>> vtable_data,
			char ch_column_separator = 0
		);
    };
}

#endif 