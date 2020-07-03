#ifndef OBJECT_H
#define OBJECT_H

class Object
{
	public:
		Object(char);
		virtual char getValue()=0;
	protected:
		char value;
};

#endif
