#include <iostream>
#include <sstream>
#include <vector>
#include "shell.h"
#include "file_ops.h"

void runShell() {
    std::string input;
    while (true) {
        std::cout << "myos> ";
        std::getline(std::cin, input);
        if (input.empty())
            continue;

        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (tokens.empty())
            continue;

        const std::string &command = tokens[0];
        if (command == "list") {
            std::string path = ".";
            if (tokens.size() > 1) {
                path = tokens[1];
            }
            listFiles(path);
        } else if (command == "rename") {
            if (tokens.size() < 3) {
                std::cout << "Usage: rename <oldname> <newname>\n";
            } else {
                renameFile(tokens[1], tokens[2]);
            }
        } else if (command == "move") {
            if (tokens.size() < 3) {
                std::cout << "Usage: move <source> <destination>\n";
            } else {
                moveFile(tokens[1], tokens[2]);
            }
        } else if (command == "delete") {
            if (tokens.size() < 2) {
                std::cout << "Usage: delete <filename>\n";
            } else {
                deleteFile(tokens[1]);
            }
        } else if (command == "copy") {
            // Usage: copy <source> <destination>
            if (tokens.size() < 3) {
                std::cout << "Usage: copy <source> <destination>\n";
            } else {
                copyFile(tokens[1], tokens[2]);
            }
        } else if (command == "create") {
              // create file <filename>
              if (tokens.size() < 3) {
                  std::cout << "Usage: create file <filename>\n";
              } else if (tokens[1] == "file") {
                  createFile(tokens[2]);
              } else {
                  std::cout << "Unknown create type. Only 'file' is supported.\n";
              }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Available commands: list, rename, move, delete, copy, exit\n";
        }
    }
}
