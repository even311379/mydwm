/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;       /* vert inner gap between windows */
static const unsigned int gappoh    = 5;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating = 0;   /* 1 means swallow floating windows by default */
static const int showbar = 1; /* 0 means no bar */
static const int topbar = 1;  /* 0 means bottom bar */
#define ICONSIZE 36 /* icon size */
#define ICONSPACING 5 /* space between icon and title */
static const int usealtbar = 0;
/* 1 means use non-dwm status bar */        /* use default bar for now... */
static const char *altbarclass = "Polybar"; /* Alternate bar class name */
static const char *alttrayname = "tray";    /* Polybar tray instance name */
static const char *altbarcmd = "$HOME/bar.sh"; /* Alternate bar launch command */
// Need to use font which support your language: ex traditional chinese...
// otherwise the chinese character will be so small
static const char *fonts[] = {
	"Noto Sans CJK TC:size=12:antialias=true:autohint=true",
	// "LiterationSans Nerd Font:size=48",
	"Font Awesome 6 Free:size=9:antialias:true:style=Solid",
	"Font Awesome 6 Brands:size=9:antialias:true",
};
static const char dmenufont[] = "monospace:size=10";
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#005577";

/* some wonderful gruvbox dark colors */
static const char col_gruvbox_dark0[] = "#282828"; // ?? grey
static const char col_gruvbox_dark1[] = "#cc241d"; // red
static const char col_gruvbox_dark2[] = "#98971a"; // green
static const char col_gruvbox_dark3[] = "#d79921"; // yellow
static const char col_gruvbox_dark4[] = "#458588"; // blue
static const char col_gruvbox_dark5[] = "#b16286"; // megenta
static const char col_gruvbox_dark6[] = "#689d6a"; // cyan
static const char col_gruvbox_dark7[] = "#a89984"; // white

static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gruvbox_dark7, col_gruvbox_dark0, col_gruvbox_dark6},
    [SchemeSel]  = {col_gruvbox_dark0, col_gruvbox_dark3, col_gruvbox_dark6},
    /* colorbar patch: */
    // Statusbar right {text,background,not used but cannot be empty}
    [SchemeStatus]  ={col_gray1, col_gruvbox_dark3, col_gruvbox_dark6},
    // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsSel]  ={col_gray1, col_gruvbox_dark5, col_gruvbox_dark6},
    // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { col_gruvbox_dark7, col_gruvbox_dark0,   col_gruvbox_dark6  }, 
    // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoSel]  = { col_gray1, col_gruvbox_dark6,   col_gruvbox_dark6  }, 
    // infobar middle  unselected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { col_gruvbox_dark7, col_gruvbox_dark0,   col_gruvbox_dark6  }, 
    
    /* status color patch*/
    [SchemeWarn] = {col_gray1, col_gruvbox_dark3, col_gruvbox_dark6},
    [SchemeUrgent] = {col_gray1, col_gruvbox_dark1, col_gruvbox_dark6},

    /* [SchemeNorm] = {col_gray3, col_gray1, col_gray2}, */
    /* [SchemeSel] = {col_gray4, col_cyan, col_cyan}, */
};
static const unsigned int alphas[][3] = {
    /*               fg      bg        border*/
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeStatus] = {OPAQUE, baralpha, borderalpha},
    [SchemeTagsSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeTagsNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeInfoSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeInfoNorm] = {OPAQUE, baralpha, borderalpha},
};
static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* tagging */
static const char *tags[] = {"", "", "", "", "", "", "", "", ""};
static const char *tagsalt[] = {"➊", "➋", "➌", "➍", "➎", "➏", "➐", "➑", "➒"};
static const int momentaryalttags=0; /* 1 means alttags will show only when key is held down */

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title     tags mask   floating?  terminal? nosawllow monitor */
    {"Gimp",        NULL,       NULL,      0,        1,            0,        0,      -1},
    {"Firefox",     NULL,       NULL,    1 << 8,     0,            0,       -1,      -1},
    {"st",          NULL,       NULL,      0,        0,            1,        0,      -1},
    {"kitty",       NULL,       NULL,      0,        0,            1,        0,      -1},
    {NULL,          NULL, "Event Tester",  0,        0,            0,        1,      -1}, /* vex */
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints = 1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[T]", tile}, /* first entry is default */
    {"[G]", grid},
    {"[M]", monocle}, 
