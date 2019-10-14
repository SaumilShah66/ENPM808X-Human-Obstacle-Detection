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
 * @file      TrainSVM.hpp
 * @author    Naman Gupta (namangupta98) Driver
 * @author    Saumil Shah (SaumilShah66) Design Keeper
 * @author    Aman Virmani (AmanVirmani) Navigator
 * @copyright MIT License
 * @brief     TrainSVM Class declaration
 * @detail    Declared functions Class to train SVM using data from class 
 * DataLoader
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

/**
 * @brief class DetectHuman
 * The class DetectHuman uses a trained SVM model to detect humans in an image 
 * and returns the pixel coordinates of the bounding boxes containing humans in
 * an image
 */
class TrainSVM {
 public:
  /**
   * @brief constructor TrainSVM
   * @param classifierFilename of type string
   * @return none
   */
  explicit TrainSVM(std::vector<double> parameters);

  /**
   * @brief constructor TrainSVM
   * @param classifierFilename of type string
   * @return none
   */
  TrainSVM();

  /**
   * @brief Function takes SVM parameters from user
   * @param parameters of type std:vector<double>
   * @return none
   * The following function gives parameters to SVM classifier which
   * are needed to train SVM
   */
  void setParameters(std::vector<double> parameters);

  /**
   * @brief Function sets directory path of positive training images
   * @param directoryPath of type string
   * @return none
   */
  void setPositiveTrainingImagesDirectory(std::string directoryPath);

  /**
   * @brief Function sets directory path of negative training images
   * @param directoryPath of type string
   * @return none
   */
  void setNegativeTrainingImagesDirectory(std::string directoryPath);

  /**
   * @brief Function sets ground truth values for training data
   * @param filesWithOutputs of type string
   * @return none
   */
  void setGroundTruthValuesFilename(std::string filesWithOutputs);

  /**
   * @brief Function gets the directory name
   * @param none
   * @return directory name containing positive training images type string
   */
  std::string getPositiveTrainingImagesDirectory();

  /**
   * @brief Function gets the directory name
   * @param none
   * @return directory name containing negative training images type string
   */
  std::string getNegativeTrainingImagesDirectory();

  /**
   * @brief Function gets the filename
   * @param none
   * @return file name containing ground truth values for training data of
   * 		   type string
   */
  std::string getGroundTruthValuesFilename();

  /**
   * @brief Function gives parameters of SVM classifier
   * @param none
   * @return parameters of SVM of type std::vector<double>
   */
  std::vector<double> getParameters();

  /**
   * @brief destructor TrainSVM
   * @param none
   * @return none
   */
  ~TrainSVM();

 private:
  /**
   * @brief Container for SVM parameters of type std::vector<double>
   */
  std::vector<double> parameters;

  /**
   * @brief Container for positive image directory name of type string
   */
  std::string positiveTrainingImagesDirectory;

  /**
   * @brief Container for negative image directory name of type string
   */
  std::string negativeTrainingImagesDirectory;

  /**
   * @brief Container to store filename containing ground truth values of
   *        type string
   */
  std::string groundTruthValuesFilename;
};
