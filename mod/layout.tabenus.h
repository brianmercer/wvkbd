/* constants */
/* how tall the keyboard should be by default (can be overriden) */
#define KBD_PIXEL_HEIGHT 400

/* how tall the keyboard should be by default (can be overriden) */
#define KBD_PIXEL_LANDSCAPE_HEIGHT 300

/* spacing around each key */
#define KBD_KEY_BORDER 1

/* layout declarations */
enum layout_id {
	Full = 0,
	Special,
	Simple,
	SimpleGrid,
	Dialer,
	Emoji,
	Nav,
	Landscape,
	NumLayouts,
};

static struct key keys_full[], keys_special[], keys_simple[], keys_simplegrid[],
    keys_emoji[], keys_nav[], keys_landscape[], keys_dialer[];

static struct layout layouts[NumLayouts] = {
  [Full] = {keys_full, "latin", "full"}, // second parameter is the keymap name
                                         // third parameter is the layout name
  [Special] = {keys_special, "latin", "special"},
  [Simple] = {keys_simple, "latin", "simple"},
  [SimpleGrid] = {keys_simplegrid, "latin", "simplegrid"},
  [Dialer] = {keys_dialer, "latin", "dialer"},
  [Emoji] = {keys_emoji, "latin", "emoji"},
  [Nav] = {keys_nav, "latin", "nav"},
  [Landscape] = {keys_landscape, "latin", "landscape"},
};

/* key layouts
 *
 * define keys like:
 *
 *  `{
 *     "label",
 *     "SHIFT_LABEL",
 *     1,
 *     [Code, Mod, Layout, EndRow, Last],
 *     [KEY_CODE, Modifier],
 *     [&layout]
 *  },`
 *
 * - label: normal label for key
 *
 * - shift_label: label for key in shifted (uppercase) layout
 *
 * - width: column width of key
 *
 * - type: what kind of action this key peforms (emit keycode, toggle modifier,
 *   switch layout, or end the layout)
 *
 * - code: key scancode or modifier name (see
 *   `/usr/include/linux/input-event-codes.h` for scancode names, and
 *   `keyboard.h` for modifiers)
 *
 * - layout: layout to switch to when key is pressed
 */
static struct key keys_full[] = {

  {"Esc", "Esc", 1.0, Code, KEY_ESC, .scheme = 1},
  {"1", "!", 1.0, Code, KEY_1},
  {"2", "@", 1.0, Code, KEY_2},
  {"3", "#", 1.0, Code, KEY_3},
  {"4", "$", 1.0, Code, KEY_4},
  {"5", "%", 1.0, Code, KEY_5},
  {"6", "^", 1.0, Code, KEY_6},
  {"7", "&", 1.0, Code, KEY_7},
  {"8", "*", 1.0, Code, KEY_8},
  {"9", "(", 1.0, Code, KEY_9},
  {"0", ")", 1.0, Code, KEY_0},
  {"-", "_", 1.0, Code, KEY_MINUS},
  {"=", "+", 1.0, Code, KEY_EQUAL},
  {"Back", "Back", 1.0, Code, KEY_BACKSPACE, .scheme = 1},
  {"", "", 0.0, EndRow},

  /* {"", "", 0.25, Pad}, */
  {"Tab", "Tab", 1.5, Code, KEY_TAB, .scheme = 1},
  {"q", "Q", 1.0, Code, KEY_Q},
  {"w", "W", 1.0, Code, KEY_W},
  {"e", "E", 1.0, Code, KEY_E},
  {"r", "R", 1.0, Code, KEY_R},
  {"t", "T", 1.0, Code, KEY_T},
  {"y", "Y", 1.0, Code, KEY_Y},
  {"u", "U", 1.0, Code, KEY_U},
  {"i", "I", 1.0, Code, KEY_I},
  {"o", "O", 1.0, Code, KEY_O},
  {"p", "P", 1.0, Code, KEY_P},
  {";", ":", 1.25, Code, KEY_SEMICOLON, .scheme = 1},
  {"'", "\"", 1.25, Code, KEY_APOSTROPHE, .scheme = 1},
/*  {"", "", 0.5, Pad},*/
  {"", "", 0.0, EndRow},

