# Introduction
## Grammar 
```
expression := 
      identity-expression 
    | creation-expression
```
* An expression takes as input one ore more entities and returns one or more entities.
* There are three types of expressions: identity expression that return the same entity; creation expression that creates a new entity from its inputs, and transformation expression that modify one or more of its input entities.
    * A creation expression may not modify its inputs 
    * A transformation expression may produce a new entity in additional to modifying an input entity. 
# Identity Expressions
## Grammar
```
identity-expression := 
      IDENTIFIER
    | "( expression ")"                   
```
### Identifiers
* The identity expression is an identifier appearing in the context of an expression.
* The input to the expression it entity associated with the variable corresponding to the identifier; the output of the expression is the same entity.
    * If the identifier corresponds to a variable that has not yet been declared; the program is ill-formed. 
    * If the identifier corresponds to a variable that has been declared but not defined; the program is ill-formed, NDR 
### Parenthesized expressions
* Parenthesized expressions take as an input the inputs to child expression and returns as outputs the outputs of the child expressions.

# Creation Expressions
## Grammar
```
creation-expression :=
      literal
    | binary-creation-expression 
```
## Literal
### Grammar
```
literal :=
      INTEGER_LITERAL 
    | FLOATING_POINT_LITERAL
```
### Semantics
* A literal creates an entity with a value always known at compile-time. 
* An integer-literal creates an entity whose value is the value of the integer-literal and whose type is the smallest type whose range contains the value.
    * If the value is out of range of all integer types; the program is ill-formed.
* A floating-point literal creates a `float64_t` whose value is the nearest IEE-754 double precision representation of the value.
    * If the floating-point literal is larger than the largest value that can be represented by a `float64_t`, the value of the created entity is ∞.
    * If a floating-point literal is smaller than the most negative value that can be represented by a `float64_t`, the value of the created entity is -∞.
    * If a floating-pointer literal is smaller than the smallest exponent of `float64_t`, the program is ill-formed.
## Binary Creation Expression 
### Grammar
```
binary-creation-expression :=
      expression "+" expression 
    | expression "-" expression 
    | expression "*" expression 
    | expression "/" expression 
    | expression "//" expression 
    | expression "^" expression 
    | expression "%" expression 
```
### Binary Addition
```
expression "+" expression
``` 
* Binary addition adds together two entities
#### Binary Integer Addition
* Binary integer addition occurs when both input entities are signed-integer types. 
* Prior to the addition, the input types will be converted to their common type then added together via signed-integer addition. 
    * The type of the output entity is the common-type of the input entities.
* If the sum is larger than the maximum value of the common-type of the input entities, signed-integer overflow occurs. 
* Binary integer addition is commutative and associative.
#### Binary Floating-Point Addition
* Binary floating-point addition occurs when the type of both input entities is a floating-point type or the type of one input entity is a signed-integer type and the type of the other input entity is a floating-point type.
* Prior to the addition, the input types will be converted to their common type then added together via floating-point addition. 
    * The addition is performed exactly then rounded to the nearest value of the common-type of the two input entities.
    * The type of the output entity is the common-type of the input entities.
* The following special values can occur as the resultant sum.
    1. If the value of either input entity is `NaN`, the value of the output entity is `NaN` and the "invalid" flag is raised.
    2. If the absolute value of the sum is greater than the maximum value that can be represented by the common-type, the value of the output entity is ∞ and the overflow flag is raised.
    3. If the absolute value of the sum is less than the minimum exponent of the the common-type, the underflow flag is raised.
* Floating-point addition is commutative.
### Binary Subtraction
```
expression "-" expression 
```
* The semantics for binary subtraction are the same as for binary addition with the following modifications:
    1. Subtraction is performed instead of addition
    2. Subtraction of signed-integers is not associative or commutative 
    3. Subtraction of floating-point numbers or a floating-point number and a signed-integer is not commutative.
### Binary Multiplication 
``` 
expression "*" expression 
```
* The semantics for binary multiplication are the same as for binary addition with the following modifications:
    1. Multiplication is performed instead of division 
### Binary Division
```
expression "/" expression 
```
* Binary division performs floating-point division on two entities. 
* If both input entities are floating-point types, they are converted to their common type, and divided using floating-point division
* If any input is a signed-integer type, it is converted to the smallest floating-point type that represents it. Then floating-point division is performed. 
* In all cases, the type of the created entity is the common-type of the input entities after any necessary conversion to a floating-point type has been performed.
* The following special values can occur as the resultant quotient
    * If the value of either input entity is `NaN`, the value of the output entity is `NaN`.
    * If the denominator is zero and the numerator is positive, the value of the output entity is ∞.
    * If the denominator and numerator are both 0, the value of the output entity is `NaN`.
    * If the denominator is 0 and the numerator is negative, the value of the output entity is -∞.
    * If the absolute value of the quotient is less than the minimum exponent of the common-type, the underflow flag is raised. 
### Binary Integer Division
```
expression "//" expression
```
* Binary integer division performs integer-division in two entities.
* The types of the two input entities must be integer types; the program is ill-formed if one or both is a floating-point type.
* The resulting quotient is calculated by exactly divided the two integers then truncating the result. 
    * x//y = floor(x/y)
* The type of the output entity is the common-type of the two input entities.
* The following special values can occur
    * If the denominator is 0 and the numerator is positive, the value of the output entity is the largest value of the common-type of the two input entities.
    * If the denominator is 0 and the numerator is non-positive, the value of the output entity is the smallest value of the common-type of the two input entities.
### Exponentiation
```
expression "^" expression
``` 
### Modulo 
```
expression "%" expression
```
* Binary modulo computes the remainder of an integer division.
    * Specifically, the modulo performs the following calculation:
        * Let x and y be two integers 
        * Let q = x // y
        * If n = x & y then n satisfies q*y + n == x
* The types of the two input entities must be integer types; the program is ill-formed if one or both is a floating-point type.
* The type of the output entity is the common-type of the two input entities.
* If the second operand to the expression is 0 then ?????