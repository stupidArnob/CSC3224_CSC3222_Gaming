/**
 * @file
 * @author Dan Nixon (120263697)
 *
 * For CSC3224 Project 2.
 */

#include "Terrain.h"

#include <Engine_Graphics/HeightmapMesh.h>
#include <Engine_Logging/Logger.h>

using namespace Engine::Common;
using namespace Engine::Graphics;
using namespace Engine::Maths;
using namespace Engine::Physics;

namespace
{
Engine::Logging::Logger g_log(__FILE__);
}

namespace GameDev
{
namespace FlightSim
{
  Terrain::Terrain(const std::string &name, float width, float depth, size_t widthResolution, size_t depthResolution)
      : RenderableObject(name, new HeightmapMesh(widthResolution, depthResolution, width, depth),
                         ShaderProgramLookup::Instance().get("terrain_shader"))
  {
  }

  Terrain::~Terrain()
  {
  }

  void Terrain::initPhysics(PhysicalSystem *system)
  {
    // Heightmap ollision shape
    m_physicsHeightmap = new Heightmap();
    m_physicsHeightmap->populate(static_cast<HeightmapMesh *>(m_mesh));

    // Motion
    SceneObjectMotionState *motion = new SceneObjectMotionState(this, Vector3(), Quaternion());

    // Body
    m_physicalBody = new RigidBody(motion, 0.0f, btVector3(0.0f, 0.0f, 0.0f), m_physicsHeightmap->shape());
    m_physicalBody->body()->setActivationState(DISABLE_DEACTIVATION);

    // Add to system
    system->addBody(m_physicalBody);
  }
}
}
