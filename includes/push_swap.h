#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_clst
{
	int				value;
	struct s_clst	*next;
}					t_clst;

typedef struct s_stcks
{
	t_clst	*stack_a;
	t_clst	*stack_b;
	int		size_a;
	int		size_b;
	int		median_a;
	int		pos_max;
	int		pos_min;
	int		last_max;
}			t_stcks;

/* Checker */
int		check_input(int argc, char **argv);
long	ft_atoi_ps(const char *str);

/* Initialize list */
t_stcks	*init_list(int argc, char **argv, t_stcks *stacks);
void	create_circular_list(int argc, char **argv, t_stcks *stacks, int count);
t_clst	*new_node(int value);

/* List utils */
void	print_list_a(t_stcks *stacks);
void	print_list_b(t_stcks *stacks);
void	free_stack(t_stcks *stacks);

/* Swap */
void	swap_a(t_stcks *stacks, int print);
void	swap_b(t_stcks *stacks, int print);
void	swap_both(t_stcks *stacks, int print);

/* Push */
void	push_a(t_stcks *stacks, int print);
void	push_b(t_stcks *stacks, int print);

/* Rotate */
void	rot_a(t_stcks *stacks, int print);
void	rot_b(t_stcks *stacks, int print);
void	rr(t_stcks *stacks, int print);

/* Reverse rotate */
void	rev_rot_a(t_stcks *stacks, int print);
void	rev_rot_b(t_stcks *stacks, int print);
void	rrr(t_stcks *stacks, int print);

/* Algorithm */
void	small_alg(t_stcks *stacks);
void	med_alg(t_stcks *stacks);
void	big_alg(t_stcks *stacks);
void	biggest_alg(t_stcks *stacks);

/* Algorithm utils */
int		is_sorted(t_stcks *stacks);
int		find_min(t_clst *stack);
int		find_max(t_clst *stack);
void	median(t_stcks *stacks);

/* Algorithm utils 2 */
void	push_below_median(t_stcks *stacks, int median);
void	push_above_median(t_stcks *stacks, int median);
void	move_to_min(t_stcks *stacks);
void	find_min_max(t_stcks *stacks);
void	push_min_max(t_stcks *stacks, int pos);

/* Algorithm utils 3 */
int		find_min_value(t_stcks *stacks);
int		find_max_value(t_stcks *stacks);
void	push_between_median(t_stcks *stacks, int from, int to);
void	move_to_value(t_stcks *stacks, int value);
void	get_block(t_stcks *stacks, long min, long max);

/* Allocation */
int		*allocate_and_parse_numbers(int argc, char *argv[]);
int		handle_multiple_arguments(int argc, char *argv[], t_stcks *stacks);
int		*allocate_and_parse_single_argument(int argc, char *argv[]);
int		handle_single_argument(int argc, char *argv[], t_stcks *stacks);
long long	ft_atol(const char *str);
int		has_duplicates(int *arr, int size);
//void print_stack(t_clst *stack, int size, char *stack_name);

#endif
