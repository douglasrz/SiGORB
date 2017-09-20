#ifndef AJUDADLG_H
#define AJUDADLG_H

#include <QDialog>

namespace Ui {
class ajudaDlg;
}

class ajudaDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ajudaDlg(QWidget *parent = 0);
    ~ajudaDlg();

private:
    Ui::ajudaDlg *ui;
};

#endif // AJUDADLG_H
