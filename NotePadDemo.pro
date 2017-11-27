#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T01:27:53
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NotePadDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ASMCompilador/ADD.cpp \
    ASMCompilador/AND.cpp \
    ASMCompilador/BRA.cpp \
    ASMCompilador/CMP.cpp \
    ASMCompilador/Compilable.cpp \
    ASMCompilador/Compilador.cpp \
    ASMCompilador/Error.cpp \
    ASMCompilador/Etiqueta.cpp \
    ASMCompilador/EtiquetaP.cpp \
    ASMCompilador/Instruccion.cpp \
    ASMCompilador/InstruccionFactory.cpp \
    ASMCompilador/JMP.cpp \
    ASMCompilador/JR.cpp \
    ASMCompilador/LabelManager.cpp \
    ASMCompilador/LB.cpp \
    ASMCompilador/LI.cpp \
    ASMCompilador/LUI.cpp \
    ASMCompilador/MOV.cpp \
    ASMCompilador/Numero.cpp \
    ASMCompilador/OR.cpp \
    ASMCompilador/ParameterFactory.cpp \
    ASMCompilador/Parametro.cpp \
    ASMCompilador/Registro.cpp \
    ASMCompilador/SB.cpp \
    ASMCompilador/SL.cpp \
    ASMCompilador/SLT.cpp \
    ASMCompilador/SPC.cpp \
    ASMCompilador/SUB.cpp \
    ASMCompilador/Util.cpp \
    ASMCompilador/XOR.cpp \
    errores_forms.cpp

HEADERS  += mainwindow.h \
    ASMCompilador/ADD.h \
    ASMCompilador/AND.h \
    ASMCompilador/BRA.h \
    ASMCompilador/CMP.h \
    ASMCompilador/Compilable.h \
    ASMCompilador/Compilador.h \
    ASMCompilador/Error.h \
    ASMCompilador/Etiqueta.h \
    ASMCompilador/EtiquetaP.h \
    ASMCompilador/Instruccion.h \
    ASMCompilador/InstruccionFactory.h \
    ASMCompilador/JMP.h \
    ASMCompilador/JR.h \
    ASMCompilador/LabelManager.h \
    ASMCompilador/LB.h \
    ASMCompilador/LI.h \
    ASMCompilador/LUI.h \
    ASMCompilador/MOV.h \
    ASMCompilador/Numero.h \
    ASMCompilador/OR.h \
    ASMCompilador/ParameterFactory.h \
    ASMCompilador/Parametro.h \
    ASMCompilador/Registro.h \
    ASMCompilador/SB.h \
    ASMCompilador/SL.h \
    ASMCompilador/SLT.h \
    ASMCompilador/SPC.h \
    ASMCompilador/SUB.h \
    ASMCompilador/Util.h \
    ASMCompilador/XOR.h \
    errores_forms.h

FORMS    += mainwindow.ui \
    errores_forms.ui

RESOURCES += \
    resource.qrc
