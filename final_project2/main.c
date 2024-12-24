#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int book_ids[50];
int book_copies[50];
int book_borrowed_counts[50];

int member_ids[30];
int member_borrowed_counts[30];

int borrow_book_ids[100];
int borrow_member_ids[100];
char borrow_dates[100][12];

int book_count = 0, member_count = 0, borrow_count = 0;

void add_book(int id, int copies) {
    book_ids[book_count] = id;
    book_copies[book_count] = copies;
    book_borrowed_counts[book_count] = 0;
    book_count++;
}

void add_member(int id) {
    member_ids[member_count] = id;
    member_borrowed_counts[member_count] = 0;
    member_count++;
}

void add_borrow(int book_id, int member_id, const char *date) {
    borrow_book_ids[borrow_count] = book_id;
    borrow_member_ids[borrow_count] = member_id;
    strcpy(borrow_dates[borrow_count], date);
    borrow_count++;

    for (int i = 0; i < book_count; i++) {
        if (book_ids[i] == book_id) {
            book_borrowed_counts[i]++;
            break;
        }
    }

    for (int i = 0; i < member_count; i++) {
        if (member_ids[i] == member_id) {
            member_borrowed_counts[i]++;
            break;
        }
    }
}

void number_books() {
    printf("%d\n", book_count);
}

void number_members() {
    printf("%d\n", member_count);
}

void book_id_min() {
    if (book_count == 0) {
        printf("none\n");
        return;
    }

    int min_id = book_ids[0];

    for (int i = 1; i < book_count; i++) {
        if (book_ids[i] < min_id) {
            min_id = book_ids[i];
        }
    }

    printf("%d\n", min_id);
}

void books_available() {
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (book_copies[i] > book_borrowed_counts[i]) {
            printf("%d\n", book_ids[i]);
            found = 1;
        }
    }
    if (!found) printf("none\n");
}

void list_book_borrowers(int book_id) {
    int found = 0;
    for (int i = 0; i < borrow_count; i++) {
        if (borrow_book_ids[i] == book_id) {
            printf("%d\n", borrow_member_ids[i]);
            found = 1;
        }
    }
    if (!found) printf("none\n");
}

void list_member_books(int member_id) {
    int found = 0;
    for (int i = 0; i < borrow_count; i++) {
        if (borrow_member_ids[i] == member_id) {
            printf("%d\n", borrow_book_ids[i]);
            found = 1;
        }
    }
    if (!found) printf("none\n");
}

void most_borrowed() {
    if (book_count == 0) {
        printf("none\n");
        return;
    }

    int max_borrows = 0;
    for (int i = 0; i < book_count; i++) {
        if (book_borrowed_counts[i] > max_borrows) {
            max_borrows = book_borrowed_counts[i];
        }
    }

    if (max_borrows == 0) {
        printf("none\n");
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (book_borrowed_counts[i] == max_borrows) {
            printf("%d\n", book_ids[i]);
        }
    }
}

void members_less(int n) {
    int found = 0;
    for (int i = 0; i < member_count; i++) {
        if (member_borrowed_counts[i] < n) {
            printf("%d\n", member_ids[i]);
            found = 1;
        }
    }
    if (!found) printf("none\n");
}

void books_unborrowed() {
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (book_borrowed_counts[i] == 0) {
            printf("%d\n", book_ids[i]);
            found = 1;
        }
    }
    if (!found) printf("none\n");
}

void books_borrowed_days() {
    int unique_days = 0;
    for (int i = 0; i < borrow_count; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(borrow_dates[i], borrow_dates[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) unique_days++;
    }
    printf("%d\n", unique_days);
}

void books_per_member() {
    for (int i = 0; i < member_count; i++) {
        printf("%d %d\n", member_ids[i], member_borrowed_counts[i]);
    }
}

void overlapping_borrowers(int book_id) {
    int found = 0;
    for (int i = 0; i < borrow_count; i++) {
        if (borrow_book_ids[i] == book_id) {
            for (int j = i + 1; j < borrow_count; j++) {
                if (borrow_book_ids[j] == book_id && strcmp(borrow_dates[i], borrow_dates[j]) == 0) {
                    printf("%d\n%d\n", borrow_member_ids[i], borrow_member_ids[j]);
                    found = 1;
                }
            }
        }
    }
    if (!found) printf("none\n");
}

int main() {
    char input[100];


    fgets(input, sizeof(input), stdin);


    if (strcmp(input, "Books:\n") != 0) {
        printf("Error: Input must start with 'Books:'\n");
        return 1;
    }


    while (fgets(input, sizeof(input), stdin)) {
        if (strcmp(input, "Members:\n") == 0) break;
        int id, copies;
        sscanf(input, "%d %d", &id, &copies);
        add_book(id, copies);
    }


    while (fgets(input, sizeof(input), stdin)) {
        if (strcmp(input, "Borrowed_Books:\n") == 0) break;
        int id;
        sscanf(input, "%d", &id);
        add_member(id);
    }


    while (fgets(input, sizeof(input), stdin)) {
        if (input[0] == '^') break;
        int book_id, member_id;
        char date[12];
        sscanf(input, "%d %d %s", &book_id, &member_id, date);
        add_borrow(book_id, member_id, date);
    }


    while (fgets(input, sizeof(input), stdin)) {
        if (strcmp(input, "Quit\n") == 0) break;
        input[strcspn(input, "\n")] = 0; // to remove newline from command

        if (strcmp(input, "Number_Books") == 0) {
            number_books();
        } else if (strcmp(input, "Number_Members") == 0) {
            number_members();
        } else if (strcmp(input, "Book_ID_Min") == 0) {
            book_id_min();
        } else if (strcmp(input, "Books_Available") == 0) {
            books_available();
        } else if (strcmp(input, "Most_Borrowed") == 0) {
            most_borrowed();
        } else if (strncmp(input, "List_Book_Borrowers", 19) == 0) {
            int book_id = atoi(input + 20);
            list_book_borrowers(book_id);
        } else if (strncmp(input, "List_Member_Books", 17) == 0) {
            int member_id = atoi(input + 18);
            list_member_books(member_id);
        } else if (strncmp(input, "Members_Less", 12) == 0) {
            int n = atoi(input + 13);
            members_less(n);
        } else if (strcmp(input, "Books_Unborrowed") == 0) {
            books_unborrowed();
        } else if (strcmp(input, "Books_Borrowed_Days") == 0) {
            books_borrowed_days();
        } else if (strcmp(input, "Books_Per_Member") == 0) {
            books_per_member();
        } else if (strncmp(input, "Overlapping_Borrowers", 21) == 0) {
            int book_id = atoi(input + 22);
            overlapping_borrowers(book_id);
        }
    }

    printf("Thanks!\n");
    return 0;
}
