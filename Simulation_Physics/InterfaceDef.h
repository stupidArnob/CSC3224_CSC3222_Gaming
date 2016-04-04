#pragma once

namespace Simulation
{
namespace Physics
{
  class InterfaceDef
  {
  public:
    InterfaceDef(Entity *e1, Entity *e2)
        : m_resolved(false)
    {
      if (e1 > e2)
      {
        m_swap = true;
        m_e1 = e2;
        m_e2 = e1;
      }
      else
      {
        m_swap = false;
        m_e1 = e1;
        m_e2 = e2;
      }
    }

    virtual ~InterfaceDef()
    {
    }

    Entity *entityA()
    {
      return m_e1;
    }

    Entity *entityB()
    {
      return m_e2;
    }

    bool resolved() const
    {
      return m_resolved;
    }

    bool swapped() const
    {
      return m_swap;
    }

    Engine::Maths::Vector2 normal() const
    {
      return m_normal;
    }

    bool operator==(const InterfaceDef &other) const
    {
      return (m_e1 == other.m_e1) && (m_e2 == other.m_e2);
    }

  private:
    friend class PhysicsUpdate;
    friend class InterfaceDetection;
    friend class InterfaceResolution;

    Entity *m_e1;
    Entity *m_e2;

    bool m_resolved;
    bool m_swap;

    Engine::Maths::Vector2 m_normal;
  };
}
}