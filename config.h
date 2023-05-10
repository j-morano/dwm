/* See LICENSE file for copyright and license details. */

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx  = 8;        /* border pixel of windows */
static const unsigned int gappx     = 8;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const char *fonts[]          = { "Fira Code:size=13" };
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_blue[]        = "#a3cbff";
static const char col_magenta[]        = "#f396ff";
static const char col_magenta_gray[]        = "#9a7a9e";
static const char col_green[]        = "#a3ffcf";
static const char col_green_gray[]        = "#72a188";
static const char col_yellow[]        = "#ffeba3";
static const char *colors[][5]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_blue  },
    [SchemeSelDeck]  = { col_gray4, col_cyan,  col_magenta  },
    [SchemeSelDeckSingle]  = { col_gray4, col_cyan,  col_magenta_gray  },
    [SchemeSelMax]  = { col_gray4, col_cyan,  col_green  },
    [SchemeSelMaxSingle]  = { col_gray4, col_cyan,  col_green_gray  },
    [SchemeSelFloat]  = { col_gray4, col_cyan,  col_yellow  },
};

/* tagging */
static const char *tags[] = {
    "1", "2", "3", "4", "5", "6", "7", "8", "9",
    "e", "r", "z", "n", "m", "g", "h", "x"
};

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    /* { "Gimp",     NULL,       NULL,       0,            1,           -1 }, */
    /* { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 }, */
    { NULL,       NULL,       NULL,       0,            False,       -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
    { "|D",       deck },
};

/* key definitions */
#define ALTKEY Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ALTKEY,                KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ALTKEY|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
/* helper for running command option from run_cmd script */
static const char runcmdpath[128] = "/home/morano/.config/suckless/run_cmd";
#define RUNCMD(opt) { .v = (const char*[]){ runcmdpath, opt, NULL } }

#include "movestack.c"
static const Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_c,      spawn,          RUNCMD("dmenu") },
    { MODKEY,             XK_Return, spawn,          RUNCMD("terminal") },
    { MODKEY,             XK_dead_acute, spawn,          RUNCMD("web_browser") },
    { MODKEY,             XK_dead_grave, spawn,          RUNCMD("file_manager") },
    { MODKEY|ALTKEY,       XK_dead_grave, spawn,          RUNCMD("terminal_file_manager") },
    { MODKEY|ShiftMask,                       XK_l, spawn,           RUNCMD("lock") },
    { MODKEY,           XK_i,  switchcol,    {0} },
    { MODKEY,           XK_a,  view,    {0} },
    { ALTKEY,             XK_plus, spawn,          RUNCMD("volume_up") },
    { ALTKEY,             XK_minus, spawn,          RUNCMD("volume_down") },
    { MODKEY,             XK_v, spawn,          RUNCMD("reset_kb_settings") },
    { MODKEY|ALTKEY,             XK_j,      movestack,      {.i = +1 } },
    { MODKEY|ALTKEY,             XK_k,      movestack,      {.i = -1 } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstackiso,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstackiso,     {.i = -1 } },
    { MODKEY,                       XK_y,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_t,      incnmaster,     {.i = -1 } },
    { MODKEY|ALTKEY,                       XK_ntilde,      setmfact,       {.f = -0.05} },
    { MODKEY|ALTKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ALTKEY,                       XK_i, zoom,           {0} },
    { MODKEY,                       XK_p, zoom,           {0} },
    { MODKEY,             XK_q,      killclient,     {0} },
    { MODKEY,                       XK_d,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_s,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_w,      setlayout,      {.v = &layouts[3]} },
    { MODKEY|ControlMask,                       XK_space,  setlayout,      {0} },
    { MODKEY|ALTKEY,             XK_f,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ALTKEY,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ALTKEY,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ALTKEY,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY|ALTKEY,             XK_o, tagmon,         {.i = +1 } },
    { MODKEY,             XK_o, focusmon,         {.i = +1 } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    TAGKEYS(                        XK_e,                      9)
    TAGKEYS(                        XK_r,                      10)
    TAGKEYS(                        XK_z,                      11)
    TAGKEYS(                        XK_n,                      12)
    TAGKEYS(                        XK_m,                      13)
    TAGKEYS(                        XK_g,                      14)
    TAGKEYS(                        XK_h,                      15)
    TAGKEYS(                        XK_space,                  16)
    { MODKEY|ALTKEY|ShiftMask,             XK_BackSpace,      quit,           {0} },
    { MODKEY|ALTKEY,             XK_BackSpace,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[3]} },
    { ClkWinTitle,          0,              Button1,        zoom,           {0} },
    { ClkWinTitle,          0,              Button3,        killclient,     {0} },
    { ClkWinTitle,          0,              Button4,        focusstackiso,     {-1} },
    { ClkWinTitle,          0,              Button5,        focusstackiso,     {+1} },
    { ClkStatusText,        0,              Button2,        spawn,          RUNCMD("terminal") },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

