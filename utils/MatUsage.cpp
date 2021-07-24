//
// Created by moicena on 2021/7/22.
//

#include "MatUsage.h"
#include <iostream>
#include <vector>

using namespace std;

void MatUsage::MatUsageTest() {
    cv::Mat center = cv::Mat::zeros(2, 4, CV_32FC1);
    center.at<float>(0, 0) = 1;
    center.at<float>(0, 1) = 2;
    center.at<float>(0, 2) = 3;
    center.at<float>(0, 3) = 4;
    center.at<float>(1, 0) = 5;
    center.at<float>(1, 1) = 6;
    center.at<float>(1, 2) = 7;
    center.at<float>(1, 3) = 8;
    cout << center << endl;
    cv::Mat center_tr = center.t();
    cout << center_tr << endl;
    auto result = center_tr * center;
    cout << result << endl;
    center_tr.at<float>(0, 1) = 0;
    cv::Mat result1 = center_tr.mul(center_tr);
    cout << result1 << endl;
}

//MatLab meshgrid
void MatUsage::MeshGrid(const Range &xgv, const Range &ygv, Mat &x, Mat &y) {
    std::vector<int> X, Y;
    for (int i = xgv.start; i < xgv.end; i++) { X.emplace_back(i); }
    for (int j = ygv.start; j < ygv.end; j++) { Y.emplace_back(j); }
    cout<<cv::Mat(X).t()<<endl;
    cv::repeat(cv::Mat(X).t(), Y.size(), 1, x);
    cv::repeat(cv::Mat(Y), 1, X.size(), y);
}

