#ifndef HOVERWATCH_H
#define HOVERWATCH_H

#include <QLabel>

class HoverWatch : public QLabel
{
    Q_OBJECT

    QString hoverName;

public:
    explicit HoverWatch(QWidget *parent = 0);
    void enterEvent(QEvent *event);

    QString getHoverName() {
        return hoverName;
    }
    void setHoverName(QString rplac) {
        hoverName = rplac;
    }
    Q_PROPERTY(QString hoverName READ getHoverName WRITE setHoverName);

signals:
    void hoverActivated(QString control);

public slots:
    void showHover(bool yesp);

};

#endif // HOVERWATCH_H
