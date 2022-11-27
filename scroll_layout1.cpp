
#include "scroll_layout1.h"
#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>

//using namespace std;

// you should probably make extensive changes to this function
void scroll_t::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {
    // the start position of result
    QLayout::setGeometry(r);
    int x = 0.1*r.height();
    int y = 0.1*r.height();
    int z = 0.1*r.height();
    int h = 0.72*r.height();
//    int a=1;
//    int b=1;
//    int z = 0.05*r.width();
//    int c = 0.05*r.width();
//    int d = 0.05*r.width();
//    int e = 0.01*r.width();
//    int f = 0.01*r.width();
//    int g = 0.01*r.width();
//    int h = 0.17*r.width();
//    int j = 0.17*r.width();

//    int a = 0;
//    int b =0;
    // for all the Widgets added in ResponsiveWindow.cpp

    for (int i = 0; i < list2_.size(); i++) {
        QLayoutItem *o = list2_.at(i);
        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                std::cout << "warning, unknown widget class in layout" << std::endl;
                // fixme: focus group did not like this behaviour for the search result element.
//                else if (label -> text() == kSearchResult ) {
                // the move of result_image
            else if (label -> text() == kSearchResultImage){
                    label->setGeometry(x, y, 0.6 * r.height(), 0.6 * r.height());
                    x += 0.7 * r.height();
                }
                // the move of result_text
            else if (label -> text() == kSearchResultText) {
                    label->setGeometry(z, h, 0.6 * r.height(), 0.18 * r.height());
                    z += 0.7 * r.height();

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
int scroll_t::count() const {
    return list2_.size();
}

QLayoutItem *scroll_t::itemAt(int idx) const {
    return list2_.value(idx);
}

QLayoutItem *scroll_t::takeAt(int idx) {
    return idx >= 0 && idx < list2_.size() ? list2_.takeAt(idx) : 0;
}

void scroll_t::addItem(QLayoutItem *item) {
    list2_.append(item);
}

QSize scroll_t::sizeHint() const {
    return minimumSize();
}

QSize scroll_t::minimumSize() const {
    return QSize(2900, 150);  //the size of horizontal scroll
}

scroll_t::~scroll_t() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}

