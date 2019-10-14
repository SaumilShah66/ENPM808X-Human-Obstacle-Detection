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
 * @file      DetectHuman.h
 * @author    Naman Gupta (namangupta98)
 * @author    Saumil Shah (SaumilShah66)
 * @author    Aman Virmani (AmanVirmani)
 * @copyright MIT License
 * @brief     DetectHuman Class declaration
 * @detail    Declared functions Class to detect humans using an SVM model 
 * trained on HOG features
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>

/**
 * @brief class DetectHuman
 * The class DetectHuman uses a trained SVM model to detect humans in an image 
 * and returns the pixel coordinates of the bounding boxes containing humans in
 * an image
 */
class DetectHuman {
 public:
  /**
   * @brief constructor DetectHuman
   * @param none
   * @return none
   */
  DetectHuman();

  /**
   * @brief constructor DetectHuman
   * @param classifierFilename of type string
   * @return none
   */
  DetectHuman(std::string classifierFilename);

  /**
   * @brief Function to load weights of SVM model
   * @param fileNameOfTrainedClassifier of type string
   * @return true if done successfully and false if not
   * The following function loads the value of weights of trained classifier
   * and saves them into classifierModel container
   */
  bool loadModel(std::string fileNameOfTrainedClassifier);

  /**
   * @brief Function to detect humans in an image or a frame of video
   * @param frame of type cv::Mat
   * @return bounding box values of type std::vector<std::vector<int>>
   * The following function takes input image and feeds it to SVM classifier
   * which provides us the bounding box values of humans detected in image
   */
  std::vector<std::vector<int>> findHumans(cv::Mat frame);

  /**
   * @brief Function gets the filename of classifier from user
   * @param filenameOfClassifier of type string
   * @return none
   * The following function sets the name of the classifier file
   */
  void setClassifierFilename(std::string filenameOfClassifier);

  /**
   * @brief Function returns the classifier filename
   * @param none
   * @return classifierFilename of type string
   */
  std::string getClassifierFilename();

  /**
   * @brief destructor DetectHuman
   * @param none
   * @return none
   */
  ~DetectHuman();

  /**
   * @brief Container to store SVM classifier model
   */
  cv::Ptr<cv::ml::SVM> classifierModel;

 private:
  /**
   * @brief Function checks either the file already exists or not
   * @param fileName of type string
   * @return true if the file already exists and false if does not exist
   */
  bool fileExist(std::string fileName);

  /**
   * @brief Container to classifierFilename of type string
   */
  std::string classifierFilename;
};
