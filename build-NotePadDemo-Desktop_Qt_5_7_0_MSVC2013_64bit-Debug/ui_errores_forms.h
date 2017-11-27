/********************************************************************************
** Form generated from reading UI file 'errores_forms.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORES_FORMS_H
#define UI_ERRORES_FORMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_errores_forms
{
public:

    void setupUi(QDialog *errores_forms)
    {
        if (errores_forms->objectName().isEmpty())
            errores_forms->setObjectName(QStringLiteral("errores_forms"));
        errores_forms->resize(400, 300);

        retranslateUi(errores_forms);

        QMetaObject::connectSlotsByName(errores_forms);
    } // setupUi

    void retranslateUi(QDialog *errores_forms)
    {
        errores_forms->setWindowTitle(QApplication::translate("errores_forms", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class errores_forms: public Ui_errores_forms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORES_FORMS_H
