/**
 * @file
 * @author Dan Nixon
 */

#ifndef _ENGINE_PHYSICS_RIGIDBODY_H_
#define _ENGINE_PHYSICS_RIGIDBODY_H_

#include <btBulletDynamicsCommon.h>

#include <IMemoryManaged.h>

#include "SceneObjectMotionState.h"

namespace Engine
{
namespace Physics
{
  class PhysicalSystem;

  /**
   * @class RigidBody
   * @brief Represents a rigid body in a physics simulation.
   * @author Dan Nixon
   */
  class RigidBody : public Engine::Common::IMemoryManaged
  {
  public:
    RigidBody(btMotionState *state, float mass, const btVector3 &inertia, btCollisionShape *shape);
    virtual ~RigidBody();

    /**
     * @copydoc IMemoryManaged::releaseOrder
     */
    virtual int releaseOrder() const
    {
      return 40;
    }

    /**
     * @brief Gets the motion sttae of this body.
     * @return Motion state
     */
    inline btMotionState *motionState()
    {
      return m_body->getMotionState();
    }

    /**
     * @brief Gets a pointer to the body.
     * @return Body
     */
    inline btRigidBody *body()
    {
      return m_body;
    }

  protected:
    friend class PhysicalSystem;

    btRigidBody *m_body;       //!< Rigid body
    btCollisionShape *m_shape; //!< Shape of body

    PhysicalSystem *m_system; //!< System this body is part of
  };
}
}

#endif