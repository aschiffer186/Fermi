module Fermi.Core.Compeval;

# Enums are strongly typed in Fermi.
# This enum allows the user to customize 
# how compeval functions and variables 
# work. Enums are also scoped.
let enum Compeval
{
    # Default, only evaulate at 
    # compile time if needed
    Relaxed,
    # Evaluate at compile-time whenever 
    # necessary
    Eager,
    # Always evaluate at compile time 
    # program is ill-formed if not 
    # possible 
    Strict
}