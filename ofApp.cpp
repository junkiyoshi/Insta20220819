#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetWindowTitle("openFrameworks");
	ofSetFrameRate(30);

	ofBackground(0);
	ofSetLineWidth(2);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius = 10;
	ofColor color;
	for (int x = -300; x <= 300; x += 30) {

		for (int y = -300; y <= 300; y += 30) {

			ofPushMatrix();
			ofTranslate(x, y);

			auto deg = ofMap(ofNoise(x * 0.0015, y * 0.0015, ofGetFrameNum() * 0.0075), 0, 1, 0, 360);

			ofDrawCircle(glm::vec2(), radius);
			ofDrawLine(
				glm::vec2(radius * 1.85 * cos(deg * DEG_TO_RAD), radius * 1.85 * sin(deg * DEG_TO_RAD)),
				glm::vec2(radius * 1.85 * cos((deg + 180) * DEG_TO_RAD), radius * 1.85  * sin((deg + 180) * DEG_TO_RAD)));
			
			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}