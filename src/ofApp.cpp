#include "ofApp.h"
#include "Globals.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofHideCursor();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofTrueTypeFont::setGlobalDpi(72);
    verdana60.load("verdana.ttf", 60, true, true);
    verdana60.setLineHeight(68.0f);
    verdana60.setLetterSpacing(1.035);
    
    leerConfig();
    //leerNombres();
    Globals::UDP.Create();
    Globals::UDP.Bind(Globals::port);
    Globals::UDP.SetNonBlocking(true);
    pantalla.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    char udpMessage[100000];
    Globals::UDP.Receive(udpMessage,100000);
    string message=udpMessage;
    
    if(message!=""){
        Globals::encoderPos = ofToInt(message);
        ofLogNotice("encoder_position : "+ofToString(Globals::encoderPos)+" at "+ofGetTimestampString("%H:%M:%S.%i"));
    }
    checkEncoder();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    if (!Globals::isSleeping) {
        pantalla.updateAndDibujar();
        if(Globals::showStroke){
            ofFill();
            ofSetColor(255, 255, 255);
            int xPos = 40;
            int yPos = 80;
            verdana60.drawString(ofToString(Globals::encoderPos), xPos, yPos);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    Globals::lastSleep = ofGetElapsedTimeMillis();
    if (key == OF_KEY_DOWN && Globals::seleccion < Globals::numFichas) {
        Globals::seleccion = Globals::seleccion+1;
        changeImages(); 
    }
    if (key == OF_KEY_UP && Globals::seleccion>0) {
        Globals::seleccion = Globals::seleccion-1;
        changeImages();
    }
    if (key=='r') {
        resetEsquinas();
    }
    bool bDeactivateOthers = false;
    switch (key) {
        case '1':
            pantalla.activeWarper=0;
            pantalla.warpers[0].toogleActive();
            bDeactivateOthers =true;
            Globals::showStroke = true;
            ofShowCursor();
            break;
            //*
        case '2':
            pantalla.activeWarper=1;
            pantalla.warpers[1].toogleActive();
            bDeactivateOthers =true;
            Globals::showStroke = true;
            ofShowCursor();
            break;
        case '3':
            pantalla.activeWarper=2;
            pantalla.warpers[2].toogleActive();
            bDeactivateOthers =true;
            Globals::showStroke = true;
            ofShowCursor();
            break;
            //*/
        default:
            break;
    }
    
    if (bDeactivateOthers) {
        for (int i =0; i<NUM_WARPERS; i++){
            if (i!=pantalla.activeWarper) {
                pantalla.warpers[i].deactivate();
            }
        }
    }
    else{
        for (int i =0; i<NUM_WARPERS; i++){
            pantalla.warpers[i].deactivate();
        }
        Globals::showStroke = false;
        ofHideCursor();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
void ofApp::leerConfig(){
    vector <string> linesOfTheFile;
    ofBuffer buffer = ofBufferFromFile("config.txt");
    for (auto line : buffer.getLines()){
        linesOfTheFile.push_back(line);
    }
    for (int i=0; i<linesOfTheFile.size()-1; i++){
        Globals::strings.push_back(linesOfTheFile[i]);
        ofLogNotice(ofToString(linesOfTheFile[i]));
    }
    ofLogNotice(ofToString(Globals::strings.size()));
    Globals::CATEGORIA = Globals::strings[0];
    Globals::numDeFichas = ofToInt(Globals::strings[1]);
}

//void ofApp::leerNombres(){
//    vector <string> linesOfTheFile;
//    ofBuffer buffer = ofBufferFromFile("categoria_"+Globals::CATEGORIA+"/nombres.txt");
//    for (auto line : buffer.getLines()){
//        linesOfTheFile.push_back(line);
//    }
//    for (int i=0; i<linesOfTheFile.size()-1; i++){
//        Globals::nombres.push_back(linesOfTheFile[i]);
//        ofLogNotice(ofToString(linesOfTheFile[i]));
//    }
//    ofLogNotice(ofToString(Globals::nombres.size()));
//}

void ofApp::save(){
    pantalla.saveEsquinas();
}
void ofApp::exit() {
    Globals::UDP.Close();
    ofLogNotice("saving corners to file");
    save();
}

void ofApp::checkSleep(){
    if ((ofGetElapsedTimeMillis()-Globals::lastSleep) > Globals::timeSleep) {
        Globals::isSleeping = true;
    } else Globals::isSleeping = false;
}
void ofApp::resetEsquinas(){
    pantalla.resetEsquinas();
}
void ofApp::recorrerEncoder(int dir_){
    if (dir_ == 1 && Globals::seleccion < Globals::numDeFichas) {
        Globals::seleccion = Globals::seleccion+1;
        changeImages();
    }
    if (dir_ == -1 && Globals::seleccion > 0) {
        Globals::seleccion = Globals::seleccion-1;
        changeImages();
    }
}
void ofApp::changeImages(){
    pantalla.setNewImages();
}

void ofApp::checkEncoder(){
    int enc = Globals::encoderPos;
    int lastPos = Globals::lastPosicion;
    if (enc != lastPos) {
        Globals::lastSleep = ofGetElapsedTimeMillis();
        Globals::currentPosicion = enc;
        if (Globals::currentPosicion > lastPos) {
            recorrerEncoder(1);
            ofLogNotice("up encoder pos: " + ofToString(Globals::currentPosicion));
            Globals::lastPosicion = Globals::currentPosicion;
        } else if (Globals::currentPosicion < lastPos) {
            recorrerEncoder(-1);
            ofLogNotice("down encoder pos: " + ofToString(Globals::currentPosicion));
            Globals::lastPosicion = Globals::currentPosicion;
        }
    }
}

