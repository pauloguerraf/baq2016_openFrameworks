//
//  lutPlanos.cpp
//  lutBaqOF
//
//  Created by Paulo Guerra on 9/27/16.
//
//

#include "lutPlanos.h"
#include "Globals.h"


void lutPlanos::setup() {
    string path = "categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/planos";
    ofDirectory dir(path);
    dir.allowExt("jpg");
    dir.listDir();
    ofLogNotice(ofToString(dir.size()) + "planos en esta ficha");
    numfots= dir.size();
    imagenes.resize(numfots);
    for (int i = 0; i<numfots; i++) {
        imagenes[i].load("categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/planos/plano_"+ofToString(i)+".jpg");
    }
}

void lutPlanos::setNewImages() {
    imagenes.clear();
    string path = "categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/planos";
    ofDirectory dir(path);
    dir.allowExt("jpg");
    dir.listDir();
    ofLogNotice(ofToString(dir.size()) + "planos en esta ficha");
    numfots= dir.size();
    imagenes.resize(numfots);
    for (int i = 0; i<numfots; i++) {
          imagenes[i].load("categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/planos/plano_"+ofToString(i)+".jpg");
    }
    currentfot = 0;
    lastChanged = ofGetElapsedTimeMillis();
}

void lutPlanos::update() {
    if ((ofGetElapsedTimeMillis()-lastChanged) > tiempoDeCambio && !Globals::isChanging) {
        lastChanged = ofGetElapsedTimeMillis();
        Globals::isChanging = true;
        change();
    }
}

void lutPlanos::change() {
    if (currentfot < numfots-1)currentfot=currentfot+1;
    else currentfot = 0;
    Globals::isChanging = false;
}


void lutPlanos::dibujar() {
    img = imagenes[currentfot];
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, opacity);
    img.draw(172, 17);
    ofDisableAlphaBlending();
}
