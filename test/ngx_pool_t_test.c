/** 
 * ngx_pool_t test, to test ngx_palloc, ngx_palloc_block, ngx_palloc_large 
 */  

#include <stdio.h>  
#include "ngx_palloc.h"  
#include "ngx_alloc.h"  

void dump_pool(ngx_pool_t* pool)  
{  
    while (pool)  
    {  
        printf("pool = 0x%p\n", pool);  
        printf("  .d\n");  
        printf("  .last = 0x%p\n", pool->d.last);  
        printf("  .end = 0x%p\n", pool->d.end);  
        printf("  .next = 0x%p\n", pool->d.next);  
        printf("  .failed = %u\n", pool->d.failed);  
        printf("  .max = %d\n", pool->max);  
        printf("  .current = 0x%p\n", pool->current);  
        printf("  .large = 0x%p\n", pool->large);  
        printf("available pool memory = %d\n\n", pool->d.end - pool->d.last);  
        pool = pool->d.next;  
    }
}

int main()  
{  
    ngx_pool_t *pool;  

    printf("--------------------------------\n");  
    printf("create a new pool:\n");  
    printf("--------------------------------\n");  
    pool = ngx_create_pool(1024);  
    dump_pool(pool);  

    printf("--------------------------------\n");  
    printf("alloc block 1 from the pool:\n");  
    printf("--------------------------------\n");  
    ngx_palloc(pool, 512);  
    dump_pool(pool);  

    printf("--------------------------------\n");  
    printf("alloc block 2 from the pool:\n");  
    printf("--------------------------------\n");  
    ngx_palloc(pool, 512);  
    dump_pool(pool);  

    printf("--------------------------------\n");  
    printf("alloc block 3 from the pool :\n");  
    printf("--------------------------------\n");  
    ngx_palloc(pool, 512);  
    dump_pool(pool);  

    ngx_destroy_pool(pool);  
    return 0;  
}  
