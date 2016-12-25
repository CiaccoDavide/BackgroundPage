[Download the latest release!](https://github.com/CiaccoDavide/BackgroundPage/releases) (v1.0)

---

Display an html page as your desktop background (over the icons, behind any window)

> ⚠  Right now only the source code for Qt Creator is avaiable.
>
> ⚠  I still have to deploy a standalone build! 

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

Until now this has been tested only on Windows 10 64bit.
