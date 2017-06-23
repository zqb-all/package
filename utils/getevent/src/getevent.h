#include <linux/input.h>
#include <stdio.h>

#define PATH_MAX 100

struct label {
    const char *name;
    int value;
};

#define LABEL(constant) { #constant, constant }
#define LABEL_END { NULL, -1 }

static struct label input_prop_labels[] = {
        LABEL(INPUT_PROP_POINTER),
        LABEL(INPUT_PROP_DIRECT),
        LABEL(INPUT_PROP_BUTTONPAD),
        LABEL(INPUT_PROP_SEMI_MT),
        LABEL_END,
};

static struct label ev_labels[] = {
        LABEL(EV_SYN),
        LABEL(EV_KEY),
        LABEL(EV_REL),
        LABEL(EV_ABS),
        LABEL(EV_MSC),
        LABEL(EV_SW),
        LABEL(EV_LED),
        LABEL(EV_SND),
        LABEL(EV_REP),
        LABEL(EV_FF),
        LABEL(EV_PWR),
        LABEL(EV_FF_STATUS),
        LABEL_END,
};

static struct label syn_labels[] = {
        LABEL(SYN_REPORT),
        LABEL(SYN_CONFIG),
        LABEL(SYN_MT_REPORT),
        LABEL(SYN_DROPPED),
        LABEL_END,
};

