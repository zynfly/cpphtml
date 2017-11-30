#include <iostream>
#include "cpphtml/cpphtml.hpp"
#include <fstream>


using namespace cpphtml;

int
main()
{
    auto page = html(
            lang_("zh-cn"),
            head(
                    meta(charset_("utf-8")),
                    meta(http_equiv_("X-UA-Compatible"), content_("IE=EDGE")),
                    meta(name_("viewport"), content_("width=device-width, initial-scale=1")),
                    title("Test Page")
            ),
            body(
                    div(
                            h1("Hello,World!")
                    )
            )
    );
    std::cout << page() << std::endl;


    return 0;
}

