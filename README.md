# Library Management System (LMS)

Welcome to the Library Management System (LMS) repository! This project is designed to manage book borrowing and lending operations efficiently, supporting functionalities like book addition, member management, and tracking borrowed books.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Functions and Commands](#functions-and-commands)
- [Contributors](#contributors)
- [License](#license)

## Overview
The LMS is built in C and handles various operations such as adding books, members, tracking borrowed books, and identifying various statistics related to book lending. It stores data for books, members, and their borrowing history.

## Features
- **Book Management**: Add books with specified IDs and copies.
- **Member Management**: Register members with unique IDs.
- **Borrowing System**: Track borrowed books, ensuring there are enough copies available and that members don’t exceed their borrowing limit.
- **Data Retrieval**: Provides various functionalities like listing available books, identifying most borrowed books, and more.
- **Overlapping Borrowers**: Identifies members who borrowed the same book on the same day.

## Usage
The program interacts with the user via standard input. Input is expected in a specific format as described below:

1. **Books Section**: Starts with `Books:` and followed by lines containing book IDs and the number of copies.
2. **Members Section**: Starts with `Members:` followed by member IDs.
3. **Borrowed Books Section**: Contains entries with book IDs, member IDs, and dates.

The program responds to various commands as specified, such as `Number_Books`, `Book_ID_Min`, `Books_Available`, etc.

## Functions and Commands
Here are the functions provided by the code along with their explanations:

### Function: `add_book(int id, int copies)`
- Adds a book with the specified ID and number of copies.
- Limits: Max of 50 books.

### Function: `add_member(int id)`
- Adds a member with a unique ID.
- Limits: Max of 30 members.

### Function: `add_borrow(int book_id, int member_id, const char *date)`
- Records borrowing transactions.
- Ensures:
  - Valid book ID and member ID.
  - Availability of copies for the book.
  - Member borrowing limit (max of 5 books).
  
### Function: `number_books()`
- Displays the total number of books.

### Function: `number_members()`
- Displays the total number of members.

### Function: `book_id_min()`
- Prints the book with the smallest ID.

### Function: `books_available()`
- Lists all books that have available copies.

### Function: `list_book_borrowers(int book_id)`
- Lists member IDs who have borrowed the specified book.

### Function: `list_member_books(int member_id)`
- Lists book IDs borrowed by the specified member.

### Function: `most_borrowed()`
- Identifies the book(s) that have been borrowed the most.

### Function: `members_less(int n)`
- Lists members who have borrowed fewer than `n` books.

### Function: `books_unborrowed()`
- Lists books that have not been borrowed.

### Function: `books_borrowed_days()`
- Displays the number of unique borrowing dates.

### Function: `overlapping_borrowers(int book_id)`
- Identifies members who borrowed the same book on the same day.

## Contributors
- **Sameer**: `books_borrowed_days` and `overlapping_borrowers` functions.
- **Youssef**: `list_book_borrowers` and `list_member_books` functions.
- **Ayman**: `book_id_min`, `books_available`, `most_borrowed`, `members_less`, and `books_unborrowed` functions.
- **Kareem & Omar**: Core structure and initial functionality.
- **Shawaf**: Helper functions `add_book`, `add_member`, `number_books`, `number_members`.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
