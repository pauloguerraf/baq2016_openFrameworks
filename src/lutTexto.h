//
//  lutTexto.hpp
//  lutBaqOF
//
//  Created by Paulo Guerra on 9/27/16.
//
//

#ifndef lutTexto_h
#define lutTexto_h

#include "ofMain.h"

class lutTexto {
    
    public:
        ofImage img;
        void setup();
        void setNewImage();
        void dibujar();
        float opacity = 255.0;
};

#endif /* lutTexto_h */
