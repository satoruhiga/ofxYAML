#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
   parseYAML();
}

void testApp::parseYAML(){
    yaml.load("my_points.yml");
    stringstream s;

    string name;
    yaml.doc["name"] >> name;
    s << "\nName: " << name;
    
    yaml.doc["color"] >> theColor;
    yaml.doc["point1"] >> point1;
    yaml.doc["point2"] >> point2;
    yaml.doc["size1"] >> size1;
    yaml.doc["size2"] >> size2;
    
    cout << dec << "r: " << (int)theColor.r << " g: " << (int)theColor.g << " b: " << (int)theColor.b << endl; 
    cout << "p1.x: " << point1.x << " p1.y: " << point1.y << endl;
    
    result = s.str();
}

//--------------------------------------------------------------
void testApp::update(){
     
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(125);
    ofSetColor(255, 0, 0);
    ofDrawBitmapString("Results from data/my_points.yml\n(Press 'r' to re-parse file to see changes)\nPress 's' to generate new random data and re-save", 15,15);
    
    //ofSetColor(theColor);
    ofSetColor(255);
    ofDrawBitmapString(result, 15,60);
    
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(15, 85);
    
    // TODO:
    // this is a hack since ofColors do not de-serialize correctly!
    ofSetColor(ofColor(theColor.r * 10, theColor.g * 10, theColor.b * 10));
    ofCircle(point1.x, point1.x, size1);
    ofCircle(point2.x, point2.x, size2);
    ofPopStyle();
    ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'r'){
        parseYAML();
    }
    if(key == 's'){
        ofColor color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
        ofPoint p1 = ofPoint(ofRandom(3,10), ofRandom(3,10));
        ofPoint p2 = ofPoint(ofRandom(20,50), ofRandom(20,50));
        int s1 = ofRandom(10);
        int s2 = ofRandom(20);
        
        YAML::Emitter out;
        out << YAML::BeginMap;     
        out << YAML::Key << "name";
        out << YAML::Value << "Greg Borenstein";
        out << YAML::Key << "color";
        out << YAML::Value << color;
        out << YAML::Key << "point1";
        out << YAML::Value << p1;
        out << YAML::Key << "point2";
        out << YAML::Value << p2;
        out << YAML::Key << "size1";
        out << YAML::Value << s1;
        out << YAML::Key << "size2";
        out << YAML::Value << s2;
        
        out << YAML::EndMap;
        
        int l = strlen(out.c_str());
        
        ofBuffer yamlData;
        yamlData.set((const char *)out.c_str(), l);
        bool fileWritten = ofBufferToFile(ofToDataPath("my_points.yml"), yamlData); 
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}