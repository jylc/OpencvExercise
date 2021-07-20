// RobustImageStitching.cpp: 定义应用程序的入口点。
//

#include "OpencvExercise.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> subdirs;
    string parent("/var/CppProjects");
    LoadDirectories(parent, subdirs);
    if (!subdirs.empty()) {
        for (auto &dir:subdirs) {
            cout << dir << endl;
        }
    }
    cv::waitKey();
    return 0;
}
