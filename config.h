/* See LICENSE in dwm source code package for copyright and license details. */
/* This is the config.h for dwm with icons and colors in font.*/
/* This dwm config is a modified version of gnusosas (gnusosa@gnusosa.net) dwm-config. Mainly scaled down. */
/* http://github.com/kusk/dwm */
/* This file can be distributed under the same license that dwm works with */ 
#include <X11/XF86keysym.h> 

/* appearance */
static const char font[] = "-*-bitocra-*-*-*-*-*-*-*-*-*-*-*-*";

#define NUMCOLORS 8
static const char colors[NUMCOLORS][ColLast][8] = {
    // border     foreground background
    { "#1A1A1A", "#FFFFFF", "#303030" },  // 01 - normal
    { "#17bbe3", "#98CBFE", "#3F3F3F" },  // 02 - selected
    { "#B3354C", "#303030", "#D370A3" },  // 03 - urgent
    { "#1A1A1A", "#1A1A1A", "#020202" },  // 04 - black
    { "#802635", "#802635", "#020202" },  // 05 - red
    { "#608040", "#608040", "#020202" },  // 06 - green
    { "#877C43", "#877C43", "#020202" },  // 07 - yellow
    { "#4C4C4C", "#4C4C4C", "#020202" },  // 08 - gray
};

static const unsigned int borderpx       = 1;                // border pixel of windows
static const unsigned int snap           = 5;                // snap pixel
static const unsigned int gappx          = 4;                /* gap pixel between windows */
static const Bool showbar                = True;             // False means no bar
static const Bool topbar                 = False;             // False means bottom bar
static Bool useicons                     = True;             // False means use ascii symbols
static const char scratchpadname[]       = "Scratchpad";
static const char ncmpcpppadname[]       = "ncmpcpp";

/* layout(s) */
static const float mfact      = 0.50;     // factor of master area size [0.05..0.95]
static const Bool resizehints = False;    // True means respect size hints in tiled resizals
static const int nmaster      = 1;        // default number of clients in the master area

static const Layout layouts[] = {
    // icon                                    symbol    arrange function
    { "/home/komrade/etc/dwm/icons/tile.xbm",     "þ",      tile },
    { "/home/komrade/etc/dwm/icons/bstack.xbm",   "ü",      bstack },
    { "/home/komrade/etc/dwm/icons/float.xbm",    "ý",      NULL },     // no layout function means floating behavior
    { "/home/komrade/etc/dwm/icons/monocle.xbm",  "ÿ",      monocle },
};

static const MonocleNumberedIcon monoclenumberedicons[] = {
	{ "/home/komrade/etc/dwm/icons/monocle.xbm" },
};

/* tagging */
static const Tag tags[] = {
    // name       layout           mfact    nmaster
    { " 1 ",        &layouts[0],   0.65,      -1 },
    { " 2 ",        &layouts[0],     -1,      -1 },
    { " 3 ",        &layouts[0],   0.65,      -1 },
    { " 4 ",        &layouts[0],   0.65,      -1 },
    { " 5 ",        &layouts[0],     -1,      -1 },
};

/* window rules */
static const Rule rules[] = {
    /* class         instance    title       tags mask     iscentered     isfloating   monitor */
    { "Gimp",        NULL,       NULL,       1 << 4,       False,          True,       -1 },
    { "Firefox",     NULL,       NULL,       1 << 4,       False,         False,       -1 },
    { "Pavucontrol", NULL,       NULL,       0,             True,          True,       1  },
    { "Pcmanfm",     NULL,       NULL,       1 << 2,       False,         False,       -1 },
    { "URxvt",       NULL, "download",       0,             True,          True,       1  },
    { "URxvt",       NULL,  "ncmpcpp",       0,             True,          True,       -1 },
    { "Nitrogen",    NULL,       NULL,       0,             True,          True,       1  },
    { "URxvt",       NULL,      "vim",       1 << 3,       False,         False,       -1 },
    { "Google-chrome-stable",    NULL,       NULL,       1 << 1,       False,         False,       -1 },
    { "tabbed",    "term",       NULL,       1,            False,         False,       -1 },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]      = { "dmenu_run", "-i", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]       = { "tabbed", "-n", "term", "urxvt", "-embed", NULL };
static const char *scratchpadcmd[] = { "urxvt", "-title", scratchpadname, "-geometry", "99x35", NULL };
static const char *ncmpcpppadcmd[] = { "urxvt", "-title", ncmpcpppadname, "-geometry", "100x40", "-e", "ncmpcpp", NULL };
static const char *pcmanfmcmd[]    = { "pcmanfm", NULL };
static const char *browsercmd[]    = { "google-chrome-stable", NULL };
static const char *incogcmd[]      = { "google-chrome-stable", "--incognito", NULL };
static const char *editcmd[]       = { "urxvt", "-e", "vim", NULL };
static const char *sublcmd[]       = { "subl", NULL };
static const char *scrotcmd[]      = { "scrot", NULL};
static const char *quitcmd[]       = { "pkill", "xinit", NULL };

