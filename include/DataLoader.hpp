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
 * @file      DataLoader.h
 * @author    Naman Gupta (namangupta98) Driver
 * @author    Saumil Shah (SaumilShah66) Design Keeper
 * @author    Aman Virmani (AmanVirmani) Navigator
 * @copyright MIT License
 * @brief     DataLoader Class declaration
 * @detail    Declared functions Class to read data from files and camera 
 * 			  sensors
 */
#ifndef INCLUDE_DATALOADER_HPP_
#define INCLUDE_DATALOADER_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

/**
 * @brief	class DataLoader
 * The class DataLoader captures image/video from camera sensor or files and
 * creates HOG feature for every image.
 */

class DataLoader {
 public:
  /**
   * @brief constructor DataLoader
   * @param none
   * @return none
   */
  DataLoader();

  /**
   * @brief Function to create HOG features
   * @param inputImage of type cv::Mat
   * @return HOG feature of type cv::Mat
   * The following function takes an input image and calculates HOG feature
   * which is an input of SVM model
   */
  cv::Mat createHOG(cv::Mat inputImage);

  /**
   * @brief Function to load images
   * @param imageName of type string
   * @return image of type cv::Mat
   * The following function takes an image name and reads it from disk
   */
  cv::Mat loadImage(std::string imageName);

  /**
   * @brief Function to read data from camera sensor
   * @param cameraCode of type int
   * @return image of type cv::Mat
   * The following function takes image from camera and returns image. Camera
   * code defines which camera sensor's data you want to read
   */
  cv::Mat Camera(int cameraCode);

  /**
   * @brief Function to load video from a video file
   * @param videoFileName of type string
   * @return frames of video of type std::vector<cv::Mat>
   * The following function parses all the frames from given video file
   */
  std::vector<cv::Mat> loadVideo(std::string videoFileName);

  /**
   * @brief Function to load all the images from a directory
   * @param directoryName of type string
   * @return images of type std::vector<cv::Mat>
   * The following function returns images from a specific directory
   */
  std::vector<cv::Mat> loadFromDirectory(std::string directoryName);

  /**
   * @brief destructor DataLoader
   * @param none
   * @return none
   */
  ~DataLoader();

 private:
  /**
   * @brief Container to store images
   */
  cv::Mat frame;

  /**
   * @brief Container to store sequence of video frames
   */
  std::vector<cv::Mat> sequenceOfFrames;

  /**
   * @brief Function to check if a specified directory exists or not
   * @param directoryName of type string
   * @return true if directory exists else return false
   * The following function returns bool value about the directory status
   */
  bool directoryExist(std::string directoryName);
};

#endif  // INCLUDE_DATALOADER_HPP_
