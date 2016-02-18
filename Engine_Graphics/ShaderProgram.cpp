#include "ShaderProgram.h"

#include "Shader.h"
#include "Mesh.h"

ShaderProgram::ShaderProgram()
: m_valid(false)
{
  for (size_t i = 0; i < NUM_SHADERS; i++)
    m_shaders[i] = NULL;

  m_program = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
  for (size_t i = 0; i < NUM_SHADERS; i++)
    glDetachShader(m_program, m_shaders[i]->object());

  glDeleteProgram(m_program);
}

bool ShaderProgram::addShader(Shader * s)
{
  for (size_t i = 0; i < NUM_SHADERS; i++)
  {
    if (m_shaders[i] == NULL)
    {
      m_shaders[i] = s;
      return true;
    }
  }

  return false;
}

bool ShaderProgram::link()
{
  if (m_valid)
    return false;

  glBindAttribLocation(m_program, VERTEX_BUFFER, "position");
  glBindAttribLocation(m_program, COLOUR_BUFFER, "colour");
  glBindAttribLocation(m_program, NORMAL_BUFFER, "normal");
  glBindAttribLocation(m_program, TANGENT_BUFFER, "tangent");
  glBindAttribLocation(m_program, TEXTURE_BUFFER, "texCoord");

  for (size_t i = 0; i < NUM_SHADERS; i++)
  {
    if (m_shaders[i] != NULL)
    {
      if (!m_shaders[i]->valid())
        return false;

      glAttachShader(m_program, m_shaders[i]->object());
    }
  }

  glLinkProgram(m_program);

  GLint status;
  glGetProgramiv(m_program, GL_LINK_STATUS, &status);

  if (status == GL_FALSE)
  {
    std::cout << "Linking failed! Error log as follows:" << std::endl;
    char error[2048];
    glGetProgramInfoLog(m_program, sizeof(error), NULL, error);
    std::cout << error << std::endl;
    return false;
  }

  m_valid = (status != GL_FALSE);
  return m_valid;
}