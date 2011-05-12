#pragma once

#include "ofMain.h"

#include "yaml.h"

class ofxYAML
{
public:

	YAML::Node doc;

	bool load(string path);
};


inline void operator >> (const YAML::Node & node, ofPoint & p)
{
	node[0] >> p.x;
	node[1] >> p.y;
	node[2] >> p.z;
}

inline void operator << (YAML::Emitter & out, ofPoint & p)
{
	out << YAML::Flow << YAML::BeginSeq;
	out << p.x << p.y << p.z;
	out << YAML::EndSeq;
}

inline void operator >> (const YAML::Node & node, ofRectangle & p)
{
	node[0] >> p.x;
	node[1] >> p.y;
	node[2] >> p.width;
	node[3] >> p.height;
}

inline void operator << (YAML::Emitter & out, ofRectangle & p)
{
	out << YAML::Flow << YAML::BeginSeq;
	out << p.x << p.y << p.width << p.height;
	out << YAML::EndSeq;
}

inline void operator >> (const YAML::Node & node, ofColor & p)
{
	node[0] >> p.r;
	node[1] >> p.g;
	node[2] >> p.b;
	node[3] >> p.a;
}

inline void operator << (YAML::Emitter & out, ofColor & p)
{
	out << YAML::Flow << YAML::BeginSeq;
	out << p.r << p.g << p.b << p.a;
	out << YAML::EndSeq;
}


#ifdef OF_VERSION >= 7

inline void operator >> (const YAML::Node & node, ofVec2f & p)
{
	node[0] >> p.x;
	node[1] >> p.y;
}

inline void operator << (YAML::Emitter & out, ofVec2f & p)
{
	out << YAML::Flow << YAML::BeginSeq;
	out << p.x << p.y;
	out << YAML::EndSeq;
}

inline void operator >> (const YAML::Node & node, ofVec4f & p)
{
	node[0] >> p.x;
	node[1] >> p.y;
	node[2] >> p.z;
	node[3] >> p.w;
}

inline void operator << (YAML::Emitter & out, ofVec4f & p)
{
	out << YAML::Flow << YAML::BeginSeq;
	out << p.x << p.y << p.z << p.w;
	out << YAML::EndSeq;
}

inline void operator >> (const YAML::Node & node, ofQuaternion & p)
{
	node[0] >> p.x();
	node[1] >> p.y();
	node[2] >> p.z();
	node[3] >> p.w();
}

inline void operator << (YAML::Emitter & out, ofQuaternion & p)
{
	out << YAML::Flow << YAML::BeginSeq;
	out << p.x() << p.y() << p.z() << p.w();
	out << YAML::EndSeq;
}

inline void operator >> (const YAML::Node & node, ofMatrix4x4 & p)
{
	vector<float> data(16);
	node >> data;
	p.set(&data[0]);
}

inline void operator << (YAML::Emitter & out, ofMatrix4x4 & p)
{
	vector<float> data(p.getPtr(), p.getPtr() + 16);
	out << YAML::Flow << data;
}

#endif