//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "responsive_layout.h"
#include "screenshot.h"
#include <iostream>
#include <QApplication>
#include <QScrollArea>
#include "scroll_layout.h"
#include "scroll_layout1.h"


ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 320);  // the mini_size
    setMaximumSize(1280, 720);  //the maximum_size

    createWidgets();
}

void ResponsiveWindow::createWidgets() {

    ResponsiveLayout * rl = new ResponsiveLayout();
    //create scroll p and p1
    QScrollArea * p = new QScrollArea();
    QScrollArea * p1 = new QScrollArea();
    //set the property of them
    p->setWidgetResizable(1);
    p->viewport()->setAutoFillBackground(1);
    // the vertical one
    p->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    p->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    p1->setWidgetResizable(1);
    p1->viewport()->setAutoFillBackground(1);
    //the horizontal one
    p1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    p1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    QWidget *w = new QWidget();
    QWidget *w1 = new QWidget();

//
    scroll_s *q = new scroll_s();
    scroll_t *q1 = new scroll_t();
    // add 17 search results
    for (int i = 0; i < 17; ++i) {
        q->addWidget(new ResponsiveLabel(kSearchResultImage));
        q->addWidget(new ResponsiveLabel(kSearchResultText));
    }
    // add 17 search results
    for (int i = 0; i < 17; ++i) {
        q1->addWidget(new ResponsiveLabel(kSearchResultImage));
        q1->addWidget(new ResponsiveLabel(kSearchResultText));
    }

    // add them to scroll
    w->setLayout(q);
    p->setWidget(w);

    // add them to scroll
    w1->setLayout(q1);
    p1->setWidget(w1);


    // add all the widgets we need to demonstrate all layouts
    rl->addWidget(new ResponsiveLabel(kNavTabs));
    rl->addWidget(new ResponsiveLabel(kSearchButton));
    rl->addWidget(new ResponsiveLabel(kPage));
    rl->addWidget(new ResponsiveLabel(kSignIn));
    rl->addWidget(new ResponsiveLabel(kSearchBackward));
    rl->addWidget(new ResponsiveLabel(kSearchForward));
    rl->addWidget(new ResponsiveLabel(kAdvert));
    rl->addWidget(new ResponsiveLabel(kAdvert));
    rl->addWidget(new ResponsiveLabel(kHomeLink));
    rl->addWidget(new ResponsiveLabel(kMenu));
    rl->addWidget(new ResponsiveLabel(kAvatar));
    rl->addWidget(new ResponsiveLabel(kSearchText));
    rl->addWidget(new ResponsiveLabel(kShoppingBasket));
    rl->addWidget(new ResponsiveLabel(kSearchOptions));
    // the vertical scroll
    rl->addWidget(p);
    // the horizontal one
    rl->addWidget(p1);
    // note that later widgets are drawn on top of earlier widgets
    setLayout(rl);
}


