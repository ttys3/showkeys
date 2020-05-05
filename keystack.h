/* Showkeys 
   Copyright Noufal Ibrahim <noufal@nibrahim.net.in> 2011

   Licensed under the GPLv3 : http://www.gnu.org/licenses/gpl.txt

   Please see LICENSE file for complete license.
*/
#define NKEYS 1

#ifdef DEBUG
#define debug_print(fmt, ...) \
            do { fprintf(stderr, fmt"\n", __VA_ARGS__); } while (0)
#else
#define debug_print(fmt, ...)
#endif

typedef struct {
    char *keyname;
    int times;
} KeyStroke;

typedef struct {
    int size;
    int pos;
    KeyStroke *keystrokes;
} KeyStack;


KeyStack *create_keystack();

void push(KeyStack *, char *);

void display_keystack(KeyStack *);


