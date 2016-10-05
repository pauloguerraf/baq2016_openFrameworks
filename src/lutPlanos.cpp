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
    initAnim();
}

void lutPlanos::initAnim(){
    alpha.reset(0);
    alpha.setCurve(EASE_IN);
    alpha.setRepeatType(PLAY_ONCE);
    alpha.setDuration(1.0);
    alpha.animateTo(255);
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
    initAnim();
}

void lutPlanos::update() {
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

void lutPlanos::change() {
    if (currentfot < numfots-1)currentfot=currentfot+1;
    else currentfot = 0;
    alpha.reset(0);
    alpha.setCurve(EASE_IN);
    alpha.setRepeatType(PLAY_ONCE);
    alpha.setDuration(1.0);
    alpha.animateTo(255);
    isChanging = false;
}


void lutPlanos::dibujar() {
    img = imagenes[currentfot];
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, alpha.val());
    img.draw(172, 17);
    ofDisableAlphaBlending();
}
