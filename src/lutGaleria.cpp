//
//  lutGaleria.cpp
//  lutBaqOF
//
//  Created by Paulo Guerra on 9/27/16.
//
//

#include "lutGaleria.h"
#include "Globals.h"


void lutGaleria::setup() {
    string path = "categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/fotos";
    ofDirectory dir(path);
    dir.allowExt("jpg");
    dir.listDir();
    ofLogNotice(ofToString(dir.size()) + "fotos en esta ficha");
    numfots = dir.size();
    imagenes.resize(numfots);
    for (int i = 0; i<numfots; i++) {
        imagenes[i].load("categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/fotos/foto_"+ofToString(i)+".jpg");
    }
}

void lutGaleria::setNewImages() {
    imagenes.clear();
    string path = "categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/fotos";
    ofDirectory dir(path);
    dir.allowExt("jpg");
    dir.listDir();
    ofLogNotice(ofToString(dir.size()) + "fotos en esta ficha");
    numfots= dir.size();
    imagenes.resize(numfots);
    for (int i = 0; i<numfots; i++) {
        //loader.loadFromDisk(imagenes[i], "categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/fotos/foto_"+ofToString(i)+".jpg");
        imagenes[i].load("categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/fotos/foto_"+ofToString(i)+".jpg");
    }

    currentfot = 0;
    lastChanged = ofGetElapsedTimeMillis();
}

void lutGaleria::update() {
    if ((ofGetElapsedTimeMillis()-lastChanged) > tiempoDeCambio && !Globals::isChanging) {
        lastChanged = ofGetElapsedTimeMillis();
        Globals::isChanging = true;
        change();
    }
}

void lutGaleria::change() {
    if (currentfot < numfots-1)currentfot=currentfot+1;
    else currentfot = 0;
    Globals::isChanging = false;
}


void lutGaleria::dibujar() {
    img = imagenes[currentfot];
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, opacity);
    img.draw(974, 62);
    ofDisableAlphaBlending();
}
