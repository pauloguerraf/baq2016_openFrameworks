//
//  lutGaleria.hpp
//  lutBaqOF
//
//  Created by Paulo Guerra on 9/27/16.
//
//

#ifndef lutGaleria_h
#define lutGaleria_h

#include "ofMain.h"

class lutGaleria{

    public:
        vector <ofImage> imagenes;
        vector <ofImage> nextImagenes;
        int numfots = 0;
        int currentfot = 0;
        unsigned int lastChanged = 0;
        unsigned int tiempoDeCambio = 7000;
        ofImage img;    
        void setup();
        void setNewImages();
        void update();
        void change();
        void dibujar();
        float opacity = 255.0;
};

#endif /* lutGaleria_h */
