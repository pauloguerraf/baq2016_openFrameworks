//
//  lutPantalla.hpp
//  lutBaqOF
//
//  Created by Paulo Guerra on 9/27/16.
//
//

#ifndef lutPantalla_h
#define lutPantalla_h

#define NUM_WARPERS 3

#include "ofMain.h"
#include "lutPlanos.h"
#include "lutGaleria.h"
#include "lutTexto.h"
#include "ofxGLWarper.h"


class lutPantalla{
    
public:
    lutPlanos galeriaPlanos;
    lutGaleria galeriaFotos;
    lutTexto textoFicha;
    void setup();
    void resetEsquinas();
    void saveEsquinas();
    void prepareNextImages();
    void setNewImages();
    void updateAndDibujar();
    void checkCalib();
    vector<ofxGLWarper> warpers;
    int activeWarper;
};

#endif /* lutPantalla_hpp */
