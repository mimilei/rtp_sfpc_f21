#include "ofApp.h"

ofImage portrait;
ofImage portrait_flipped;
int canvas_w;
int canvas_h;

//--------------------------------------------------------------
void ofApp::setup(){
//    portrait.load("img/alegria_white_singer.jpeg"); //1135 x 1500 > 681 x 900
//    portrait.resize(681, 900);
    portrait.load("img/OldVera_1961_PhotoCreditFrancoisMolnar.jpeg");// 498 x 850
//    portrait.setImageType(OF_IMAGE_GRAYSCALE);
//    portrait_flipped.load("img/OldVera_1961_PhotoCreditFrancoisMolnar.jpeg");// 498 x 850
//    portrait_flipped.setImageType(OF_IMAGE_GRAYSCALE);
//    portrait_flipped.rotate90(2);
    canvas_w = 800;
    canvas_h = 1000;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255);
    
    // SELF PORTRAIT
    /**
     Divide image into 5 sections (can play with this later).
     Each section is randomly flipped upside-down.
     Sections are drawn in random orders. 
     */
    ofSeedRandom(mouseX);
    float num_sections = 5.0; // Can randomize later
    float section_h = canvas_h / num_sections;
    float corner_x = (canvas_w - portrait.getWidth())/2;
    float corner_y = (canvas_h - portrait.getHeight())/2;
//    portrait.draw((canvas_w - portrait.getWidth())/2, (canvas_h - portrait.getHeight())/2);

    for (int i = 0; i < num_sections; i++) {
        ofImage p;
        p.load("img/OldVera_1961_PhotoCreditFrancoisMolnar.jpeg");// 498 x 850
        p.setImageType(OF_IMAGE_GRAYSCALE);
        if (corner_y + section_h > portrait.getHeight()) { // Not all imgs perfectly divisible
            p.crop(0, section_h * i, portrait.getWidth(), portrait.getHeight() - section_h * i);
        } else {
            p.crop(0, section_h * i, portrait.getWidth(), section_h);
        }
        if (i%2 == 0) {
            p.rotate90(2);
        }
        p.draw(corner_x, corner_y);
//        if (i%2 == 1) {
//            if (corner_y + section_h > portrait.getHeight()) { // Not all imgs perfectly divisible
//                portrait.drawSubsection(corner_x, corner_y, portrait.getWidth(), portrait.getHeight() - section_h * i, 0, section_h * i);
//            } else {
//                portrait.drawSubsection(corner_x, corner_y, portrait.getWidth(), section_h, 0, section_h * i);
//            }
//        } else {
//            if (i == 0) { // Not all imgs perfectly divisible
//                portrait_flipped.drawSubsection(corner_x, corner_y, portrait.getWidth(), portrait.getHeight() - section_h * i, 0, section_h * (num_sections - 1 - i));
//            } else {
//                portrait_flipped.drawSubsection(corner_x, corner_y, portrait.getWidth(), section_h, 0, section_h * (num_sections - 1 - i));
//            }
//        }
        corner_y += section_h;
    }
    
    // Computer-rosace A
    
    // IGNORE =====================
//    ofSeedRandom(mouseX);
//    for (int i = 0; i < 800; i++) {
//        ofDrawCircle(i, 400 + ofRandom(-100, 100), 2);
//    }
//    ofDrawLine(-15, 0, 0+15, 0);
//    for (int i = 0; i < 800; i++) {
//        ofDrawCircle(i, 400 + ofSignedNoise(i * 0.03) * 100, 2);
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
