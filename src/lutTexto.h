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
#include "ofxAnimatableFloat.h"

class lutTexto {
    
    public:
        ofImage img;
        void setup();
        void initAnim();
        void setNewImage();
        void update();
        void dibujar();
        float opacity = 255.0;
        ofxAnimatableFloat alpha;
    
};

#endif /* lutTexto_h */
