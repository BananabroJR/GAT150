#include "NeutralComponent.h"
#include "Engine.h"
#include <iostream>

void NeutralComponent::Initialize()
{
    CharacterComponent::Initialize();
}

void NeutralComponent::Update()
{
        auto actor = Skyers::Factory::Instance().Create<Skyers::Actor>("Bat");
        
    
        if (actor->m_transform.position.x >= 0)
        {

            Skyers::Vector2 direction = Skyers::Vector2::right;
            Skyers::Vector2 force = direction.Normalized() * speed;
            auto component = m_owner->GetComponent<Skyers::PhysicsComponent>();
            if (component)
            {
                component->ApplyForce(force);
            }
        }

        if (actor->m_transform.position.x <= 800)
        {
            Skyers::Vector2 direction = Skyers::Vector2::left;
            Skyers::Vector2 force = direction.Normalized() * speed;
           auto component = m_owner->GetComponent<Skyers::PhysicsComponent>();
            if (component) component->ApplyForce(force);
        }
    
}

void NeutralComponent::OnCollisionEnter(Skyers::Actor* other)
{

    if (other->GetTag() == "Player")
    {
        Skyers::Event event;
        event.name = "EVENT_DAMAGE";
        event.data = damage * 2;
        event.receiver = other;

        auto component = m_owner->GetComponent<Skyers::PhysicsComponent>();
        if (component)
        {

            component->ApplyForce(Skyers::Vector2::up * 1000);


        }

        Skyers::g_event.Notify(event);
    }
}

void NeutralComponent::OnCollisionExit(Skyers::Actor* other)
{
}

void NeutralComponent::OnNotify(const Skyers::Event& event)
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

bool NeutralComponent::Write(const rapidjson::Value& value) const
{
    return true;
}

bool NeutralComponent::Read(const rapidjson::Value& value)
{
    CharacterComponent::Read(value);

    return true;
}