static struct label key_labels[] = {
        LABEL(KEY_RESERVED),
        LABEL(KEY_ESC),
        LABEL(KEY_1),
        LABEL(KEY_2),
        LABEL(KEY_3),
        LABEL(KEY_4),
        LABEL(KEY_5),
        LABEL(KEY_6),
        LABEL(KEY_7),
        LABEL(KEY_8),
        LABEL(KEY_9),
        LABEL(KEY_0),
        LABEL(KEY_MINUS),
        LABEL(KEY_EQUAL),
        LABEL(KEY_BACKSPACE),
        LABEL(KEY_TAB),
        LABEL(KEY_Q),
        LABEL(KEY_W),
        LABEL(KEY_E),
        LABEL(KEY_R),
        LABEL(KEY_T),
        LABEL(KEY_Y),
        LABEL(KEY_U),
        LABEL(KEY_I),
        LABEL(KEY_O),
        LABEL(KEY_P),
        LABEL(KEY_LEFTBRACE),
        LABEL(KEY_RIGHTBRACE),
        LABEL(KEY_ENTER),
        LABEL(KEY_LEFTCTRL),
        LABEL(KEY_A),
        LABEL(KEY_S),
        LABEL(KEY_D),
        LABEL(KEY_F),
        LABEL(KEY_G),
        LABEL(KEY_H),
        LABEL(KEY_J),
        LABEL(KEY_K),
        LABEL(KEY_L),
        LABEL(KEY_SEMICOLON),
        LABEL(KEY_APOSTROPHE),
        LABEL(KEY_GRAVE),
        LABEL(KEY_LEFTSHIFT),
        LABEL(KEY_BACKSLASH),
        LABEL(KEY_Z),
        LABEL(KEY_X),
        LABEL(KEY_C),
        LABEL(KEY_V),
        LABEL(KEY_B),
        LABEL(KEY_N),
        LABEL(KEY_M),
        LABEL(KEY_COMMA),
        LABEL(KEY_DOT),
        LABEL(KEY_SLASH),
        LABEL(KEY_RIGHTSHIFT),
        LABEL(KEY_KPASTERISK),
        LABEL(KEY_LEFTALT),
        LABEL(KEY_SPACE),
        LABEL(KEY_CAPSLOCK),
        LABEL(KEY_F1),
        LABEL(KEY_F2),
        LABEL(KEY_F3),
        LABEL(KEY_F4),
        LABEL(KEY_F5),
        LABEL(KEY_F6),
        LABEL(KEY_F7),
        LABEL(KEY_F8),
        LABEL(KEY_F9),
        LABEL(KEY_F10),
        LABEL(KEY_NUMLOCK),
        LABEL(KEY_SCROLLLOCK),
        LABEL(KEY_KP7),
        LABEL(KEY_KP8),
        LABEL(KEY_KP9),
        LABEL(KEY_KPMINUS),
        LABEL(KEY_KP4),
        LABEL(KEY_KP5),
        LABEL(KEY_KP6),
        LABEL(KEY_KPPLUS),
        LABEL(KEY_KP1),
        LABEL(KEY_KP2),
        LABEL(KEY_KP3),
        LABEL(KEY_KP0),
        LABEL(KEY_KPDOT),
        LABEL(KEY_ZENKAKUHANKAKU),
        LABEL(KEY_102ND),
        LABEL(KEY_F11),
        LABEL(KEY_F12),
        LABEL(KEY_RO),
        LABEL(KEY_KATAKANA),
        LABEL(KEY_HIRAGANA),
        LABEL(KEY_HENKAN),
        LABEL(KEY_KATAKANAHIRAGANA),
        LABEL(KEY_MUHENKAN),
        LABEL(KEY_KPJPCOMMA),
        LABEL(KEY_KPENTER),
        LABEL(KEY_RIGHTCTRL),
        LABEL(KEY_KPSLASH),
        LABEL(KEY_SYSRQ),
        LABEL(KEY_RIGHTALT),
        LABEL(KEY_LINEFEED),
        LABEL(KEY_HOME),
        LABEL(KEY_UP),
        LABEL(KEY_PAGEUP),
        LABEL(KEY_LEFT),
        LABEL(KEY_RIGHT),
        LABEL(KEY_END),
        LABEL(KEY_DOWN),
        LABEL(KEY_PAGEDOWN),
        LABEL(KEY_INSERT),
        LABEL(KEY_DELETE),
        LABEL(KEY_MACRO),
        LABEL(KEY_MUTE),
        LABEL(KEY_VOLUMEDOWN),
        LABEL(KEY_VOLUMEUP),
        LABEL(KEY_POWER),
        LABEL(KEY_KPEQUAL),
        LABEL(KEY_KPPLUSMINUS),
        LABEL(KEY_PAUSE),
        LABEL(KEY_SCALE),
        LABEL(KEY_KPCOMMA),
        LABEL(KEY_HANGEUL),
        LABEL(KEY_HANGUEL),
        LABEL(KEY_HANJA),
        LABEL(KEY_YEN),
        LABEL(KEY_LEFTMETA),
        LABEL(KEY_RIGHTMETA),
        LABEL(KEY_COMPOSE),
        LABEL(KEY_STOP),
        LABEL(KEY_AGAIN),
        LABEL(KEY_PROPS),
        LABEL(KEY_UNDO),
        LABEL(KEY_FRONT),
        LABEL(KEY_COPY),
        LABEL(KEY_OPEN),
        LABEL(KEY_PASTE),
        LABEL(KEY_FIND),
        LABEL(KEY_CUT),
        LABEL(KEY_HELP),
        LABEL(KEY_MENU),
        LABEL(KEY_CALC),
        LABEL(KEY_SETUP),
        LABEL(KEY_SLEEP),
        LABEL(KEY_WAKEUP),
        LABEL(KEY_FILE),
        LABEL(KEY_SENDFILE),
        LABEL(KEY_DELETEFILE),
        LABEL(KEY_XFER),
        LABEL(KEY_PROG1),
        LABEL(KEY_PROG2),
        LABEL(KEY_WWW),
        LABEL(KEY_MSDOS),
        LABEL(KEY_COFFEE),
        LABEL(KEY_SCREENLOCK),
        LABEL(KEY_DIRECTION),
        LABEL(KEY_CYCLEWINDOWS),
        LABEL(KEY_MAIL),
        LABEL(KEY_BOOKMARKS),
        LABEL(KEY_COMPUTER),
        LABEL(KEY_BACK),
        LABEL(KEY_FORWARD),
        LABEL(KEY_CLOSECD),
        LABEL(KEY_EJECTCD),
        LABEL(KEY_EJECTCLOSECD),
        LABEL(KEY_NEXTSONG),
        LABEL(KEY_PLAYPAUSE),
        LABEL(KEY_PREVIOUSSONG),
        LABEL(KEY_STOPCD),
        LABEL(KEY_RECORD),
        LABEL(KEY_REWIND),
        LABEL(KEY_PHONE),
        LABEL(KEY_ISO),
        LABEL(KEY_CONFIG),
        LABEL(KEY_HOMEPAGE),
        LABEL(KEY_REFRESH),
        LABEL(KEY_EXIT),
        LABEL(KEY_MOVE),
        LABEL(KEY_EDIT),
        LABEL(KEY_SCROLLUP),
        LABEL(KEY_SCROLLDOWN),
        LABEL(KEY_KPLEFTPAREN),
        LABEL(KEY_KPRIGHTPAREN),
        LABEL(KEY_NEW),
        LABEL(KEY_REDO),
        LABEL(KEY_F13),
        LABEL(KEY_F14),
        LABEL(KEY_F15),
        LABEL(KEY_F16),
        LABEL(KEY_F17),
        LABEL(KEY_F18),
        LABEL(KEY_F19),
        LABEL(KEY_F20),
        LABEL(KEY_F21),
        LABEL(KEY_F22),
        LABEL(KEY_F23),
        LABEL(KEY_F24),
        LABEL(KEY_PLAYCD),
        LABEL(KEY_PAUSECD),
        LABEL(KEY_PROG3),
        LABEL(KEY_PROG4),
        LABEL(KEY_DASHBOARD),
        LABEL(KEY_SUSPEND),
        LABEL(KEY_CLOSE),
        LABEL(KEY_PLAY),
        LABEL(KEY_FASTFORWARD),
        LABEL(KEY_BASSBOOST),
        LABEL(KEY_PRINT),
        LABEL(KEY_HP),
        LABEL(KEY_CAMERA),
        LABEL(KEY_SOUND),
        LABEL(KEY_QUESTION),
        LABEL(KEY_EMAIL),
        LABEL(KEY_CHAT),
        LABEL(KEY_SEARCH),
        LABEL(KEY_CONNECT),
        LABEL(KEY_FINANCE),
        LABEL(KEY_SPORT),
        LABEL(KEY_SHOP),
        LABEL(KEY_ALTERASE),
        LABEL(KEY_CANCEL),
        LABEL(KEY_BRIGHTNESSDOWN),
        LABEL(KEY_BRIGHTNESSUP),
        LABEL(KEY_MEDIA),
        LABEL(KEY_SWITCHVIDEOMODE),
        LABEL(KEY_KBDILLUMTOGGLE),
        LABEL(KEY_KBDILLUMDOWN),
        LABEL(KEY_KBDILLUMUP),
        LABEL(KEY_SEND),
        LABEL(KEY_REPLY),
        LABEL(KEY_FORWARDMAIL),
        LABEL(KEY_SAVE),
        LABEL(KEY_DOCUMENTS),
        LABEL(KEY_BATTERY),
        LABEL(KEY_BLUETOOTH),
        LABEL(KEY_WLAN),
        LABEL(KEY_UWB),
        LABEL(KEY_UNKNOWN),
        LABEL(KEY_VIDEO_NEXT),
        LABEL(KEY_VIDEO_PREV),
        LABEL(KEY_BRIGHTNESS_CYCLE),
        LABEL(KEY_BRIGHTNESS_ZERO),
        LABEL(KEY_DISPLAY_OFF),
        LABEL(KEY_WIMAX),
        LABEL(KEY_RFKILL),
        LABEL(BTN_0),
        LABEL(BTN_1),
        LABEL(BTN_2),
        LABEL(BTN_3),
        LABEL(BTN_4),
        LABEL(BTN_5),
        LABEL(BTN_6),
        LABEL(BTN_7),
        LABEL(BTN_8),
        LABEL(BTN_9),
        LABEL(BTN_LEFT),
        LABEL(BTN_RIGHT),
        LABEL(BTN_MIDDLE),
        LABEL(BTN_SIDE),
        LABEL(BTN_EXTRA),
        LABEL(BTN_FORWARD),
        LABEL(BTN_BACK),
        LABEL(BTN_TASK),
        LABEL(BTN_JOYSTICK),
        LABEL(BTN_TRIGGER),
        LABEL(BTN_THUMB),
        LABEL(BTN_THUMB2),
        LABEL(BTN_TOP),
        LABEL(BTN_TOP2),
        LABEL(BTN_PINKIE),
        LABEL(BTN_BASE),
        LABEL(BTN_BASE2),
        LABEL(BTN_BASE3),
        LABEL(BTN_BASE4),
        LABEL(BTN_BASE5),
        LABEL(BTN_BASE6),
        LABEL(BTN_DEAD),
        LABEL(BTN_A),
        LABEL(BTN_B),
        LABEL(BTN_C),
        LABEL(BTN_X),
        LABEL(BTN_Y),
        LABEL(BTN_Z),
        LABEL(BTN_TL),
        LABEL(BTN_TR),
        LABEL(BTN_TL2),
        LABEL(BTN_TR2),
        LABEL(BTN_SELECT),
        LABEL(BTN_START),
        LABEL(BTN_MODE),
        LABEL(BTN_THUMBL),
        LABEL(BTN_THUMBR),
        LABEL(BTN_TOOL_PEN),
        LABEL(BTN_TOOL_RUBBER),
        LABEL(BTN_TOOL_BRUSH),
        LABEL(BTN_TOOL_PENCIL),
        LABEL(BTN_TOOL_AIRBRUSH),
        LABEL(BTN_TOOL_FINGER),
        LABEL(BTN_TOOL_MOUSE),
        LABEL(BTN_TOOL_LENS),
        LABEL(BTN_TOUCH),
        LABEL(BTN_STYLUS),
        LABEL(BTN_STYLUS2),
        LABEL(BTN_TOOL_DOUBLETAP),
        LABEL(BTN_TOOL_TRIPLETAP),
        LABEL(BTN_TOOL_QUADTAP),
        LABEL(BTN_GEAR_DOWN),
        LABEL(BTN_GEAR_UP),
        LABEL(KEY_OK),
        LABEL(KEY_SELECT),
        LABEL(KEY_GOTO),
        LABEL(KEY_CLEAR),
        LABEL(KEY_POWER2),
        LABEL(KEY_OPTION),
        LABEL(KEY_INFO),
        LABEL(KEY_TIME),
        LABEL(KEY_VENDOR),
        LABEL(KEY_ARCHIVE),
        LABEL(KEY_PROGRAM),
        LABEL(KEY_CHANNEL),
        LABEL(KEY_FAVORITES),
        LABEL(KEY_EPG),
        LABEL(KEY_PVR),
        LABEL(KEY_MHP),
        LABEL(KEY_LANGUAGE),
        LABEL(KEY_TITLE),
        LABEL(KEY_SUBTITLE),
        LABEL(KEY_ANGLE),
        LABEL(KEY_ZOOM),
        LABEL(KEY_MODE),
        LABEL(KEY_KEYBOARD),
        LABEL(KEY_SCREEN),
        LABEL(KEY_PC),
        LABEL(KEY_TV),
        LABEL(KEY_TV2),
        LABEL(KEY_VCR),
        LABEL(KEY_VCR2),
        LABEL(KEY_SAT),
        LABEL(KEY_SAT2),
        LABEL(KEY_CD),
        LABEL(KEY_TAPE),
        LABEL(KEY_RADIO),
        LABEL(KEY_TUNER),
        LABEL(KEY_PLAYER),
        LABEL(KEY_TEXT),
        LABEL(KEY_DVD),
        LABEL(KEY_AUX),
        LABEL(KEY_MP3),
        LABEL(KEY_AUDIO),
        LABEL(KEY_VIDEO),
        LABEL(KEY_DIRECTORY),
        LABEL(KEY_LIST),
        LABEL(KEY_MEMO),
        LABEL(KEY_CALENDAR),
        LABEL(KEY_RED),
        LABEL(KEY_GREEN),
        LABEL(KEY_YELLOW),
        LABEL(KEY_BLUE),
        LABEL(KEY_CHANNELUP),
        LABEL(KEY_CHANNELDOWN),
        LABEL(KEY_FIRST),
        LABEL(KEY_LAST),
        LABEL(KEY_AB),
        LABEL(KEY_NEXT),
        LABEL(KEY_RESTART),
        LABEL(KEY_SLOW),
        LABEL(KEY_SHUFFLE),
        LABEL(KEY_BREAK),
        LABEL(KEY_PREVIOUS),
        LABEL(KEY_DIGITS),
        LABEL(KEY_TEEN),
        LABEL(KEY_TWEN),
        LABEL(KEY_VIDEOPHONE),
        LABEL(KEY_GAMES),
        LABEL(KEY_ZOOMIN),
        LABEL(KEY_ZOOMOUT),
        LABEL(KEY_ZOOMRESET),
        LABEL(KEY_WORDPROCESSOR),
        LABEL(KEY_EDITOR),
        LABEL(KEY_SPREADSHEET),
        LABEL(KEY_GRAPHICSEDITOR),
        LABEL(KEY_PRESENTATION),
        LABEL(KEY_DATABASE),
        LABEL(KEY_NEWS),
        LABEL(KEY_VOICEMAIL),
        LABEL(KEY_ADDRESSBOOK),
        LABEL(KEY_MESSENGER),
        LABEL(KEY_DISPLAYTOGGLE),
        LABEL(KEY_SPELLCHECK),
        LABEL(KEY_LOGOFF),
        LABEL(KEY_DOLLAR),
        LABEL(KEY_EURO),
        LABEL(KEY_FRAMEBACK),
        LABEL(KEY_FRAMEFORWARD),
        LABEL(KEY_CONTEXT_MENU),
        LABEL(KEY_MEDIA_REPEAT),
        LABEL(KEY_10CHANNELSUP),
        LABEL(KEY_10CHANNELSDOWN),
        LABEL(KEY_IMAGES),
        LABEL(KEY_DEL_EOL),
        LABEL(KEY_DEL_EOS),
        LABEL(KEY_INS_LINE),
        LABEL(KEY_DEL_LINE),
        LABEL(KEY_FN),
        LABEL(KEY_FN_ESC),
        LABEL(KEY_FN_F1),
        LABEL(KEY_FN_F2),
        LABEL(KEY_FN_F3),
        LABEL(KEY_FN_F4),
        LABEL(KEY_FN_F5),
        LABEL(KEY_FN_F6),
        LABEL(KEY_FN_F7),
        LABEL(KEY_FN_F8),
        LABEL(KEY_FN_F9),
        LABEL(KEY_FN_F10),
        LABEL(KEY_FN_F11),
        LABEL(KEY_FN_F12),
        LABEL(KEY_FN_1),
        LABEL(KEY_FN_2),
        LABEL(KEY_FN_D),
        LABEL(KEY_FN_E),
        LABEL(KEY_FN_F),
        LABEL(KEY_FN_S),
        LABEL(KEY_FN_B),
        LABEL(KEY_BRL_DOT1),
        LABEL(KEY_BRL_DOT2),
        LABEL(KEY_BRL_DOT3),
        LABEL(KEY_BRL_DOT4),
        LABEL(KEY_BRL_DOT5),
        LABEL(KEY_BRL_DOT6),
        LABEL(KEY_BRL_DOT7),
        LABEL(KEY_BRL_DOT8),
        LABEL(KEY_BRL_DOT9),
        LABEL(KEY_BRL_DOT10),
        LABEL(KEY_NUMERIC_0),
        LABEL(KEY_NUMERIC_1),
        LABEL(KEY_NUMERIC_2),
        LABEL(KEY_NUMERIC_3),
        LABEL(KEY_NUMERIC_4),
        LABEL(KEY_NUMERIC_5),
        LABEL(KEY_NUMERIC_6),
        LABEL(KEY_NUMERIC_7),
        LABEL(KEY_NUMERIC_8),
        LABEL(KEY_NUMERIC_9),
        LABEL(KEY_NUMERIC_STAR),
        LABEL(KEY_NUMERIC_POUND),
        LABEL(KEY_CAMERA_FOCUS),
        LABEL(KEY_WPS_BUTTON),
        LABEL(KEY_TOUCHPAD_TOGGLE),
        LABEL(KEY_TOUCHPAD_ON),
        LABEL(KEY_TOUCHPAD_OFF),
        LABEL(KEY_CAMERA_ZOOMIN),
        LABEL(KEY_CAMERA_ZOOMOUT),
        LABEL(KEY_CAMERA_UP),
        LABEL(KEY_CAMERA_DOWN),
        LABEL(KEY_CAMERA_LEFT),
        LABEL(KEY_CAMERA_RIGHT),
        LABEL(BTN_TRIGGER_HAPPY1),
        LABEL(BTN_TRIGGER_HAPPY2),
        LABEL(BTN_TRIGGER_HAPPY3),
        LABEL(BTN_TRIGGER_HAPPY4),
        LABEL(BTN_TRIGGER_HAPPY5),
        LABEL(BTN_TRIGGER_HAPPY6),
        LABEL(BTN_TRIGGER_HAPPY7),
        LABEL(BTN_TRIGGER_HAPPY8),
        LABEL(BTN_TRIGGER_HAPPY9),
        LABEL(BTN_TRIGGER_HAPPY10),
        LABEL(BTN_TRIGGER_HAPPY11),
        LABEL(BTN_TRIGGER_HAPPY12),
        LABEL(BTN_TRIGGER_HAPPY13),
        LABEL(BTN_TRIGGER_HAPPY14),
        LABEL(BTN_TRIGGER_HAPPY15),
        LABEL(BTN_TRIGGER_HAPPY16),
        LABEL(BTN_TRIGGER_HAPPY17),
        LABEL(BTN_TRIGGER_HAPPY18),
        LABEL(BTN_TRIGGER_HAPPY19),
        LABEL(BTN_TRIGGER_HAPPY20),
        LABEL(BTN_TRIGGER_HAPPY21),
        LABEL(BTN_TRIGGER_HAPPY22),
        LABEL(BTN_TRIGGER_HAPPY23),
        LABEL(BTN_TRIGGER_HAPPY24),
        LABEL(BTN_TRIGGER_HAPPY25),
        LABEL(BTN_TRIGGER_HAPPY26),
        LABEL(BTN_TRIGGER_HAPPY27),
        LABEL(BTN_TRIGGER_HAPPY28),
        LABEL(BTN_TRIGGER_HAPPY29),
        LABEL(BTN_TRIGGER_HAPPY30),
        LABEL(BTN_TRIGGER_HAPPY31),
        LABEL(BTN_TRIGGER_HAPPY32),
        LABEL(BTN_TRIGGER_HAPPY33),
        LABEL(BTN_TRIGGER_HAPPY34),
        LABEL(BTN_TRIGGER_HAPPY35),
        LABEL(BTN_TRIGGER_HAPPY36),
        LABEL(BTN_TRIGGER_HAPPY37),
        LABEL(BTN_TRIGGER_HAPPY38),
        LABEL(BTN_TRIGGER_HAPPY39),
        LABEL(BTN_TRIGGER_HAPPY40),
        LABEL_END,
};

