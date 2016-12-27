[Download the latest release!](https://github.com/CiaccoDavide/BackgroundPage/releases) (v1.0)

---

Display an html page as your desktop background (over the icons, behind any window)

> ⚠  TODO:

> * system tray icon with options (like a "change remote url" option, an "autorun at startup" checkbox and a button to quit the application without the need to use the task manager)

> * linux port (macOS too?)

## BackgroundPage

I created **BackgroundPage** because I felt the need for an interactive desktop background.

I didn't found anything that would satisfy me: Rainmeter (wich is awesome if properly configured) felt linke an overkill, Windows decided to drop the old Active Desktop system and the only application similar to mine is hosted on one of those sketchy _"dowload the downloader to install the installer to download the application"_ type of websites.

I probably didn't search deeply enough, maybe something like **BackgroundPage** already exists, I just felt the need to write my own program in Qt.

> ⚠  _I never used Qt before, so please be gentle! **Constructive criticism is always welcome.**_

---

### Behavior

You can choose the URL of the page that you want to display.

If your system is offline, a local page (that you can customize) will be loaded instead.

The _BackgroundPage_ will stay behind any open window. (but will still cover the desktop and its icons)

Clicking the "show desktop" button will work as intended, so that you will be able to interact with the desktop icons.

This application will not appear into the "alt+tab selector".

Clicking on the _BackgroundPage_ is like clicking on the desktop: focus on any window will be lost but the BackgroundPage will remain behind them.

---

### Usage

The application will have some resources:

 * a file ( _remoteURL.conf_ ) that will store the target URL
 * a folder ( called _local_ ) with an _index.html_ (for the offline execution) and any other resource neded by that file ( like _images, *.css, *.js, etc..._ )
 
To load a custom URL you have to edit _remoteURL.conf_ placing your URL in the first line of that file, any following line will be ignored.

To edit the custom offline page you have to edit the contents of _local_, your _index.html_ must be in that folder.

---

### Video

<iframe style="width:100%;height: 400px;overflow: hidden;border-radius:5px;border:1px solid #ddd;box-shadow:0 0 6px #666;" src="https://www.youtube.com/embed/SsPK5mimgnk" frameborder="0" allowfullscreen></iframe>



---


### How it's made

I programmed **BackgroundPage** in C++ using Qt Creator 4.1.0 which is based on Qt 5.7.0.

The Qt WebEngine core is based on the Chromium Project.

Until now this has been tested only on Windows 10 64bit.

I tested it also on Linux Mint and Lubuntu, but I failed to deploy a standalone release build...

---

#### Linux Port

On some linux systems (x11) the application's window could not work as intended, to make it work just edit the WindowFlags like this:

```
// inside "main.cpp"
backgroundPage.setWindowFlags(
                Qt::WindowDoesNotAcceptFocus
                |Qt::WindowSystemMenuHint
                |Qt::FramelessWindowHint
                |Qt::SubWindow
                |Qt::ToolTip
                |Qt::Widget
                |Qt::Window
                |Qt::WindowStaysOnBottomHint
    );
```

#### Screenshots and background urls

_Send me your urls and screenshots!_ [ciaccodavide+backgroundpage@gmail.com](mailto:ciaccodavide+backgroundpage@gmail.com)

---

[Her - OS1 Loading

![](http://i.imgur.com/HFKgBPp.gif)

![](http://i.imgur.com/5pJ2pIw.gif)

](http://ciaccodavi.de/her/)

_credits: [Siyoung Park's "Her - OS1 Loading"](https://codepen.io/psyonline/pen/yayYWg)_

---

[Particles

![](http://i.imgur.com/2ur29kA.gif)

](http://ciaccodavi.de/particles/)

_credits: [Justin Windle's "30,000 Particles"](https://codepen.io/soulwire/pen/Ffvlo)_

---

[Winter with clock

![](http://i.imgur.com/LZZrmM3.png)

](http://ciaccodavi.de/backgrounds/winter/)

_credits: [/u/bozarcking's "Sunset over the mountains of Las Vegas"](https://www.reddit.com/r/EarthPorn/comments/5khkl9/sunset_over_the_mountains_of_las_vegas_2500x1668/)_