  {"$=/[", "$=/[", 2.0, Layout, 0, &layouts[Special], .scheme = 2},
  {"a", "A", 1.0, Code, KEY_A},
  {"s", "S", 1.0, Code, KEY_S},
  {"d", "D", 1.0, Code, KEY_D},
  {"f", "F", 1.0, Code, KEY_F},
  {"g", "G", 1.0, Code, KEY_G},
  {"h", "H", 1.0, Code, KEY_H},
  {"j", "J", 1.0, Code, KEY_J},
  {"k", "K", 1.0, Code, KEY_K},
  {"l", "L", 1.0, Code, KEY_L},
  {"Enter", "Enter", 3.0, Code, KEY_ENTER, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"Shift", "Shift", 2.5, Mod, Shift, .scheme = 1},
  {"z", "Z", 1.0, Code, KEY_Z},
  {"x", "X", 1.0, Code, KEY_X},
  {"c", "C", 1.0, Code, KEY_C},
  {"v", "V", 1.0, Code, KEY_V},
  {"b", "B", 1.0, Code, KEY_B},
  {"n", "N", 1.0, Code, KEY_N},
  {"m", "M", 1.0, Code, KEY_M},
  {",", "<", 1.0, Code, KEY_COMMA},
  {".", ">", 1.0, Code, KEY_DOT},
  {"/", "?", 1.5, Code, KEY_SLASH},
/*  {"", "", 0.5, Pad},*/
  {"↑", "↑", 1.0, Code, KEY_UP, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"Ctrl", "Ctrl", 1.5, Mod, Ctrl, .scheme = 1},
  {"Alt", "Alt", 1.5, Mod, Alt, .scheme = 1},
  {"", "", 8.0, Code, KEY_SPACE},
  {"←", "←", 1.0, Code, KEY_LEFT, .scheme = 1},
  {"→", "→", 1.0, Code, KEY_RIGHT, .scheme = 1},
  {"↓", "↓", 1.0, Code, KEY_DOWN, .scheme = 1},

  /* end of layout */
  {"", "", 0.0, Last},
};

static struct key keys_special[] = {
  {"Esc", "Esc", 1.0, Code, KEY_ESC, .scheme = 1},
  {"Ctrl", "Ctrl", 1.0, Mod, Ctrl, .scheme = 1},
  {"Tab", "Tab", 1.0, Code, KEY_TAB, .scheme = 1},
  {"↑", "↑", 1.0, Code, KEY_UP, .scheme = 1},
  {"↓", "↓", 1.0, Code, KEY_DOWN, .scheme = 1},
  {"←", "←", 1.0, Code, KEY_LEFT, .scheme = 1},
  {"→", "→", 1.0, Code, KEY_RIGHT, .scheme = 1},
  {"PgU", "PgU", 1.0, Code, KEY_PAGEUP, .scheme = 1},
  {"PgD", "PgD", 1.0, Code, KEY_PAGEDOWN, .scheme = 1},
  {"Home", "Home", 1.0, Code, KEY_HOME, .scheme = 1},
  {"End", "End", 1.0, Code, KEY_END, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"1", "!", 1.0, Code, KEY_1},
  {"2", "@", 1.0, Code, KEY_2},
  {"3", "#", 1.0, Code, KEY_3},
  {"4", "$", 1.0, Code, KEY_4},
  {"5", "%", 1.0, Code, KEY_5},
  {"6", "^", 1.0, Code, KEY_6},
  {"7", "&", 1.0, Code, KEY_7},
  {"8", "*", 1.0, Code, KEY_8},
  {"9", "(", 1.0, Code, KEY_9},
  {"0", ")", 1.0, Code, KEY_0},
  {"", "", 0.0, EndRow},

