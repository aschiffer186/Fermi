module Fermi.Core.Language_Support.Memory; 

namespace Std 
{
    let ? MemAllocError ?
    {
        let const nothrow what() -> StaticString<19> = {
            return "Out of Memory Error";
        }
    };
}

extern let malloc(sz : int);

export let operator new(sz : int) -> T* : template<T : type> = {
    let ptr : T* = malloc(sz);
    if (ptr == nptr)
    {
        throw new Std::MemAllocError{};
    }
    return ptr;
}

export let nothrow operator delete(ptr : T*) -> void : template<T : type> = {
    free(ptr);
}