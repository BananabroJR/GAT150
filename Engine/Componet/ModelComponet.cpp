#include "ModelComponet.h"
#include "Renderer/Model.h"
#include "Framework/Actor.h"
#include "Engine.h"

namespace Skyers
{

	void ModelComponent::Update()
	{
	}

	void ModelComponent::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_owner->m_transform);
	}
	bool ModelComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool ModelComponent::Read(const rapidjson::Value& value)
	{
		std::string model_name;
		READ_DATA(value, model_name);

		m_model = g_resource.Get<Model>(model_name);

		return true;
	}
}
