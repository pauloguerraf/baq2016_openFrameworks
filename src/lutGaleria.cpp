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
    initAnim();
}

void lutGaleria::initAnim(){
    alpha.reset(0);
    alpha.setCurve(EASE_IN);
    alpha.setRepeatType(PLAY_ONCE);
    alpha.setDuration(1.0);
    alpha.animateTo(255);
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
    initAnim();
}

void lutGaleria::update() {
    float dt = 1.0f / 60.0f;
    alpha.update(dt);
    if ((ofGetElapsedTimeMillis()-lastChanged) > tiempoDeCambio && !isChanging) {
        lastChanged = ofGetElapsedTimeMillis();
        isChanging = true;
        alpha.reset(255);
        alpha.setCurve(EASE_IN);
        alpha.setRepeatType(PLAY_ONCE);
        alpha.setDuration(1.0);
        alpha.animateTo(0);
    }
    if(isChanging == true){
        if(alpha.getPercentDone() == 1.0){
            change();
        }
    }
}

void lutGaleria::change() {
    if (currentfot < numfots-1)currentfot=currentfot+1;
    else currentfot = 0;
    alpha.reset(0);
    alpha.setCurve(EASE_IN);
    alpha.setRepeatType(PLAY_ONCE);
    alpha.setDuration(1.0);
    alpha.animateTo(255);
    isChanging = false;
}


void lutGaleria::dibujar() {
    img = imagenes[currentfot];
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, alpha.val());
    img.draw(974, 62);
    ofDisableAlphaBlending();
}
