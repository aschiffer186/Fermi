# Introduction 
* A statement is the smallest unit of executable code. 
# Expression Statement 
```
expression-statement := expression ";"
```
* An expression statement executes its child expression
# Variable Declaration Statement
```
variable-declaration :=
      "let" IDENTIFIER ":" type
    | "let" IDENTIFIER ":" type "=" expression 
    | "let" IDENTIFIER ":" type "=" expression
```
* A variable declaration introduces a new name and associates an entity with the variable.
* If the type of the variable is given in the variable declaration; the type of the variable and the associated entity is the given type. 
    * If an initializer is provided, the type of the output entity of the expression must be implicitly convertible to the type of the variable.
* If no type is given; the type is deduced from the initializer.
* The lifetime of a variable begins when it is declared and continues until the end of its enclosing scope; however, no memory is allocated for the associated entity's associated object until the first time it is assigned to.
* If an initializer is present, memory is allocated for the the associated entity's associated object and the value of the output entity of the initializer expression is copied into the variable's associated entity.
# Assignment Statement
```
assignment-statement :=
    IDENTIFIER "=" expression ";"
```
* An assignment statement executes the expression and copies the value of the output entity of the expression into the associated entity of the identifier
* If the identifier has not yet been defined, the program is ill-formed
* If the type of the output entity and the type of the entity associated with the identifier are not the same, one of the following happens
    * If the output type of the expression can be implicitly converted to the type of the identifier's associated entity, an implicit conversion is done 
    * Otherwise, the program is ill-formed