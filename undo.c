#include <uvsqgraphics.h>
#include "struct.h"

void pile_push(Pile ** p_pile, int data)
{
	Pile *p_new = malloc(sizeof *p_new);
	if (p_new == NULL) {fprintf(stderr,"La mémoire n'a pas pus être alloué pour la pile");}
	if (p_new != NULL) {
		p_new->data = data;
		p_new->prev = *p_pile;
		*p_pile = p_new;

	}
}

int pile_pop(Pile ** p_pile)
{
	int ret = 0;
	if (p_pile != NULL) {
		Pile *temporary = (*p_pile)->prev;
		ret = (*p_pile)->data;
		free(*p_pile), *p_pile = NULL;
		*p_pile = temporary;
	}
	return ret;
}
