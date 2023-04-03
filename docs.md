# Useful documentation

## Installation

```sh
# Dependencies
sudo dnf install dnf libX11-devel libXft-devel libXinerama-devel libXrandr-devel xorg-x11-xinit-session
# Installation command
make && sudo make install
# Xsessions
sudo cp dwm.desktop /usr/share/xsessions/
```


## See the logs

```
journalctl -b -1
```

## Issues

### Unexpected crashes web pages

Journal:
```
Nov 16 10:08:06 hemingway /usr/libexec/gdm-x-session[6867]: X Error of failed request:  BadLength (poly request too large or internal Xlib length error)
Nov 16 10:08:06 hemingway /usr/libexec/gdm-x-session[6867]:   Major opcode of failed request:  139 (RENDER)
Nov 16 10:08:06 hemingway /usr/libexec/gdm-x-session[6867]:   Minor opcode of failed request:  20 (RenderAddGlyphs)
Nov 16 10:08:06 hemingway /usr/libexec/gdm-x-session[6867]:   Serial number of failed request:  629
Nov 16 10:08:06 hemingway /usr/libexec/gdm-x-session[6867]:   Current serial number in output stream:  636
```

#### Solution:

```
sudo apt install unifont
```
