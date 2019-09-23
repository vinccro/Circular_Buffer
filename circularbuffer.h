#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#define DEBUG 1
#define LENGTH 3
#define BUFFER_LENGTH (LENGTH + 1)
#define MOD(a,b) ((((a)%(b))+(b))%(b))



typedef int buffer_t;


typedef struct c_buffer{
        buffer_t data[BUFFER_LENGTH];
        unsigned int size;
        unsigned int start;
        unsigned int end;
} c_buffer;

//typedef int buffer_t;

int isfull(c_buffer*);
int isempty(c_buffer*);
int push(c_buffer*, buffer_t);
buffer_t pull(c_buffer*);


#define CIRCULAR_BUFFER_MAKE(name) \
        c_buffer name = {\
        .data = {0},\
        .size = BUFFER_LENGTH,\
        .start = 0,\
        .end = 0,\
}

#endif