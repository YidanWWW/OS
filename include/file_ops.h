#ifndef FILE_OPS_H
#define FILE_OPS_H

#include <string>

void createFile(const std::string &filepath);

// Lists all files in the given directory.
void listFiles(const std::string &path);

// Renames a file from oldName to newName.
void renameFile(const std::string &oldName, const std::string &newName);

// Moves a file from source to destination (using rename under the hood).
void moveFile(const std::string &source, const std::string &destination);

// Deletes the specified file.
void deleteFile(const std::string &filename);

//copy file
void copyFile(const std::string &source, const std::string &destination);

#endif // FILE_OPS_H
