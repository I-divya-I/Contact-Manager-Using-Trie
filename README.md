# 📞 Contact Manager Using Trie (C++)

A Command-Line Interface (CLI) Contact Manager written in C++ that uses the **Trie data structure** for efficient prefix-based search. This project demonstrates real-world usage of core Data Structures and Algorithms (DSA) concepts like Tries, Hash Maps, and Recursion.

---

## 🚀 Features

- ✅ Add a new contact with name and number
- 🔍 Search contacts by name prefix (auto-complete)
- 🧾 Display all saved contacts
- ✏️ Edit existing contacts (name or number)
- ❌ Delete contacts by name

---

## 💡 Data Structures Used

| Concept          | Usage                                           |
|------------------|--------------------------------------------------|
| **Trie (Prefix Tree)** | Efficient storage and prefix search of names |
| **Hash Map (`unordered_map`)** | Store contact details (name ➝ number)     |
| **Recursion**     | Delete operation in Trie                       |
| **Vectors**       | Store and display search results               |

---

## 🧠 Why Trie?

Trie allows for:
- Fast prefix-based searching (O(length of prefix))
- Efficient string storage and retrieval
- Auto-complete-like behavior for names

---

## 📷 Sample Output

```text
1. Add Contact
2. Search by Name Prefix
3. Display All Contacts
4. Delete Contact
5. Edit Contact
6. Exit

> 1
Enter name: Alice
Enter number: 9998887777

> 1
Enter name: Alina
Enter number: 8887776666

> 2
Enter prefix: Al
Alice : 9998887777
Alina : 8887776666

> 4
Enter name to delete: Alina

> 3
Alice : 9998887777
