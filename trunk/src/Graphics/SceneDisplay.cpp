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


	static Position3 position;
	position = coordinator->getPlayerPosition();
	static vector<KDPair> closest;

	static long frames = 0;
	if(frames++ % 100 == 0)
	{
		closest = coordinator->getClosestPoints();
	}

	glLineWidth(3.f);
	glBegin(GL_LINES);

	for(unsigned int i = 0; i < closest.size(); i++)
	{
		Position3 p = closest[i].node->position + c;
		glColor3f(0.2f * i, 1 - 0.2f * i, 0.5f);
		glVertex3f(position.x+c.y * 0.04f, c.y+0.1f, position.z+c.y * 0.04f);
		glVertex3f(p.x, p.y, p.z);

	}

	glEnd();

	/*
		glColor3f(0.0f, 1.0f, 0.5f);
		glLineWidth(4.f);
		glVertex3f(position.x, c.y+0.2f, position.z);
		glVertex3f(closest2.x, closest2.y, closest2.z);
	glEnd();
	glBegin(GL_POINTS);
		glVertex3f(position.x, c.y + 0.2f, position.z);
		glVertex3f(closest.x, closest.y, closest.z);
	glEnd();
	*/
}

KDTree* SceneDisplay::getKDTree()
{
	return tree;
}
