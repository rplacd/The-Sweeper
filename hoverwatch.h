#ifndef HOVERWATCH_H
#define HOVERWATCH_H

#include <QLabel>

class HoverWatch : public QLabel
{
    Q_OBJECT

    QString hoverName;
    QString getHoverName() {
        return hoverName;
    }


    void setHoverName(QString rplac) {
        hoverName = rplac;
    }

    Q_PROPERTY(QString hoverName READ getHoverName WRITE setHoverName);
public:
    explicit HoverWatch(QWidget *parent = 0);
    void enterEvent(QEvent *event);

signals:
    void hoverActivated(QString control);

public slots:

};

#endif // HOVERWATCH_H
