#include "unity.h"
#include "libft.h"
#include <ctype.h>
#include <string.h>

void setUp(void) {
//    This function runs before each test
}

void tearDown(void) {
//    This function runs after each test
}

/* Original isalpha() returns non-zero value if the character is alphabetical */
void test_isalpha_1(void) {
    TEST_ASSERT_EQUAL_INT(1, ft_isalpha('a'));
    TEST_ASSERT_EQUAL_INT(1, ft_isalpha('A'));
    TEST_ASSERT_EQUAL_INT(1, ft_isalpha('Z'));
}

void test_isalpha_0(void) {
    TEST_ASSERT_EQUAL_INT(0, ft_isalpha(0));
    TEST_ASSERT_EQUAL_INT(0, ft_isalpha('0'));
    TEST_ASSERT_EQUAL_INT(0, ft_isalpha(' '));
    TEST_ASSERT_EQUAL_INT(0, ft_isalpha('&'));
}

void test_isdigit_1(void) {
    TEST_ASSERT_EQUAL_INT(1, ft_isdigit('0'));
    TEST_ASSERT_EQUAL_INT(1, ft_isdigit('1'));
}

void test_isdigit_0(void) {
    TEST_ASSERT_EQUAL_INT(0, ft_isdigit('&'));
    TEST_ASSERT_EQUAL_INT(0, ft_isdigit('a'));
    TEST_ASSERT_EQUAL_INT(0, ft_isdigit(' '));
    TEST_ASSERT_EQUAL_INT(0, ft_isdigit('Z'));
    TEST_ASSERT_EQUAL_INT(0, ft_isdigit(2));
}

void test_isalnum_1(void) {
    TEST_ASSERT_EQUAL_INT(1, ft_isalnum('a'));
    TEST_ASSERT_EQUAL_INT(1, ft_isalnum('A'));
    TEST_ASSERT_EQUAL_INT(1, ft_isalnum('Z'));
    TEST_ASSERT_EQUAL_INT(1, ft_isalnum('0'));
    TEST_ASSERT_EQUAL_INT(1, ft_isalnum('1'));
}

void test_isalnum_0(void) {
    TEST_ASSERT_EQUAL_INT(0, ft_isalnum('&'));
    TEST_ASSERT_EQUAL_INT(0, ft_isalnum(' '));
    TEST_ASSERT_EQUAL_INT(0, ft_isalnum(2));
    TEST_ASSERT_EQUAL_INT(0, ft_isalnum(0));
}

void test_isascii_1(void) {
    TEST_ASSERT_EQUAL_INT(1, ft_isascii('A'));
    TEST_ASSERT_EQUAL_INT(1, ft_isascii('0'));
    TEST_ASSERT_EQUAL_INT(1, ft_isascii('&'));
    TEST_ASSERT_EQUAL_INT(1, ft_isascii(127));
    TEST_ASSERT_EQUAL_INT(1, ft_isascii(' '));
}

void test_isascii_0(void) {
    TEST_ASSERT_EQUAL_INT(0, ft_isascii(-1));
    TEST_ASSERT_EQUAL_INT(0, ft_isascii(128));
    TEST_ASSERT_EQUAL_INT(0, ft_isascii(255));
}

void test_isprint_1(void) {
    TEST_ASSERT_EQUAL_INT(1, ft_isprint('A'));
    TEST_ASSERT_EQUAL_INT(1, ft_isprint('0'));
    TEST_ASSERT_EQUAL_INT(1, ft_isprint('&'));
    TEST_ASSERT_EQUAL_INT(1, ft_isprint(' '));
}

void test_isprint_0(void) {
    TEST_ASSERT_EQUAL_INT(0, ft_isprint(-1));
    TEST_ASSERT_EQUAL_INT(0, ft_isprint(127));
}

void test_strlen_equal(void) {
    TEST_ASSERT_EQUAL(strlen("hola"), ft_strlen("hola"));
    TEST_ASSERT_EQUAL(strlen("hola\0"), ft_strlen("hola\0"));
    TEST_ASSERT_EQUAL(strlen(""), ft_strlen(""));
    TEST_ASSERT_EQUAL(strlen("a"), ft_strlen("a"));
    TEST_ASSERT_EQUAL(strlen("hola\nmundo\t!"), ft_strlen("hola\nmundo\t!"));
}

void test_memset_equal(void) {
    /* Length > size test*/
    unsigned char   p1[5] = "hola";
    unsigned char   p2[5] = "hola";

    memset(p1, 'a', 2);
    ft_memset(p2, 'a', 2);
    TEST_ASSERT_EQUAL_MEMORY(p1, p2, 5);

    /* Empty character */
    memcpy(p1, "hola", 5);
    memcpy(p2, "hola", 5);

    memset(p1, 0, 2);
    ft_memset(p2, 0, 2);
    TEST_ASSERT_EQUAL_MEMORY(p1, p2, 5);

    /* n = 0 */
    memcpy(p1, "hola", 5);
    memcpy(p2, "hola", 5);

    size_t n = 0;
    memset(p1, 'a', n);
    ft_memset(p2, 'a', n);
    TEST_ASSERT_EQUAL_MEMORY(p1, p2, 5);
}

