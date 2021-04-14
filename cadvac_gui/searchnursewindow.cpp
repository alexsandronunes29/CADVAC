#include "searchnursewindow.h"
#include "ui_searchnursewindow.h"

SearchNurseWindow::SearchNurseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchNurseWindow)
{
    ui->setupUi(this);

    //sys = new System();
}

SearchNurseWindow::~SearchNurseWindow()
{
    delete ui;
}

void SearchNurseWindow::on_searchNurseButton_clicked()
{
    nurseDetailsWindow.setVisible(true);
    nurseDetailsWindow.setSys(sys);

    Nurse* n = sys->nurse->getNurse("123");
    QString cpf = QString::fromUtf8(n->getCpf().c_str());
    QString name = QString::fromUtf8(n->getName().c_str());
    QString coren = QString::number(n->getCoren());
    QString dateEdit = QString::fromUtf8(n->getBirthDate().c_str());

    cout<<"N: "<<n->getCpf()<<endl;
    nurseDetailsWindow.getCpfLineEdit()->setText(cpf);
    nurseDetailsWindow.getNameLineEdit()->setText(name);
    nurseDetailsWindow.getCorenLineEdit()->setText(coren);
    nurseDetailsWindow.getBirthDateLineEdit()->setText(dateEdit);
}
