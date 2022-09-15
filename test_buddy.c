#include "buddy.h"
#include <stdio.h>
#include <assert.h>

int main()
{
    struct buddy b;
    int ret;

    //*buddy, capacity, min_item_sz, max_item_sz
    ret = buddy_init(&b, (size_t)1<<10, 4, 512);
    assert(ret);

    printf("addr of b = %p\n", &b);
    size_t addr;

    for(size_t i = 0; i < 4; i ++)
    {
        addr = buddy_allocate_at(&b, 4 * i , 4);
        assert(addr != BUDDY_ALLOCATE_FAILED);
        printf("addr = %p\n", addr);
    }

    for(size_t i = 0; i < 4; i ++)
    {
        ret = buddy_free(&b, 4 * i, 4);
        assert(ret);
    }

    for(size_t i = 0; i < 4; i ++)
    {
        addr = buddy_allocate(&b, 4);
        assert(addr != BUDDY_ALLOCATE_FAILED);
        printf("addr = %p\n", addr);
    }

    for(size_t i = 0; i < 4; i ++)
    {
        ret = buddy_free(&b, 4 * i, 4);
        assert(ret);
    }

    return 0;
}