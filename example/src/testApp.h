#pragma once

#include "ofMain.h"
#include "ofxYAML.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    string result;
    ofPoint point1, point2;
    int size1, size2;
    ofColor theColor;
    ofxYAML yaml;
    
    void parseYAML();
    
};
