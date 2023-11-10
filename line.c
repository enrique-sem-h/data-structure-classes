#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct Line{
    int start, end;
    int items[MAX];
}Line;

void initLine(Line *line){
    line->start = -1;
    line->end = -1;
}

int isEmpty(Line *line){
    return (line->start == -1 && line->end == -1) || (line->start > line->end);
}

int isFull(Line *line){
    return (line->end + 1) % MAX == line->start;
}

void append(Line *line, int data){
    if (isFull(line)){
        printf("the line is full\n");
    } else {
        if (line->start == -1){
            line->start = 0;
        }
        line->items[++line->end] = data;
    }
}

int removeItem(Line *line){
    if(isEmpty(line)){
        printf("The line is empty\n");
        return -1;
    }
        return line->items[line->start++];
}

void print(Line *line){
    for(int i = 0; i <= line->end; i++){
        if(i >= line->start){
        printf("item %d: %d\n", i - line->start + 1, line->items[i]);
        }
    }
}

int main(){
    Line line;
    initLine(&line);

    append(&line, 1);
    append(&line, 2);
    append(&line, 3);
    append(&line, 4);
    append(&line, 5);
    append(&line, 6);

    print(&line);

    printf("Item deleted: %d\n", removeItem(&line));
    print(&line);
}