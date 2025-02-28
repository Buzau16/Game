#include "Scene.h"

void Scene::RemoveObject(Object* object)
{
	auto it = std::find(m_Objects.begin(), m_Objects.end(), object);
	if (it != m_Objects.end()) {
		m_Objects.erase(it);
	}
}
