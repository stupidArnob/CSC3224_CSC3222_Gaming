/** @file */

#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "GL/glew.h"

/**
 * @class Shader
 * @brief Encapsulation for a single OpenGL shader.
 * @author Dan Nixon
 */
class Shader
{
public:
  Shader(std::string filename, GLuint stage);
  virtual ~Shader();

  GLuint stage() const
  {
    return m_stage;
  }

  /**
   * @brief Returns the GL shader object.
   * @return Shader object
   */
  GLuint object() const
  {
    return m_shaderObject;
  }

  /**
   * @brief Checks if the shader has been compiled.
   * @return True if shader is valid
   */
  bool valid() const
  {
    return m_valid;
  }

private:
  bool loadFile(std::string filename, std::string &into);
  bool compile(std::string filename);

  GLuint m_stage;
  GLuint m_shaderObject;

  bool m_valid;
};