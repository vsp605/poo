#include <stdio.h>
#include <stdlib.h>

typedef struct free_block {
    int start_addr;
    int size;
    struct free_block *next;
} free_block;

typedef struct allocated_block {
    int start_addr;
    int size;
    struct allocated_block *next;
} allocated_block;

free_block *free_head = NULL;
allocated_block *allocated_head = NULL;

void insert_free_block(int start_addr, int size) {
    free_block *new_block = (free_block *)malloc(sizeof(free_block));
    new_block->start_addr = start_addr;
    new_block->size = size;
    new_block->next = free_head;
    free_head = new_block;
}

void insert_allocated_block(int start_addr, int size) {
    allocated_block *new_block = (allocated_block *)malloc(sizeof(allocated_block));
    new_block->start_addr = start_addr;
    new_block->size = size;
    new_block->next = allocated_head;
    allocated_head = new_block;
}

void best_fit(int size) {
    free_block *curr = free_head;
    free_block *best = NULL;
    free_block *prev_best = NULL;
    free_block *prev = NULL;
    int best_size = -1;

    while (curr) {
        if (curr->size >= size && (best_size == -1 || curr->size < best_size)) {
            best = curr;
            prev_best = prev;
            best_size = curr->size;
        }
        prev = curr;
        curr = curr->next;
    }

    if (best) {
        insert_allocated_block(best->start_addr, size);
        if (best_size == size) {
            if (prev_best) {
                prev_best->next = best->next;
            } else {
                free_head = best->next;
            }
            free(best);
        } else {
            best->size -= size;
            best->start_addr += size;
        }
    } else {
        printf("No suitable block found for allocation\n");
    }
}

void first_fit(int size) {
    free_block *curr = free_head;
    free_block *prev = NULL;

    while (curr) {
        if (curr->size >= size) {
            insert_allocated_block(curr->start_addr, size);
            if (curr->size == size) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    free_head = curr->next;
                }
                free(curr);
            } else {
                curr->size -= size;
                curr->start_addr += size;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("No suitable block found for allocation\n");
}

void worst_fit(int size) {
    free_block *curr = free_head;
    free_block *worst = NULL;
    free_block *prev_worst = NULL;
    free_block *prev = NULL;
    int worst_size = -1;

    while (curr) {
        if (curr->size >= size && (worst_size == -1 || curr->size > worst_size)) {
            worst = curr;
            prev_worst = prev;
            worst_size = curr->size;
        }
        prev = curr;
        curr = curr->next;
    }

    if (worst) {
        insert_allocated_block(worst->start_addr, size);
        if (worst_size == size) {
            if (prev_worst) {
                prev_worst->next = worst->next;
            } else {
                free_head = worst->next;
            }
            free(worst);
        } else {
            worst->size -= size;
            worst->start_addr += size;
        }
    } else {
        printf("No suitable block found for allocation\n");
    }
}

void print_free_list() {
    free_block *curr = free_head;
    printf("Free List:\n");
    while (curr) {
        printf("[%d-%d] ", curr->start_addr, curr->start_addr + curr->size - 1);
        curr = curr->next;
    }
    printf("NULL\n");
}

void print_allocated_list() {
    allocated_block *curr = allocated_head;
    printf("Allocated List:\n");
    while (curr) {
        printf("[%d-%d] ", curr->start_addr, curr->start_addr + curr->size - 1);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, b, n, ba, s, i;
    printf("Enter number of blocks:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the base address and size:");
        scanf("%d%d", &ba, &s);
        insert_free_block(ba, s);
    }

    printf("Initial Free List:\n");
    print_free_list();
    
    while (1) {
        printf("Enter choice (1: Best Fit, 2: First Fit, 3: Worst Fit, 4: Exit): ");
        scanf("%d", &ch);
        if (ch == 4) {
            break;
        }
        printf("Enter the size of the process to be allocated: ");
        scanf("%d", &b);
        
        switch (ch) {
            case 1:
                best_fit(b);
                printf("After Best Fit Allocation:\n");
                break;
            case 2:
                first_fit(b);
                printf("After First Fit Allocation:\n");
                break;
            case 3:
                worst_fit(b);
                printf("After Worst Fit Allocation:\n");
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }
        
        print_free_list();
        print_allocated_list();
    }

    return 0;
}
