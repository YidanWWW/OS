#include "file_ops.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

// create file：if the path does not exist, it will recursively create directory at first
void createFile(const std::string &filepath) {
    fs::path p(filepath);
    fs::path parent = p.parent_path();
    if (!parent.empty() && !fs::exists(parent)) {
        if (fs::create_directories(parent)) {
            std::cout << "Created missing directories: " << parent.string() << "\n";
        } else {
            std::cerr << "Failed to create directories: " << parent.string() << "\n";
        }
    } else {
        std::cout << "Parent directory exists: "
                  << (parent.empty() ? "(none)" : parent.string()) << "\n";
    }

    std::ofstream ofs(filepath);
    if (ofs) {
        std::cout << "Created file: " << filepath << "\n";
    } else {
        std::cerr << "Error creating file: " << filepath << "\n";
    }
}

void listFiles(const std::string &path) {
    try {
        for (const auto &entry : fs::directory_iterator(path)) {
            std::cout << entry.path().filename().string() << "\n";
        }
    } catch (const fs::filesystem_error &e) {
        std::cerr << "Error listing files: " << e.what() << "\n";
    }
}

void renameFile(const std::string &oldName, const std::string &newName) {
    try {
        fs::rename(oldName, newName);
        std::cout << "Renamed " << oldName << " to " << newName << "\n";
    } catch (const fs::filesystem_error &e) {
        std::cerr << "Error renaming file: " << e.what() << "\n";
    }
}

void moveFile(const std::string &source, const std::string &destination) {
    try {
        // std::filesystem::rename will move the file if source and destination are on the same filesystem.
        fs::rename(source, destination);
        std::cout << "Moved " << source << " to " << destination << "\n";
    } catch (const fs::filesystem_error &e) {
        std::cerr << "Error moving file: " << e.what() << "\n";
    }
}

void deleteFile(const std::string &filename) {
    try {
        if (fs::remove(filename)) {
            std::cout << "Deleted " << filename << "\n";
        } else {
            std::cout << "File not found: " << filename << "\n";
        }
    } catch (const fs::filesystem_error &e) {
        std::cerr << "Error deleting file: " << e.what() << "\n";
    }
}

void copyFile(const std::string &source, const std::string &destination) {
    try {
        // use overwrite_existing option in case target file already exists
        fs::copy_file(source, destination, fs::copy_options::overwrite_existing);
        std::cout << "Copied " << source << " to " << destination << "\n";
    } catch (const fs::filesystem_error &e) {
        std::cerr << "Error copying file: " << e.what() << "\n";
    }
}
