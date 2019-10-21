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
 * @file      VisionInputTest.cpp
 * @author    Saumil Shah (SaumilShah66) Driver
 * @author    Naman Gupta (namangupta98) Navigator
 * @author    Aman Virmani (AmanVirmani) Design Keeper
 * @copyright MIT License
 * @brief     Test cases for VisionInput class methods
 */

#include <gtest/gtest.h>
#include <TrainSVM.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <VisionInput.hpp>

/** 
 * @brief Test for camera sensor read when no camera is present
 * It checks whether image container of class object is empty or not in order
 * to make sure it is not reading any data as no camera is present
 */
TEST(CameraCheck, NoPresentCameraCheck) {
  VisionInput vision;
  vision.setupDetector("0");
  vision.detectWithCamera(2);
  ASSERT_EQ(vision.image.empty(), 1);
}

/** 
 * @brief Test for checking video file read
 * It checks whether VisionInput class is able to parse frames from specified video
 * file
 */
TEST(VideoFileCheck, ShouldReadFrames) {
  VisionInput vision;
  vision.setupDetector("0");
  vision.detectWithVideoFile("../test_data/vid.mp4");
  ASSERT_EQ(vision.image.empty(), 1);
}

/** 
 * @brief Test for checking empty video file read
 * Program should not crash if non existing files are passed to read
 */
TEST(VideoFileCheck, NoVideoFile) {
  VisionInput vision;
  vision.setupDetector("0");
  vision.detectWithVideoFile("../test_data/v.mp4");
  ASSERT_EQ(vision.image.empty(), 1);
}

/** 
 * @brief Test for reading image from file
 * Checksif object is able to read imagefile succesfully
 */
TEST(ImageFileCheck, ImageReadSuccessfully) {
  VisionInput vision;
  vision.setupDetector("0");
  vision.detectWithImage("../test_data/1.png");
  ASSERT_EQ(vision.image.empty(), 0);
}

/** 
 * @brief Test for reading image from non existing file 
 * Programe should not crash if file is not available
 */
TEST(ImageFileCheck, NonExistingFile) {
  VisionInput vision;
  vision.setupDetector("0");
  vision.detectWithImage("../test_data/sss.png");
  ASSERT_EQ(vision.image.empty(), 1);
}
