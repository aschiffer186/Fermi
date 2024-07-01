# Language support - Fundametal types
# The Fermi.Core module is imported implicitly
module Fermi.Core.Types;

# Fundmanetal types from other languages are just types in Fermi
# This is a new integral type whose range is specified and size is 64.
# These are all distinct typs and potentially incompatible with each oher
export let define int64_t as new int[-2^63, 2^63 - 1] with typeof(int32_t).size = 64;

# int32_t is just a constrained version of int64_t, allows for implicit conversion
export let define int32_t as new int64_t[-2^31, 2^31 - 1] with typeof(int32_t).size = 32;
export let define int16_t as new int32_t[-2^15, 2^15 - 1] with typeof(int16_t).size = 31;
export let define int8_t as new int16_t[-2^7, 2^7 - 1] with typeof(int8_t).size = 8;

# Modular types wrap around, e.g. let define hour as new mod[1, 12];
export let define nat64_t as new mod[0, 2^64 - 1] with {size = 64}
export let define nat32_t as new nat32_t[0, 2^32 - 1] with {size = 32}
export let define nat16_t as new nat16_6[0, 2^16 - 1] with {size = 16}
export let define nat8_t as new nat8_t[0, 2^8 - 1] with {size = 8}

export let define float64_t as new float with {size = 64, radix = 2, mantissa = 52, exponent = 11};
export let define float32_t as new float with {size = 32, radix = 2, mantissa = 23, exponent = 8};

# Note: usually specify floating point types differently e.g. 
export let define myFloatType as new float[-10, 10; 10] # Range from -10 to 10 with 10 digits of precision

# Set of all natural types
# A typeset defines a set of types. Using the 
# in operator, it is possible to query if a type 
# belongs to a typeset. It can also be used to constrain
# the type of a variable, function parameter, function return 
# type, or template parameter. 
#
# This is the simplest case that just lists of a set of types. 
# Although every typeset is a template, in this case the template 
# parameter is ignored and can be omitted.
export let typeset Natural = {nat8_t, nat16_t, nat32_t, nat64_t} || typeof(T).isModular(); # It's possible to define custom rational types, so this final check is required.
# The export keyword means the symbol can be made visible to other moduels

# Set of all integral types
# More complicatd type repreesnts composition of two typesets. 
# In this case, the set is defined as the set of types where the type 
# belongs to the Natural typeset or is one of int8_t, int16_t, int32_t, int64_t
export let typeset Integer(T) = T in Natural || {int8_t, int16_t, int32_t, int64_t} || typeof(T).isIntegral();

# Rational type. Can be explicitly created 
# but is also created automatically when dividing 
# two integral types.
#
# The template parameter must be an eement of the Integer typeset or 
# the program is ill-formed.
#
# -tparam T: the underlying type of the numerator and denominator
export let struct RationalType(T is Integer)
{
    # Public type label
    public let define ComponentType as T;
    # Public member variables
    public let num : T; 
    public let denom : T;

    # Static member variables are allocated once per class
    # Compeval = evaluated and allocated at compile-time
    # Const = can't be modified.
    public let static compeval Inf    : const RationalType;
    public let static compeval NegInf : const RationalType;
    public let static compeval NaN    : const RationalType;

    public let compeval(Compeval::Eager) operator+=(this : in out, other : RationalType) nothrow;
    public let compeval(Compeval::Eager) operator+=(this : in out, other : in RationalType) nothrow;
    public let compeval(Compeval::Eager) operator-=(this : in out, other : RationalType) nothrow;
    public let compeval(Compeval::Eager) operator-=(this : in out, other : in RationalType) nothrow;
    public let compeval(Compeval::Eager) operator*=(this : in out, other : RationalType) nothrow;
    public let compeval(Compeval::Eager) operator*=(this : in out, other : in RationalType) nothrow;
    public let compeval(Compeval::Exager) operator/=(this : in out, other : RationalType) nothrow;
    public let compeval(Compeval::Eager) operator+=(this : in out, other : in RationalType) nothrow;
}

