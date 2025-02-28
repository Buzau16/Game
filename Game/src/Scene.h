#pragma once
#include <vector>
#include "Object.h"
#include "memory"


class Scene {

public:
	Scene() = default;
	~Scene() = default;

	void AddObject(Object* object) { m_Objects.push_back(object); };
	void RemoveObject(Object* object);
	std::vector<Object*>& GetObjects() { return m_Objects; };

private:

	std::vector<Object*> m_Objects;
};