//{ "[@]",      spiral },
//{ "[\\]",     dwindle },
//{ "H[]",      deck },
//{ "TTT",      bstack },
//{ "===",      bstackhoriz },
//{ "HHH",      grid },
//{ "###",      nrowgrid },
//{ "---",      horizgrid },
//{ ":::",      gaplessgrid },
//{ "|M|",      centeredmaster },
//{ ">M>",      centeredfloatingmaster },
    {"[F]", NULL}, /* no layout function means floating behavior */
    {NULL, NULL}, 
};

/* key definitions */

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
//	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,     {.ui = TAG } },     \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb",
// col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

/* 
   Can not spawn kitty with fixed size...
   still need to stick on st... otherwise the scratchpad will not work good
   st alpha is just not working...
 */
static const char *termcmd[] = {"st"}; 
static const char *layoutmenu_cmd = "layoutmenu.sh"; //need to install xmenu and then click on it 
static const char scratchpadname[] = "scratchpad";
/* static const char *scratchpadcmd[] = {"st", "-t", scratchpadname, "-g", "120x34"}; */
/* static const char *volumemixercmd[] = {"st", "-t", scratchpadname, "-g", "120x34", "-e", "pulsemixer", "NULL"}; */


static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY | ShiftMask, XK_Return, spawn, SHCMD("st")},
    {MODKEY, XK_b, spawn, SHCMD("thorium-browser")},
    {MODKEY, XK_e, spawn, SHCMD("st -e vifm")},
    // dolphin with KDE env so that the color will be perfect!
    {MODKEY | ShiftMask, XK_e, spawn, SHCMD("env XDG_CURRENT_DESKTOP=KDE XDG_SESSION_DESKTOP=KDE XDG_SESSION_VERSION=5 dolphin")}, 
    {MODKEY, XK_w, spawn, SHCMD("com.logseq.Logseq")},  // my note app logseq
    /* {MODKEY, XK_grave, spawn, {.v = scratchpadcmd}}, */
    {MODKEY, XK_v, spawn, SHCMD("st -t scratchpad -g 120x34 -e pulsemixer")},
    {MODKEY, XK_a, spawn, SHCMD("dmenu_run -c -l 16")},
    {MODKEY | ShiftMask, XK_a, spawn, SHCMD("./.local/share/dmenu_scripts/dmenu_kill")},
    {MODKEY | ShiftMask, XK_m, spawn, SHCMD("./.local/share/dmenu_scripts/dmenu_music")},
    {MODKEY, XK_p, spawn, SHCMD("./.local/share/dmenu_scripts/dmenu_power")},
    {Mod1Mask, XK_Tab, spawn, SHCMD("./.local/share/dmenu_scripts/dmenu_wswitcher")},

    {MODKEY | ShiftMask, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY | ShiftMask, XK_i, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_h, setcfact, {.f = +0.25}},
    {MODKEY | ShiftMask, XK_l, setcfact, {.f = -0.25}},
    {MODKEY | ShiftMask, XK_o, setcfact, {.f = 0.00}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}}, // taggle between last view?
    {MODKEY | ShiftMask , XK_Tab, view, {.ui = ~0}}, // view all
    {MODKEY, XK_q, killclient, {0}},
    {MODKEY, XK_space, cyclelayout, {.i = +1}},
    {MODKEY | ShiftMask, XK_space, cyclelayout, {.i = -1}},
    {MODKEY , XK_0, togglesticky, {0}}, // toggle sticky it works!
    {MODKEY , XK_n, togglealttag, {0}}, // toggle alttag

    {MODKEY, XK_comma,  focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma,  tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},

    TAGKEYS(XK_1, 0) 
    TAGKEYS(XK_2, 1)
    TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3)
    TAGKEYS(XK_5, 4)
    TAGKEYS(XK_6, 5)
    TAGKEYS(XK_7, 6)
    TAGKEYS(XK_8, 7)
    TAGKEYS(XK_9, 8)
    {MODKEY | ControlMask, XK_q, quit, {0}}, // quit dwm
    {MODKEY | ControlMask, XK_r, quit, {1}}, // restart dwm
                                             
    // the rest peripheral control          
    {MODKEY, XK_s, spawn, SHCMD("flameshot gui")},
    {MODKEY, XK_Up, spawn, SHCMD("amixer -q sset Master 5%+")},
    {MODKEY, XK_Down, spawn, SHCMD("amixer -q sset Master 5%-")},

    // style related key binding....
    // vanitygaps 
	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    // drag to reorder win position? placemouse patch from bakkeby/dwm-flexipatch
    // move to place is more natural use case... so I move default drag to float ShiftMask one
    {ClkClientWin, MODKEY, Button1, moveorplace, {.i = 1}}, 
    {ClkClientWin, MODKEY | ShiftMask, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkClientWin, MODKEY | ShiftMask, Button3, dragcfact, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
