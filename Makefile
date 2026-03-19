CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pthread

SERVER_TARGET = server
CLIENT_TARGET = client

SRC_DIR = src
INC_DIR = include

# Server-specific files
SERVER_OBJS = $(SRC_DIR)/main.o $(SRC_DIR)/ConnectionHandler.o $(SRC_DIR)/Commands.o
# Client-specific files
CLIENT_OBJS = $(SRC_DIR)/Client.o

all: $(SERVER_TARGET) $(CLIENT_TARGET)

# Link the Server
$(SERVER_TARGET): $(SERVER_OBJS)
	$(CXX) $(CXXFLAGS) $(SERVER_OBJS) -o $(SERVER_TARGET)

# Link the Client
$(CLIENT_TARGET): $(CLIENT_OBJS)
	$(CXX) $(CXXFLAGS) $(CLIENT_OBJS) -o $(CLIENT_TARGET)

# Compile Server Objects
$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/ConnectionHandler.hpp $(INC_DIR)/Commands.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(SRC_DIR)/main.o

$(SRC_DIR)/ConnectionHandler.o: $(SRC_DIR)/ConnectionHandler.cpp $(INC_DIR)/ConnectionHandler.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/ConnectionHandler.cpp -o $(SRC_DIR)/ConnectionHandler.o

$(SRC_DIR)/Commands.o: $(SRC_DIR)/Commands/Commands.cpp $(INC_DIR)/Commands.hpp $(INC_DIR)/ConnectionHandler.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Commands/Commands.cpp -o $(SRC_DIR)/Commands.o

$(SRC_DIR)/Client.o: $(SRC_DIR)/Client.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Client.cpp -o $(SRC_DIR)/Client.o

clean:
	rm -f $(SRC_DIR)/*.o $(SERVER_TARGET) $(CLIENT_TARGET)
	rm -f *.o main
run_server: $(SERVER_TARGET)
	./$(SERVER_TARGET)

run_client: $(CLIENT_TARGET)
	./$(CLIENT_TARGET)