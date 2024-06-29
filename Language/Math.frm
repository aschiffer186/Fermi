module Fermi.Math; 

export let compeval diff(func : Callable<float64_t, float64_t>, x : float64_t) pure(func(x)) nothrow(func(x))-> float64_t = 
{
    # The match construct is very very powerful in Fermi. Since 
    # functions are first class citizens and combinations of functions 
    # are baked into the type system, it is possible to match based on 
    # the structure of functions.
    static match(func)
    {
    # syntact sugar for when typeof(func) is BinaryCallable<float64_t, Callable<float64_t, float64_t>, Callable<float64_t, floa64_t, 
    when f + g => 
        return diff(f, x) + diff(g, x);
    when f - g => 
        return diff(f, x) - diff(g, x); 
    when f * g => 
        return diff(f, x)*g + f*diff(g, x);
    when f / g => 
        return (diff(f, x)*g - f*(diff(g, x)))/g^2;
    when f ^ [a in Real] => 
        return a * f ^ (a - 1) * diff(f);
    when 
    }
}