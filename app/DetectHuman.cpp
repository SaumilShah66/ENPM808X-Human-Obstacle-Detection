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
 * @author    Naman Gupta (namangupta98) Driver
 * @author    Saumil Shah (SaumilShah66) Design Keeper
 * @author    Aman Virmani (AmanVirmani) Navigator
 * @copyright MIT License
 * @brief     DetectHuman Class declaration
 * @detail    Declared functions Class to detect humans using an SVM model 
 *            trained on HOG features
 */
#include <DetectHuman.hpp>

DetectHuman::DetectHuman() {

}

DetectHuman::DetectHuman(std::string classifierFilename) {

}

bool DetectHuman::loadModel(std::string fileNameOfTrainedClassifier) {

}

std::vector<std::vector<int>> DetectHuman::findHumans(cv::Mat frame) {

}

void DetectHuman::setClassifierFilename(std::string filenameOfClassifier) {

}

std::string DetectHuman::getClassifierFilename() {

}

bool DetectHuman::fileExist(std::string fileName) {
	
}

DetectHuman::~DetectHuman() {

}
