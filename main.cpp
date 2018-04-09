#include<iostream>
#include<opencv2/opencv.hpp>
#include"sort.h"
#include<fstream>
#include<string>
#include<cstdlib>
using namespace cv;

int main(void) {
	Mat img = imread("sample4-1.jpg");
	if (img.empty()) {
		std::cout << "not found" << std::endl;
		return -1;
	}

	int k;
	std::cout << "”z—ñ‚Ì”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
	std::cin >> k;

	Mat dst = Mat::zeros(img.rows, img.cols, CV_8UC3);

	std::ofstream fs;
	fs.open("median.txt");
	std::ofstream ft;
	ft.open("median2.txt");

	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			int tmp = 0, b[10000] = { 0 }, g[10000] = { 0 }, r[10000] = { 0 }, medb = 0, medg = 0, medr = 0;
			for (int i = (k - 1) / 2; i < ((k - 1) / 2) + k; i++) {
				for (int j = (k - 1) / 2; j < ((k - 1) / 2) + k; j++) {
					int s = y - i;
					int t = x - j;
					if (s < 0) {
						s = 0;
					}
					if (s >= img.rows) {
						s = img.rows - 1;
					}
					if (t < 0) {
						t = 0;
					}
					if (t >= img.cols) {
						t = img.cols - 1;
					}
					Vec3b tmp = img.at<Vec3b>(s, t);
					b[j - 1 + k * (i - 1)] = tmp[0];
					g[j - 1 + k * (i - 1)] = tmp[1];
					r[j - 1 + k * (i - 1)] = tmp[2];
				}
			}
			medb = sort(b, (k*k));
			medg = sort(g, (k*k));
			medr = sort(r, (k*k));
			dst.at<Vec3b>(y, x) = Vec3b(medb, medg, medr);
		}
	}

	imshow("View", img);
	imshow("Filter", dst);
	imwrite("Median_Filter.jpg", dst);
	waitKey();

	system("pause");
	return 0;
}