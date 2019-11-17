//
// FumaroleDetector.hpp
// Takes input for fumarole thermal images and recognizes fumaroles
//

#ifndef FUMAROLE_LOCALIZATION_FUMAROLEDETECTOR_HPP
#define FUMAROLE_LOCALIZATION_FUMAROLEDETECTOR_HPP

#include <map>
#include <memory>
#include <string>

#include "detection/FumaroleDetection.hpp"
#include "pipeline/Pipeline.hpp"

namespace Detection
{
    // Typedef for this recognizers main output - a map where key:fileID, value: list of detections
    typedef std::map<std::string, std::vector<FumaroleDetection>> FumaroleDetectionsPerImage;

    class FumaroleDetector
    {
    public:
        /// Default constructor
        FumaroleDetector();

        /// Destructor
        ~FumaroleDetector();

        /// Recognize all the fumaroles in the given image
        /// \param fileID The ID to associate with this image
        /// \param thermalImagePath The file path to the thermal image to load
        /// \param result A reference to the detection result that will be set
        /// \return Returns true on success
        bool DetectFumaroles(const std::string& fileID, const std::string& thermalImagePath, std::vector<Detection::FumaroleDetection> &results) const;

        /// Recognize all the fumaroles in the given image set and map bounding boxes for all of them
        /// \param files A map where key = the file id, and value = the file path to the thermal image
        /// \param results A reference that will be set to a map with key = file id, and value = a vector of detections for the fumaroles
        /// \return Returns true on success
        bool DetectFumaroles(const std::map<std::string, std::string>& files, std::map<std::string, std::vector<FumaroleDetection>>& results) const;

        /// Save the result detection map [maps image id -> list of fumaroles] as images with the bounding boxes drawn on top
        /// \param resultMap A map with <file_id: <list of fumarole detection results>>
        void SaveResults(const FumaroleDetectionsPerImage& resultMap) const;

    private:
        std::map<std::string, std::vector<FumaroleDetection>> ConvertLocalizations(const Pipeline::PipelineLocalizations& localizations, Model::FumaroleType type) const;
        std::vector<FumaroleDetection> ClassifyLocalizations(const std::vector<std::vector<cv::Point>>& contours) const;
        std::vector<FumaroleDetection> DetectOpenVents(const std::vector<std::vector<cv::Point>>& contours) const;
        std::vector<FumaroleDetection> DetectHiddenVents(const std::vector<std::vector<cv::Point>>& contours) const;
        cv::Scalar ColorForType(Model::FumaroleType type) const;

    private:
        float m_MinAreaForHeatedArea;
    };
}

#endif //FUMAROLE_LOCALIZATION_FUMAROLEDETECTOR_HPP