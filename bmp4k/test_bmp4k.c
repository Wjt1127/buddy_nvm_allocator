#include <bmp4k.h>
#include <stdio.h>
#include <common.h>

int main()
{
    struct bmp4k b;
    int ret;
    
    ret = bmp4k_init(&b, 4000, 0);
    assert(ret);

    for(size_t i = 0; i < 4000; i++)
    {
        size_t index = bmp4k_search(&b, 0);
        assert(index != BMP4K_NOT_FOUND);
        ret = bmp4k_set(&b, index, 1);
        assert(ret);
    }

    ret = bmp4k_exist(&b, 0);
    assert(!ret);

    ret = bmp4k_exist(&b, 1);
    assert(ret);

    for(size_t i = 0; i < 4000; i++)
    {
        size_t index = bmp4k_search(&b, 1);
        assert(index != BMP4K_NOT_FOUND);
        ret = bmp4k_set(&b, index, 0);
        assert(ret);
    }

    ret = bmp4k_exist(&b, 0);
    assert(ret);

    ret = bmp4k_exist(&b, 1);
    assert(!ret);

    return 0;
}