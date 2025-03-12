#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {


    // Bild laden (achte darauf, dass das Bild im richtigen Verzeichnis ist!)
    string imagePath = "C:/basic_OpenCV/REF/test.jpg";  // Ersetze mit deinem Bildpfad
    Mat image = imread(imagePath);

    // Überprüfen, ob das Bild geladen wurde
    if (image.empty()) {
        cout << "Fehler: Konnte das Bild nicht laden!" << endl;
        // Erstelle ein schwarzes Bild (Fenstergröße: 500x300)
        Mat image = Mat::zeros(300, 500, CV_8UC3);
    }

    // Text auf das Bild schreiben
    string text = "Hello, OpenCV!";
    int font = FONT_HERSHEY_SIMPLEX;
    double scale = 1.0;
    Scalar color(255, 255, 255); // Weiß
    int thickness = 2;
    int baseline = 0;

    // Position berechnen (damit der Text in der Mitte ist)
    Size textSize = getTextSize(text, font, scale, thickness, &baseline);
    Point textPos((image.cols - textSize.width) / 2, (image.rows + textSize.height) / 2);

    // Den Text zeichnen
    putText(image, text, textPos, font, scale, color, thickness);

    // Fenster anzeigen
    imshow("Hello OpenCV", image);
    waitKey(0); // Warten, bis eine Taste gedrückt wird
    return 0;
}
