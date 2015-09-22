#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct m_node

{
	struct m_node *prev;
	struct m_node *next;

	void		  *data;
}				node;

#endif // LINKED_LIST_H
