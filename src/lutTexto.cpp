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
}

void lutTexto::setNewImage() {
    img.load("categoria_"+Globals::CATEGORIA+"/"+Globals::CATEGORIA+"_ficha_"+ofToString(Globals::seleccion)+"/texto.jpg");
}

void lutTexto::dibujar() {
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, opacity);
    img.draw(974, 459);
    ofDisableAlphaBlending();
}
