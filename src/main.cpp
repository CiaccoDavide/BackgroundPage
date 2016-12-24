#include "backgroundpagebrowser.h"
#include <QWebEngineView>
#include <QApplication>
#include <QScreen>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

  //  qDebug() << "App path : " << app.applicationDirPath();
    // this will be the widget with the webview that will display the desired page
    BackgroundPageBrowser backgroundPage;

    //  view.setWindowState(Qt::WindowFullScreen);
    QRect rect = app.screens().at(0)->availableGeometry();

    // set the background color
    // (I set it dark so that it will not white-flash you in the face, burning your eyes)
    // [anyway it will be covered by the html page (once loaded)]
    backgroundPage.setStyleSheet("background-color:#161616;");

    // not activating will prevent some flickering
    backgroundPage.setAttribute(Qt::WA_ShowWithoutActivating);

    // apply flags to the backgroundPage window to make it borderless and limit interaction
    backgroundPage.setWindowFlags(
                 backgroundPage.windowFlags() // get the current flags
                |Qt::FramelessWindowHint
                |Qt::SubWindow
                |Qt::Widget
                |Qt::Window
                |Qt::WindowSystemMenuHint
                |Qt::WindowDoesNotAcceptFocus
                |Qt::ToolTip
    );

    // resize the backgroundPage to fill the screen
    backgroundPage.resize(rect.width(),rect.height());

    // the BackgroundPage will be pushed behind any other running application
    backgroundPage.lower();

    // show the BackgroundPage
    backgroundPage.show();

    return app.exec();
}
