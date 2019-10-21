/******************************************************************************
 * MIT License

 * Copyright (c) 2019 Saumil Shah, Aman Virmani, Naman Gupta

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 ******************************************************************************/

/**
 * @file      VisionInput.hpp
 * @author    Saumil Shah (SaumilShah66) Driver
 * @author    Naman Gupta (namangupta98) Navigator
 * @author    Aman Virmani (AmanVirmani) Design Keeper
 * @copyright MIT License
 * @brief     VisionInput Class declaration
 * @detail    Declared functions Class to get data for realtime detection
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <DataLoader.hpp>
#include <sys/stat.h>
#include <fstream>
#include <sys/types.h>
#include <DetectHuman.hpp>

/**
 * @brief class VisionInput
 * The class VisionInput gives different functionalities to use HOG feature 
 * based Human detection, so that it can be used with live videos from camera sensor
 * or saved videos and image files.
 */
class VisionInput {
 public:
  /**
   * @brief constructor VisionInput
   * @param none
   * @return none
   */
  VisionInput();
  /**
   * @brief Container to store an image
   */
  cv::Mat image;
    /**
   * @brief Instance created of DetecHuman class for human detection with data fedd
   */
  DetectHuman humanDetector;
    /**
   * @brief Container to store detected human positions in form of pixel coordinates
   */
  std::vector<cv::Rect> boundingBoxes;

  /**
   * @brief This method starts human detection from specified camera feed
   * @param cameraCode of type int
   * @return none
   * @description Camera code depends which camera you want to use. Normally 
   * code 0 is used to start reading data from webcam.
   */
  void detectWithCamera(int cameraCode);
  /**
   * @brief This method starts human detection from specified video file
   * @param filename of type string
   * @return none
   * @description Provide a video filename with full path in order to run
   * human detection with videofiles 
   */
  void detectWithVideoFile(std::string filename);
  /**
   * @brief This method starts human detection from specified image file
   * @param cameraCode of type string
   * @return none
   * @description Provide an image filename with full path in order to run
   * human detection with image files
   */
  void detectWithImage(std::string filename);
  /**
   * @brief This method sets which SVM model will be used for detection
   * @param SVMFilename of type string
   * @return none
   * @description You can provide your own SVM classifier or you can use
   * default classifier provided with OpenCV
   */
  void setupDetector(std::string SVMFilename);
  /**
   * @brief This method creates bounding boxes around detected humans
   * @param none
   * @return none
   */
  void showImageWithBox();
    /**
   * @brief destructor VisionInput
   * @param none
   * @return none
   */
  ~VisionInput();
 private:
  /**
   * @brief Checks if given SVM classifier file exists or not
   * @param filename of type string
   * @return true if file exists and false otehrwise
   */
  bool fileExist(const std::string& filename);
};

