#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H
#include <memory>
#include <vector>

int launcher(std::vector<std::string> &files);
int countTotalPages(std::shared_ptr<std::ifstream> &p);
void findPage(std::shared_ptr<std::ifstream> &p, int pageNumber);
int findFrame(std::shared_ptr<std::ifstream> p);
#endif //MEMORYMANAGER_H
