/* Showkeys 
   Copyright Noufal Ibrahim <noufal@nibrahim.net.in> 2011

   Licensed under the GPLv3 : http://www.gnu.org/licenses/gpl.txt

   Please see LICENSE file for complete license.
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keystack.h"

static void
push_back(KeyStack *stack, int index) {
    int i;
    free(stack->keystrokes[0].keyname);
    for (i = 0; i < index; i++)
        stack->keystrokes[i] = stack->keystrokes[i + 1];
}

KeyStack *
create_keystack(int size) {
    int i;
    KeyStack *retval = NULL;
    KeyStroke *stack = NULL;

    stack = (KeyStroke *) malloc(sizeof(KeyStroke) * size);
    for (i = 0; i < size; i++) {
        stack[i].keyname = NULL;
        stack[i].times = 0;
    }

    retval = (KeyStack *) malloc(sizeof(KeyStack));
    retval->size = size;
    retval->pos = -1;
    retval->keystrokes = stack;

    return retval;
}

void
push(KeyStack *stack, char *keyname) {
    int index;
    KeyStroke *last;
    char *last_key;

    if (stack->pos > -1) {
        last = &stack->keystrokes[stack->pos];
        last_key = last->keyname;
    }
    index = stack->pos + 1;

    debug_print("push(): stack->pos: %d\n", stack->pos);

#ifdef SK_NO_REPEATS
    if (last_key) {
        debug_print("SK_NO_REPEATS: index: %d, equal: last_key: %s, new keyname: %s\n", index, last_key, keyname);
    } else {
        debug_print("SK_NO_REPEATS: index: %d, equal: last_key is NULL, new keyname: %s\n", index, keyname);
    }
    if (index && !strcmp(last_key, keyname)) {
        /* If the same as the top of the stack, increment count */
        last->times++;
    } else {
#endif
        debug_print("REPEATS: Add a new entry: keyname: %s\n", keyname);
        /* Add a new entry */
        if (index == stack->size) {
            push_back(stack, stack->pos);
            index = stack->size - 1;
        }
        stack->keystrokes[index].keyname = keyname;
        stack->keystrokes[index].times = 1;
        stack->pos = index;
#ifdef SK_NO_REPEATS
    }
#endif
}


void
display_keystack(KeyStack *stack) {
    int i;
    debug_print("---- Keystack ----");
    for (i = 0; i <= stack->pos; i++) {
        debug_print("%s %d times", stack->keystrokes[i].keyname, stack->keystrokes[i].times);
    }
    debug_print("---- -------- ----\n");
}