  {"ABC", "ABC", 2.0, Layout, 0, &layouts[Full], .scheme = 1},
  {"`", "~", 1.0, Code, KEY_GRAVE},
  {"'", "\"", 1.0, Code, KEY_APOSTROPHE},
  {"-", "_", 1.0, Code, KEY_MINUS},
  {"=", "+", 1.0, Code, KEY_EQUAL},
  {"[", "{", 1.0, Code, KEY_LEFTBRACE},
  {"]", "}", 1.0, Code, KEY_RIGHTBRACE},
  {"\\", "|", 1.0, Code, KEY_BACKSLASH},
  {"Del", "Del", 1.0, Code, KEY_DELETE, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"Shift", "Shift", 2.0, Mod, Shift, .scheme = 1},
  {";", ":", 1.0, Code, KEY_SEMICOLON},
  {"/", ">", 1.0, Code, KEY_SLASH},
  {"<", "«", 1.0, Code, KEY_COMMA},
  {">", "»", 1.0, Code, KEY_DOT},
  {"¡", "¿", 1.0, Code, KEY_MENU},
  {"🙂", "🙂", 1.0, Layout, 0, &layouts[Emoji]},
  {"BackSp", "BackSp", 1.0, Code, KEY_BACKSPACE, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"Caps", "Caps", 1.0, Mod, CapsLock, .scheme = 1},
  {"Sup", "Sup", 1.0, Mod, Super, .scheme = 1},
  {"Alt", "Alt", 1.0, Mod, Alt, .scheme = 1},
  {",", "'", 1.0, Code, KEY_COMMA},
  {"", "", 4.0, Code, KEY_SPACE},
  {".", "?", 1.0, Code, KEY_DOT},
  {"Enter", "Enter", 2.0, Code, KEY_ENTER, .scheme = 1},

  /* end of layout */
  {"", "", 0.0, Last},
};

static struct key keys_simple[] = {
  {"↹", "↹", 0.5, Code, KEY_TAB, .scheme = 1},
  {"q", "Q", 1.0, Code, KEY_Q},
  {"w", "W", 1.0, Code, KEY_W},
  {"e", "E", 1.0, Code, KEY_E},
  {"r", "R", 1.0, Code, KEY_R},
  {"t", "T", 1.0, Code, KEY_T},
  {"y", "Y", 1.0, Code, KEY_Y},
  {"u", "U", 1.0, Code, KEY_U},
  {"i", "I", 1.0, Code, KEY_I},
  {"o", "O", 1.0, Code, KEY_O},
  {"p", "P", 1.0, Code, KEY_P},
  {"", "", 0.0, EndRow},

  {"a", "A", 1.0, Code, KEY_A},
  {"s", "S", 1.0, Code, KEY_S},
  {"d", "D", 1.0, Code, KEY_D},
  {"f", "F", 1.0, Code, KEY_F},
  {"g", "G", 1.0, Code, KEY_G},
  {"h", "H", 1.0, Code, KEY_H},
  {"j", "J", 1.0, Code, KEY_J},
  {"k", "K", 1.0, Code, KEY_K},
  {"l", "L", 1.0, Code, KEY_L},
  {"'", "\"", 0.5, Code, KEY_APOSTROPHE},
  {"", "", 0.0, EndRow},

  {"⇧", "⇫", 1.5, Mod, Shift, .scheme = 1},
  {"z", "Z", 1.0, Code, KEY_Z},
  {"x", "X", 1.0, Code, KEY_X},
  {"c", "C", 1.0, Code, KEY_C},
  {"v", "V", 1.0, Code, KEY_V},
  {"b", "B", 1.0, Code, KEY_B},
  {"n", "N", 1.0, Code, KEY_N},
  {"m", "M", 1.0, Code, KEY_M},
  {"⌫", "⌫", 1.5, Code, KEY_BACKSPACE, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"Abc", "Abc", 1.0, NextLayer, .scheme = 1},
  {"Ctr", "Ctr", 1.0, Mod, Ctrl, .scheme = 1},
  {"-", "_", 1.0, Code, KEY_MINUS},
  {"", "", 4.0, Code, KEY_SPACE},
  {".", "?", 1.0, Code, KEY_DOT},
  {"Enter", "Enter", 2.0, Code, KEY_ENTER, .scheme = 1},

  /* end of layout */
  {"", "", 0.0, Last},
};

