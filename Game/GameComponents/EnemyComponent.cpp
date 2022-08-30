#include "EnemyComponent.h"
#include "Engine.h"
#include <iostream>

void EnemyComponent::Initialize()
{
    CharacterComponent::Initialize();
}

void EnemyComponent::Update()
{
    auto actor = m_owner->GetScene()->GetActorFromName("Player");
    if (actor)
    {
        Skyers::Vector2 direction = actor->m_transform.position - m_owner->m_transform.position;
        Skyers::Vector2 force = direction.Normalized() * speed;

        auto component = m_owner->GetComponent<Skyers::PhysicsComponent>();
        if (component) component->ApplyForce(force);
    }
}

void EnemyComponent::OnCollisionEnter(Skyers::Actor* other)
{

    if (other->GetTag() == "Player")
    {
        Skyers::Event event;
        event.name = "EVENT_DAMAGE";
        event.data = damage;
        event.receiver = other;

        Skyers::g_event.Notify(event);
    }
}

void EnemyComponent::OnCollisionExit(Skyers::Actor* other)
{
}

void EnemyComponent::OnNotify(const Skyers::Event& event)
{
    if (event.name == "EVENT_DAMAGE")
    {
        health -= std::get<float>(event.data);
        if (health <= 0)
        {
            m_owner->SetDestroy();
        }
    }

}

bool EnemyComponent::Write(const rapidjson::Value& value) const
{
    return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value)
{
    CharacterComponent::Read(value);

    return true;
}