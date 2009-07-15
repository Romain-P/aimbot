#include "SceneDisplay.h"
#include "../Game/GameCoordinator.h"

SceneDisplay::SceneDisplay(GameCoordinator* coordinator, Animator* animator) :
	Drawable(0)
{
	this->animator = animator;
	this->coordinator = coordinator;
	initSceneObjects();
}

SceneDisplay::~SceneDisplay()
{
	//delete mesh;

	for(int i = 0; i < 3; i++)
		delete blocks[i];
	delete [] blocks;

	delete textured;
	//delete signature;
}

void SceneDisplay::initSceneObjects()
{
	textured = new MeshOBJ();
	textured->setCentre(Position3(0, -0.5f, 0));
	textured->read("testmap.obj");
	textured->loadTexture("testmap.png");

	tree = new KDTree(textured->getVertices());

	blocks = new Animatable*[3];
	blocks[0] = new RotatingBlock(50, 0.15f, Position3(0, 0.25f, 0));
	blocks[1] = new RotatingBlock(100, 0.05f, Position3(-0.1f, 0.6f, 0));
	blocks[2] = new RotatingBlock(300, 0.015f, Position3(-0.2f, 0.75f, 0));

	for(int i = 0; i < 3; i++)
		animator->addAnimatable(blocks[i]);
}

void SceneDisplay::draw()
{
	Position3 c = textured->getCentre();
	glPushMatrix();
		glTranslatef(c.x, c.y, c.z);
		drawTexturedMesh(textured);
	glPopMatrix();

	for(int i = 0; i < 3; i++)
		blocks[i]->draw();


	static long frames = 0;
	static Position3 position;
	static Position3 closest;

	position = coordinator->getPlayerPosition();

	if(frames++ % 100 == 0)
	{
		closest = Position3(textured->getCentre()) + Position3(coordinator->getClosestPoint());
	}

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex3f(position.x, c.y+0.2f, position.z);
		glVertex3f(closest.x, closest.y, closest.z);
	glEnd();
	glLineWidth(10.f);
	glBegin(GL_POINTS);
		glVertex3f(position.x, c.y + 0.2f, position.z);
		glVertex3f(closest.x, closest.y, closest.z);
	glEnd();
}

KDTree* SceneDisplay::getKDTree()
{
	return tree;
}
