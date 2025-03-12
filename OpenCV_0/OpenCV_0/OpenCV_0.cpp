#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void Hello_OpenCV();
void Video();

int main() {
    
    Hello_OpenCV();
    Video();
    
    return 0;
}

void Hello_OpenCV() {
    // Stelle sicher, dass der Bildpfad korrekt ist!
    string imagePath = "C:/basic_OpenCV/REF/test.jpg"; // Verwende \\ oder /
    Mat image = imread(imagePath);

    // Falls das Bild nicht geladen werden konnte, erstellen wir einen schwarzen Hintergrund
    if (image.empty()) {
        cout << "Fehler: Bild konnte nicht geladen werden!" << endl;
        image = Mat::zeros(300, 500, CV_8UC3); // Schwarzes Bild 300x500
    }

    // Text für die Anzeige
    string text = "Hello, OpenCV!";
    int font = FONT_HERSHEY_SIMPLEX;
    double scale = 1.0;
    Scalar color(255, 255, 255); // Weiße Farbe
    int thickness = 2;
    int baseline = 0;

    // Berechnung der Position, um den Text mittig zu platzieren
    Size textSize = getTextSize(text, font, scale, thickness, &baseline);
    Point textPos((image.cols - textSize.width) / 2, (image.rows + textSize.height) / 2);

    // Text auf das Bild setzen
    putText(image, text, textPos, font, scale, color, thickness);

    // Bild anzeigen
    imshow("Hello OpenCV", image);
    waitKey(0); // Warten, bis eine Taste gedrückt wird
}

void Video() {
    // Kamera öffnen (0 = erste Kamera)
    VideoCapture cap(0);

    // Überprüfen, ob die Kamera geöffnet wurde
    if (!cap.isOpened()) {
        cout << "Fehler: Kamera konnte nicht geöffnet werden!" << endl;
        return; // Funktion verlassen
    }

    // Fenster einmalig erstellen
    namedWindow("Webcam", WINDOW_NORMAL);

    // Schleife zur Anzeige des Videostreams
    while (true) {
        Mat frame;
        cap >> frame; // Ein Frame von der Kamera lesen

        // Überprüfen, ob ein Frame erhalten wurde
        if (frame.empty()) {
            cout << "Fehler: Leerer Frame!" << endl;
            break;
        }

        // Video anzeigen
        imshow("Webcam", frame);

        int key = waitKey(1);
        // Falls 'q' gedrückt wird, beenden
        if (key == 27 || key == 'q') { // 27 = ESC, 'q' = 113
            break;
        }
    }

    // Ressourcen freigeben
    cap.release();
    destroyAllWindows();
}
