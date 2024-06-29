module Fermi.Core.Functions; 

# Functions are baked into the type system 

export let typeset Callable(T);

# Type of basic callable 
export let struct LeafCallable(_RetType, _Args..., _Pure : bool, _CompevalType : Compeval)
{
    public let define ReturnType as _RetType; 
    public let define ArgumentTypes... as _Args...;

    extern let compeval(_CompevalType) operator()(args : _Args...) _Pure -> ReturnType;
}

# let func() = {}
# Type is LeafCallable<void, false, Compeval::NotCompeval>;

# let compeval func(arg : int32_t) pure -> int32_t
#Type is LeafCallable<int32_t, int32_t, true, Compeval::Relaxed>;

# let a = func + func;
# Type is BinaryCallable<int32_t, 
#                        BinaryOperator::Addition,
#                        LeafCallable<int32_t, int32_t, true, Compeval::Relaxed>,
#                        LeafCallable<int32_t, int32_t, true, Compeval::Relaxed>