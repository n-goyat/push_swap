#include "./includes/push_swap.h"
t_clst	*new_node(int	value)
{
	t_clst		*new;

	new = (t_clst *)malloc(sizeof(t_clst));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

//t_stcks	*init_list(int argc, char **argv, t_stcks *stacks)
//{
//	int count;
//	t_clst *tmp;
//	t_clst *head;
//
//	stacks->stack_b = NULL;
//	stacks->size_b = 0;
//	stacks->size_a = argc - 1;
//	if (argc == 2)
//		count = 0;
//	else
//		count = 1;
//	stacks->stack_a = new_node(ft_atoi(argv[count]));
//	if (!stacks->stack_a)
//		return (NULL);
//	head = stacks->stack_a;
//	tmp = stacks->stack_a;
//	while (++count < argc) {
//		tmp->next = new_node(ft_atoi(argv[count]));
//		if (!tmp->next) {
//			// Handle memory cleanup if allocation fails
//			free_stack(stacks);
//			return (NULL);
//		}
//		tmp = tmp->next;
//	}
//	tmp->next = head; // Make the list circular
//	return (stacks);
//}
void create_circular_list(int argc, char **argv, t_stcks *stacks, int count)
{
    t_clst *tmp;
    t_clst *head;
    stacks->stack_a = new_node(ft_atoi(argv[count]));
    if (!stacks->stack_a)
        return;
    head = stacks->stack_a;
    tmp = stacks->stack_a;
    while (++count < argc)
    {
        tmp->next = new_node(ft_atoi(argv[count]));
        if (!tmp->next)
        {
            free_stack(stacks);
            return;
        }
        tmp = tmp->next;
    }
    tmp->next = head;
}

t_stcks *init_list(int argc, char **argv, t_stcks *stacks)
{
    stacks->stack_b = NULL;
    stacks->size_b = 0;
    stacks->size_a = argc - 1;
    int count = (argc == 2) ? 0 : 1;
    create_circular_list(argc, argv, stacks, count);
    return (stacks);
}

void	free_stack(t_stcks *stacks)
{
    t_clst *tmp;
    t_clst *next;

    if (stacks->stack_a)
    {
        tmp = stacks->stack_a->next;
        while (tmp != stacks->stack_a)
        {
            next = tmp->next;
            free(tmp);
            tmp = next;
        }
        free(stacks->stack_a);
    }
    if (stacks->stack_b)
    {
        tmp = stacks->stack_b->next;
        while (tmp != stacks->stack_b)
        {
            next = tmp->next;
            free(tmp);
            tmp = next;
        }
        free(stacks->stack_b);
    }
}
