#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
class MyLabel: public QLabel
{
    Q_OBJECT
public:
    MyLabel(QString path, QWidget*);
    void setPosition(int x, int y, int width, int height);
    void setView(bool ok);
private:
    QString picturePath;

};

#endif // MYLABEL_H
