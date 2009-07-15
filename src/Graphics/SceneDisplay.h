#ifndef scenedisplay_h
#define scenedisplay_h

#include "Drawable.h"
#include "MeshRenderer.h"

#include "../Graphics/Animation/Animator.h"
#include "../Graphics/Animation/Animatable.h"
#include "../Graphics/Materials.h"
#include "../Graphics/Animation/RotatingBlock.h"
//#include "../SceneObjects/Maps/Map.h"
#include "../Utils/Structures/KDTree.h"

using std::cout;
using std::endl;

class GameCoordinator;

class SceneDisplay : public Drawable, public MeshRenderer
{
private:
	Animator* animator;
	Animatable** blocks;

	MeshOBJ* textured;
	MeshOBJ* signature;

	GameCoordinator* coordinator;

	KDTree* tree;
	void initSceneObjects();

public:
	SceneDisplay(GameCoordinator* coordinator, Animator* animator);
	virtual ~SceneDisplay();
	void draw();
	KDTree* getKDTree();
};

#endif
