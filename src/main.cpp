#include <iostream>
#include <optional>
#include <stdexcept>

#include "Agenda/Agenda.hpp"
#include "Contact/Contact.hpp"
#include "StringUtils/StringUtils.hpp"

using namespace std;

Agenda agenda("contacts.csv");

void newContact() {
  string name, phone, email;

  cout << "Insira os dados do contato a seguir para cadatrá-lo" << endl;

  cout << "Nome: ";
  getline(cin, name);
  name = StringUtils::trim(name);

  cout << "Telefone: ";
  cin >> phone;
  cin.ignore();
  phone = StringUtils::trim(phone);

  cout << "Email: ";
  cin >> email;
  cin.ignore();
  email = StringUtils::trim(email);

  agenda.add(Contact(name, phone, email));
}

void searchContact() {
  string target;
  optional<Contact> optC;

  cout << "Nome do contato procurado: ";
  getline(cin, target);
  target = StringUtils::trim(target);

  optC = agenda.findContactByName(target);

  if (!optC.has_value()) {
    cout << "Contato não encontrado" << endl;
    return;
  }

  cout << optC.value().toString() << endl;
}

void removeContact() {
  string target;

  cout << "Nome do contato a ser removido: ";
  getline(cin, target);
  target = StringUtils::trim(target);

  agenda.remove(target);
}

int main() {
  string action;
  cout << "\033[2J\033[1;1H" << endl;

  try {
    agenda.load();

    do {
      cout << "\n[0] Salvar e Sair\n[1] Inserir contato\n[2] Buscar contato\n[3] Exibir contatos\n[4] Remover contato" << endl;
      cout << "Selecione sua ação: ";

      getline(cin, action);
      action = StringUtils::trim(action);

      if (action == "0") {
        agenda.save();
        cout << "Porgrama encerrado" << endl;

      } else if (action == "1") {
        newContact();

      } else if (action == "2") {
        searchContact();

      } else if (action == "3") {
        if (agenda.empty()) {
          cout << "Agenda de contatos vazia" << endl;
          continue;
        }

        cout << " ===== CONTATOS ===== " << endl;
        agenda.printAgenda();

      } else if (action == "4") {
        removeContact();

      } else {
        cout << "Opção não suportada" << endl;
      }
    } while (action != "0");

  } catch (const exception& e) {
    cerr << e.what() << endl;
  }

  return 0;
}
