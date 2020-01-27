
#include "buffer.h"

STACK *memory_blocks[32] = {NULL};
void *memory;

void init_buddy(){
    int i;
    for(i = 0; i < 32; memory_blocks[i++] = new_stack());
    int size = get_optimal_size_for(INITIAL_MEMORY_SIZE);
    int index = get_power_bound_for(size);
    push_stack(memory_blocks[index], 0, size - 1);
    memory = calloc(size, sizeof(uint8_t));
    //todo// initialize map after changes
}


void *balloc(int n){
    int index = get_power_bound_for(n);
    PAIR *allocated = NULL;

    if(memory_blocks[index]->size > 0){
        allocated = pop_stack(memory_blocks[index]);
        printf("allocated start: %d\n", allocated->lower_bound);

        put_map(allocated->lower_bound, allocated->upper_bound - allocated->lower_bound + 1);
        return (void *)((int)memory + (int)allocated->lower_bound);//if eligible block found, return it
    }

    int search_for_bigger = index + 1;

    while(search_for_bigger < 32 && memory_blocks[search_for_bigger]->size == 0) search_for_bigger++; //search for bigger block

    if(search_for_bigger == 32) return -1; // failed to find block

    //manage block splitting

    allocated = pop_stack(memory_blocks[search_for_bigger--]);

    for(; search_for_bigger >= index; search_for_bigger--){

        push_stack(memory_blocks[search_for_bigger],
                    allocated->lower_bound + (allocated->upper_bound - allocated->lower_bound + 1) / 2,
                    allocated->upper_bound);

        push_stack(memory_blocks[search_for_bigger],
                allocated->lower_bound,
                allocated->lower_bound + (allocated->upper_bound - allocated->lower_bound) / 2);

        free(allocated);

        allocated = pop_stack(memory_blocks[search_for_bigger]);
    }


    put_map(allocated->lower_bound, allocated->upper_bound - allocated->lower_bound + 1);
    return (void *)((int)allocated->lower_bound + (int)memory);

}




void bfree(int n){
    n -= (int)memory;
    if(!contains_map(n)){
        printf("not found node!\n");
        return;
    }

    int index = get_power_bound_for(get_map(n));

    int i, buddyNumber, buddyAddress, pow_of_index;

    pow_of_index = (int)pow(2, index);

    push_stack(memory_blocks[index], n, n + pow_of_index - 1);

    buddyNumber = n / get_map(n);

    if (buddyNumber % 2 == 0) {
        buddyAddress = n - pow_of_index;
    }
    else {
        buddyAddress = n + pow_of_index;
    }

    PAIR *element = memory_blocks[index]->head;
    PAIR *prev = element;
    int done = 0;

    for (i = 0; i < memory_blocks[index]->size; i++) {

        if(element->lower_bound == buddyAddress){
            if (buddyNumber % 2 == 0) {
                push_stack(memory_blocks[index + 1], n, n + 2 * pow_of_index - 1 );

            }
            else {
                push_stack(memory_blocks[index + 1], buddyAddress, buddyAddress + 2 * pow_of_index - 1);
            }


            prev->next = element->next;
            free(element);
            memory_blocks[index]->size--;
            free(pop_stack(memory_blocks[index]));

            done = 1;
            break;
        }
        if(!done){
            prev = element;
            element = element->next;
        }
    }
    remove_map(n);
}
