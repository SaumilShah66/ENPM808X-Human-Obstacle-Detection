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
 * @file      DataLoaderTest.cpp
 * @author    Saumil Shah (SaumilShah66) Driver
 * @author    Naman Gupta (namangupta98) Navigator
 * @author    Aman Virmani (AmanVirmani) Design Keeper
 * @copyright MIT License
 * @brief     Test cases for DataLoader class methods
 */

#include <gtest/gtest.h>
#include <DataLoader.hpp>

/** 
 * @brief Test for training data collection
 * It checks whether DataLoader class is able to read images from given directory
 */
TEST(DataCheck, CheckImagesRead) {
  DataLoader datatest;

  datatest.pos_dir = "../test_data/np";
  datatest.neg_dir = "../test_data/nn";

  datatest.get_training_data();

  ASSERT_EQ(datatest.descriptors.size(), 42);
}

/** 
 * @brief Test for training labels creations
 * It checks whether DataLoader class is able to generate labels for positive
 * and negative images
 */
TEST(DataCheck, CheckLabelsCreated) {
  DataLoader datatest;
  datatest.pos_dir = "../test_data/np";
  datatest.neg_dir = "../test_data/nn";
  datatest.get_training_data();
  ASSERT_EQ(datatest.labels.size(), 42);
}

/** 
 * @brief Test for training labels values
 * It checks whether DataLoader class is able to generate right labels for positive
 * and negative images
 */
TEST(DataCheck, CheckLabelValues) {
  DataLoader datatest;
  datatest.pos_dir = "../test_data/np";
  datatest.neg_dir = "../test_data/nn";
  datatest.get_training_data();
  int sum = 0;
  for (auto& j : datatest.labels) {
    sum = sum+j;
  }
  ASSERT_EQ(sum, 40);
}

/** 
 * @brief Test for non existing directory
 * It checks the behaviour of DataLoader class with non existing directory
 */
TEST(DataCheck, CheckEmpty) {
  DataLoader datatest;
  datatest.pos_dir = "../test_da";
  datatest.neg_dir = "../test_da";
  datatest.get_training_data();
  ASSERT_EQ(datatest.descriptors.size(), 0);
}
