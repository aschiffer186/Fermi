# Fundamentals
* Entity: an entity is the smallest semantic unit of Fermi; it has a type, a value, and an associated object 
    * The value of an entity is either
        1. If the type of an entity is a fundamental type, the in memory representation of the associated object
* Object: an object has an address, a size, and an in-memory representation
* Variable: a variable is a strongly-typed identifier that has an associated entity
* Type: A type has a name, a set of valid operations, and a size
# Basic Types
## Arithmetic Types
### Integer Types
* Fermi defines five signed integer types 
    * `int8_t`: a one byte (8-bit) signed integer type whose range is -2^7 to 2^7 - 1
    * `int16_t`: a two byte (16-bit) signed integer type whose range is -2^15 to 2^15 - 1
    * `int32_t`: a four byte (32-bit) signed integer type whose range is -2^31 to 2^31 - 1
    * `int64_t`: an eight bye (64-bit) signed integer type whose range is -2^63 to 2^63 - 1
    * `int128_t`: a sixteen byte (128-bit) signed integer type whose range is -2^127 to 2^127 - 1 (maybe???)
### Floating-Point Types
* Fermi defines two floating-point types
    * `float32_t`: an IEEE-754 32-bit floating-point type
    * `float64_t`: an IEEE-754 64-bit floating-point type
### Type Promotion Rules
* The arithmetic type promotion rules describe the legality of implicit conversions between fundamental arithmetic types as well as the type deduction guidelines for expressions involving arithmetic types. 
* A fundamental arithmetic type `T1` is said to be _implicitly convertible_ to or _promotable_ to another fundamental arithmetic type `T2` if one of the following is true:
    1. `T1` and `T2` are exactly the same type.
    2. `T1` ane `T2` are both signed integral types and the size of `T2` is larger than the size of `T1`.
    3. `T1` and `T2` are both floating-point types and the size of `T2` is larger than the size of `T1`.
    4. `T1` is a signed integral type and `T2` is a floating-point type whose size is at least as large as the size of `T1`. 