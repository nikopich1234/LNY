#include <stdio.h>
#include <string.h>

#define MAX 15

typedef union BookInfo{
    int pages;
    float file_size;
    float duration;
} BookInfo;

typedef enum BookType{
    paper,
    ebook,
    audio
} BookType;

typedef struct Books{
    char name[50];
    char author[50];
    int year;
    BookType type;
    BookInfo info;
} Books;

void swap(Books *a, Books *b){
    Books temp = *a;
    *a = *b;
    *b = temp;
}

int compare(Books *a, Books *b){
    if(a->year == b->year){
        return 0;
    }
    else if(a->year > b->year){
        return 1;
    }
    return -1;
}

void sortBooks(Books arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(compare(&arr[j],&arr[j+1]) == -1){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printRow(Books* book){
    printf("|%-12s|%-18s|%-6i|",book->author,book->name,book->year);
    switch(book->type){
        case paper:
            printf("%-5s | pages: %i", "paper", book->info.pages);
            break;
        case ebook:
            printf("%-5s | size: %lf", "ebook", book->info.file_size);
            break;
        case audio:
            printf("%-5s | duration: %lf", "audio", book->info.duration);
            break;
        default:
            printf("-");
    }
    printf("\n");
}

void printData(Books arr[], int n){
    for(int i = 0; i < n; i++){
        printf("#|%-2i", i+1);
        printRow(&arr[i]);
    }
}

int filter(Books arr[], int n, int year){
    int count = 0;

    for(int i = 0; i < n; i++){
        if(arr[i].year > year){
            if(i != count){
                arr[count] = arr[i];
            }
            count++;
        }
    }
    return count;
}

Books modifyItem(Books book){
    if(book.type == ebook){
        book.info.file_size *=1.2;
    }
    return book;
}

int main(){
    Books arr[MAX] = {
    {"Kobzar",             "Shevchenko", 1840, paper, .info.pages = 320},
    {"Clean Code",         "R. Martin",  2008, ebook, .info.file_size = 4.5f},
    {"Dune",               "F. Herbert", 1965, audio, .info.duration = 21.0f},
    {"1984",               "G. Orwell",  1949, paper, .info.pages = 328},
    {"Sapiens",            "Y. Harari",  2011, ebook, .info.file_size = 6.2f},
    {"Atomic Habits",      "J. Clear",   2018, audio, .info.duration = 5.5f},
    {"The Hobbit",         "J. Tolkien", 1937, paper, .info.pages = 310},
    {"Pragmatic Prog.",    "A. Hunt",    1999, ebook, .info.file_size = 3.8f},
    {"Project Hail Mary",  "A. Weir",    2021, audio, .info.duration = 16.1f},
    {"Zakhar Berkut",      "I. Franko",  1883, paper, .info.pages = 240},
    {"Fahrenheit 451",     "R. Bradbury",1953, paper, .info.pages = 256},
    {"The Martian",        "A. Weir",    2011, ebook, .info.file_size = 2.9f}
    };
    int n = 12;
    printf("Data:\n");
    printData(arr,n);
    arr[11] = modifyItem(arr[11]);
    printf("Sorted data:\n");
    sortBooks(arr, n);
    printData(arr,n);
    printf("Filtered data:\n");
    n = filter(arr, n, 2008);
    printData(arr,n);

    return 0;
}