static struct label rel_labels[] = {
        LABEL(REL_X),
        LABEL(REL_Y),
        LABEL(REL_Z),
        LABEL(REL_RX),
        LABEL(REL_RY),
        LABEL(REL_RZ),
        LABEL(REL_HWHEEL),
        LABEL(REL_DIAL),
        LABEL(REL_WHEEL),
        LABEL(REL_MISC),
        LABEL_END,
};

static struct label abs_labels[] = {
        LABEL(ABS_X),
        LABEL(ABS_Y),
        LABEL(ABS_Z),
        LABEL(ABS_RX),
        LABEL(ABS_RY),
        LABEL(ABS_RZ),
        LABEL(ABS_THROTTLE),
        LABEL(ABS_RUDDER),
        LABEL(ABS_WHEEL),
        LABEL(ABS_GAS),
        LABEL(ABS_BRAKE),
        LABEL(ABS_HAT0X),
        LABEL(ABS_HAT0Y),
        LABEL(ABS_HAT1X),
        LABEL(ABS_HAT1Y),
        LABEL(ABS_HAT2X),
        LABEL(ABS_HAT2Y),
        LABEL(ABS_HAT3X),
        LABEL(ABS_HAT3Y),
        LABEL(ABS_PRESSURE),
        LABEL(ABS_DISTANCE),
        LABEL(ABS_TILT_X),
        LABEL(ABS_TILT_Y),
        LABEL(ABS_TOOL_WIDTH),
        LABEL(ABS_VOLUME),
        LABEL(ABS_MISC),
        LABEL(ABS_MT_SLOT),
        LABEL(ABS_MT_TOUCH_MAJOR),
        LABEL(ABS_MT_TOUCH_MINOR),
        LABEL(ABS_MT_WIDTH_MAJOR),
        LABEL(ABS_MT_WIDTH_MINOR),
        LABEL(ABS_MT_ORIENTATION),
        LABEL(ABS_MT_POSITION_X),
        LABEL(ABS_MT_POSITION_Y),
        LABEL(ABS_MT_TOOL_TYPE),
        LABEL(ABS_MT_BLOB_ID),
        LABEL(ABS_MT_TRACKING_ID),
        LABEL(ABS_MT_PRESSURE),
        LABEL(ABS_MT_DISTANCE),
        LABEL_END,
};

