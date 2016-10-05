//
//  Globals.cpp
//  lutBaqOF
//
//  Created by Paulo Guerra on 9/27/16.
//
//

#include "Globals.h"
ofxUDPManager Globals::UDP;

int Globals::port = 11999;
int Globals::encoderPos = 0;
int Globals::seleccion = 0;
int Globals::lastPosicion = 0;
int Globals::currentPosicion = 0;
int Globals::numFichas = 3;
int Globals::timeSleep  = 1800000;
int Globals::lastSleep = 0;
int Globals::currentCorner = 0;

float Globals::rad = 10.0;

bool Globals::showStroke = false;
bool Globals::isSleeping = false;
bool Globals::mousePressed  = false;

int Globals::numDeFichas;
vector <string> Globals::strings;

string Globals::CATEGORIA = "b";
