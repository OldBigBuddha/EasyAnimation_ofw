#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(30);       //フレームレートを３０FPSに
  ofSetBackgroundColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));

  //変数初期化
  radius   = 30;                                            //円の半径
  location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);      //初期位置、画面中央
  velocity = ofVec2f(ofRandom(-15, 20), ofRandom(-15,20));  //速度、ランダム
  isMoving = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
  //速度から位置を算出
  location += velocity;
}

//--------------------------------------------------------------
void ofApp::draw(){
  //計算した位置に円を描写
  ofSetColor(31,12,255);      //色設定
  ofDrawCircle(location, radius); //半径３０で計算した位置に円を描写

  //左右の画面端にきたらバウンド(反転)
  if (location.x < radius/2 || location.x > ofGetWidth() - radius/2) {
    ofSetBackgroundColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    velocity.x *= -1;
  }

  //上下の画面端にきたらバウンド(反転)
  if (location.y < radius/2 || location.y > ofGetHeight() - radius/2) {
    ofSetBackgroundColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));

    velocity.y *= -1;
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == 's') {
    velocity = ofVec2f(0,0);  //停止
    isMoving = 0;
  }
  if (key == 'p') {
    if (isMoving == 0) {
      velocity = ofVec2f(ofRandom(-15, 20), ofRandom(-15,20));  //速度、ランダム
      isMoving = 1;
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
