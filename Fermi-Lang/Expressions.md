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
### Literal
#### Grammar
```
literal :=
      INTEGER_LITERAL 
    | FLOATING_POINT_LITERAL
```
#### Semantics
* A literal creates an entity with a value always known at compile-time. 
* An integer-literal creates an entity whose value is the value of the integer-literal and whose type is the smallest type whose range contains the value.
    * If the value is out of range of all integer types; the program is ill-formed.
* A floating-point literal creates a `float64_t` whose value is the nearest IEE-754 double precision representation of the value.
    * If the floating-point literal is larger than the largest value that can be represented by a `float64_t`, the value of the created entity is ∞.
    * If a floating-point literal is smaller than the most negative value that can be represented by a `float64_`, the value of the created entity is -∞.
### Binary Creation Expression 
#### Grammar
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
#### Binary Addition
```
expression "+" expression
``` 
* Binary addition adds together two entities
* If the type of both input entities is a signed-integer type, they wil be converted to their common-type if necessary, and added together using signed-integer addition.
    * If the resulting value is larger than the maximum value of common-type of the input entities, signed integer overflow occurs.
* If the type of both input entities is a floating-point type, they will be converted their common-type if necessary, and added together using floating-point addition.
    * If the resulting value is larger than the maximum value of the common-type of the input entities, infinity is returned.
* If one of the input entities is a floating-point type and one is a signed-integer type, they will be converted to their common-type and added together using floating-point addition.
    * If the resulting value is larger than the maximum value of the common-type of the input entities, infinity is returned.
* In all cases, the type of the created entity is the common-type of the input entities.
* The input entities are not modified.
* The addition of two signed-integers is associative and commutative; the addition of two floating-point numbers or a floating-point number and a signed-integer is only commutative.
#### Binary Subtraction
```
expression "-" expression 
```
* The semantics for binary subtraction are the same as for binary addition with the following modifications:
    1. Subtraction is performed instead of addition
    2. Subtraction of signed-integers is not associative or commutative 
    3. Subtraction of floating-point numbers or a floating-point number and a signed-integer is not commutative.