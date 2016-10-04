//
//  lutPantalla.cpp
//  lutBaqOF
//
//  Created by Paulo Guerra on 9/27/16.
//
//

#include "lutPantalla.h"
#include "Globals.h"

void lutPantalla::setup(){
    warpers.push_back(ofxGLWarper());
    warpers.back().setup(172, 17, 746, 1048);
    warpers.push_back(ofxGLWarper());
    warpers.back().setup(974, 62, 554, 390);
    warpers.push_back(ofxGLWarper());
    warpers.back().setup(974, 459, 600, 667);
    warpers[0].load("warpConfigSaved_1.xml");
    warpers[1].load("warpConfigSaved_2.xml");
    warpers[2].load("warpConfigSaved_3.xml");
    activeWarper =-1;
    galeriaPlanos.setup();
    galeriaFotos.setup();
    textoFicha.setup();
}

void lutPantalla::resetEsquinas() {
    warpers[0].load("warpConfigOrigin_1.xml");
    warpers[1].load("warpConfigOrigin_2.xml");
    warpers[2].load("warpConfigOrigin_3.xml");
}

void lutPantalla::saveEsquinas(){
    warpers[0].save("warpConfigSaved_1.xml");
    warpers[1].save("warpConfigSaved_2.xml");
    warpers[2].save("warpConfigSaved_3.xml");
}

void lutPantalla::setNewImages() {
    galeriaPlanos.setNewImages();
    galeriaFotos.setNewImages();
    textoFicha.setNewImage();
}
    
void lutPantalla::updateAndDibujar() {
    galeriaPlanos.update();
    galeriaFotos.update();
    warpers[0].begin();
    warpers[0].draw();
    galeriaPlanos.dibujar();
    warpers[0].draw();
    warpers[0].end();
    warpers[1].begin();
    warpers[1].draw();
    galeriaFotos.dibujar();
    warpers[1].draw();
    warpers[1].end();
    warpers[2].begin();
    warpers[2].draw();
    textoFicha.dibujar();
    warpers[2].draw();
    warpers[2].end();
}
