#include "utils.h"

int get_power_bound_for(int n){
    return (int)ceil(log(n) / log(2));
}

int get_optimal_size_for(int n){
    if(n == 0) return 0;
    return 1 << get_power_bound_for(n);
}
