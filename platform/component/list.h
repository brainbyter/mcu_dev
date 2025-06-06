// Copyright @2019 Pony AI Inc. All rights reserved.

#ifndef COMPONENT_LIST_H_
#define COMPONENT_LIST_H_

#include <stdbool.h>

#include "common/mcu/system/init.h"

typedef struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
} list_node_t;

bool ListInit(list_node_t *l);
bool ListIsEmpty(const list_node_t *l);
bool ListInsertAfter(list_node_t *l, list_node_t *n);
bool ListInsertBefore(list_node_t *l, list_node_t *n);
bool ListRemove(list_node_t *n);
uint32_t ListGetLength(const list_node_t *l);

#define list_entry(node, type, member) container_of(node, type, member)
#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#endif  // COMPONENT_LIST_H_
