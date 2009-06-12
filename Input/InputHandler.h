#ifndef inputhandler_h
#define inputhandler_h

class InputHandler
{
private:
public:
	InputHandler()
	{
	}

	static inline void keyboardDelegate(unsigned char key, int x, int y);
	static inline void specialKeyDelegate(unsigned char key, int x, int y);
	static inline void mouseDelegate(int button, int state, int x, int y);
	static inline void motionDelegate(int x, int y);

	void mouseFunction(int button, int state, int x, int y);
	void motionFunction(int x, int y);
	void keyboardFunction(unsigned char key);
	void specialKeyFunction(unsigned char key);


};
#endif
