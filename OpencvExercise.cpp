// RobustImageStitching.cpp: 定义应用程序的入口点。
//

#include "OpencvExercise.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include "MatUsage.h"

using namespace std;
using namespace cv;

int main() {
    GetTranslatedImage(200,-100);
    cv::waitKey();
    return 0;
}
