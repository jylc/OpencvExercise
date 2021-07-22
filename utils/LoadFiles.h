//
// Created by moicena on 2021/7/20.
//

#ifndef LOAD_FILES_H
#define LOAD_FILES_H

#include <fstream>
#include <cstring>
#include <vector>
#include <iostream>
#include "Logger.h"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
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


cv::Mat ReadImage() {
    Mat image = imread("/media/moicena/0D951B4C0D951B4C/电脑壁纸/pixiv/pic1.png", IMREAD_COLOR);
    Size size(image.cols / 2, image.rows / 2);
    resize(image, image, size);
    imshow("girl", image);
    cout << "rows = " << image.rows << ", cols = " << image.cols << endl;
    return image;
}


void PrintMatrix(const cv::Mat &matrix) {
    for (size_t i = 0; i < matrix.cols; i++) {
        for (size_t j = 0; j < matrix.rows; j++)
            std::cout << matrix.at<float>(i, j) << " ";

        std::cout << std::endl;
    }
}

void GetTranslatedImage(float x, float y) {
    cv::Mat image = ReadImage();
    cv::Mat res1;
    cv::Mat shiftMat = cv::Mat::zeros(2, 3, CV_32FC1);
    shiftMat.at<float>(0, 0) = 1;
    shiftMat.at<float>(1, 1) = 1;
    shiftMat.at<float>(0, 2) = x;
    shiftMat.at<float>(1, 2) = y;
    cv::warpAffine(image, res1, shiftMat, image.size());
    cv::imshow("result", res1);

    std::pair<int, int> shift;
    shift.first = 200;
    shift.second = -100;
    auto up = (std::abs(shift.second) + shift.second) / 2;
    auto left = (std::abs(shift.first) + shift.first) / 2;
    auto down = (std::abs(shift.second) - shift.second) / 2;
    auto right = (std::abs(shift.first) - shift.first) / 2;
    auto width = image.cols - right - left;
    auto height = image.rows - down - up;
    std::printf("up %d,down %d,left %d,right %d\n", up, down, left, right);
    cv::Rect rect1(right, down, width, height);
    cv::Mat res2 = image(rect1);
    cv::imshow("result2", res2);
}


#endif //LOAD_FILES_H
