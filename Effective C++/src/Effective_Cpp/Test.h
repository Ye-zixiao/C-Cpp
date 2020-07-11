#pragma once

class Test {
public:
	enum mem {C1,C2};
	virtual int get(void) const = 0;
	virtual Test& modify(int value) = 0;
	static Test* creator(int v,mem m);
};