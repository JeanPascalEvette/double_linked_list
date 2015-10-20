
#include <iostream>

// This is your
template <class Type> 
struct typed_item {
	// link to next item in the list or "head"
	typed_item *prev;

  // link to the previous item or "head"
	typed_item *next;

  // the value in the list
  int value;

  typed_item(int value=0) : value(value) {}
};
    
// The 
template <class Type>
class double_linked_list {
	typedef typed_item<Type> item;

public:
  // placeholder for you to replace.
  item* tail = nullptr;

  // The head item is the first and last in the list.
  // head <-> one <-> two <-> three <-> head
  item head;

  double_linked_list() {
    // at the start, the head points to itself.
    head.prev = head.next = tail = &head;
  }

  item *insert(int value) {
    item *new_item = new item(value);
    new_item->prev = &head;
    new_item->next = (&head)->next; // fill this in
	if ((&head)->next == &head)
		tail = new_item;
	(&head)->next->prev = new_item;
    head.prev = tail; // fill this in
    head.next = new_item;
	return new_item;
  }

  item *insert_after(item *prev, int value) {
    item *next = prev->next;
    item *new_item = new item(value);
    new_item->prev = prev;
    new_item->next = prev->next; // fill this in
    prev->next = new_item; // fill this in
    next->prev = new_item; // fill this in
	return new_item;
  }

  item *find(int value) {
     // write a loop here to return the first element with this value
	  item* current_item = &head;
	  do
	  {
		  if (current_item->value == value)
			  return current_item;
		  current_item = current_item->next;
	  } while (current_item != &head);
	  return nullptr;
  }

  item *get_first() {
     return head.next;
  }

  void remove(item *victim) {
      item *prev = victim->prev;
      item *next = victim->next;
      victim->prev = nullptr; // fill this in
      victim->next = nullptr; // fill this in
      prev->next = next; // fill this in
      next->prev = prev; // fill this in
  }

  void dump(std::ostream &os) {
    for (item *it = head.next; it != &head; it = it->next) {
      os << "item " << it << " has value " << it->value << "\n";
    }
	os << "---------\n";
  }
    
  // unit test
  void unit_test() {
    double_linked_list my_list;
    my_list.insert(1);
    my_list.insert(2);
    my_list.insert(3);
    my_list.insert(4);
    my_list.dump(std::cout);
    auto two = my_list.find(2);
    my_list.remove(two);
    my_list.dump(std::cout);
    auto three = my_list.find(3);
    my_list.insert_after(three, 33);
    my_list.dump(std::cout);
  }
};

int main() {
  double_linked_list<float> my_list;
  my_list.unit_test();
}

