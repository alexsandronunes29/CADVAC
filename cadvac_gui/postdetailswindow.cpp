#include "postdetailswindow.h"
#include "ui_postdetailswindow.h"


System *PostDetailsWindow::getSys() const
{
    return sys;
}

void PostDetailsWindow::setSys(System *value)
{
    sys = value;
}

PostDetailsWindow::PostDetailsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PostDetailsWindow)
{
    ui->setupUi(this);
    sys = new System();
}

PostDetailsWindow::~PostDetailsWindow()
{
    delete ui;
}

QLineEdit *PostDetailsWindow::getAddressLineEdit()
{
    return ui->addressLineEdit;
}

QLineEdit *PostDetailsWindow::getPostNameLineEdit()
{
    return ui->nameLineEdit;
}

QLineEdit *PostDetailsWindow::getVaccinesLineEdit()
{
    return ui->vaccinesLineEdit;
}

void PostDetailsWindow::on_updatePostButton_clicked()
{

}

void PostDetailsWindow::on_removePostButton_clicked()
{

}

void PostDetailsWindow::on_updateNumberVaccinesButton_clicked()
{
    updateVaccines.setVisible(true);
    updateVaccines.setSys(sys);

    updateVaccines.postName = ui->nameLineEdit->text().toStdString();
    clearForm();
    this->close();

}

void PostDetailsWindow::clearForm()
{
    ui->addressLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->vaccinesLineEdit->clear();
}
