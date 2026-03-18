#ifndef CONNECTIONHANDLER_HPP
#define CONNECTIONHANDLER_HPP

#include <string>

class ConnectionHandler {
public:
    ConnectionHandler(int clientSocket, const std::string& clientLabel);
    void sendMessage(std::string& message);
    std::string getClientLabel() const;
    int getSocket() const;
    void setClientLabel(std::string newNick);

private:
    int clientSocket;
    std::string clientLabel;
};

#endif