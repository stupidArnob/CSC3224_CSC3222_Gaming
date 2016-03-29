/**
 * @file
 * @author Dan Nixon
 */

#include "SceneObjectMotionState.h"

#include <Matrix4.h>
#include <Quaternion.h>
#include <Vector3.h>

using namespace Engine::Common;
using namespace Engine::Maths;

namespace Engine
{
namespace Physics
{
  /**
   * @brief Creates a new motion sate for a SceneObject.
   * @param object Target scene object
   * @param initialPos Initial position
   * @param initialRot Initial orientation
   */
  SceneObjectMotionState::SceneObjectMotionState(SceneObject *object, const Vector3 &initialPos, Quaternion initialRot)
      : m_sceneObject(object)
  {
    initialRot.normalise();
    m_initial = btTransform(btQuaternion(initialRot.i(), initialRot.j(), initialRot.k(), initialRot.w()),
                            btVector3(initialPos.x(), initialPos.y(), initialPos.z()));
  }

  SceneObjectMotionState::~SceneObjectMotionState()
  {
  }

  /**
   * @brief Sets the target scene obejct.
   * @param object Target object
   */
  void SceneObjectMotionState::setSceneObject(Engine::Common::SceneObject *object)
  {
    m_sceneObject = object;
  }

  void SceneObjectMotionState::getWorldTransform(btTransform &worldTrans) const
  {
    worldTrans = m_initial;
  }

  void SceneObjectMotionState::setWorldTransform(const btTransform &worldTrans)
  {
    if (m_sceneObject == nullptr)
      return;

    btQuaternion rot = worldTrans.getRotation();
    btVector3 pos = worldTrans.getOrigin();

    Quaternion rotQuat(rot.w(), rot.x(), rot.y(), rot.z());
    Vector3 posVec(pos.x(), pos.y(), pos.z());

    Matrix4 modelMat = Matrix4::Translation(posVec) * rotQuat.rotationMatrix();
    m_sceneObject->setModelMatrix(modelMat);
  }
}
}
