#include <gtest/gtest.h>
#include "ringbuffer.h"
//n‰‰ on pathaat testit
TEST(SuperTEST,INIT)
{
unsigned char buff[MAX_BUFFER];
struct buffer_type b;

init_buffer(&b,buff);
assert(b.head==buff);
assert(b.tail==buff);
assert(b.buffer==buff);
}

TEST(SuperTEST,EMPTY)
{
unsigned char buff[MAX_BUFFER];
struct buffer_type b;

init_buffer(&b,buff);

b.head=b.head+5;
b.tail=b.tail+2;
empty_buffer(&b);
assert(b.head==b.tail);
}

TEST(SuperTEST,STATUS)
{
unsigned char buff[MAX_BUFFER];
struct buffer_type b;
int err;

init_buffer(&b,buff);
assert(get_buffer_status(b,&err)==0);

b.tail=b.tail+5;

EXPECT_EQ(3,get_buffer_status(b,&err));
}

TEST(SuperTEST,ADDCHAR)
{
unsigned char buff[MAX_BUFFER];
struct buffer_type b;
int err;

init_buffer(&b,buff);

EXPECT_EQ(1,add_char_to_buffer(&b,'c', &err));
add_char_to_buffer(&b,'c', &err);
add_char_to_buffer(&b,'c', &err);
EXPECT_EQ(4,add_char_to_buffer(&b,'c', &err));
}

TEST(SuperTEST,GETCHAR)
{
unsigned char buff[MAX_BUFFER];
struct buffer_type b;
int err;
int i;
init_buffer(&b,buff);

for(i=0;i<=MAX_BUFFER;i++)
	{
	add_char_to_buffer(&b,i, &err);
	EXPECT_EQ(i,get_char_from_buffer(&b, &err));
	};

for(i=0;i<=(MAX_BUFFER+30);i++)
	{
	add_char_to_buffer(&b,i, &err);
	EXPECT_EQ(i,get_char_from_buffer(&b, &err));
	};
}

TEST(SuperTEST,PRINT)
{
unsigned char buff[MAX_BUFFER];
struct buffer_type b;
int err;
unsigned char start,end;

init_buffer(&b,buff);

add_char_to_buffer(&b,'a', &err);
add_char_to_buffer(&b,'b', &err);
add_char_to_buffer(&b,'c', &err);

start=*(b.tail);

EXPECT_EQ(3,print_buffer(b,&err));

end=*(b.tail);
assert(start==end);
}

TEST(SuperTEST,ADDSTRING)
{
unsigned char buff[MAX_BUFFER];
struct buffer_type b;
int err;
unsigned char string[]="moro";

init_buffer(&b,buff);

EXPECT_EQ(4,add_string_to_buffer(&b,string,&err));
add_string_to_buffer(&b,string,&err);
EXPECT_EQ(-1,add_string_to_buffer(&b,string,&err));
}

TEST(SuperTEST,GETSTRING)
{
unsigned char buff[MAX_BUFFER];
struct buffer_type b;
int err;
unsigned char string1[20]="\0";
unsigned char string2[]="heippa";

init_buffer(&b,buff);

add_string_to_buffer(&b,string2,&err);

EXPECT_EQ(5,get_string_from_buffer(&b,string1,5,&err));

printf("%s",string1);

}