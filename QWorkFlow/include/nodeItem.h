#ifndef NODEITEM_H
#define NODEITEM_H

#include <iostream>

#define HASH std::string

class NodeItem {
 public:
  /// @brief Init NodeItem
  NodeItem(HASH HASH_item);
  bool NodeLegalCheck(HASH HASH_item);
  bool CreateNode(HASH HASH_item);
};

#endif