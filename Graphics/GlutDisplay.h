#ifndef glutdisplay_h
#define glutdisplay_h

class GlutDisplay
{
public:
	static inline void displayDelegate();
	static inline void reshapeDelegate(int w, int h);

	void displayFunction()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.5, 0.5, 0.5, 0.0);

		glutSwapBuffers();
	}

	void reshapeFunction(int w, int h)
	{

	}
};

#endif
