#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include <memory>
#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // Task 3 : Exclusive Ownership 2
    // In file chatlogic.h / chatlogic.cpp, adapt the vector _nodes in a way
    // that the instances of GraphNodes to which the vector elements refer
    // are exclusively owned by the class ChatLogic. Use an appropriate type
    // of smart pointer to achieve this. Where required, make changes to
    // the code such that data structures and function parameters reflect
    // the changes. When passing the GraphNode instances to functions, make
    // sure to not transfer ownership and try to contain the changes to class
    // ChatLogic where possible.

    // data handles (owned)
    // std::vector<GraphNode *> _nodes;
    std::vector<std::unique_ptr<GraphNode>> _nodes;
    std::vector<GraphEdge *> _edges;

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */