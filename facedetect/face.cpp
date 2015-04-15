//#include "opencv2/core/core.hpp"
//#include "opencv2/contrib/contrib.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/objdetect/objdetect.hpp"
//#include "opencv2/core/utility.hpp"

//#include <cctype>
//#include <iostream>
//#include <fstream>
//#include <sstream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

string cascade = "haarcascade_frontalface_default.xml";


int main(int argc, char** argv)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

	vector<Rect> faces;
	CascadeClassifier haar_cascade;
	int test;
	test = haar_cascade.load(cascade);

	cout << test;
    namedWindow("Face",WINDOW_NORMAL);
	for(;;)
	{
		Mat frame;
		Mat gray;
		cap >> frame; // get a new frame from camera
		cvtColor(frame,gray,CV_RGB2GRAY);

	haar_cascade.detectMultiScale(gray, faces, 1.1, 5, 0|CASCADE_SCALE_IMAGE, Size(30,30) );

		for(int i=0; i<faces.size(); i++)
		{
			rectangle(frame, faces[i], CV_RGB(0, 255,0), 1);
		}

		imshow("Face", frame);
		if(waitKey(30) >= 0) break;
	}

    return 0;
}
