/**
 * @file
 * @author Dan Nixon
 */

#include "IMenu.h"

#include <Matrix4.h>
#include <Shaders.h>

using namespace Engine::Common;
using namespace Engine::Graphics;
using namespace Engine::Maths;

namespace Engine
{
namespace UIMenu
{
  IMenu::IMenu(TTF_Font *font, int screenWidth, int screenHeight, float textHeight)
      : GraphicalScene(new SceneObject("/"),
                       Matrix4::BuildViewMatrix(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, -1.0f)),
                       Matrix4::Orthographic(0.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f))
      , m_font(font)
      , m_textHeight(textHeight)
      , m_screenWidth(screenWidth)
      , m_screenHeight(screenHeight)
  {
    // Create shaders
    m_shaderProg = new ShaderProgram();
    m_shaderProg->addShader(new VertexShader("../resources/shader/vert_simple.glsl"));
    m_shaderProg->addShader(new FragmentShader("../resources/shader/frag_tex.glsl"));
    m_shaderProg->link();

    // Defualt colours
    m_itemColours[MenuItemState::NORMAL] = Colour(1.0f, 1.0f, 1.0f, 1.0f);
    m_itemColours[MenuItemState::HOVER] = Colour(0.8f, 0.9f, 1.0f, 1.0f);
    m_itemColours[MenuItemState::DISABLED] = Colour(0.5f, 0.5f, 0.5f, 1.0f);
  }

  IMenu::~IMenu()
  {
  }

  Vector3 IMenu::position() const
  {
    return m_root->modelMatrix().positionVector();
  }

  void IMenu::setPosition(const Vector3 &position)
  {
    m_root->setModelMatrix(Matrix4::Translation(position));
  }

  bool IMenu::visible() const
  {
    return m_root->active();
  }

  void IMenu::show()
  {
    m_root->setActive(true, std::numeric_limits<size_t>::max());

    // Enable mouse event handling
    enable();
  }

  void IMenu::hide()
  {
    // Disable mouse event handling
    disable();

    m_root->setActive(false, std::numeric_limits<size_t>::max());
  }

  void IMenu::handleButton(const SDL_MouseButtonEvent &e)
  {
    // TODO
    std::cout << "click" << std::endl;
  }

  void IMenu::handleMotion(const SDL_MouseMotionEvent &e)
  {
    std::pair<float, float> pos = MouseHandler::GetNormalisedPos(e, m_screenWidth, m_screenHeight);
    const Vector3 mousePos(pos.first, pos.second, 0.0f);
    checkMouseOver(mousePos, m_root);
  }

  void IMenu::checkMouseOver(const Vector3 &mousePos, SceneObject *node)
  {
    for (SceneObject::SceneObjectListIter it = node->children().begin(); it != node->children().end(); ++it)
    {
      MenuItem *obj = static_cast<MenuItem *>(*it);
      Mesh * m = obj->mesh();
      if (obj->state() != MenuItemState::DISABLED)
      {
        auto bb = m->boundingBox();
        bb += obj->worldTransform().positionVector();

        if (bb.pointInside(mousePos))
          obj->setState(MenuItemState::HOVER);
        else
          obj->setState(MenuItemState::NORMAL);
      }
    }
  }
}
}