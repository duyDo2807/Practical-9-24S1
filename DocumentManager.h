#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <iostream>
#include <unordered_map>
#include <vector>

class Document_manager {
 private:
  struct Document {
    std::string name;
    int id;
    int license_limit;
    int copies;
  };

  std::unordered_map<std::string, Document> documents_name;
  std::unordered_map<int, Document> documents_id;
  std::unordered_map<int, int> borrowed_copies;
  std::unordered_map<int, bool> patrons;

 public:
  void addDocument(std::string name, int id, int license_limit);
  void addPatron(int patronID);
  int search(std::string name);
  bool borrowDocument(int docID, int patronID);
  void returnDocument(int docID, int patronID);
};

#endif