static struct label sw_labels[] = {
        LABEL(SW_LID),
        LABEL(SW_TABLET_MODE),
        LABEL(SW_HEADPHONE_INSERT),
        LABEL(SW_RFKILL_ALL),
        LABEL(SW_RADIO),
        LABEL(SW_MICROPHONE_INSERT),
        LABEL(SW_DOCK),
        LABEL(SW_LINEOUT_INSERT),
        LABEL(SW_JACK_PHYSICAL_INSERT),
        LABEL(SW_VIDEOOUT_INSERT),
        LABEL(SW_CAMERA_LENS_COVER),
        LABEL(SW_KEYPAD_SLIDE),
        LABEL(SW_FRONT_PROXIMITY),
        LABEL(SW_ROTATE_LOCK),
        LABEL_END,
};

static struct label msc_labels[] = {
        LABEL(MSC_SERIAL),
        LABEL(MSC_PULSELED),
        LABEL(MSC_GESTURE),
        LABEL(MSC_RAW),
        LABEL(MSC_SCAN),
        LABEL_END,
};

static struct label led_labels[] = {
        LABEL(LED_NUML),
        LABEL(LED_CAPSL),
        LABEL(LED_SCROLLL),
        LABEL(LED_COMPOSE),
        LABEL(LED_KANA),
        LABEL(LED_SLEEP),
        LABEL(LED_SUSPEND),
        LABEL(LED_MUTE),
        LABEL(LED_MISC),
        LABEL(LED_MAIL),
        LABEL(LED_CHARGING),
        LABEL_END,
};

