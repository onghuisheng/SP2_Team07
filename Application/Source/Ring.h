#ifndef RING_H
#define RING_H


#include "Object.h"


// Interactable RING, pickable and harvestable
class Ring : public Object {

public:
	Ring(Scene* scene, Vector3 pos);
	~Ring() { RingCount--; };

	virtual void checkInteract();
	virtual void interact();
	static int RingCount;
	const float _interactDistance = 2.0f;

private:
	float _defaultScale = 1;

};
#endif