#include "ofxYAML.h"

bool ofxYAML::load(string path)
{
	path = ofToDataPath(path);
	
	std::ifstream fin(path.c_str());
    YAML::Parser parser(fin);
	
	parser.GetNextDocument(doc);
	
	return true;
}

bool ofxYAML::parse(string str)
{
	stringstream ss;
	ss << str;
    YAML::Parser parser(ss);
	
	parser.GetNextDocument(doc);
	
	return true;
}