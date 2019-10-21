// test.cpp
// Test program for testing the pipeline / detector against ground truth dataset

#include "io/DatasetLoader.hpp"
#include "io/fumarole_data_io.hpp"

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>

int main(int argc, char** argv)
{
    // Load test bounding boxes (ground truth)
    std::map<std::string, std::vector<cv::Rect>> groundTruth;
    IO::DatasetLoader::LoadTestData(groundTruth);

    for (auto iter = groundTruth.begin(); iter != groundTruth.end(); iter++)
    {
        std::cout << "\n\n" << iter->first << std::endl;
        for (auto rect : iter->second) {
            std::cout << "\nx: " << rect.x << " y: " << rect.y << " width: " << rect.width << " height: " << rect.height << std::endl;
        }
    }

    // load test data
    std::vector<std::string> testFileIDs;
    IO::DatasetLoader::GetTestFileIDs(testFileIDs);

    return 0;
}