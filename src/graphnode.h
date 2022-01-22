#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"

// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // Task 4 : Moving Smart Pointers
    // In files chatlogic.h / chatlogic.cpp and graphnode.h / graphnode.cpp
    // change the ownership of all instances of GraphEdge in a way such that
    // each instance of GraphNode exclusively owns the outgoing GraphEdges
    // and holds non-owning references to incoming GraphEdges. Use appropriate
    // smart pointers and where required, make changes to the code such that
    // data structures and function parameters reflect the changes. When
    // transferring ownership from class ChatLogic, where all instances of
    // GraphEdge are created, into instances of GraphNode, make sure to
    // use move semantics.

    // data handles (owned)
    std::vector<GraphEdge *> _childEdges; // edges to subsequent nodes (outgoing?)
    // std::vector<std::unique_ptr<GraphEdge>> _childEdges; // edges to subsequent nodes (outgoing?)

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes (incoming?)
    ChatBot *_chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(GraphEdge *edge);

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot *chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */