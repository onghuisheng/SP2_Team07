#ifndef OBJ_COLLIDER_H
#define OBJ_COLLIDER_H

#include "Vector3.h"

class Collider {

public:
	Collider(Vector3* pos, float width, float height, float depth);
	~Collider() {};

	float bboxWidth = 0;
	float bboxHeight = 0;
	float bboxDepth = 0;

	Vector3 getBoxMin();
	Vector3 getBoxMax();

	void setBoundingBoxSize(Vector3 size) { bboxWidth = size.x; bboxHeight = size.y; bboxDepth = size.z; };
	bool checkCollision(Collider &other, Vector3* hitDirection);

private:
	Vector3* position;

};
#endif