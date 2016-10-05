//
//  lutTexto.cpp
//  lutBaqOF
//
//  Created by Paulo Guerra on 9/27/16.
//
//

#include "lutTexto.h"
#include "Globals.h"

void lutTexto::setup(){
    img.load("categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/texto.jpg");
    initAnim();
}

void lutTexto::initAnim(){
    alpha.reset(0);
    alpha.setCurve(EASE_IN);
    alpha.setRepeatType(PLAY_ONCE);
    alpha.setDuration(1.0);
    alpha.animateTo(255);
}

void lutTexto::setNewImage() {
    img.load("categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/texto.jpg");
    initAnim();
}

void lutTexto::update(){
    float dt = 1.0f / 60.0f;
    alpha.update(dt);
}

void lutTexto::dibujar() {
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, alpha.val());
    img.draw(974, 459);
    ofDisableAlphaBlending();
}
