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
 * @file      DetectHumanTest.cpp
 * @author    Saumil Shah (SaumilShah66) Driver
 * @author    Naman Gupta (namangupta98) Navigator
 * @author    Aman Virmani (AmanVirmani) Design Keeper
 * @copyright MIT License
 * @brief     Test cases for VisionInput class methods
 */

#include <gtest/gtest.h>
#include <stdio.h>
#include <TrainSVM.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <DetectHuman.hpp>

/** 
 * @brief Test for DetectHuman class checks if fileExist methods works 
 */
TEST(DetectionCheck, FileDoesnotExist) {
  DetectHuman testDetector;
  ASSERT_EQ(testDetector.fileExist("randomfile.text"), 0);
}

/** 
 * @brief Test for DetectHuman class checks if fileExist methods works
 */
TEST(DetectionCheck, FileExist) {
  DetectHuman testDetector;
  ASSERT_EQ(testDetector.fileExist("../test_data/1.png"), 1);
}

/** 
 * @brief Test for DetectHuman class checks if it sets default SVM
 */
TEST(DetectionCheck, ReadingDefaultSVM) {
  DetectHuman testDetector;
  testDetector.setDefaultSVM();
  ASSERT_NE(testDetector.hog.svmDetector.size(), 1);
}

/** 
 * @brief Test for DetectHuman class checks if it does not set SVM when passed file doesnot exist
 */
TEST(DetectionCheck, ReadingFromNonExistingFile) {
  DetectHuman testDetector;
  testDetector.setCustomSVM("pp");
  ASSERT_EQ(testDetector.hog.svmDetector.size(), 0);
}
