* An expression takes as input one ore more entities and returns one or more entities.
* There are three types of expressions: identity expression that return the same entity; creation expression that creates a new entity from its inputs, and transformation expression that modify one or more of its input entities.
    * A creation expression may not modify its inputs 
    * A transformation expression may produce a new entity in additional to modifying an input entity. 
# Identity Expressions
## Grammar
    `identity-expression := IDENTIFIER`
* The identity expression is an identifier appearing in the context of an expression.
* The input to the expression it entity associated with the variable corresponding to the identifier; the output of the expression is the same entity.
    * If the identifier corresponds to a variable that has not yet been declared; the program is ill-formed. 
    * If the identifier corresponds to a variable that has been declared but not defined; the program is ill-formed.