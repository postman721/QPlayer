# QPlayer

QPlayer is a  **C++ / Qt6** video player for local media files.

© 2018–2026 JJ Posti <techtimejourney.net>
License: **GPL v2**

## Features
- Plays files/videos supported by **Qt Multimedia**
- Open, Play, Pause, Stop  
- Seek slider  
- Fullscreen with **Esc** to exit

## Building (Debian / Ubuntu – Qt6)

Install dependencies:

```bash
sudo apt install qt6-base-dev qt6-multimedia-dev qt6-tools-dev
```

Build with **Qt Creator** or:

```bash
qmake6
make
```

## Notes
- Uses **Qt6 Multimedia**

- ESC key will quit full screen mode. Alt+F4 might also work there.

