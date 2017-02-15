#include "ObjectCollider.h"


Collider::Collider(Vector3* pos, float width, float height, float depth) {
	position = pos;
	bboxWidth = width;
	bboxHeight = height;
	bboxDepth = depth;
}


Vector3 Collider::getBoxMin() {
	return Vector3((-bboxWidth / 2) + position->x,
				   (-bboxHeight / 2) + position->y,
				   (-bboxDepth / 2) + position->z);
}

Vector3 Collider::getBoxMax() {
	return Vector3((bboxWidth / 2) + position->x,
				   (bboxHeight / 2) + position->y,
				   (bboxDepth / 2) + position->z);
}

bool Collider::checkCollision(Collider &other, Vector3* hitDirection) {

	Vector3 myMin = getBoxMin();
	Vector3 myMax = getBoxMax();

	Vector3 otherMin = other.getBoxMin();
	Vector3 otherMax = other.getBoxMax();

	if (
		myMax.x > otherMin.x &&
		myMin.x < otherMax.x &&
		myMax.y > otherMin.y &&
		myMin.y < otherMax.y &&
		myMax.z > otherMin.z &&
		myMin.z < otherMax.z
		) {

		Vector3 hitDir = (*other.position) - (*position);
		(*hitDirection) = hitDir.Normalized();

		return true;
	}

	return false;
}