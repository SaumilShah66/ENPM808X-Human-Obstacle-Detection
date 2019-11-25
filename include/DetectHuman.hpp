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
 * @file      DetectHuman.hpp
 * @author    Saumil Shah (SaumilShah66) Driver
 * @author    Naman Gupta (namangupta98) Navigator
 * @author    Aman Virmani (AmanVirmani) Design Keeper
 * @copyright MIT License
 * @brief     DetectHuman Class declaration
 * @detail    Declared functions Class to detect humans using an SVM model 
 *            trained on HOG features
 */

#ifndef INCLUDE_DETECTHUMAN_HPP_
#define INCLUDE_DETECTHUMAN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include <sys/stat.h>

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
   * @brief Container to store SVM classifier model
   */
  cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
  /**
   * @brief Instance of HOGDescriptor for feature extraction and
   * detection 
   */
  cv::HOGDescriptor hog;
  /**
   * @brief Method sets the SVM model provided by OpenCV for Human detcection
   * @param none
   * @return none
   */
  virtual void setDefaultSVM();
  /**
   * @brief Method sets the SVM model trained by TrainSVM class
   * @param customSVMFile of type string
   * @return none
   * Path of custom trained SVM model should be provided to the method
   * in order to use custom SVM with HOGDescriptor
   */
  virtual void setCustomSVM(std::string customSVMFile);
  /**
   * @brief Function checks either the file already exists or not
   * @param fileName of type string
   * @return true if the file already exists and false if does not exist
   */
  virtual bool fileExist(const std::string& filename);
  /**
   * @brief destructor DetectHuman
   * @param none
   * @return none
   */
  virtual ~DetectHuman();
};

#endif  // INCLUDE_DETECTHUMAN_HPP_
