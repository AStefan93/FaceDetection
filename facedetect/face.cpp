#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

string cascade = "haarcascade_frontalface_default.xml"; //path to trained .xml for objet detection


int main(int argc, char** argv)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

	vector<Rect> faces; //vector to store detected faces
	CascadeClassifier haar_cascade;
	haar_cascade.load(cascade);//load the xml file for detectMultiScale
	namedWindow("Face",WINDOW_NORMAL);

	for(;;)
	{
		Mat frame;
		Mat image;
		Mat gray;
		cap >> frame; // get a new frame from camera

		bilateralFilter(frame,image,5,80,80); //filter frame using bilateral filter and store it in image
		cvtColor(image,gray,CV_RGB2GRAY);//change image color to gray

		equalizeHist(gray,gray);//increase contrast for easier face detection
	haar_cascade.detectMultiScale(gray, faces, 1.1, 5, 0|CASCADE_SCALE_IMAGE, Size(30,30) ); //the face detection algorithm

		for(int i=0; i<faces.size(); i++) //loop for all the detected faces
		{
			rectangle(image, faces[i], CV_RGB(0, 255,0), 1); //draw rectangle for face[i]
		}

		imshow("Face", image);//show the frame with the rectangle drawn on the face
		if(waitKey(30) >= 0) break; //30 ms delay for imshow
	}

    return 0;
}