static struct key keys_dialer[] = {
  {"Esc", "Esc", 1.0, Code, KEY_ESC},
  {"+","+", 1.0, Code, KEY_KPPLUS},
  {"⌫", "⌫", 1.0, Code, KEY_BACKSPACE},
  {"", "", 0.0, EndRow},
  {"1", "1", 1.0, Code, KEY_1},
  {"2", "2", 1.0, Code, KEY_2},
  {"3", "3", 1.0, Code, KEY_3},
  {"", "", 0.0, EndRow},
  {"4", "4", 1.0, Code, KEY_4},
  {"5", "5", 1.0, Code, KEY_5},
  {"6", "6", 1.0, Code, KEY_6},
  {"", "", 0.0, EndRow},
  {"7", "7", 1.0, Code, KEY_7},
  {"8", "8", 1.0, Code, KEY_8},
  {"9", "9", 1.0, Code, KEY_9},
  {"", "", 0.0, EndRow},
  {"*", "*", 1.0, Code, KEY_KPASTERISK},
  {"0", "0", 1.0, Code, KEY_0},
  {"#", "#", 1.0, Code, KEY_NUMERIC_POUND},
  {"", "", 0.0, EndRow},
  {"Abc", "Abc", 1.0, NextLayer, .scheme = 1},
  {"Enter", "Enter", 2.0, Code, KEY_ENTER, .scheme = 1},

  /* end of layout */
  {"", "", 0.0, Last},
};

static struct key keys_simplegrid[] = {
  {"q", "Q", 1.0, Code, KEY_Q},
  {"w", "W", 1.0, Code, KEY_W},
  {"e", "E", 1.0, Code, KEY_E},
  {"r", "R", 1.0, Code, KEY_R},
  {"t", "T", 1.0, Code, KEY_T},
  {"y", "Y", 1.0, Code, KEY_Y},
  {"u", "U", 1.0, Code, KEY_U},
  {"i", "I", 1.0, Code, KEY_I},
  {"o", "O", 1.0, Code, KEY_O},
  {"p", "P", 1.0, Code, KEY_P},
  {"", "", 0.0, EndRow},

  {"a", "A", 1.0, Code, KEY_A},
  {"s", "S", 1.0, Code, KEY_S},
  {"d", "D", 1.0, Code, KEY_D},
  {"f", "F", 1.0, Code, KEY_F},
  {"g", "G", 1.0, Code, KEY_G},
  {"h", "H", 1.0, Code, KEY_H},
  {"j", "J", 1.0, Code, KEY_J},
  {"k", "K", 1.0, Code, KEY_K},
  {"l", "L", 1.0, Code, KEY_L},
  {"'", "\"", 1.0, Code, KEY_APOSTROPHE},
  {"", "", 0.0, EndRow},

  {"⇧", "⇫", 1.0, Mod, Shift, .scheme = 1},
  {"z", "Z", 1.0, Code, KEY_Z},
  {"x", "X", 1.0, Code, KEY_X},
  {"c", "C", 1.0, Code, KEY_C},
  {"v", "V", 1.0, Code, KEY_V},
  {"b", "B", 1.0, Code, KEY_B},
  {"n", "N", 1.0, Code, KEY_N},
  {"m", "M", 1.0, Code, KEY_M},
  {"Tab", "Tab", 1.0, Code, KEY_TAB, .scheme = 1},
  {"⌫", "⌫", 1.0, Code, KEY_BACKSPACE, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"Abc", "Abc", 1.0, NextLayer, .scheme = 1},
  {"Ctr", "Ctr", 1.0, Mod, Ctrl, .scheme = 1},
  {"-", "_", 1.0, Code, KEY_MINUS},
  {"", "", 3.0, Code, KEY_SPACE},
  {".", "?", 1.0, Code, KEY_DOT},
  {"Enter", "Enter", 2.0, Code, KEY_ENTER, .scheme = 1},

  /* end of layout */
  {"", "", 0.0, Last},
};

