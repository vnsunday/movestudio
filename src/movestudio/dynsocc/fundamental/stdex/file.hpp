#ifndef DYNSOCC_FUNDAMENTAL_STDEX_FILE_HPP_
#define DYNSOCC_FUNDAMENTAL_STDEX_FILE_HPP_

#include <vector>
#include <string>
#include <fstream>

// file_path: string, 
// vectorline: vector<string>
#define READ_FILE_LINE_BY_LINE(file_path, vectorline) { \
        vectorline.clear();                             \
        std::ifstream file1(file_path);                 \
        if (file1.is_open())                            \
        {                                               \
            std::string line;                           \
            while (std::getline(file1, line))           \
            {                                           \
                vectorline.push_back(line);             \
            }                                           \
            file1.close();                              \
        }                                               \
    }


namespace dynsocc
{
    class fileutil
    {
    public:
        int get_filename(std::string path, std::string& filename);
        int get_folder(std::string path, std::string& folder);
        int get_filename_without_ext(std::string filepath, std::string& filename_noext);
        int get_file_extension(std::string filepath, std::string& extension);
        int get_file_extension_withdot(std::string filepath, std::string& extension);
        std::string join_path(std::string path1, std::string path2, std::string seperator="/");
    };
}

#endif