static Key keys[] = {
   // modifier                      key        function        argument
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },           //#Mod+i:Increments number of windows in master area
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },           //#Mod+d:Decrements Number of windows in master area
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },     //#Mod+p:Launches dmenu for user input
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },      //#Mod+Shift+Return:Spawns urxvt embedded in tabbed
    { MODKEY,                       XK_f,      spawn,          {.v = pcmanfmcmd } },   //#Mod+f:Spawns pcmanfm
    { MODKEY,                       XK_w,      spawn,          {.v = browsercmd } },   //#Mod+w:Spawns google-chrome-stable
    { MODKEY|ShiftMask,             XK_w,      spawn,          {.v = incogcmd } },     //#Mod+Shift+w:Spawns an incognito window of google-chrome-stable
    { MODKEY,                       XK_e,      spawn,          {.v = editcmd } },      //#Mod+e:Spawns vim
    { MODKEY|ShiftMask,             XK_e,      spawn,          {.v = sublcmd } },      //#Mod+Shift+e:Spawns sublime-text
    { MODKEY,                       XK_Return, zoom,           {0} },                  //#Mod+Return:Swaps current window with master
    { MODKEY,		                XK_Tab,    focusstack,     {.i = +1 } },           //#Mod+Tab:Moves one window forward in stack focus
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },           //#Mod+k:Moves one window backward in stack focus
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },         //#Mod+h:Decrements master area size by 5% of the screen
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },         //#Mod+l:Increments master area size by 5% of the screen
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },                  //#Mod+Shift+c:Kills currently focused window
    { Mod1Mask,                     XK_z,      togglescratch,  {.v = scratchpadcmd} }, //#Alt_L+z:Spawns/Summons urxvt scratchpad
    { Mod1Mask,                     XK_m,      togglescratch,  {.v = ncmpcpppadcmd} }, //#Alt_L+z:Spawns/Summons ncmpcpp in a urxvt scratchpad
    { MODKEY,                       XK_b,      togglebar,      {0} },                  //#Mod+b:Toggle dwm info bar
    { MODKEY,                       XK_space,  setlayout,      {0} },                  //#Mod+Space:Cycle Layouts
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },                  //#Mod+Shift+Space:Toggle floating on focused window
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },          //#Mod+0:Toggle all tags visible
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },          //#Mod+Shift+0:Toggle focused window visible on all tags
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },           //#Mod+,:Focus previous monitor
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },           //#Mod+.:Focus next monitor
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },           //#Mod+Shift+,:Move focused window to last monitor
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },           //#Mod+Shift+.:Move focused window to next monitor
    { MODKEY,                       XK_Print,  spawn,          {.v = scrotcmd } },     //#Mod+PrtSc:Take a screenshot and move it to ~/images/scrots
    TAGKEYS(                        XK_1,                      0)                      //#Mod+[1..5]:Toggle chosen tag view visible
    TAGKEYS(                        XK_2,                      1)                      //#Mod+Control+[1..5]:View only chosen tag
    TAGKEYS(                        XK_3,                      2)                      //#Mod+Shift+[1..5]:Switch focused window to chosen tag
    TAGKEYS(                        XK_4,                      3)                      //#Mod+Control+Shift:Add chosen tag to focused window's tag list
    TAGKEYS(                        XK_5,                      4)                      //#Mod+Mouse2:Toggle focused window to and from floating mode
    { MODKEY,                       XK_q,      quit,           {0} },                  //#Mod+q:Restart dwm (.xinitrc loop)
    { MODKEY|ShiftMask,             XK_q,      spawn,          {.v = quitcmd } },      //#Mod+Shift+q:Kill X11
    { 0,                  XF86XK_Launch1,      spawn,          {.v = scratchpadcmd }}, //#ThinkVantage:Spawns/Summons urxvt scratchpad
};

// click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin
static Button buttons[] = {
    // click                event mask      button          function        argument
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkWinTitle,          0,              Button1,        focusstack,     {.i = +1 } },
    { ClkWinTitle,          0,              Button3,        focusstack,     {.i = -1 } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },        //Mod+Mouse1:Drag focused floating window under pointer
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },        //Mod+Mouse2:Toggle focused window to and from floating mode
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },        //Mod+Mouse3:Resize focused floating window under pointer
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
