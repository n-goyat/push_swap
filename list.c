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

t_stcks	*init_list(int argc, char **argv, t_stcks *stacks)
{
	int		count;
	t_clst	*tmp;

	stacks->stack_b = NULL;
	stacks->size_b = 0;
	stacks->size_a = argc - 1;
	count = 1;
	stacks->stack_a = new_node(ft_atol(argv[count]));
	tmp = stacks->stack_a;
	while (argv[++count])
	{
		tmp->next = new_node(ft_atol(argv[count]));
		tmp = tmp->next;
	}
	tmp->next = stacks->stack_a;
	stacks->stack_a = tmp;
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
