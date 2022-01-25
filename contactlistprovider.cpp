#include "contactlistprovider.h"
#include <cstdlib>

ContacListProvider::ContacListProvider() {

}

std::string ContacListProvider::getFirstName(int contactID) {
  return contact.at(contactID).first.first;
}

std::string ContacListProvider::getSecondName(int contactID) {
  return contact.at(contactID).first.second;
}

void ContacListProvider::setID() {
  ID = rand();
}

unsigned int ContacListProvider::getID(int contactID) {
  return contact.at(contactID).second;
}

void ContacListProvider::addContact(std::string firstName, std::string secondName) {
  setID();
  contact.push_back(std::make_pair(std::make_pair(firstName, secondName),ID));
}

bool ContacListProvider::call(unsigned int id) {
  return false;
}

unsigned int ContacListProvider::getNumberOfContacts() {
  return contact.size();
}

ContacListProvider::~ContacListProvider() {

}
