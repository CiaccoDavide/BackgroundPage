
```markdown

 ⚠  For now only the source code for Qt Creator is avaiable.
 ⚠  I still have to deploy a standalone build! 

```

## BackgroundPage

I created **_BackgroundPage_** because I felt the need for an interactive desktop background.

I didn't found anything that would satisfy me: Rainmeter (wich is awesome if properly configured) felt linke an overkill, Windows decided to drop the old Active Desktop system and the only application similar to mine is hosted on one of those sketchy _"dowload the downloader to install the installer to download the application"_ type of websites.

I probably didn't search deeply enough, maybe something like **_BackgroundPage_** already exists, I just felt the need to write my own program in Qt.

_I never used Qt before, so please be gentle! **Constructive criticism is always welcome.**_

### Behavior

You can choose the URL of the page that you want to display.

If your system is offline, a local page (that you can customize) will be loaded instead.

The _BackgroundPage_ will stay behind any open window. (but will still cover the desktop and its icons)

Clicking the "show desktop" button will work as intended, so that you will be able to interact with the desktop icons.

This application will not appear into the "alt+tab selector".

Clicking on the _BackgroundPage_ is like clicking on the desktop: focus on any window will be lost but the BackgroundPage will remain behind them.


### Usage

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for


### Video

<iframe width="560" height="315" src="https://www.youtube.com/embed/SsPK5mimgnk" frameborder="0" allowfullscreen></iframe>

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).
