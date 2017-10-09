
#include "ringbuffer.h"


void init_buffer(struct buffer_type *b, unsigned char *buffer)
{
    b->head=buffer;
    b->tail=buffer;
    b->buffer=buffer;
};

void empty_buffer(struct buffer_type *b)
{
	b->tail=b->head;
};

signed int get_buffer_state(struct buffer_type b, error_type *err)
{
	int length=b.head-b.tail;

	if(length<0)
		{
		length=length+MAX_BUFFER;
		}
	if(length>=0 && length<=MAX_BUFFER)
		{
		*err= OK;
		return length;
		}
	else
		{
		*err= BUFFER_OVER_FLOW;
		return -1;
		};
};
int add_char_to_buffer(struct buffer_type *b, unsigned char c, error_type *err)
{
	if(b->head<(b->buffer+MAX_BUFFER-1))
		{
		 	*(b->head)=c;
			
			b->head++;
		}
	else if((b->head==(b->buffer+MAX_BUFFER-1)) && (b->tail!=b->buffer))
		{
		 	*(b->head)=c;			
			b->head=b->buffer;
		}
	else
		{
			*err= BUFFER_FULL;
			return -1;
		};
	*err= OK;
	return get_buffer_status(*b,err);
};
unsigned char get_char_from_buffer(struct buffer_type *b, error_type *err)
{
	unsigned char reijo;
	if(b->tail<(b->buffer+MAX_BUFFER-1) && (b->tail!=b->head))
		{
		 	reijo=*(b->tail);			
			b->tail++;
		}
	else if(b->tail==(b->buffer+MAX_BUFFER-1))
		{
		 	reijo=*(b->tail);			
			b->tail=b->buffer;
		}
	else
		{
			*err= BUFFER_FULL;
			return -1;
		};
	*err=OK;
	return reijo;
	
};
int print_buffer(struct buffer_type b, error_type *err)
{
	unsigned char *head=b.head;
	unsigned char *tail=b.tail;
	unsigned char *buffer=b.buffer;
	unsigned char c;
	int amount=0;
	
	while(head!=tail)
		{
			//c=*tail;
			//printf("%c",c);
			//tail++;
			if(tail<(buffer+MAX_BUFFER-1) && (tail!=head))
				{
					c=*tail;			
					tail++;
				}
			else if(tail==(buffer+MAX_BUFFER-1))
				{
					c=*tail;			
					tail=buffer;
				}
			else
				{	
					*err=EMPTY_BUFFER;
					return -1;
				};
			printf("%c",c);
			amount++;
		};
	printf("\n");
	*err=OK;
	return amount;
};

int add_string_to_buffer(struct buffer_type *b, unsigned char *s, error_type *err)
{
	int check1,check2,i;
	check1=get_buffer_status(*b,err);
	check2=my_strlen(s);
	
	if(check2 <= (MAX_BUFFER-check1))
		{
			for(i=0; i<check2; i++)
				{
					add_char_to_buffer(b, *(s+i), err);
				};
			*err=OK;
			return check2;
		}
	else
		{
			*err=BUFFER_FULL;
			return -1;
		};
	
};
int  get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, error_type *err)
{
	int i;
			
	for(i=0; i<=len; i++)
		{
			*(dest+i)=get_char_from_buffer(b, err);			
		};
	*err=OK;
	return i-1;

};

int my_strlen(unsigned char *c)
{
	int i=0;
	
	while(*(c+i) != '\0')
		{
		i++;
		}
	return i;
};