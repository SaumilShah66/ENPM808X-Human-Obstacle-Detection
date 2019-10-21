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
 * @file      main.cpp
 * @author    Naman Gupta (namangupta98) Driver
 * @author    Saumil Shah (SaumilShah66) Design Keeper
 * @author    Aman Virmani (AmanVirmani) Navigator
 * @copyright MIT License
 * @brief     main implementation for human obstacle detection
 */

#include <iostream>
#include <DataLoader.hpp>
#include <TrainSVM.hpp>
#include <VisionInput.hpp>

int main() {
  std::cout << "Do you want train a SVM model (y/n) :";
  std::string response, media;
  std::getline(std::cin, response);
  std::string pd, nd, svmFilename;
  if (response == "y") {
    TrainSVM trainer;
    std::cout
        << "Please provide path to directory consisting positive images :";
    std::getline(std::cin, pd);
    std::cout
        << "Please provide path to directory consisting negative images :";
    std::getline(std::cin, nd);
    std::cout << "Where do you want to save it(provide .xml filename) :";
    std::getline(std::cin, svmFilename);
    trainer.setPosDirectory(pd);
    trainer.setNegDirectory(nd);
    trainer.startTraining();
    trainer.saveSVM(svmFilename);
  } else {
    std::cout << "Do you want to use default classifier ?(y/n)";
    std::getline(std::cin, response);
    int camCode = 0;
    if (response == "y") {
      std::cout << "Camera/Videofile/Image ? ";
      std::getline(std::cin, media);
      VisionInput vision;
      vision.setupDetector("0");
      if (media == "Camera") {
        std::cout << "Enter camera code (0 for webcam): ";
        std::cin >> camCode;
        vision.detectWithCamera(camCode);
      }
      if (media == "Videofile") {
        std::cout << "Enter filename ";
        std::getline(std::cin, response);
        vision.detectWithVideoFile(response);
      }
      if (media == "Image") {
        std::cout << "Enter filename ";
        std::getline(std::cin, response);
        vision.detectWithImage(response);
      }
    } else {
      std::cout << "Do you want to use custom classifier ?(y/n)";
      std::getline(std::cin, response);
      if (response == "y") {
        std::cout << "Specify path of SVM file : ";
        std::getline(std::cin, media);
        std::cout << "Camera/Videofile/Image ? ";
        std::getline(std::cin, response);
        VisionInput vision;
        vision.setupDetector(response);
        if (media == "Camera") {
          std::cout << "Enter camera code (0 for webcam): ";
          std::cin >> camCode;
          vision.detectWithCamera(camCode);
        }
        if (media == "Videofile") {
          std::cout << "Enter filename ";
          std::getline(std::cin, response);
          vision.detectWithVideoFile(response);
        }
        if (media == "Image") {
          std::cout << "Enter filename ";
          std::getline(std::cin, response);
          vision.detectWithImage(response);
        }
      }
    }
  }
  return 0;
}