static struct key keys_emoji[] = {
  {"🙂", "🙏", 1.0, Copy, 0x1f642, 0, 0x1f64f}, // Emojis
  {"😀", "🙋", 1.0, Copy, 0x1f600, 0, 0x1f64b},
  {"😁", "✋", 1.0, Copy, 0x1f601, 0, 0x270B},
  {"😂", "🙇", 1.0, Copy, 0x1f602, 0, 0x1f647},
  {"😃", "👨", 1.0, Copy, 0x1f603, 0, 0x1f468},
  {"😄", "👩", 1.0, Copy, 0x1f604, 0, 0x1f469},
  {"😅", "👶", 1.0, Copy, 0x1f605, 0, 0x1f476},
  {"😆", "👻", 1.0, Copy, 0x1f606, 0, 0x1f47b},
  {"😇", "✨", 1.0, Copy, 0x1f607, 0, 0x2728},
  {"🤣", "💰", 1.0, Copy, 0x1f923, 0, 0x1f4b0},
  {"", "", 0.0, EndRow},
  {"😉", "🐕", 1.0, Copy, 0x1f609, 0, 0x1f415},
  {"😊", "🐈", 1.0, Copy, 0x1f60a, 0, 0x1f408},
  {"😋", "🐧", 1.0, Copy, 0x1f60b, 0, 0x1f427},
  {"😌", "🐇", 1.0, Copy, 0x1f60c, 0, 0x1f407},
  {"😍", "💔", 1.0, Copy, 0x1f60d, 0, 0x1f494},
  {"😘", "💕", 1.0, Copy, 0x1f618, 0, 0x1f495},
  {"😎", "❤", 1.0, Copy, 0x1f60e, 0, 0x2764},
  {"😐", "😏", 1.0, Copy, 0x1f610, 0, 0x1f60f},
  {"😒", "👀", 1.0, Copy, 0x1f612, 0, 0x1f440},
  {"😓", "💀", 1.0, Copy, 0x1f613, 0, 0x1f480},
  {"", "", 0.0, EndRow},
  {"⇧", "⇧", 1.0, Mod, Shift, .scheme = 1},
  {"😛", "😜", 1.0, Copy, 0x1f61b, 0, 0x1f61c},
  {"😮", "😝", 1.0, Copy, 0x1f62e, 0, 0x1f61d},
  {"😟", "😞", 1.0, Copy, 0x1f61f, 0, 0x1f61e},
  {"😠", "🥺", 1.0, Copy, 0x1f620, 0, 0x1f97a},
  {"😢", "👿", 1.0, Copy, 0x1f622, 0, 0x1f47f},
  {"😭", "😯", 1.0, Copy, 0x1f62d, 0, 0x1f62f},
  {"😳", "😕", 1.0, Copy, 0x1f633, 0, 0x1f615},
  {"😴", "😵", 1.0, Copy, 0x1f634, 0, 0x1f635},
  {"⌫", "⌫", 1.0, Code, KEY_BACKSPACE, .scheme = 1},
  {"", "", 0.0, EndRow},
  {"Abc", "Abc", 1.0, BackLayer, .scheme = 1},
  {"👆", "👊", 1.0, Copy, 0x1f446, 0, 0x1f44a},
  {"👇", "👌", 1.0, Copy, 0x1f447, 0, 0x1f44c},
  {"👈", "👏", 1.0, Copy, 0x1f448, 0, 0x1f44f},
  {"👉", "👐", 1.0, Copy, 0x1f449, 0, 0x1f450},
  {"👋", "🙌", 1.0, Copy, 0x1f44b, 0, 0x1f64c},
  {"👍", "✅", 1.0, Copy, 0x1f44d, 0, 0x2705},
  {"👎", "💪", 1.0, Copy, 0x1f44e, 0, 0x1f4aa},
  {"Enter", "Enter", 2.0, Code, KEY_ENTER, .scheme = 1},
  {"", "", 0.0, Last},
};

