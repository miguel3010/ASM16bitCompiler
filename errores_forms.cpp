#include "errores_forms.h"
#include "ui_errores_forms.h"

errores_forms::errores_forms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errores_forms)
{
    ui->setupUi(this);
}

errores_forms::~errores_forms()
{
    delete ui;
}

void errores_forms::mostarErroes(std::list<Error*> errores){
	for (Error* e : errores){
		ui->listWidget->addItem( QString::fromStdString(e->ToString()));
	}

}