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
 * @file      VisionInput.cpp
 * @author    Naman Gupta (namangupta98) Driver
 * @author    Saumil Shah (SaumilShah66) Design Keeper
 * @author    Aman Virmani (AmanVirmani) Navigator
 * @copyright MIT License
 * @brief     VisionInput Class declaration
 * @detail    Implementation of class methods to train SVM using data from class
 * DataLoader
 */

#include <VisionInput.hpp>

VisionInput::VisionInput(){

}

void VisionInput::setupDetector(std::string SVMFilename){
	///Check if file already exist or not
	if(SVMFilename=="0"){
		humanDetector.setDefaultSVM();
	}
	else if(humanDetector.fileExist(SVMFilename)){
		humanDetector.setCustomSVM(SVMFilename);
	}
	else{
		std::cout << "File does not exist";
	}
}

void VisionInput::detectWithCamera(int cameraCode){
	image.release();
	///Setting up Camera object
	cv::VideoCapture cap(cameraCode); 
 	if(!cap.isOpened()){
 		std::cout << "No camera avilable to read";
 	}
 	else{
 	while(1)
	  {
	  	cap >> image;
	  	if (image.empty())
	  		break;
	  	///Finding humans
	    humanDetector.hog.detectMultiScale(image, boundingBoxes, 0, cv::Size(8,8), cv::Size(), 1.05, 2, false);
	  	///Display image with bounding around humans
	  	showImageWithBox();
	  	///Press ESC to exit
	  	char c=(char)cv::waitKey(25);
    	if(c==27){
      		break;
    	}
    	
  	   }
  	   cap.release();
  	   cv::destroyAllWindows();
  	   } 
}

void VisionInput::detectWithVideoFile(std::string filename){
	image.release();
	cv::VideoCapture cap(filename); 
 	if(!cap.isOpened()){
 		std::cout << "No video file avilable to read";
 	}
 	else{
 	while(true)
	  {
	  	cap >> image;
	  	if (image.empty())
	  		break;
	    humanDetector.hog.detectMultiScale(image, boundingBoxes, 0, cv::Size(8,8), cv::Size(), 1.05, 2, false);
	  	showImageWithBox();
	  	char c=(char)cv::waitKey(25);
    	if(c==27){
      		break;
    	}
    	
  	   }
  	   cap.release();
  	   cv::destroyAllWindows();
  	   } 
}

void VisionInput::detectWithImage(std::string filename){
	image.release();
	image = cv::imread(filename);
	if(!image.empty()){
		humanDetector.hog.detectMultiScale(image, boundingBoxes, 0, cv::Size(8,8), cv::Size(), 1.05, 2, false);
	  	showImageWithBox();
	}
	else{
		std::cout << "Image file does not exist";
	}
}

void VisionInput::showImageWithBox() {
	///Dimensions of bounding box
	for(auto& r : boundingBoxes) {
	    r.x += cvRound(r.width*0.1);
	    r.width = cvRound(r.width*0.8);
	    r.y += cvRound(r.height*0.07);
	    r.height = cvRound(r.height*0.8);
    }
    for(auto& r:boundingBoxes) {  
    	cv::rectangle(image, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
 	}
 	if(!boundingBoxes.empty()){
 		std::cout << "Humans detected";
 	}
 	cv::imshow("ACME Robotics", image);
}

VisionInput::~VisionInput(){

}