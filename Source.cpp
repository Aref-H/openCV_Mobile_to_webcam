// Our libraries
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {


	string webcamUrl = "http://192.168.1.8:8080/video";

	VideoCapture cap(webcamUrl, CAP_FFMPEG);
	if (!cap.isOpened()) {
		system("cls");
		cerr << "ERROR: Could not open!" << endl;
		return -1;
	}

	Mat frame;

	while (true) {
		cap >> frame;
		if (frame.empty()) {
			system("cls");
			cerr << "ERROR: Could not read!" << endl;
			break;
		}

		imshow("mobWebcam", frame);
		if (waitKey(5) == 'l') {  // Push l to logout
			system("cls");
			cout << "Goodbye" << endl;
			break;
		}
	}
	return 0;
}