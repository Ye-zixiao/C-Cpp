#pragma once

class Test {
public:
	static Test& get_instance(void) {
		static Test item(32);
		return item;
	}
	int get(void) const {
		return value;
	}

private:
	int value;
	Test(int v):value(v){}
};