void test_bzero_equal(void) {
    /* Length > size test*/
    unsigned char   s1[5] = "hola";
    unsigned char   s2[5] = "hola";

    bzero(s1, 2);
    ft_bzero(s2, 2);
    TEST_ASSERT_EQUAL_MEMORY(s1, s2, 5);

    /* n = 0 */
    memcpy(s1, "hola", 5);
    memcpy(s2, "hola", 5);

    bzero(s1, 0);
    ft_bzero(s2, 0);
    TEST_ASSERT_EQUAL_MEMORY(s1, s2, 5);
}

void test_memcpy_equal(void) {
    /* Length > size test*/
    unsigned char   d1[5] = "hola";
    unsigned char   s1[5] = "hola";

    unsigned char   d2[5] = "hola";
    unsigned char   s2[5] = "hola";

    memcpy(d1, s1, 2);
    ft_memcpy(d2, s2, 2);
    TEST_ASSERT_EQUAL_MEMORY(d1, d2, 5);

    /* Empty character */
    memcpy(d1, "hola", 5);
    memcpy(d2, "hola", 5);

    unsigned char   p2[5];

    memcpy(d1, p2, 2);
    ft_memcpy(d2, p2, 2);
    TEST_ASSERT_EQUAL_MEMORY(d1, d2, 5);

    /* n = 0 */
    memcpy(d1, "hola", 5);
    memcpy(d2, "hola", 5);

    memcpy(d1, s1, 2);
    ft_memcpy(d2, s2, 2);
    TEST_ASSERT_EQUAL_MEMORY(d1, d2, 5);
}

void test_strlcpy_equal(void) {
    /* Buffer == 0 */
    char   d1[20];
    char   d2[20];
    char   s1[5] = "hola";
    char   s2[5];

    TEST_ASSERT_EQUAL_MEMORY(strlcpy(d1, s1, 0), ft_strlcpy(d2, s1, 0), 5);

    /* Buffer > src */
    char   p1[20];
    char   p2[20];

    TEST_ASSERT_EQUAL_MEMORY(strlcpy(p1, s1, 8), ft_strlcpy(p2, s1, 8), 5);

    /* Empty src */
    char   a1[20];
    char   a2[20];

    TEST_ASSERT_EQUAL_MEMORY(strlcpy(a1, s2, 3), ft_strlcpy(a2, s2, 3), 5);
}

void test_strlcat_equal(void) {
    /* Buffer == 0 */
    char   d1[20] = "hola ";
    char   d2[20] = "hola ";
    char   s1[9] = "caracola";
    char   s2[9];

    TEST_ASSERT_EQUAL(strlcat(d1, s1, 0), ft_strlcat(d2, s1, 0));

    /* Buffer > src */
    char   p1[20] = "hola ";
    char   p2[20] = "hola ";

    TEST_ASSERT_EQUAL(strlcat(p1, s1, 12), ft_strlcat(p2, s1, 12));

    /* Empty src */
    char   a1[20] = "hola ";
    char   a2[20] = "hola ";

    TEST_ASSERT_EQUAL(strlcat(a1, s2, 3), ft_strlcat(a2, s2, 3));
}

void test_toupper_equal(void) {

    TEST_ASSERT_EQUAL(toupper('a'), ft_toupper('a'));
    TEST_ASSERT_EQUAL(toupper('D'), ft_toupper('D'));
    TEST_ASSERT_EQUAL(toupper('-'), ft_toupper('-'));
    TEST_ASSERT_EQUAL(toupper(9), ft_toupper(9));
}

void test_tolower_equal(void) {

    TEST_ASSERT_EQUAL(tolower('a'), ft_tolower('a'));
    TEST_ASSERT_EQUAL(tolower('D'), ft_tolower('D'));
    TEST_ASSERT_EQUAL(tolower('-'), ft_tolower('-'));
    TEST_ASSERT_EQUAL(tolower(9), ft_tolower(9));
}

void test_strchr_equal(void) {

    const char *s = "holacaracola";
    const char *d = "";

    TEST_ASSERT_EQUAL(strchr(s, 'r'), ft_strchr(s, 'r'));
    TEST_ASSERT_EQUAL(strchr(s, 'y'), ft_strchr(s, 'y'));
    TEST_ASSERT_EQUAL(strchr(d, 'y'), ft_strchr(d, 'y'));
    TEST_ASSERT_EQUAL(strchr(d, '\0'), ft_strchr(d, '\0'));
    TEST_ASSERT_EQUAL(strchr(s, '\0'), ft_strchr(s, '\0'));
}

