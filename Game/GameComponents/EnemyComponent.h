#pragma once
#pragma once
#include "Componet/CharacterComponent.h"

class EnemyComponent : public Skyers::CharacterComponent
{
public:
	CLASS_DECLARATION(EnemyComponent)

		virtual void Initialize() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(Skyers::Actor* other) override;
	virtual void OnCollisionExit(Skyers::Actor* other) override;

	virtual void OnNotify(const Skyers::Event& event) override;

	virtual bool Write(const rapidjson::Value& value) const override;
	virtual bool Read(const rapidjson::Value& value) override;

protected:
};