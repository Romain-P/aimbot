#ifndef graphicincludes_h
#define graphicincludes_h

	#ifdef WIN32
		#define GLUT_DISABLE_ATEXIT_HACK
		#include <windows.h>
	#endif

	#ifdef __APPLE__
		#include <OpenGL/gl.h>
		#include <GLUT/glut.h>
		#include <OpenGL/glu.h>
	#else
		#include <GL/glut.h>
		#define GL_GLEXT_PROTOTYPES
		#include <GL/glext.h>
	#endif

#endif
