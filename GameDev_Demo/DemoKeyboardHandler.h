/**
* @file
* @author Dan Nixon
*/

#pragma once

#include <KeyboardHandler.h>

#include <iostream>

/**
 * @class DemoKeyboardHandler
 * @brief Demonstraton of a keyboard event handler.
 * @author Dan Nixon
 */
class DemoKeyboardHandler : public Engine::Input::KeyboardHandler
{
public:
  DemoKeyboardHandler()
  {
  }

  virtual ~DemoKeyboardHandler()
  {
  }

  /**
   * @copydoc KeyboardHandler::handleKey
   */
  void handleKey(const SDL_KeyboardEvent &e)
  {
    std::cout << "State: "
              << ((e.state == SDL_PRESSED) ? "pressed" : "released")
              << std::endl
              << "Key: " << e.keysym.sym << std::endl;
  }
};