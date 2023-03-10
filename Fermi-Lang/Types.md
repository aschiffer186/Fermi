# Introduction
* A type is named category of entities and the operations that may be performed on those values. 
* All types have the following operations defined for them:
    * The _identity function_: maps a type to itself; takes in a entity and returns the same entity unchanged
    * The _size function_: maps a type to an `int64_t`: takes in an entity and returns the number of bytes required for its associated object.
        * This function returns the same value for all entities of a particular type. 
    * The _address function_: maps a type to a ??: takes in an entity and returns the address of its associated object. 
* A type may have one or more labels that provide alternative names for the type. These labels do not create distinct types. 
* There are 3 categories of types:
    * Arithmetic Types 
    * Void Type 
    * Unit Type
# Arithmetic Types
* Arithmetic types provide representations of the real number system and its subsets.
* There are two types of arithmetic types: integer-types and floating-point types. 
## Integer Types
* Integer types represent signed-integer types.
    * The associated objects of entities of signed-integer types are represented using the twos-complement representation.
* There are four integer types: `int8_t`, `int16_t`, `int32_t`, `int64_t`
    * `int8_t` is a signed 8-bit, 1-byte integer type.
        * The range of this type is -128 to 127
    * `int16_t` is a signed 16-bit, 2-byte integer type.
        * The range of this type is -32,768 to 32,767
    * `int32_t` is a signed 32-bit, 4-byte integer type.
        * The range of this type is -2,147,483,648 to 2,147,483,647
    * `int64_t` is a signed 64-bit, 8-byte integer type.
        * The range of this type is -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
## Rational Types
* Rational types represent the exact value of the division of two integers.
* All entities of rational types have two accessible sub-entities representing the numerator and denominator of the rational number.
    * The type of the sub-entities must be the same and must be an integer-type.
    * The type of the sub-entities is referred to as the _representation type_ of the rational type.
    * The `Num` property is an entity of the representation type whose value is the numerator of the rational type 
    * The `Denom` property is an entity of the representation type whose value is the denominator of the rational type
* There are four rational types: `rat8_t`, `rat16_t`, `rat32_t`, `rat64_t`
    * `rat8_t` has a representation type of `int8_t`
    * `rat16_t` has a representation type of `int16_t`
    * `rat32_t` has a representation type of `int32_t`
    * `rat64_t` has a representation type of `int64_t`
## Floating Point Types
* Floating-points are approximations of real-numbers.
* There are two floating-point types: `float32_t` and `float64_`
    * `float32_t` is a 32-bit IEEE-754 floating-point type
        * The range of exponents supported by the type is -126 to 127
        * The significant has 24-bits of precision
    * `float64_t` is a 64-bit IEEE-754 floating-point type
        * The range of exponents is -1022 to 1023
        * The significant has 53-bits of precision
* All floating-point types additionally have 4 specialize values
    1. Quiet NaN (qNaN)
    2. Signaling Nan (sNaN)
    3. ∞
    4. -∞
## Arithmetic Type Promotion
* The arithmetic type promotion rules determine how arithmetic types can be implicitly converted. 
* An entity of an integral type can be implicitly converted to an entity of an equal or larger integral type.
* An entity of an integral type _T_ can be implicitly converted to a rational type if _T_ can be implicitly converted to the rational type's representation type.
* An entity of type `float32_t` can be implicitly converted to an entity of type `float64_t`.
* An entity of any integral type may be implicitly converted to a floating-point type. 
* An entity of any rational type may be implicitly converted to a floating-point-type.
* The _common type_ of two integer types is the larger of the two types.
* The _common type_ of two rational types _T1_ and _T2_ is a rational type whose representation type is the common type of the representation types of _T1_ and _T2_.
* The _common type_ of two floating-point types is the larger of the two types.
* The _common type_ of an integer type _T1_ and a rational type _T2_ is the rational type whose representation type is the common type of _T1_ and the representation type of _T2_.
* The _common type_ of an integer type and a floating-point type is the floating-point type.
* The _common type_ of a rational type and a floating-point type is the floating-point type.
# Bool Type
* The bool type is used to express logical conditions and is denoted by the keyword `bool`.
* All entities of type `bool` can have one of two possible values: true, denoted by the keyword `true` and false, denoted by the keyword `false`.
* The size of `bool` is 1. 
# Void Type
* The void type is the unique type that contains no input entities.
* The void type is denoted by the keyword `void`.
* A program that attempts to create an entity whose type is `void` is ill-formed. 
* The identity and address functions are not defined for the void type.
* The size function of `void` returns 0; `void` is the only type whose size is 0. 
# Unit Type
* The unit type is the unique type that contains exactly one entity.
    * All instances? of the unity type are the same entity. Specifically, the address of all instances of the unit type are the same.
* The size of the unit type is implementation defined.