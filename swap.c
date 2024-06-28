//swap.c
#include "./includes/push_swap.h"
void	swap_a(t_stcks *stacks, int print)
{
	t_clst	*tmp;
	int		value;

	(void)print;
	if (stacks->size_a > 1)
	{
		tmp = stacks->stack_a->next;
		value = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = value;
	}
	if (print) {
        ft_putstr_fd("pa\n", 1);
        print_stack(stacks->stack_a, stacks->size_a, "Stack A");
        print_stack(stacks->stack_b, stacks->size_b, "Stack B");
    }
}

void	swap_b(t_stcks *stacks, int print)
{
	t_clst	*tmp;
	int		value;

	(void)print;

	if (stacks->size_b > 1)
	{
		tmp = stacks->stack_b->next;
		value = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = value;
	}
	if (print) {
        ft_putstr_fd("pa\n", 1);
        print_stack(stacks->stack_a, stacks->size_a, "Stack A");
        print_stack(stacks->stack_b, stacks->size_b, "Stack B");
    }
}

void	swap_both(t_stcks *stacks, int print)
{
		(void)print;

	swap_a(stacks, 0);
	swap_b(stacks, 0);
	if (print) {
        ft_putstr_fd("pa\n", 1);
        print_stack(stacks->stack_a, stacks->size_a, "Stack A");
        print_stack(stacks->stack_b, stacks->size_b, "Stack B");
    }
}
