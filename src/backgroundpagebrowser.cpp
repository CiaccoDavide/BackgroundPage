#include "backgroundpagebrowser.h"
#include <QWebEngineView>
#include <QApplication>
#include <QTextStream>
#include <QVBoxLayout>
#include <QIODevice>
#include <QString>
#include <QEvent>
#include <QFile>

QWebEngineView *browser;

BackgroundPageBrowser::BackgroundPageBrowser(QWidget *parent) : QWidget(parent)
{
    // instantiate a new layout for the QWidget
    QVBoxLayout *l = new QVBoxLayout();

    // instantiate the WebEngineView that will display the web page
    browser = new QWebEngineView(parent);

    // set the background of the web view transparent (so that the color of the widget is shown)
    browser->page()->setBackgroundColor(Qt::transparent);

    // if a connection is avaiable load the url from file
    QFile file(QApplication::applicationDirPath()+"/BackgroundPageResources/remoteURL.conf");

    // the string where the url will be stored
    QString urlString = "";

    // open the file
    if (file.open(QIODevice::ReadOnly))
    {
        // read the file as a text stream
        QTextStream in(&file);

        // fetch only the first line of the file (that should contain the url)
        if(!in.atEnd()) // if the file is not empty
        {
            // save the first line into "urlString"
            urlString = in.readLine();

            // call "onLoadFinished" when the web view has finished loading
            // deals with connection errors, loading a local page
            connect(browser, SIGNAL(loadFinished(bool)), SLOT(onLoadFinished(bool)));

            // load the desired web page
            browser->load(QUrl(urlString+"?ad"));
        }
        // close the file
        file.close();
    }

    // add the webView to the widget
    l->addWidget(browser, 1);

    // remove margins
    l->layout()->setContentsMargins(0,0,0,0);

    // apply the layout
    setLayout(l);
}

BackgroundPageBrowser::~BackgroundPageBrowser()
{
}

void BackgroundPageBrowser::enterEvent(QEvent*ev)
{
   BackgroundPageBrowser::lower();
}

void BackgroundPageBrowser::onLoadFinished(bool success)
{
    // if there is some kind of connection error
    if ( ! success )
    {
        // load the desired local page
        browser->load(QUrl("file:///"+QApplication::applicationDirPath()+"/BackgroundPageResources/local/index.html"));
    }
}
