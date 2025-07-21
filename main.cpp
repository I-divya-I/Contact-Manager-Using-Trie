#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class ContactTrie {
    TrieNode* root;
    unordered_map<string, string> phoneBook; // name -> number

    void displayHelper(TrieNode* node, string prefix, vector<string>& result) {
        if (node->isEndOfWord)
            result.push_back(prefix);
        for (auto& child : node->children)
            displayHelper(child.second, prefix + child.first, result);
    }

public:
    ContactTrie() {
        root = new TrieNode();
    }

    void insert(string name, string number) {
        TrieNode* curr = root;
        for (char c : name) {
            if (!curr->children[c])
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
        phoneBook[name] = number;
    }

    void searchPrefix(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (!curr->children[c]) {
                cout << "No contact found!\n";
                return;
            }
            curr = curr->children[c];
        }
        vector<string> matches;
        displayHelper(curr, prefix, matches);
        if (matches.empty()) {
            cout << "No contact found!\n";
            return;
        }
        for (string name : matches)
            cout << name << " : " << phoneBook[name] << endl;
    }

    void displayAll() {
        vector<string> contacts;
        displayHelper(root, "", contacts);
        if (contacts.empty()) {
            cout << "No contacts saved yet.\n";
            return;
        }
        for (string name : contacts)
            cout << name << " : " << phoneBook[name] << endl;
    }

    bool deleteContact(string name) {
        if (phoneBook.find(name) == phoneBook.end()) {
            cout << "Contact not found.\n";
            return false;
        }
        deleteHelper(root, name, 0);
        phoneBook.erase(name);
        cout << "Contact deleted.\n";
        return true;
    }

    bool deleteHelper(TrieNode* node, string name, int depth) {
        if (!node) return false;
        if (depth == name.length()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            return node->children.empty();
        }
        char ch = name[depth];
        if (deleteHelper(node->children[ch], name, depth + 1)) {
            delete node->children[ch];
            node->children.erase(ch);
            return !node->isEndOfWord && node->children.empty();
        }
        return false;
    }

    void editContact(string oldName) {
        if (phoneBook.find(oldName) == phoneBook.end()) {
            cout << "Contact not found.\n";
            return;
        }

        string newName, newNumber;
        cout << "Enter new name (or same): ";
        cin >> newName;
        cout << "Enter new number: ";
        cin >> newNumber;

        deleteContact(oldName);
        insert(newName, newNumber);
        cout << "Contact updated.\n";
    }
};

int main() {
    ContactTrie ct;
    int choice;
    string name, number;

    while (true) {
        cout << "\n1. Add Contact\n2. Search by Name Prefix\n3. Display All Contacts\n";
        cout << "4. Delete Contact\n5. Edit Contact\n6. Exit\n> ";
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter number: ";
                cin >> number;
                ct.insert(name, number);
                break;

            case 2:
                cout << "Enter name prefix to search: ";
                cin >> name;
                ct.searchPrefix(name);
                break;

            case 3:
                ct.displayAll();
                break;

            case 4:
                cout << "Enter contact name to delete: ";
                cin >> name;
                ct.deleteContact(name);
                break;

            case 5:
                cout << "Enter contact name to edit: ";
                cin >> name;
                ct.editContact(name);
                break;

            case 6:
                cout << "Exiting Contact Manager...\n";
                return 0;

            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