void test_strrchr_equal(void) {

    const char *s = "holacaracola";
    const char *d = "";

    TEST_ASSERT_EQUAL(strrchr(s, 'o'), ft_strrchr(s, 'o'));
    TEST_ASSERT_EQUAL(strrchr(s, 'y'), ft_strrchr(s, 'y'));
    TEST_ASSERT_EQUAL(strrchr(d, 'y'), ft_strrchr(d, 'y'));
    TEST_ASSERT_EQUAL(strrchr(d, '\0'), ft_strrchr(d, '\0'));
    TEST_ASSERT_EQUAL(strrchr(s, '\0'), ft_strrchr(s, '\0'));
}

void test_strncmp_equal(void) {

    TEST_ASSERT_EQUAL(strncmp("abc", "abc", 3), ft_strncmp("abc", "abc", 3));
    TEST_ASSERT_EQUAL(strncmp("abc", "abd", 3), ft_strncmp("abc", "abd", 3));
    TEST_ASSERT_EQUAL(strncmp("abcX", "abcY", 3), ft_strncmp("abcX", "abcY", 3));
    TEST_ASSERT_EQUAL(strncmp("abc", "ab", 3), ft_strncmp("abc", "ab", 3));
    TEST_ASSERT_EQUAL(strncmp("abc", "def", 0), ft_strncmp("abc", "def", 0));
    TEST_ASSERT_EQUAL(strncmp("\200", "\0", 1), ft_strncmp("\200", "\0", 1));
    TEST_ASSERT_EQUAL(strncmp("a\0c", "a\0b", 3), ft_strncmp("a\0c", "a\0b", 3));
}

void test_memchr_equal(void) {

    TEST_ASSERT_EQUAL(memchr("abc", 'a', 1), ft_memchr("abc", 'a', 1));
    TEST_ASSERT_EQUAL(memchr("abc", 'a', 0), ft_memchr("abc", 'a', 0));
    TEST_ASSERT_EQUAL(memchr("abc", 'b', 1), ft_memchr("abc", 'b', 1));
    TEST_ASSERT_EQUAL(memchr("a\0c", '\0', 3), ft_memchr("a\0c", '\0', 3));
}

void test_memcmp_equal(void) {

    TEST_ASSERT_EQUAL(memcmp("abc", "abc", 3), ft_memcmp("abc", "abc", 3));
    TEST_ASSERT_EQUAL(memcmp("abc", "abd", 3), ft_memcmp("abc", "abd", 3));
    TEST_ASSERT_EQUAL(memcmp("abcX", "abcY", 3), ft_memcmp("abcX", "abcY", 3));
    TEST_ASSERT_EQUAL(memcmp("abd", "ab", 3), ft_memcmp("abd", "ab", 3));
    TEST_ASSERT_EQUAL(memcmp("abc", "def", 0), ft_memcmp("abc", "def", 0));
    TEST_ASSERT_EQUAL(memcmp("\200", "\0", 1), ft_memcmp("\200", "\0", 1));
    TEST_ASSERT_EQUAL(memcmp("a\0c", "a\0b", 3), ft_memcmp("a\0c", "a\0b", 3));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_isalpha_1);
    RUN_TEST(test_isalpha_0);
    RUN_TEST(test_isdigit_1);
    RUN_TEST(test_isdigit_0);
    RUN_TEST(test_isalnum_1);
    RUN_TEST(test_isalnum_0);
    RUN_TEST(test_isascii_1);
    RUN_TEST(test_isascii_0);
    RUN_TEST(test_isprint_1);
    RUN_TEST(test_isprint_0);
    RUN_TEST(test_strlen_equal);
    RUN_TEST(test_memset_equal);
    RUN_TEST(test_bzero_equal);
    RUN_TEST(test_memcpy_equal);
    RUN_TEST(test_strlcpy_equal);
    RUN_TEST(test_strlcat_equal);
    RUN_TEST(test_toupper_equal);
    RUN_TEST(test_tolower_equal);
    RUN_TEST(test_strchr_equal);
    RUN_TEST(test_strrchr_equal);
    RUN_TEST(test_strncmp_equal);
    RUN_TEST(test_memchr_equal);
    RUN_TEST(test_memcmp_equal);
    return UNITY_END();
}

/*
gcc -o test_libft \
    test/test_libft.c \    
    unity/unity.c \
    src/.*c \
    -I unity \
    -I src
*/

/* Makefile

CC = gcc
CFLAGS = -Iunity -Isrc -Wall -Wextra -std=c99
SRC = src/math_operations.c
TEST_SRC = test/test_math_operations.c
UNITY_SRC = unity/unity.c
TARGET = test_math_operations

all: $(TARGET)

$(TARGET): $(TEST_SRC) $(SRC) $(UNITY_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(TEST_SRC) $(SRC) $(UNITY_SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)


*/