static struct key keys_nav[] = {
  {"Esc", "Esc", 1.0, Code, KEY_ESC, .scheme = 1},
  {"⌫", "⌫", 1.0, Code, KEY_BACKSPACE, .scheme = 1},
  {"↑", "↑", 1.0, Code, KEY_UP, .scheme = 1},
  {"⇈", "⇈", 1.0, Code, KEY_PAGEUP, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"q", "q", 1.0, Code, KEY_Q, .scheme = 1},
  {"←", "←", 1.0, Code, KEY_LEFT, .scheme = 1},
  {"Enter", "Enter", 1.0, Code, KEY_ENTER, .scheme = 1},
  {"→", "→", 1.0, Code, KEY_RIGHT, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"Sym", "Sym", 1.0, NextLayer, .scheme = 1},
  {"", "", 1.0, Code, KEY_SPACE, .scheme = 1},
  {"↓", "↓", 1.0, Code, KEY_DOWN, .scheme = 1},
  {"⇊", "⇊", 1.0, Code, KEY_PAGEDOWN, .scheme = 1},
  {"", "", 0.0, Last},
};

static struct key keys_landscape[] = {
  {"Esc", "Esc", 1.0, Code, KEY_ESC, .scheme = 1},
  {"q", "Q", 1.0, Code, KEY_Q},
  {"w", "W", 1.0, Code, KEY_W},
  {"e", "E", 1.0, Code, KEY_E},
  {"r", "R", 1.0, Code, KEY_R},
  {"t", "T", 1.0, Code, KEY_T},
  {"y", "Y", 1.0, Code, KEY_Y},
  {"u", "U", 1.0, Code, KEY_U},
  {"i", "I", 1.0, Code, KEY_I},
  {"o", "O", 1.0, Code, KEY_O},
  {"p", "P", 1.0, Code, KEY_P},
  {"(", "(", 0.75, Copy, KEY_9, .scheme = 1},
  {")", ")", 0.75, Code, KEY_0, .scheme = 1},
  {"Tab", "Tab", 0.75, Code, KEY_TAB, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"a", "A", 1.0, Code, KEY_A},
  {"s", "S", 1.0, Code, KEY_S},
  {"d", "D", 1.0, Code, KEY_D},
  {"f", "F", 1.0, Code, KEY_F},
  {"g", "G", 1.0, Code, KEY_G},
  {"h", "H", 1.0, Code, KEY_H},
  {"j", "J", 1.0, Code, KEY_J},
  {"k", "K", 1.0, Code, KEY_K},
  {"l", "L", 1.0, Code, KEY_L},
  {";", ":", 1.0, Code, KEY_SEMICOLON, .scheme = 1},
  {"'", "\"", 1.0, Code, KEY_APOSTROPHE, .scheme = 1},
  {"-", "_", 0.5, Code, KEY_MINUS, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"⇧", "⇫", 1.5, Mod, Shift, .scheme = 1},
  {"z", "Z", 1.0, Code, KEY_Z},
  {"x", "X", 1.0, Code, KEY_X},
  {"c", "C", 1.0, Code, KEY_C},
  {"v", "V", 1.0, Code, KEY_V},
  {"b", "B", 1.0, Code, KEY_B},
  {"n", "N", 1.0, Code, KEY_N},
  {"m", "M", 1.0, Code, KEY_M},
  {"↑", "↑", 0.75, Code, KEY_UP, .scheme = 1},
  {"↓", "↓", 0.75, Code, KEY_DOWN, .scheme = 1},
  {"/", ">", 0.75, Code, KEY_SLASH, .scheme = 1},
  {"⌫", "⌫", 1.5, Code, KEY_BACKSPACE, .scheme = 1},
  {"", "", 0.0, EndRow},

  {"Sym", "Sym", 1.0, NextLayer, .scheme = 1},
  {"Ctr", "Ctr", 1.0, Mod, Ctrl, .scheme = 1},
  {"Alt", "Alt", 0.5, Mod, Alt, .scheme = 1},
  {",", "'", 0.5, Code, KEY_COMMA},
  {"", "", 3.0, Code, KEY_SPACE},
  {".", "?", 1.0, Code, KEY_DOT},
  {"Enter", "Enter", 2.0, Code, KEY_ENTER, .scheme = 1},

  /* end of layout */
  {"", "", 0.0, Last},
};


