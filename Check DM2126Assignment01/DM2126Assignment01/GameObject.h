#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

using std::string;

class GameObject
{
public:
    GameObject(){};
	virtual ~GameObject() = 0;
	virtual string getName(void);
	static int getCount();

protected:
	//Overload Function
	GameObject(const string&);

	const string kName;

private:
	static int count_;
};

#endif