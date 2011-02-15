#ifndef HOVERWATCH_H
#define HOVERWATCH_H

#include <QLabel>
#include <vector>

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
    void reactToHover(QString control);

};

//connects slots in hoverActivateds to reactToHovers - all of them.
void setupCoReaction(std::vector<HoverWatch*> &vec);

#endif // HOVERWATCH_H
