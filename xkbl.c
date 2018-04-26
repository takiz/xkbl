#include <stdio.h>
#include <stdlib.h>
#include <X11/XKBlib.h>

int main(void)
{
        Display *dpy = XOpenDisplay(NULL);

        if (dpy == NULL) {
                fprintf(stderr, "Can't open display\n");
                exit(EXIT_FAILURE);
        }

        XkbStateRec state;
        XkbDescPtr desc;
        char *kb_name;
        
        if (XkbGetState(dpy, XkbUseCoreKbd, &state) == Success)        
                desc = XkbGetMap(dpy, XkbAllClientInfoMask, XkbUseCoreKbd);
        
        if (desc && XkbGetNames(dpy, XkbGroupNamesMask, desc) == Success)
                kb_name = XGetAtomName(dpy, desc->names->groups[state.group]);
        
        if (kb_name) {
                printf("%.2s", kb_name);
                XFree(kb_name);
        }
                
        XkbFreeClientMap(desc, XkbAllClientInfoMask, True);
        XkbFreeNames(desc, XkbGroupNamesMask, True);
        XCloseDisplay(dpy);
        return 0;
}
