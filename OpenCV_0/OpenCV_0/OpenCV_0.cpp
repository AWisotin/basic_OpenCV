#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {
    // Erstelle ein schwarzes Bild (Fenstergröße: 500x300)
    cv::Mat image = cv::Mat::zeros(300, 500, CV_8UC3);

    // Text auf das Bild schreiben
    std::string text = "Hello, OpenCV!";
    int font = cv::FONT_HERSHEY_SIMPLEX;
    double scale = 1.0;
    cv::Scalar color(255, 255, 255); // Weiß
    int thickness = 2;
    int baseline = 0;

    // Position berechnen (damit der Text in der Mitte ist)
    cv::Size textSize = cv::getTextSize(text, font, scale, thickness, &baseline);
    cv::Point textPos((image.cols - textSize.width) / 2, (image.rows + textSize.height) / 2);

    // Den Text zeichnen
    cv::putText(image, text, textPos, font, scale, color, thickness);

    // Fenster anzeigen
    cv::imshow("Hello OpenCV", image);
    cv::waitKey(0); // Warten, bis eine Taste gedrückt wird
    return 0;
}
