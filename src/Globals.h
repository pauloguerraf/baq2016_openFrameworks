//
//  Globals.hpp
//  lutBaqOF
//
//  Created by Paulo Guerra on 9/27/16.
//
//

#ifndef Globals_h
#define Globals_h

#include "ofMain.h"
#include "ofxNetwork.h"



class Globals{
    public:
    static int port;
    static ofxUDPManager UDP;
    static int encoderPos;
    static int seleccion;
    static int lastPosicion;
    static int currentPosicion;
    static int numFichas;
    
    static float rad;
    static bool showStroke;
    static vector <string> strings;
    static string CATEGORIA;
    static int numDeFichas;
    static int timeSleep;
    static int lastSleep;
    static bool isSleeping;
    static int currentCorner;
    static bool mousePressed;


};
#endif /* Globals_hpp */
