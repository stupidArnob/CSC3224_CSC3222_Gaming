/**
 * @file
 * @author Dan Nixon (120263697)
 *
 * For CSC3222 Project 2.
 */

#include "CppUnitTest.h"

#include <string>

#include <Simulation_PathFinding/GraphLoader.h>

/**
 * @def FP_ACC
 * @brief Accuracy for floating point comparison.
 */
#define FP_ACC 0.001f

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine::Maths;

// clang-format off
namespace Simulation
{
namespace PathFinding
{
namespace Test
{
#ifndef DOXYGEN_SKIP
TEST_CLASS(GraphLoaderTest)
{
public:
  TEST_METHOD(GraphLoader_FailNoFile)
  {
    std::vector<Node *> nodes;
    std::vector<Edge *> edges;

    // Test load
    Assert::IsFalse(GraphLoader::LoadGraph(nodes, edges, "../../../../resources/notafile.dat"));
    Assert::AreEqual((size_t)0, nodes.size());
    Assert::AreEqual((size_t)0, edges.size());
  }

  TEST_METHOD(GraphLoader_LoadGraphFromFile)
  {
    std::vector<Node *> nodes;
    std::vector<Edge *> edges;

    // Test load
    Assert::IsTrue(GraphLoader::LoadGraph(nodes, edges, "../../../../resources/buckminsterfullerene.dat"));
    Assert::AreEqual((size_t)60, nodes.size());
    Assert::AreEqual((size_t)90, edges.size());

    // Test nodes

    // 0:[0,1,4.85410196625]
    Assert::AreEqual(std::string("0"), nodes[0]->id());
    Assert::AreEqual(0.0f, nodes[0]->position()[0], FP_ACC);
    Assert::AreEqual(1.0f, nodes[0]->position()[1], FP_ACC);
    Assert::AreEqual(4.85410196625f, nodes[0]->position()[2], FP_ACC);

    // 30:[1.61803398875,-2,4.2360679775]
    Assert::AreEqual(std::string("30"), nodes[30]->id());
    Assert::AreEqual(1.61803398875f, nodes[30]->position()[0], FP_ACC);
    Assert::AreEqual(-2.0f, nodes[30]->position()[1], FP_ACC);
    Assert::AreEqual(4.2360679775f, nodes[30]->position()[2], FP_ACC);

    // 59:[-3.2360679775,-1,-3.61803398875]]
    Assert::AreEqual(std::string("59"), nodes[59]->id());
    Assert::AreEqual(-3.2360679775f, nodes[59]->position()[0], FP_ACC);
    Assert::AreEqual(-1.0f, nodes[59]->position()[1], FP_ACC);
    Assert::AreEqual(-3.61803398875f, nodes[59]->position()[2], FP_ACC);

    // Test edges

    // E0:0,2
    Assert::AreEqual(std::string("E0"), edges[0]->id());
    Assert::IsTrue(nodes[0] == edges[0]->nodeA());
    Assert::IsTrue(nodes[2] == edges[0]->nodeB());

    // E29:35,3
    Assert::AreEqual(std::string("E29"), edges[29]->id());
    Assert::IsTrue(nodes[35] == edges[29]->nodeA());
    Assert::IsTrue(nodes[3] == edges[29]->nodeB());

    // E59:46,47
    Assert::AreEqual(std::string("E59"), edges[59]->id());
    Assert::IsTrue(nodes[46] == edges[59]->nodeA());
    Assert::IsTrue(nodes[47] == edges[59]->nodeB());

    // E89:53,55
    Assert::AreEqual(std::string("E89"), edges[89]->id());
    Assert::IsTrue(nodes[53] == edges[89]->nodeA());
    Assert::IsTrue(nodes[55] == edges[89]->nodeB());
  }
};
#endif /* DOXYGEN_SKIP */
}
}
}
