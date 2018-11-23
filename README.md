# OOP345 Final Project

The purpose of this term project is to put my C++ Object Oriented skills to practice by developing a simulated Assembly Line.

Below is a check list of the modules that are to be implemented to the project:
- [x] Utilities
    - Used to parse strings and help populate data for other modules.
- [x] Item
    - Manages a single item on the assembly line.
- [x] CustomerOrder
    - Used to encapsulate and manage all the details related to a customer's order on the assembly line.
- [ ] Task
    - Inherits from the Item module, and will contain additional information:
        - a double ended queue with CustomerOrders, coming in one side and exited out the other once it is filled.
        - a pointer to the next task on the assembly line.
- [ ] LineManager
    - Manages the entire assembly line

Here you can find a documentation of the classes that are currently implemented:

### Utilities
```setFieldWidth```

```getFieldWidth```

```extractToken```

```setDelimiter```

```getDelimiter```

*My intention with uploading school assignments on GitHub is merely to build a portfolio of my work.* **_Please do not plagiarize._**