#ifndef CONTACLISTPROVIDER_H
#define CONTACLISTPROVIDER_H

#include <string>
#include <vector>
#include <utility>

class ContacListProvider
{
public:
  ContacListProvider();
  ~ContacListProvider();

  std::string getFirstName(int contactID);
  std::string getSecondName(int contactID);
  unsigned int getID(int contactID);

  void setID();

  void addContact(std::string, std::string);

  unsigned int getNumberOfContacts();

  bool call(unsigned int id);
private:
  unsigned int ID;
  std::vector<std::pair<std::pair<std::string, std::string>, unsigned int>> contact;
};

#endif // CONTACLISTPROVIDER_H
