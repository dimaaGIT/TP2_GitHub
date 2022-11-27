#pragma once

class Container {
public:
	Container();
	~Container();
private:
	Container(const Container& other);
	Container& operator=(const Container& other);
	Container* first;
};