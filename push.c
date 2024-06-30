//push.c
#include "./includes/push_swap.h"

t_clst *push_helper(t_clst *stack, t_clst *new_node) {
	if (!stack) {
		new_node->next = new_node;
		return new_node;
	} else {
		new_node->next = stack->next;
		stack->next = new_node;
		return stack;
	}
}

void push_a(t_stcks *stacks, int print)
{
	t_clst *tmp;

	tmp = stacks->stack_b->next;
	if (stacks->stack_b == NULL)
		return;
	if (tmp == stacks->stack_b)
		stacks->stack_b = NULL;
	else
		stacks->stack_b->next = tmp->next;
	stacks->stack_a = push_helper(stacks->stack_a, tmp);
	stacks->size_a++;
	stacks->size_b--;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void push_b(t_stcks *stacks, int print)
{
	t_clst *tmp;

	tmp = stacks->stack_a->next;
	if (stacks->stack_a == NULL)
		return;
	if (tmp == stacks->stack_a)
		stacks->stack_a = NULL;
	else
		stacks->stack_a->next = tmp->next;
	stacks->stack_b = push_helper(stacks->stack_b, tmp);
	stacks->size_a--;
	stacks->size_b++;
	if (print)
		ft_putstr_fd("pb\n", 1);
}




//t_clst	*push_helper(t_clst *ab_tmp, t_clst *tmp)
//{
//	if (!ab_tmp)
//	{
//		ab_tmp = tmp;
//		ab_tmp->next = ab_tmp;
//	}
//	else
//	{
//		tmp->next = ab_tmp->next;
//		ab_tmp->next = tmp;
//	}
//	return (ab_tmp);
//}
//
//void	push_a(t_stcks *stacks, int print)
//{
//	t_clst	*a_tmp;
//	t_clst	*b_tmp;
//	t_clst	*tmp;
//
//	a_tmp = stacks->stack_a;
//	b_tmp = stacks->stack_b;
//    printf("Before push_a: size_a=%d size_b=%d\n", stacks->size_a, stacks->size_b);
//    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
//    print_stack(stacks->stack_b, stacks->size_b, "Stack B");
//	if (stacks->size_b == 1)
//	{
//		tmp = stacks->stack_b;
//		tmp->next = tmp;
//		stacks->stack_b = NULL;
//	}
//	else
//	{
//		tmp = b_tmp->next;
//		b_tmp->next = tmp->next;
//		tmp->next = tmp;
//		stacks->stack_b = b_tmp;
//	}
//	stacks->stack_a = push_helper(a_tmp, tmp);
//	stacks->size_a++;
//	stacks->size_b--;
//        printf("After push_a: size_a=%d size_b=%d\n", stacks->size_a, stacks->size_b);
//    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
//    print_stack(stacks->stack_b, stacks->size_b, "Stack B");
//	if (print)
//		ft_putstr_fd("pa\n", 1);
//}
//
//void	push_b(t_stcks *stacks, int print)
//{
//	t_clst	*a_tmp;
//	t_clst	*b_tmp;
//	t_clst	*tmp;
//
//	a_tmp = stacks->stack_a;
//	b_tmp = stacks->stack_b;
//        printf("Before push_a: size_a=%d size_b=%d\n", stacks->size_a, stacks->size_b);
//    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
//    print_stack(stacks->stack_b, stacks->size_b, "Stack B");
//	if (stacks->size_a == 1)
//	{
//		tmp = stacks->stack_a;
//		tmp->next = tmp;
//		stacks->stack_a = NULL;
//	}
//	else
//	{
//		tmp = a_tmp->next;
//		a_tmp->next = tmp->next;
//		tmp->next = tmp;
//		stacks->stack_a = a_tmp;
//	}
//	stacks->stack_b = push_helper(b_tmp, tmp);
//	stacks->size_a--;
//	stacks->size_b++;
//        printf("After push_a: size_a=%d size_b=%d\n", stacks->size_a, stacks->size_b);
//    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
//    print_stack(stacks->stack_b, stacks->size_b, "Stack B");
//	if (print)
//		ft_putstr_fd("pb\n", 1);
//}





//void	push_a(t_stcks *stacks, int print)
//{
//    t_clst *tmp;
//
//    if (stacks->stack_b == NULL) return;
//
//    printf("Before push_a: size_a=%d size_b=%d\n", stacks->size_a, stacks->size_b);
//    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
//    print_stack(stacks->stack_b, stacks->size_b, "Stack B");
//
//    if (stacks->stack_b->next == stacks->stack_b) {
//        tmp = stacks->stack_b;
//        stacks->stack_b = NULL;
//    } else {
//        tmp = stacks->stack_b->next;
//        stacks->stack_b->next = tmp->next;
//    }
//
//    stacks->stack_a = push_helper(stacks->stack_a, tmp);
//    stacks->size_a++;
//    stacks->size_b--;
//
//    printf("After push_a: size_a=%d size_b=%d\n", stacks->size_a, stacks->size_b);
//    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
//    print_stack(stacks->stack_b, stacks->size_b, "Stack B");
//
//    if (print) {
//        ft_putstr_fd("pa\n", 1);
//    }
//}
//
//void	push_b(t_stcks *stacks, int print)
//{
//    t_clst *tmp;
//
//    if (stacks->stack_a == NULL) return;
//
//    printf("Before push_b: size_a=%d size_b=%d\n", stacks->size_a, stacks->size_b);
//    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
//    print_stack(stacks->stack_b, stacks->size_b, "Stack B");
//
//    if (stacks->stack_a->next == stacks->stack_a) {
//        tmp = stacks->stack_a;
//        stacks->stack_a = NULL;
//    } else {
//        tmp = stacks->stack_a->next;
//        stacks->stack_a->next = tmp->next;
//    }
//
//    stacks->stack_b = push_helper(stacks->stack_b, tmp);
//    stacks->size_a--;
//    stacks->size_b++;
//
//    printf("After push_b: size_a=%d size_b=%d\n", stacks->size_a, stacks->size_b);
//    print_stack(stacks->stack_a, stacks->size_a, "Stack A");
//    print_stack(stacks->stack_b, stacks->size_b, "Stack B");
//
//    if (print) {
//        ft_putstr_fd("pb\n", 1);
//    }
//}