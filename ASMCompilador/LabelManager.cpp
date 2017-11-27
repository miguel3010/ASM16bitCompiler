#include "stdafx.h"
#include "LabelManager.h"


#include <algorithm>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include "Instruccion.h"
#include "Error.h"
#include "EtiquetaP.h"

LabelManager* LabelManager::instance;

LabelManager::LabelManager() {

}

LabelManager::~LabelManager() {
	err.clear();
}

LabelManager* LabelManager::getInstance() {
    if (!instance) {
        instance = new LabelManager();
    }
    return instance;
}

/**
 * Registra un etiqueta al record de etiquetas
 * @param et
 * @param PC
 * @return 
 *  true si la etiqueta existe pero no esta enlzada con una linea del codigo o no existe.
 *  false Existe y esta repetida.
 */
bool LabelManager::RegistrarEtiruetaInstruccion(std::string et, int PC) {
    if (!et.empty() && PC >= 0) {
        et.erase(std::remove(et.begin(), et.end(), ':'), et.end());
        Etiqueta *etq = getEtiqueta(et);
        if (etq) {
			int k = etq->PC;
            if (k>= 0) {
                //Existe y esta repetida
                Error *e = new Error();
                e->setLinea(PC);
                e->setdescripcion("La etiqueta '" + et + "' está repetida.");
                this->err.push_back(e);
                return false;
            } else {
                //Existe pero no esta enlzada con una linea del codigo
                etq->PC = PC;
                return true;
            }
        } else {
            //No existe y se registra
            Etiqueta *e = new Etiqueta();

            e->Label = et;
            e->PC = PC;
            etiquetas.push_back(e);
            return true;
        }
    }
    return false;


}

/**
 * Obtiene un parametro etiqueta asociado a una etiqueta instruccion exista o no hasta el actual momento.
 * @param et
 * @return 
 */
EtiquetaP* LabelManager::getEtiquetaParametro(std::string et) {
    if (!et.empty()) {
        Etiqueta *etq = getEtiqueta(et);
        if (etq) {
            EtiquetaP *i = new EtiquetaP();
            i->etiqueta = etq;
            return i;
        } else {

            etq = new Etiqueta();
            etq->Label = et;
            etiquetas.push_back(etq);
            EtiquetaP *p = new EtiquetaP();
            p->etiqueta = etq;
            return p;
        }
    }
    return nullptr;
}

/**
 * Verifica la existencia de errores o corrupcion de etiquetas en el manager
 * @return 
 * true si todo es correcto.
 * false si existen errores y se agregar tales errores a la lista global de errores.
 */
bool LabelManager::errorAnalyce() {
    bool err = false;
    if (!etiquetas.empty()) {
        for (auto i : etiquetas) {
            if (i->PC == -1) {
                err = true;
                Error *e = new Error();
                std::string desc = "La etiqueta: '" + i->Label + "' no se encuentra en el codigo descrito.";
                e->setdescripcion(desc);
                this->err.push_back(e);
            }
        }
    }
    return err;
}

/**
 * Busca una etiqueta en la lista de etiquetas actuales
 * @param et
 * @return 
 */
Etiqueta* LabelManager::getEtiqueta(std::string et) {
    if (!et.empty()) {
        et.erase(std::remove(et.begin(), et.end(), ':'), et.end());
        if (!etiquetas.empty()) {
            for (auto i : etiquetas) {
                if (!i->Label.compare(et)) {
                    return i;
                }
            }
        }
    }
    return nullptr;
}

std::list<Error*> LabelManager::getErrores() {
    return err;
}

void LabelManager:: borrarTodaEtiqueta(){
	etiquetas.clear();
}

void LabelManager::reset(){
	LabelManager::~LabelManager();
	instance = nullptr;
}