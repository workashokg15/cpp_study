Template Pattern
================
- **Allows us to define the skeleton of the algorithm, with concrete implementations defined in subclasses.**

    -   Algorithms can be decomposed into common parts + specifics
    - Strategy pattern does this through composition
        -   High level algorithms uses an interface
        - Concrete implementations implement the interface
    - Template Method does this tthrough inheritance
        - Overall algorithm makes use of abstract member
        - Inheritors override the abstract class
        - Parent template method invoked
