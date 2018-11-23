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
`void setFieldWidth(size_t)`  
   - Sets the field width of the current object.

 `size_t getFieldWidth() const`  
   - Returns the field width of the current object.

`const std::string extractToken(const std::string& str, size_t& next_pos, bool& more)`  
   - Extracts tokens from `str`.  
   - This extracts the token start at position `next_pos`.  
   - If the extraction is successful it sets `more` to true or false depending if there are more tokens to extract.  
   - This function returns a string of the token found.  
   - This function will throw an exception if:  
        - There are no more tokens to be extract  
        - `next_pos` is out of bounds of `str`

```static void setDelimiter(const char&)```  
    - Sets the delimiter character. The delimiter character is a shared value accross all instances of Utilities.

```const char getDelimiter() const```  
    - Returns the delimiter character.

*My intention with uploading school assignments on GitHub is merely to build a portfolio of my work.* **_Please do not plagiarize._**
