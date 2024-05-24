#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
  Document doc = {name, id, license_limit, 0};
  documents_name[name] = doc;
  documents_id[id] = doc;
}

void DocumentManager::addPatron(int patronID) { patrons[patronID] = patronID; }

int DocumentManager::search(std::string name) {
  if (documents_name.find(name) != documents_name.end()) {
    return documents_name[name].id;
  }
  return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
  if (patrons.find(patronID) == patrons.end() ||
      documents_id.find(docid) == documents_id.end()) {
    return false;
  }
  if (borrowed_copies[docid] < documents_id[docid].license_limit) {
    borrowed_copies[docid]++;
    documents_id[docid].copies++;
    return true;
  }
  return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
  if (patrons.find(patronID) != patrons.end() &&
      documents_id.find(docid) != documents_id.end()) {
    borrowed_copies[docid]--;
    documents_id[docid].copies--;
  }
}