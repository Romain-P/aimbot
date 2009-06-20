/*
 * From 'Modern C++ Design'
 */


#ifndef singleton_h
#define singleton_h

template<class T, class Tag = void>
class Singleton
{
private:
	Singleton()
	{
	}
	~Singleton()
	{
	}
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}
};

#endif
