#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QFileDialog>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QPrintDialog>
#include <QPrinter>
#include <QLineEdit>
#include <QString>
#include <QCloseEvent>
#include "ASMCompilador/Compilador.h"
#include "ASMCompilador\LabelManager.h"
#include <iostream>
#include <cstdlib>
#include "errores_forms.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered(){
    filePath = "";
    ui->textEdit->setText("");

}

void MainWindow::on_actionOpen_triggered(){
    QString filter = "All File (*.*) ;; Text File (*.txt)";
    QString fileName = QFileDialog::getOpenFileName(this,"Seleccionar Archivo",QDir::homePath(),filter);
    filePath = fileName;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        //QMessageBox::warning(this,"Cuidado","Archivo no se pudo abrir");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}

void MainWindow::on_actionSave_triggered(){
    if (!filePath.isEmpty()){
        QFile file(filePath);
        if (!file.open(QFile::WriteOnly | QFile::Text)){
            //QMessageBox::warning(this,"Cuidado","Archivo no se pudo abrir");
            return;
        }
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.flush();
        file.close();
    }else{
        on_actionSave_As_triggered();

    }
}

void MainWindow::on_actionSave_As_triggered(){
    QString filter = "All File (*.*) ;; Text File (*.txt)";
    QString fileName = QFileDialog::getSaveFileName(this,"Seleccionar Archivo",QDir::homePath(),filter);
    filePath = fileName;
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        //QMessageBox::warning(this,"Cuidado","Archivo no se pudo abrir");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();

}

void MainWindow::on_actionCut_triggered(){
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered(){
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered(){
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered(){
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered(){

    ui->textEdit->undo();

}

void MainWindow::on_actionAbout_Notepad_triggered(){
    QMessageBox::information(this,"Acerda De","Compilador del Grupo 3 y 4");

}

void MainWindow::on_actionFont_triggered(){
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if (ok){
        ui->textEdit->setFontPointSize(font.pointSizeF());
        ui->textEdit->setFontFamily(font.family());
    }else{
        return;
    }

}

void MainWindow::on_actionColor_triggered(){
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if (color.isValid()){
        ui->textEdit->setTextColor(color);
    }else{
        return;
    }
}

void MainWindow::on_actionBackGround_Color_triggered(){
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if (color.isValid()){
        ui->textEdit->setTextBackgroundColor(color);
    }else{
        return;
    }
}

void MainWindow::on_actionBackGroundColor_Page_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if (color.isValid()){
        ui->textEdit->setPalette(color);
    }else{
        return;
    }
}

void MainWindow::on_actionPrint_triggered(){
    QPrinter *printer;
    //printer.setPrinterName("");
    QPrintDialog dialog(this);
    if(dialog.exec() == QDialog::Rejected) return;
    //ui->textEdit->print(&printer);
    printer = dialog.printer();
    ui->textEdit->print(printer);

}

void MainWindow::on_actionCompilador_triggered()
{
    if (filePath.isEmpty()){
        on_actionSave_As_triggered();
    }
    else{
        on_actionSave_triggered();
    }
    if (!filePath.isEmpty()){
        Compilador *c=new Compilador();
        c->setURLToFile(filePath.toStdString());
        bool ad=c->compilar();
        if (ad){
			ui->statusBar->showMessage("Compilación Exitosa");
        }
        else{
			ui->statusBar->showMessage("Compilación Fallida");
			errores_forms ef;
			std::list<Error*> le = c->getErrorFlags();
			ef.mostarErroes(le);
			int i = 0;
			ef.setModal(true);
			ef.exec();
			le.clear();
        }
    }
	LabelManager* l = LabelManager::getInstance();
	l->borrarTodaEtiqueta();
	l = nullptr;
	
}

