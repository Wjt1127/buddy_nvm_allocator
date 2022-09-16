#include "common.h"
#include "nvmalloc.h"

int main()
{
    struct nvmalloc nvm;
    int ret;
    size_t addr;
    size_t size;

    ret = nvmalloc_init(&nvm, (size_t)1<<40);
    assert(ret);

    for(size_t i = 0; i < 100000000; i++)
    {
        addr = nvmalloc_malloc_at(&nvm, i<<6, 1<<6);
        assert(addr != NVMALLOC_ALLOCATE_FAILED);
    }

    for(size_t i = 0; i < 1000000000; i++)
    {
        ret = nvmalloc_free(&nvm, i<<6);
        assert(ret);
    }

    ret = nvmalloc_deinit(&nvm);
    assert(ret);

    return 0;
}