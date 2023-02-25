* A function is a mapping from one or more types to one or more types. 
* A function has zero or more inputs and produces zero or more outputs.
    * If a function has no inputs, it maps from the `void` type to another type.
    * If a function has no outputs, it maps from one or more types to the `void` type. 
* A function may optionally be marked as pure. A pure function may not has side effects. Specifically, a pure function must meet the following requirements:
    1. The function may not modify its inputs.
    2. The function must not call any impure functions. 
    3. The function must produce the same output every-time it is called with the same inputs. 
* All functions are entities whose type is the `Callable` type. The `Callable` type has two predefined operations:
    * The function-call operator that executes the mapping. 
    * The composition operator.
* Given two functions _f_ and _g_, the composition operator produces a new function that is _g ∘ f_.
    * Note, the function call operator creates a new function that performs _g ∘ f_ with only one function call. It is not equivalent to the following code: 
        ```
            let x = f(args...);
            let y = g(y);
        ```