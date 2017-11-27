#ifndef ERRORES_FORMS_H
#define ERRORES_FORMS_H

#include <QDialog>
#include "ASMCompilador\Error.h"
namespace Ui {
class errores_forms;
}

class errores_forms : public QDialog
{
    Q_OBJECT

public:
    explicit errores_forms(QWidget *parent = 0);
    ~errores_forms();
	void mostarErroes(std::list<Error*> errores);
private:
    Ui::errores_forms *ui;
};

#endif // ERRORES_FORMS_H
