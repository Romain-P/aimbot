/*
 * From 'Modern C++ Design'
 */


#ifndef singleton_h
#define singleton_h

template<class T>
class Singleton
{
private:

	// Making these private prevents misuse of singleton
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);

public:
	Singleton()	{}
	static T& Instance()
	{
		static T instance;
		return instance;
	}
};

#endif
