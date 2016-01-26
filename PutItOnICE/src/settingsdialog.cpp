#include "headers/settingsdialog.h"
#include "ui_settingsdialog.h"

SetingsDialog::SetingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetingsDialog)
{
    ui->setupUi(this);
}

SetingsDialog::~SetingsDialog()
{
    delete ui;
}
