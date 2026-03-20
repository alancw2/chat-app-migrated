#include "../../include/Commands.hpp"
#include "../../include/ConnectionHandler.hpp"
#include <iostream>
#include <format>

void Commands::joinNewRoom(std::shared_ptr<ConnectionHandler> conn, std::string& newRoom) {
    newRoom.erase(std::remove(newRoom.begin(), newRoom.end(), '\n'), newRoom.end());
    newRoom.erase(std::remove(newRoom.begin(), newRoom.end(), '\r'), newRoom.end());
    newRoom.erase(newRoom.find_last_not_of(" ") + 1);

    if (!newRoom.empty()) {
        conn->changeRoom(newRoom);
    }
}
void Commands::setNewNickname(std::shared_ptr<ConnectionHandler> conn, std::string& newNick) {
    newNick.erase(std::remove(newNick.begin(), newNick.end(), '\n'), newNick.end());
    newNick.erase(std::remove(newNick.begin(), newNick.end(), '\r'), newNick.end());
    newNick.erase(newNick.find_last_not_of(" ") + 1);

    if (newNick != "") {
        std::cerr << "0 - nickname change success" << std::endl;
        conn->setClientLabel(newNick);
        return;
    } 
    std::cerr << "1 - nickname change fail (bad nickname)" << std::endl;
    return;
    

} 
std::string Commands::getUsersInRoom(std::shared_ptr<ConnectionHandler> conn, std::vector<std::shared_ptr<ConnectionHandler>>& connections) {
    std::string users = "";
    for (const auto& connection : connections) {
        if (connection->getCurrentRoom() == conn->getCurrentRoom()) {
            users += connection->getClientLabel();
            users += '\n';
        }
    }
    return users;
    
}
bool Commands::nickAvailable(std::vector<std::shared_ptr<ConnectionHandler>>& connections, const std::string& newNick) {
    for (const auto& connection : connections) {
        if (connection->getClientLabel() == newNick) {
            std::cerr << "2 - nickname change fail (taken nickname)" << std::endl;
            return false;
        }
    }
    return true;
}
