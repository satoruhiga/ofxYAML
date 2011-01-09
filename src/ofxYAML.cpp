#include "ofxYAML.h"

bool ofxYAML::load(string path)
{
	path = ofToDataPath(path);
	
	std::ifstream fin(path.c_str());
    YAML::Parser parser(fin);
	
	parser.GetNextDocument(doc);
	
	return true;
}