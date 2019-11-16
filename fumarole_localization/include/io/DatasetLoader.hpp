//
// DatasetLoader.hpp
// Loads data from the file system
//

#ifndef FUMAROLE_LOCALIZATION_DATASETLOADER_HPP
#define FUMAROLE_LOCALIZATION_DATASETLOADER_HPP

#include <string>
#include <vector>
#include <map>
#include <opencv2/core/types.hpp>

#include "detection/FumaroleDetection.hpp"

namespace IO
{
    class DatasetLoader
    {
    public:
        /// Loads the file IDs from the given file
        /// \param files A reference to a map that will be filled with <file id: file path>
        static void GetTestFiles(const std::string& folder, std::map<std::string, std::string> &files);

        /// Load testing data to test the algorithm and pipeline
        /// \param folder The name of the folder in the resources directory that has the list of labelImg files
        /// \param testFiles Will be loaded with <file id: file path>
        /// \param groundTruth Will be loaded with <file id: the list of ground truth recognition results>
        static void LoadTestData(const std::string& folder, std::map<std::string, std::string>& testFiles, std::map<std::string, std::vector<Detection::FumaroleDetection>>& groundTruth);
    };
}

#endif //FUMAROLE_LOCALIZATION_DATASETLOADER_HPP
