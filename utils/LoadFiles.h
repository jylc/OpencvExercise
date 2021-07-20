//
// Created by moicena on 2021/7/20.
//

#ifndef LOAD_FILES_H
#define LOAD_FILES_H

#include <fstream>
#include <cstring>
#include <vector>
#include "Logger.h"
#ifdef __WIN32__
#include <io.h>
#endif // !__WIN32__

#ifdef __linux__
#include <dirent.h>
#endif // !__linux__

static void LoadDirectories(std::string &parent, std::vector<std::string> &subdirs) {
#ifdef __linux__
    DIR *dir;
    struct dirent *dir_list;
    if ((dir = opendir(parent.c_str())) == nullptr) {
        Logger::logger("cannot open the dir :" + parent);
        exit(-1);
    }
    fflush(stdout);
    if (readdir(dir) == nullptr) {
        printf("read dictionary failed!");
        closedir(dir);
        exit(-1);
    }

    while ((dir_list = readdir(dir)) != nullptr) {
        if (dir_list->d_type == 4)//dir
        {
            if (std::strcmp(dir_list->d_name, ".") != 0 && std::strcmp(dir_list->d_name, "..") != 0) {
                printf("dir: %s\n", dir_list->d_name);
                subdirs.emplace_back(dir_list->d_name);
            }
        }
    }
    closedir(dir);
#endif // !__linux__

#ifdef __WIN32__
    intptr_t hFile = 0;
    struct _finddata_t fileinfo;
    std::string p;

    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do {
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
                    subdirs.push_back(fileinfo.name);
                }
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
#endif // !__WIN32__
}


#endif //LOAD_FILES_H