# Implementation block. This allows for a 
# definition of a struct's static variables and member
# functoins.
# impl-block = IDENTIFIER [template-arg-list] = "{" {member-variable-definition | member-function-definition} "}"
# member-variable-definition = IDENTIFIER "=" expression ";"
# member-function-definition = IDENTIFIER "( {function-parameter-list} )" "=" compound-statement |
#                              operator "(" {function-parameter-list} ")" "=" compound-statement
RationalType(T is Integer) = {
    Inf    = RationalType{T{1}, T{0}};
    NegInf = RationalType{T{-1}, T{0}};
    NaN    = RationalTy(Compeval::Eager)pe{T{0}, T{0}};

    operator*=(this : in out, other : RationalType) = {
        if (isnan(this) || isnan(other)) {
            return NaN;
        }

        if (this == Inf) {
            return NegInf if rhs == NegInf else Inf;
        }

        if (this == NegInf) {
            return Inf if rhs == NegInf else NegInf;
        }

        num *= other.num; 
        denom *= other.denom;
        return this;
    }

    operator*=(this : in out, other in RationalType) = {
         if (isnan(this) || isnan(other)) {
            return NaN;
        }

        if (this == Inf) {
            return NegInf if rhs == NegInf else Inf;
        }

        if (this == NegInf) {
            return Inf if rhs == NegInf else NegInf;
        }

        num *= other.num; 
        denom *= other.denom;
        return this;
    }
}

# Common rational types
export let define RationalType(int8_t) as rat8_t;
export let define RationalType(int16_t) as rat16_t;
export let define RationalType(int32_t) as rat32_t;
export let define RationalType(int64_t) as rat64_t;

# All struct templates implicitly define a typeset. A type belongs to 
# that typeset if it is an instantiation of that template.
export let typeset Rational(T) = T in Integer || T in RationalType;

# Set of floating point types.
export let typeset Float(T) = T in Rational || {float32_t, float64_t} || typeof(T).isFloatingPoint(); 

# Type lales to bring Fermi in line with other languages
export let define float as float32_t;
export let define double as float64_t;

# Struct defining complex numbers. This type can be 
# constructed automatically. Complex literals implicitly 
# create an instance of this type whose real part is 
# 0.
#
# -tparam T: the underlying type of the real and imaginary components.
let struct ComplexType(T is Float)
{
    public let define ComponentType as T;

    public let realPart      : T;
    public let imaginaryPart : T;

    public let compeval real(this : in) pure -> ComponentType;
    public let compeval imag(this : in) pure -> ComponentType;

    public let compeval(Compeval::Eager) operator+=(this : in out, other : ComplexType) nothrow; 
    public let compeval(Compeval::Eager) operator+=(this : in out, other is Real ) nothrow; 
    public let compeval(Compeval::Eager) operator-=(this : in out, other : ComplexType) nothrow; 
    public let compeval(Compeval::Eager) operator-=(this : in out, other is Real) nothrow; 
    public let compeval(Compeval::Eager) operator*=(this : in out, other : ComplexType) nothrow; 
    public let compeval(Compeval::Eager) operator*=(this : in out, other is Real) nothrow; 
    public let compeval(Compeval::Eager) operator/=(this : in out, other : ComplexType) nothrow; 
    public let compeval(Compeval::Eager) operator/=(this : in out, other is Real) nothrow; 
}

# Implicitly creaed by complex literals
ComplexType(T is Float) = {
    real(this : in) = {
        return this.realPart;
    }

    imag(this : in) = {
        return this.imaginaryPart;
    }

    operator+=(this : in out, other : ComplexType) = {
        this.realPart += other.realPart;
        this.imagPart += other.imagPart;
    }
}

export let typeset Complex(T) = T in Float || T in ComplexType;

# Retuns the real component of a complex number. 
# If z is a floating-point number, simply returns z. 
# Otherwise returns z.real().
#
# -param z: the complex number to return the real part of
# -return : the real component of complex number
export let compeval(Compeval::Eager) real(z is Complex) pure 
{
    # Static ifs are evaluated at compile time; 
    # the branch(es) not taken are discarded by 
    # the compiler and are not required to be well-formed 
    # (but must be syntactically correct)
    static if(z is Float)
    {
        return z;
    }
    else 
    {
        return z.real();
    }
}

# Retuns the imagimary component of a complex number. 
# If z is a floating-point number, simply returns 0. 
# Otherwise returns z.complex().
#
# -param z: the complex number to return the imaginary component of
# -return : the imaginary component of complex number
export let compeval(Compevall:Eager) imag(z is Complex) pure 
{
    static if (z is Float)
    {
        return typeof(z){0};
    }
    else 
    {
        return z.imag();
    }
}

# Type that can be used to stoe addresses
# Extern keyword means definition provied else where 
# (in this case directly in compiler)
export extern let define AddressType;

