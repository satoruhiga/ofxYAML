#pragma once

#include "ofMain.h"
#include "yaml.h"

class ofxYAML
{
public:
	
	YAML::Node doc;
	
	bool load(string path);
};


inline void operator>>(const YAML::Node &node, ofPoint &p)
{
	node[0] >> p.x;
	node[1] >> p.y;
	node[2] >> p.z;
}

inline void operator>>(const YAML::Node &node, ofRectangle &p)
{
	node[0] >> p.x;
	node[1] >> p.y;
	node[2] >> p.width;
	node[3] >> p.height;
}

inline void operator>>(const YAML::Node &node, ofColor &p)
{
	node[0] >> p.r;
	node[1] >> p.g;
	node[2] >> p.b;
	node[3] >> p.a;
}

