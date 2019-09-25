#include "circularbuffer.h"

#ifdef DEBUG
#include <stdlib.h>
#include <stdio.h>
#endif


int push(c_buffer* buf, buffer_t element){
        if( isfull(buf)  ) return 0;
        else{
                buf->data[buf->end] = element;
                buf->end = MOD((buf->end+1), BUFFER_LENGTH);
                return 1;
                }
}

buffer_t pull(c_buffer* buf){
        if(isempty(buf)) return 0;
        else{
                buffer_t hold = buf->data[buf->start];
                buf->start = MOD( (buf->start+1), BUFFER_LENGTH);
                return hold;
        }
}

int isempty(c_buffer* buf){
        return (buf->start == buf->end) ? 1 : 0;
}
int isfull(c_buffer* buf){
        return (MOD( (buf->start-1), BUFFER_LENGTH) == buf->end) ? 1 : 0;
}
#ifdef DEBUG
int printBuffer(c_buffer* buf){
        for( int pp = 0; pp<(BUFFER_LENGTH); pp++){
                printf("%d,", buf->data[pp]);
        }
}
#endif