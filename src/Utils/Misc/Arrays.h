#ifndef arrays_h
#define arrays_h

/*
 * Efficient array allocation and deletion
 * minimizing calls to new and delete
 */

template <class T>
class Arrays
{
private:
public:
	static T* oneD(int rows)
	{
		return new T[rows];
	}

	static T** twoD(int rows, int cols)
	{
		T** pointers = new T*[rows];
		T* allElements = new T[rows * cols];

		for(int i = 0; i < rows; i++)
			pointers[i] = &allElements[rows * i];

		return pointers;
	}

	static T*** threeD(const int rows, const int cols, const int stacks)
	{
		T*** pointers = new T**[rows];
		T** metapointers = new T*[rows * cols];
		T* allElements = new T[rows * cols * stacks];

		for(int i = 0; i < stacks; i++)
			metapointers[i] = &allElements[rows * cols * i];

		for(int i = 0; i < cols; i++)
			pointers[i] = &metapointers[rows * i];

		// don't THINK we need this anymore...
		delete [] metapointers;

		return pointers;
	}
};

#endif
