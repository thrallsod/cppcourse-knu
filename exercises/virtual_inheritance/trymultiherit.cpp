#include "TextBox.hpp"
#include <iostream>

int main() {
    TextBox tb("Hello World", 5, 5);
//     tb.draw();
//output before fixing
//    class TextBox -> Rectangle -> Drawable
//    class TextBox -> Text -> Drawable
//    6 |      tb.draw();
//    |         ^
//./TextBox.hpp:8:10: note: member found by ambiguous name lookup
//  8 |     void draw() const;
//    |          ^
//1 error generated.
//

    Rectangle &r = tb;
    r.draw();
    Text &t = tb;
    t.draw();
}
// До зміни
//(base) mykytarubanenko@LT-M-5216 virtual_inheritance % ./textbox
//Drawing 1
//Drawing 2
// Після зміни
//(base) mykytarubanenko@LT-M-5216 virtual_inheritance % ./textbox
//Drawing 3
//Drawing 3
