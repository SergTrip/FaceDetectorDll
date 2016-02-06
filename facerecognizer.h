#ifndef FACERECOGNIZER_H
#define FACERECOGNIZER_H

#include <QWidget>
#include <QImage>
#include <QTimer>
#include <QPainter>
#include <QDebug>

#include <opencv2/opencv.hpp>

//#define FACE_CASCADE_NAME   "D:\\Dropbox\\Germanij\\Projects\\Faces\\Data\\haarcascades\\haarcascade_frontalface_alt.xml"
#define FACE_CASCADE_NAME   "/home/sergey/Libs/opencv/data/haarcascades/haarcascade_frontalface_alt.xml"

//#define FACE_CASCADE_NAME   "../../Data/lbpcascades/lbpcascade_frontalface.xml"

//#define EYE_CASCADE_NAME    "../../Data/haarcascades/haarcascade_eye_tree_eyeglasses.xml"

//#define FILE_NAME           "../../Data/MyFace.3gp"
//#define PHOTO_NAME          "../../Data/Face.jpg"

namespace Ui {
class FaceRecognizer;
}

//  using namespace cv;
using namespace std;

class FaceRecognizer : public QWidget
{
    Q_OBJECT

public:
    explicit FaceRecognizer(QWidget *parent = 0);
    ~FaceRecognizer();

private:
    // Непосредственно опеределяет расположение лица
    void detectAndDraw();

private:
    // Экземпляр изображения Qt
    QImage                  m_oQtImage;
    // Хранилище с динамически изменяемым размером
    cv::Mat                 m_oCVMat;
    // Объект для работы с камерой
    cv::VideoCapture        m_oCVCapture;

    // Классификаторы для обнраужения объекта
    cv::CascadeClassifier   m_pCVFaceCascade;
    cv::CascadeClassifier   m_pCVEyeCascade;

    // Реализация унаследованного класса перерисовки
    void paintEvent(QPaintEvent* event);

    // Экземпляр таймера
    QTimer* m_pQtTimer;
    // Время таймера
    int m_nTime;

public slots:
    // Обработать следующий кадр
    void queryFrame();

    // Запустить таймер
    void startTimer();
    // Остановить таймер
    void stopTimer();
    // Установить время
    void setTime( int time );

public:
    // Получить текущее изображение
    QImage getImage();

};

#endif // FACERECOGNIZER_H
