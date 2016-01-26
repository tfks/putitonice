#ifndef SETINGSDIALOG_H
#define SETINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SetingsDialog;
}

class SetingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetingsDialog(QWidget *parent = 0);
    ~SetingsDialog();

private:
    Ui::SetingsDialog *ui;
};

#endif // SETINGSDIALOG_H
