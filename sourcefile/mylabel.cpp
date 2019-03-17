#include "mylabel.h"

MyLabel::MyLabel(QString path, QWidget *w)
{
    this->setParent(w);
    picturePath = path;
    auto pix = QPixmap(picturePath);
    this->setPixmap(pix);
}

void MyLabel::setPosition(int x, int y, int width, int height){
    this->setGeometry(y, x, width, height);
}

void MyLabel::setView(bool ok){
    this->setVisible(ok);
}
