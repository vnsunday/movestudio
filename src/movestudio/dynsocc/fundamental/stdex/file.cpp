#include "file.hpp"

using namespace std;
using namespace dynsocc;

int fileutil::get_filename(std::string path, std::string& filename)
{
    int n = path.length()-1;

    while (n>=0 && path[n] != '\\' && path[n] != '/')
    {
        n--;
    }

    filename = path.substr(n+1);
    return 0;
}

int fileutil::get_folder(std::string path, std::string& folder)
{
    int n = path.length()-1;

    while (n>=0 && path[n] != '\\' && path[n] != '/')
    {
        n--;
    }

    folder = path.substr(0, n);
    return 0;
}

int fileutil::get_filename_without_ext(std::string filepath, std::string& filename_noext)
{
    string filename;
    get_filename(filepath, filename);
    
    int n = filename.length()-1;
    while (n>=0 && filename[n] != '.') { n--; }

    if (n>=0)
    {
        filename_noext = filename.substr(0, n);
    }
    else 
    {
        filename_noext = filename;
    }

    return 0;
}

int fileutil::get_file_extension(std::string filepath, std::string& extension)
{
    string filename;
    get_filename(filepath, filename);
    
    int n = filename.length()-1;
    while (n>=0 && filename[n] != '.') { n--; }

    if (n>=0)
    {
        extension = filename.substr(n+1);
    }
    else 
    {
        extension = "";
    }
    return 0;
}

int fileutil::get_file_extension_withdot(std::string filepath, std::string& extension)
{
    string filename;
    get_filename(filepath, filename);
    
    int n = filename.length()-1;
    while (n>=0 && filename[n] != '.') { n--; }

    if (n>=0)
    {
        extension = filename.substr(n);
    }
    else 
    {
        extension = "";
    }
    return 0;
}

std::string fileutil::join_path(std::string path1, std::string path2, std::string seperator)
{
    while (path1.length() > 0 && (path1[path1.length()-1] == '/' || path1[path1.length()-1] == '\\'))
    {
        path1.pop_back();
    }

    while (path2.length() > 0 && (path2[0]=='/' || path2[0]=='\\')) 
    {
        path2.erase(0,1);
    }

    return path1 + seperator + path2;
}