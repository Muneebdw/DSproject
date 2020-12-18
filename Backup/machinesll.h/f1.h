#include "AVL.h"

class Machine_node {
  public:
    int key;
  int data;
  Machine_node * next;
 
  Machine_node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Machine_node(int k, int d) {
    key = k;
    data = d;
  }
};
 
class Machines {
  public:
    Machine_node * head;
 
  Machines() {
    head = NULL;
  }
 
  Machine_node * nodeExists(int k) {
 
    Machine_node * temp = NULL;
    Machine_node * ptr = head;
 
    if (ptr == NULL) {
      return temp;
    } else {
      do {
        if (ptr->key == k) {
          temp = ptr;
        }
        ptr = ptr->next;
 
      } while (ptr != head);
      return temp;
    }
 
  }
 
  void AddMahcine(Machine_node * new_node) {
    if (nodeExists(new_node->key) != NULL) {
      cout << "Machine_node Already exists with key value : " <<
        new_node->key <<
        ". Append another Machine_node with different Key value" <<
        endl;
    } else {
      if (head == NULL) {
        head = new_node;
        new_node->next = head;
        cout << "Machine_node Appended at first Head position" << endl;
      } else {
        Machine_node * ptr = head;
        while (ptr->next != head) {
          ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = head;
        cout << "Machine_node Appended" << endl;
      }
    }
 
  }
  void prependNode(Machine_node * new_node) {
    if (nodeExists(new_node->key) != NULL) {
      cout << "Machine_node Already exists with key value : " <<
        new_node->key <<
        ". Append another Machine_node with different Key value" <<
        endl;
    } else {
      if (head == NULL) {
        head = new_node;
        new_node->next = head;
        cout << "Machine_node Prepended at first Head position" << endl;
      } else {
        Machine_node * ptr = head;
        while (ptr->next != head) {
          ptr = ptr->next;
        }
 
        ptr->next = new_node;
        new_node->next = head;
        head = new_node;
        cout << "Machine_node Prepended" << endl;
      }
 
    }
  }
 
  void insertNodeAfter(int k, Machine_node * new_node) {
    Machine_node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No Machine_node exists with key value OF: " << k << endl;
    } else {
      if (nodeExists(new_node->key) != NULL) {
        cout << "Machine_node Already exists with key value : " <<
          new_node->key <<
          ". Append another Machine_node with different Key value" <<
          endl;
      } else {
        if (ptr->next == head) {
          new_node->next = head;
          ptr->next = new_node;
          cout << "Machine_node Inserted at the End" << endl;
        } else {
          new_node->next = ptr->next;
          ptr->next = new_node;
          cout << "Machine_node Inserted in between" << endl;
        }
 
      }
    }
  }
 
  void DeleteMachine(int k) {
    Machine_node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No Machine_node exists with key value OF : " << k <<
        endl;
    } else {
 
      if (ptr == head) {
        if (head->next == NULL) {
          head = NULL;
          cout << "Head Machine_node Unlinked... List Empty";
        } else {
          Machine_node * ptr1 = head;
          while (ptr1->next != head) {
            ptr1 = ptr1->next;
          }
          ptr1->next = head->next;
          head = head->next;
          cout << "Machine_node UNLINKED with keys value : " << k << endl;
        }
      } else {
        Machine_node * temp = NULL;
        Machine_node * prevptr = head;
        Machine_node * currentptr = head->next;
        while (currentptr != NULL) {
          if (currentptr->key == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr->next;
            currentptr = currentptr->next;
          }
        }
 
        prevptr->next = temp->next;
        cout << "Machine_node UNLINKED with keys value : " << k << endl;
 
      }
 
    }
 
  }
  void UpdateMachine(int k, int new_data) {
 
    Machine_node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr->data = new_data;
      cout << "Machine_node Data Updated Successfully" << endl;
    } else {
      cout << "Machine_node Doesn't exist with key value : " << k << endl;
    }
 
  }
 
  void displaymachines() {
    if (head == NULL) {
      cout << "No Nodes in Circular Linked List";
    } else {
      cout << endl << "head address : " << head << endl;
      cout << "Circular Linked List Values : " << endl;
 
      Machine_node * temp = head;
 
      do {
        cout << "(" << temp->key << "," << temp->data << "," << temp->next << ") --> ";
        temp = temp->next;
      } while (temp != head);
    }
 
  }
 
};