# User-Books Database Documentation

## Structure
```cpp
database = {
    (UserData) {
        "john", { 
            (BookAndDue) {"book1", 7},
            (BookAndDue) {"book2", 3}
        }
    },
    (UserData) {
        "gabe", {
            (BookAndDue) {"book2", 3},
            (BookAndDue) {"book4", 3},
            (BookAndDue) {"book5", 4}
        }
    }
};

### The `UserData` struct
```cpp
/* Struct that has a username and their borrowed books */
typedef struct UserData {

    /* Username */
    std::string username;

    /* List of the books and their due dates */
    std::vector<Book> borrowedBooks;

} UserData;
```

## Locating where things are
```cpp
// to find the first book a person has borrowed:
return database[userIndex].borrowedBooks[0].title;
```
`database[userIndex]` accesses a UserData struct at a specific index.  
`.borrowedBooks[0]` accesses the first BookAndDue struct inside the borrowedBooks vector, which is the first entry.  
`.title` accesses the title of the book.

## Changing things
```cpp
// to delete the last book a person has borrowed:
database[userIndex].borrowedBooks.pop_back()
```
`database[userIndex]` accesses a UserData struct at a specific index.  
`.borrowedBooks` accesses the borrowedBooks vector.
`.pop_back()` deletes the last item in the vector.