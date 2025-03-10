#include <opencv2/opencv.hpp>

int main() {
    // Создаем изображение черного фона (черный экран)
    cv::Mat image = cv::Mat::zeros(300, 600, CV_8UC3);

    // Выводим текст "Hello, OpenCV!" на изображении
    cv::putText(image, "Hello, OpenCV!", cv::Point(100, 150), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);

    // Отображаем изображение в окне
    cv::imshow("Hello OpenCV", image);

    // Ожидаем нажатия клавиши для закрытия окна
    cv::waitKey(0);

    return 0;
}