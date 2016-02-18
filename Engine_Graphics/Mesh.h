/** @file */

#pragma once

#include <vector>
#include <string>
#include <fstream>

#include <GL/glew.h>
#include <SDL_opengl.h>

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

using std::ifstream;
using std::string;

/**
 * @enum MeshBuffer
 * @brief Describes the type of data held in a buffer.
 */
enum MeshBuffer
{
  VERTEX_BUFFER = 0,
  COLOUR_BUFFER = 1,
  TEXTURE_BUFFER,
  NORMAL_BUFFER,
  TANGENT_BUFFER,
  INDEX_BUFFER,
  MAX_BUFFER
};

/**
 * @class Mesh
 * @brief Wrapper around OpenGL primitives, geometry and related OGL functions.
 * @author Rich Davison, Dan Nixon
 *
 * Modified from the original nclgl library.
 */
class Mesh
{
public:
  static Mesh *GenerateTriangle();
  static Mesh *GenerateLine(const Vector3 &from, const Vector3 &to);
  static Mesh *GenerateRing2D(float radiusOuter, float radiusInner,
                              int resolution = 64);
  static Mesh *LoadASCIIMeshFile(const string &filename);
  static Mesh *LoadModelFile(const string &filename, size_t meshIdx);

  static std::pair<Vector3, Vector3> GetBoundingBox(Mesh *m);

  Mesh();
  virtual ~Mesh();

  virtual void draw();

protected:
  void generateNormals();
  void bufferData();

  GLuint m_type;                     //!< Type of primitives used in mesh
  GLuint m_arrayObject;              //!< OGL array object for this mesh
  GLuint m_bufferObject[MAX_BUFFER]; //!< OGL buffer objects for each buffer
                                     //!  used in this mesh
  GLuint m_numVertices;              //!< Number of vertices for the mesh
  GLuint m_numIndices;               //!< Number of indices for the mesh

  Vector3 *m_vertices;      //!< Pointer to vertex position data
  Vector4 *m_colours;       //!< Pointer to vertex colour data
  Vector2 *m_textureCoords; //!< Pointer to vertex texture coordinate data
  Vector3 *m_normals;       //!< Pointer to vertex normals data
  Vector3 *m_tangents;      //!< Pointer to vertex tangents data
  size_t *m_indices;        //!< Pointer to vertex indices data
};