#include "DocumentManager.h"

void Document_manager::addDocument(std::string name, int id,
                                   int license_limit) {
  Document doc = {name, id, license_limit, 0};
  documents_name[name] = doc;
  documents_id[id] = doc;
}

void Document_manager::addPatron(int patronID) { patrons[patronID] = patronID; }

int Document_manager::search(std::string name) {
  if (documents_name.find(name) != documents_name.end()) {
    return documents_name[name].id;
  }
  return 0;
}

bool Document_manager::borrowDocument(int docID, int patronID) {
  if (patrons.find(patronID) == patrons.end() ||
      documents_id.find(docID) == documents_id.end()) {
    return false;
  }
  if (borrowed_copies[docID] < documents_id[docID].license_limit) {
    borrowed_copies[docID]++;
    documents_id[docID].copies++;
    return true;
  }
  return false;
}

void Document_manager::returnDocument(int docID, int patronID) {
  if (patrons.find(patronID) != patrons.end() &&
      documents_id.find(docID) != documents_id.end()) {
    borrowed_copies[docID]--;
    documents_id[docID].copies--;
  }
}