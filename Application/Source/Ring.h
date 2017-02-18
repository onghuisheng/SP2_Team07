#ifndef RING_H
#define RING_H


#include "Object.h"


// Interactable RING, pickable and harvestable
class Ring : public Object {

public:
	Ring(Scene* scene, Vector3 pos);
	~Ring();

	static int RingCount;
	static Vector3* NearestRingPos;

	virtual void checkInteract();
	virtual void interact();
	float _interactDistance;

};
#endif