
#include "scroll_layout.h"
#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>

//using namespace std;

// you should probably make extensive changes to this function
void scroll_s::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {
    // the start position of result
    QLayout::setGeometry(r);
    int x = 0.03*r.width();
    int y = 0.03*r.width();
    int z = 0.03*r.width();
    int h = 0.515*r.width();
    int a=1;
    int b=1;

    // for all the Widgets added in ResponsiveWindow.cpp

    for (int i = 0; i < list1_.size(); i++) {
        QLayoutItem *o = list1_.at(i);
        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                std::cout << "warning, unknown widget class in layout" << std::endl;


                // fixme: focus group did not like this behaviour for the search result element.

            // the move of result_image
            else if (label -> text() == kSearchResultImage) {
                    label->setGeometry(x, y, 0.455 * r.width(), 0.455 * r.width());
                    if (a == 1) {
                        x += 0.485 * r.width();
                        a = 0;
                    } else {
                        x = 0.03 * r.width();
                        y += 0.615 * r.width();
                        a = 1;
                }
            }
                // the move of result_text
            else if (label -> text() == kSearchResultText) {
                    label->setGeometry(z, h, 0.455 * r.width(), 0.1 * r.width());
                    if (b == 1) {
                        z += 0.485 * r.width();
                        b = 0;
                    } else {
                        z = 0.03 * r.width();
                        h += 0.615 * r.width();
                        b = 1;
                    }

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
int scroll_s::count() const {
    return list1_.size();
}

QLayoutItem *scroll_s::itemAt(int idx) const {
    return list1_.value(idx);
}

QLayoutItem *scroll_s::takeAt(int idx) {
    return idx >= 0 && idx < list1_.size() ? list1_.takeAt(idx) : 0;
}

void scroll_s::addItem(QLayoutItem *item) {
    list1_.append(item);
}

QSize scroll_s::sizeHint() const {
    return minimumSize();
}

QSize scroll_s::minimumSize() const {
    return QSize(250, 4700);  //the size of vertical scroll
}

scroll_s::~scroll_s() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
