//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>

//using namespace std;

// you should probably make extensive changes to this function
void ResponsiveLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {

    QLayout::setGeometry(r);
    int z = 0.05 * r.width();  // the start position of advert when r.width() <= 700 && r.height() > 510
    int g = 0.01 * r.width(); // the start position of advert when r.width() > 700 && r.height() > 510
    // for all the Widgets added in ResponsiveWindow.cpp

    for (int i = 0; i < list_.size(); i++) {
        QLayoutItem *o = list_.at(i);
        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) {// null: cast failed on pointer
                std::cout << "warning, unknown widget class in layout" << std::endl;
            } else if (label->text() == kNavTabs && r.width() > 700) {// headers go at the top
                // the position of nav_tab when r.width() > 700
                label->setGeometry(0.27 * r.width(), 0.03 * r.height(), 0.46 * r.width(), 0.1 * r.height());

            }
                // only show a search button on small resolution, at the right of the window
//                 fixme: focus group did not like this behaviour for the search result element.
            else if (label->text() == kSearchOptions && r.width() > 700)
                // the position of search_options when r.width() > 700
                label->setGeometry(0.47 * r.width(), 0.15 * r.height(), 0.15 * r.width(), 0.1 * r.height());
            else if (label->text() == kSearchButton && r.width() <= 700) {
                // the position of search_button when r.width() <= 700
                label->setGeometry(0.8 * r.width(), 0.15 * r.height(), 0.15 * r.width(), 0.1 * r.height());
            } else if (label->text() == kSearchText && r.width() <= 700)
                // the position of search_text when r.width() <= 700
                label->setGeometry(0.05 * r.width(), 0.15 * r.height(), 0.7 * r.width(), 0.1 * r.height());
            else if (label->text() == kSearchText && r.width() > 700)
                // the position of search_text when r.width() > 700
                label->setGeometry(0.16 * r.width(), 0.15 * r.height(), 0.3 * r.width(), 0.1 * r.height());
            else if (label->text() == kSearchButton && r.width() > 700)
                // the position of search_button when r.width() > 700
                label->setGeometry(0.63 * r.width(), 0.15 * r.height(), 0.12 * r.width(), 0.1 * r.height());
            else if (label->text() == kAvatar && r.width() > 700)
                // the position of avatar when r.width() > 700
                label->setGeometry(0.76 * r.width(), 0.15 * r.height(), 0.09 * r.width(), 0.1 * r.height());
            else if (label->text() == kAdvert && r.width() <= 700 && r.height() > 510) {
                // the position of advert when r.width() <= 700 && r.height() > 510
                label->setGeometry(z, 0.27 * r.height(), 0.425 * r.width(), 0.2 * r.height());
                z += 0.475 * r.width(); //get the second advert
            } else if (label->text() == kAdvert && r.width() > 700 && r.height() > 510) {
                // the position of advert when r.width() > 700 && r.height() > 510
                label->setGeometry(g, 0.27 * r.height(), 0.15 * r.width(), 0.6 * r.height());
                g += 0.83 * r.width();
            } else if (label->text() == kMenu && r.width() <= 700)
                //the position of menu when r.width() <= 700
                label->setGeometry(0.525 * r.width(), 0.03 * r.height(), 0.425 * r.width(), 0.1 * r.height());
            else if (label->text() == kSignIn && r.width() <= 700)
                //the position of sign_in when r.width() <= 700
                label->setGeometry(0.05 * r.width(), 0.03 * r.height(), 0.425 * r.width(), 0.1 * r.height());
            else if (label->text() == kSignIn && r.width() > 700)
                //the position of sign_in when r.width() > 700
                label->setGeometry(0.01 * r.width(), 0.03 * r.height(), 0.12 * r.width(), 0.1 * r.height());
            else if (label->text() == kMenu && r.width() > 700)
                //the position of menu when r.width() > 700
                label->setGeometry(0.14 * r.width(), 0.03 * r.height(), 0.12 * r.width(), 0.1 * r.height());
            else if (label->text() == kShoppingBasket && r.width() > 700)
                //the position of shopping_basket when r.width() > 700
                label->setGeometry(0.74 * r.width(), 0.03 * r.height(), 0.12 * r.width(), 0.1 * r.height());
            else if (label->text() == kHomeLink && r.width() > 700)
                //the position of home_link when r.width() > 700
                label->setGeometry(0.87 * r.width(), 0.03 * r.height(), 0.12 * r.width(), 0.1 * r.height());
            else if (label->text() == kSearchBackward) {
                //the position of search_backward
                    label->setGeometry(0.25 * r.width(), 0.85 * r.height(), 0.15 * r.width(), 0.1 * r.height());
            }
            else if (label->text() == kSearchForward) {
                //the position of search_forward
                label->setGeometry(0.6 * r.width(), 0.85 * r.height(), 0.15 * r.width(), 0.1 * r.height());
            }
            else if (label->text() == kPage) {
                //the position of page
                label->setGeometry(0.425 * r.width(), 0.85 * r.height(), 0.15 * r.width(), 0.1 * r.height());
            }
            else if (i == list_.size() - 2 && r.height() <= 510 && r.width() <= 700) {
                //the position of scroll when r.height() <= 510 && r.width() <= 700
                label->setGeometry(0.07 * r.width(), 0.28 * r.height(), 0.86 * r.width(), 0.5 * r.height());
            } else if (i == list_.size() - 1 && r.height() <= 510 && r.width() > 700) {
                //the position of scroll when r.height() <= 510 && r.width() > 700
                label->setGeometry(0.07 * r.width(), 0.28 * r.height(), 0.86 * r.width(), 0.5 * r.height());
            } else if (i == list_.size() - 2 && r.width() <= 700 && r.height() > 510) {
                //the position of scroll when r.height() > 510 && r.width() <= 700
                label->setGeometry(0.07 * r.width(), 0.48 * r.height(), 0.86 * r.width(), 0.3 * r.height());
            } else if (i == list_.size() - 2 && r.width() > 700 && r.height() > 510) {
                //the position of scroll when r.height() > 510 && r.width() > 700
                label->setGeometry(0.17 * r.width(), 0.27 * r.height(), 0.66 * r.width(), 0.55 * r.height());
            }
            else // otherwise: disappear label by moving out of bounds
                label->setGeometry(-1, -1, 0, 0);

        }
        catch (std::bad_cast) {
            // bad_case: cast failed on reference...
            std::cout << "warning, unknown widget class in layout" << std::endl;
        }
    }
}


// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {
    return QSize(320, 320);
}

ResponsiveLayout::~ResponsiveLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
