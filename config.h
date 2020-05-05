/*
  Config header for showkeys.c
*/

/* Display font, select a font using 'xfontsel -scaled' */
#define SK_FONT     "-*-courier*-*-*-*-*-60-*-*-*-*-*-*-*"

/* Display position, possible values: XOSD_top, XOSD_bottom */
#define SK_POS      XOSD_top

/* changes the number of pixels the XOSD window is offset from the top
   or bottom of the screen. This is normally set to a value such as 48
   to avoid desktop-panels, such as those provided by GNOME or KDE. */
#define SK_OFFSET   400

/* Display alignment, possible values: XOSD_right, XOSD_center, XOSD_left, */
#define SK_ALIGN    XOSD_center

#define SK_H_OFFSET 0

/*
 * Foreground color name
 * possible values, see rgb.txt
 * As of X.Org Release 7.4 rgb.txt is no longer included in the roll up release,
 * and the list is built directly into the server.
 * The optional module xorg/app/rgb contains the stand-alone rgb.txt file.
 * https://en.wikipedia.org/wiki/X11_color_names#Color_name_chart
 * for Fedora 32: `sudo dnf install -y rgb`
 * ❯ rpm -ql rgb
    /usr/bin/showrgb
    /usr/lib/.build-id
    /usr/lib/.build-id/99
    /usr/lib/.build-id/99/0d3d24726cf3ff23cdd09a1e28102fe1774685
    /usr/share/X11/rgb.txt
    /usr/share/man/man1/showrgb.1.gz
 */

#define SK_FG       "OliveDrab"

/* Shadow color */
#define SK_SHADOW   "Olive"

/* Outline color */
#define SK_OUTLINE  "Black"

/* Outline offset, pixel */
#define SK_OL_OFFSET 1

/* Shadow offset, pixel */
#define SK_SHOFFSET 3

/* Hide display after N seconds, set to -1 to never hide */
#define SK_TIMEOUT  1

/* By default, repeated key presses will be shown as "n 3 times".
   If you want to display each key press separately, change this
   to: #undef SK_NO_REPEATS. */
#define SK_NO_REPEATS

