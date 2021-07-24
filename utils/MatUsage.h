//
// Created by moicena on 2021/7/22.
//

#ifndef OPENCVEXERCISE_MATUSAGE_H
#define OPENCVEXERCISE_MATUSAGE_H

#include <opencv2/core.hpp>

using namespace cv;

class MatUsage {
public:
    static void MatUsageTest();

    static void MeshGrid(const Range &xgv, const Range &ygv, Mat &x, Mat &y);
};


#endif //OPENCVEXERCISE_MATUSAGE_H
