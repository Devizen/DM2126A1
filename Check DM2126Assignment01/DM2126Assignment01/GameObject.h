#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

using std::string;

class GameObject
{
public:
    GameObject(){};
	virtual ~GameObject() = 0;

    //Get back object name.
	virtual string getName(void);

    //Print count value.
	static int getCount();

protected:
	//Overload Function
	GameObject(const string& name);

    //Variable to store object name.
	const string kName;

private:
    //Count to keep track of objects.
	static int count_;
};

#endif