static struct label rep_labels[] = {
        LABEL(REP_DELAY),
        LABEL(REP_PERIOD),
        LABEL_END,
};

static struct label snd_labels[] = {
        LABEL(SND_CLICK),
        LABEL(SND_BELL),
        LABEL(SND_TONE),
        LABEL_END,
};
#if 0
static struct label id_labels[] = {
        LABEL(ID_BUS),
        LABEL(ID_VENDOR),
        LABEL(ID_PRODUCT),
        LABEL(ID_VERSION),
        LABEL_END,
};
static struct label bus_labels[] = {
        LABEL(BUS_PCI),
        LABEL(BUS_ISAPNP),
        LABEL(BUS_USB),
        LABEL(BUS_HIL),
        LABEL(BUS_BLUETOOTH),
        LABEL(BUS_VIRTUAL),
        LABEL(BUS_ISA),
        LABEL(BUS_I8042),
        LABEL(BUS_XTKBD),
        LABEL(BUS_RS232),
        LABEL(BUS_GAMEPORT),
        LABEL(BUS_PARPORT),
        LABEL(BUS_AMIGA),
        LABEL(BUS_ADB),
        LABEL(BUS_I2C),
        LABEL(BUS_HOST),
        LABEL(BUS_GSC),
        LABEL(BUS_ATARI),
        LABEL(BUS_SPI),
        LABEL_END,
};
#endif
static struct label mt_tool_labels[] = {
        LABEL(MT_TOOL_FINGER),
        LABEL(MT_TOOL_PEN),
        LABEL(MT_TOOL_MAX),
        LABEL_END,
};

static struct label ff_status_labels[] = {
        LABEL(FF_STATUS_STOPPED),
        LABEL(FF_STATUS_PLAYING),
        LABEL(FF_STATUS_MAX),
        LABEL_END,
};

static struct label ff_labels[] = {
        LABEL(FF_RUMBLE),
        LABEL(FF_PERIODIC),
        LABEL(FF_CONSTANT),
        LABEL(FF_SPRING),
        LABEL(FF_FRICTION),
        LABEL(FF_DAMPER),
        LABEL(FF_INERTIA),
        LABEL(FF_RAMP),
        LABEL(FF_SQUARE),
        LABEL(FF_TRIANGLE),
        LABEL(FF_SINE),
        LABEL(FF_SAW_UP),
        LABEL(FF_SAW_DOWN),
        LABEL(FF_CUSTOM),
        LABEL(FF_GAIN),
        LABEL(FF_AUTOCENTER),
        LABEL_END,
};

static struct label key_value_labels[] = {
        { "UP", 0 },
        { "DOWN", 1 },
        { "REPEAT", 2 },
        LABEL_END,
};
