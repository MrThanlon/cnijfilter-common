/*  Canon Inkjet Printer Driver for Linux
 *  Copyright CANON INC. 2001-2010
 *  All Rights Reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307, USA.
 *
 * NOTE:
 *  - As a special exception, this program is permissible to link with the
 *    libraries released as the binary modules.
 *  - If you write modifications of your own for these programs, it is your
 *    choice whether to permit this exception to apply to your modifications.
 *    If you do not wish that, delete this exception.
 */


/* XPM */
static char * info_xpm[] = {
"30 30 7 1",
" 	c None",
".	c None",
"+	c #808080",
"@	c #FFFFFF",
"#	c #000000",
"$	c #C0C0C0",
"%	c #0000FF",
"...........++++++++...........",
"........+++@@@@@@@@+++........",
".......+@@@@@@@@@@@@@@+.......",
".....++@@@@@@@@@@@@@@@@++.....",
"....+@@@@@@@@@@@@@@@@@@@@#....",
"...+@@@@@@@@@@@@@@@@@@@@@@#...",
"...+@@@@@@@@@@@@@@@@@@@@@@#...",
"..+@@@@@@@@@$%%%%$@@@@@@@@@#..",
".+@@@@@@@@@@%%%%%%@@@@@@@@@@#.",
".+@@@@@@@@@@%%%%%%+@@@@@@@@@#.",
".+@@@@@@@@@@$%%%%$+@@@@@@@@@#.",
"+@@@@@@@@@@@@@++++@@@@@@@@@@@#",
"+@@@@@@@@@@@@@@@@@@@@@@@@@@@@#",
"+@@@@@@@@@@%%%%%%%@@@@@@@@@@@#",
"+@@@@@@@@@@@+%%%%%+@@@@@@@@@@#",
"+@@@@@@@@@@@@%%%%%+@@@@@@@@@@#",
"+@@@@@@@@@@@@%%%%%+@@@@@@@@@@#",
"+@@@@@@@@@@@@%%%%%+@@@@@@@@@@#",
"+@@@@@@@@@@@@%%%%%+@@@@@@@@@@#",
".+@@@@@@@@@@@%%%%%+@@@@@@@@@#.",
".+@@@@@@@@@@@%%%%%+@@@@@@@@@#.",
".+@@@@@@@@@%%%%%%%%%@@@@@@@@#.",
"..+@@@@@@@@@+++++++++@@@@@@#..",
"...+@@@@@@@@@@@@@@@@@@@@@@#...",
"...+@@@@@@@@@@@@@@@@@@@@@@#...",
"....+@@@@@@@@@@@@@@@@@@@@#....",
".....+#@@@@@@@@@@@@@@@@##.....",
".......#@@@@@@@@@@@@@@#.......",
"........###@@@@@@@@###........",
"...........########..........."};

/* XPM */
static char * exclam_xpm[] = {
"30 30 7 1",
" 	c None",
".	c None",
"+	c #808000",
"@	c #FFFF00",
"#	c #C0C0C0",
"$	c #000000",
"%	c #808080",
".............+++..............",
"............+@@#$.............",
"...........+@@@@#$............",
"...........+@@@@@$............",
"..........+@@@@@@#$...........",
"..........+@@@@@@@$...........",
".........+@@@@@@@@#$..........",
".........+@@@@@@@@@$..........",
"........+@@@@@@@@@@#$.........",
"........+@@@#$$$#@@@$.........",
".......+@@@@$$$$$@@@#$........",
".......+@@@@$$$$$%@@@$........",
"......+@@@@@$$$$$%@@@#$.......",
"......+@@@@@$$$$$%@@@@$.......",
".....+@@@@@@$$$$$%@@@@#$......",
".....+@@@@@@+$$$+%@@@@@$......",
"....+@@@@@@@#$$$#%@@@@@#$.....",
"....+@@@@@@@@$$$%@@@@@@@$.....",
"...+@@@@@@@@@+$+%@@@@@@@#$....",
"...+@@@@@@@@@#$#%@@@@@@@@$....",
"..+@@@@@@@@@@@$%@@@@@@@@@#$...",
"..+@@@@@@@@@@@%%@@@@@@@@@@$...",
".+@@@@@@@@@@@#$$#@@@@@@@@@#$..",
".+@@@@@@@@@@@$$$$%@@@@@@@@@$..",
"+@@@@@@@@@@@@$$$$%@@@@@@@@@#$.",
"+@@@@@@@@@@@@#$$#%@@@@@@@@@@$.",
"+@@@@@@@@@@@@@%%%@@@@@@@@@@@$.",
"+@@@@@@@@@@@@@@@@@@@@@@@@@@#$.",
".+@@@@@@@@@@@@@@@@@@@@@@@@#$..",
"..+$$$$$$$$$$$$$$$$$$$$$$$$..."};

/* XPM */
static char * syserr_xpm[] = {
"30 30 7 1",
" 	c None",
".	c None",
"+	c #800000",
"@	c #FF0000",
"#	c #000000",
"$	c #FFFFFF",
"%	c #808080",
"...........++++++++...........",
"........+++@@@@@@@@+++........",
".......+@@@@@@@@@@@@@@+.......",
".....++@@@@@@@@@@@@@@@@++.....",
"....+@@@@@@@@@@@@@@@@@@@@#....",
"...+@@@@@@@@@@@@@@@@@@@@@@#...",
"...+@@@@@@@@@@@@@@@@@@@@@@#...",
"..+@@@@@@$@@@@@@@@@@$@@@@@@#..",
".+@@@@@@$$$@@@@@@@@$$$@@@@@@#.",
".+@@@@@$$$$$@@@@@@$$$$$@@@@@#.",
".+@@@@@@$$$$$@@@@$$$$$%@@@@@#.",
"+@@@@@@@@$$$$$@@$$$$$%@@@@@@@#",
"+@@@@@@@@@$$$$$$$$$$%@@@@@@@@#",
"+@@@@@@@@@@$$$$$$$$%@@@@@@@@@#",
"+@@@@@@@@@@@$$$$$$%@@@@@@@@@@#",
"+@@@@@@@@@@@$$$$$$@@@@@@@@@@@#",
"+@@@@@@@@@@$$$$$$$$@@@@@@@@@@#",
"+@@@@@@@@@$$$$$$$$$$@@@@@@@@@#",
"+@@@@@@@@$$$$$%@$$$$$@@@@@@@@#",
".+@@@@@@$$$$$%@@@$$$$$@@@@@@#.",
".+@@@@@$$$$$%@@@@@$$$$$@@@@@#.",
".+@@@@@@$$$%@@@@@@@$$$%@@@@@#.",
"..+@@@@@@$%@@@@@@@@@$%@@@@@#..",
"...+@@@@@%@@@@@@@@@@%@@@@@#...",
"...+@@@@@@@@@@@@@@@@@@@@@@#...",
"....+@@@@@@@@@@@@@@@@@@@@#....",
".....+#@@@@@@@@@@@@@@@@##.....",
".......#@@@@@@@@@@@@@@#.......",
"........###@@@@@@@@###........",
"...........########..........."};

