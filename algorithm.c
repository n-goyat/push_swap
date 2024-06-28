//algorithm.c
#include "./includes/push_swap.h"
void small_alg(t_stcks *stacks)
{
    t_clst *tmp;

    if (stacks->size_a == 1 || is_sorted(stacks))
        return;
    if (stacks->size_a == 2)
    {
        swap_a(stacks, 1); // directly swap two elements if size is 2
        return;
    }
    if (stacks->size_a == 3)
    {
        tmp = stacks->stack_a->next;
        // Sort three elements in stack A
        if (tmp->value == find_max_value(stacks))
            rot_a(stacks, 1); // rotate if max is in the wrong place
        while (!is_sorted(stacks))
        {
            tmp = stacks->stack_a->next;
            if (tmp->value < tmp->next->value)
                rev_rot_a(stacks, 1); // reverse rotate to fix order
            else
                swap_a(stacks, 1); // swap if necessary
        }
    }
}


void med_alg(t_stcks *stacks)
{
    if (is_sorted(stacks))
        return;
    
    move_to_min(stacks); // move minimum element to the top
    push_b(stacks, 1); // push to stack B
    
    if (stacks->size_a == 4)
    {
        move_to_min(stacks); // for size 4, move again and push
        push_b(stacks, 1);
    }
    
    small_alg(stacks); // use small algorithm for remaining elements
    
    push_a(stacks, 1); // push back to stack A
    if (stacks->size_b)
        push_a(stacks, 1); // push remaining B elements to A
}


void big_alg(t_stcks *stacks)
{
    if (is_sorted(stacks))
        return;

    median(stacks); // calculate median of stack A
    push_below_median(stacks, stacks->median_a); // push elements <= median to B
    while (stacks->size_b)
        find_min_max(stacks); // move elements to correct position in A

    push_above_median(stacks, stacks->median_a); // push remaining elements to B
    while (stacks->size_b)
        find_min_max(stacks); // move elements to correct position in A

    move_to_min(stacks); // move minimum element to top
}


void biggest_alg(t_stcks *stacks)
{
    int min;
    int max;

    if (is_sorted(stacks))
        return;

    min = find_min_value(stacks);
    max = find_max_value(stacks);
    get_block(stacks, min, max); // divide and conquer approach
    move_to_min(stacks); // move minimum element to top
    if (!is_sorted(stacks))
        big_alg(stacks); // apply big algorithm if not sorted
}
