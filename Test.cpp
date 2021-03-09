#include "doctest.h"
#include "snowman.hpp"

using namespace ariel;
using namespace std;


TEST_CASE("options for snowman") {
    /*
    check all the options {1,2,3,4} for each member of the snowman (Hat, nose, arms, etc.)
    not all the combinations because there are lots of these.
    For now it does not refer to spaces because it depends on the realization.
    */
    CHECK(snowman(11114411) == "_===_\n(.,.)\n( : )\n( : )");
    CHECK(snowman(12222212) == " _===_\n\\(o.o)/\n ( : ) \n (" ")");
    CHECK(snowman(22222222) == "  ___\n ..... \n\\(o.o)/\n (] [) \n (" ")");
    CHECK(snowman(33232124) == "   _\n  /_\n\\(o_O)\n (] [)>\n (   )");
    CHECK(snowman(32443333) == "   _\n  /_\\n (-.-) \n/(> <)\\n (___)");
    CHECK(snowman(41341144) == "  ___\n (_*_)\n (O,-) \n<(   )>\n (   )");
    CHECK(snowman(44242123) == "  ___\n (_*_)\n\\(o -) \n (] [)>\n (___)");
    CHECK(snowman(44444432) == " ___ \n (_*_)\n (- -)\n (> <)\n (" ")");

}

TEST_CASE("too short number") {
    CHECK_THROWS(snowman(4));
    CHECK_THROWS(snowman(24));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1323));
    CHECK_THROWS(snowman(34124));
    CHECK_THROWS(snowman(413412));
    CHECK_THROWS(snowman(1242243));
}

TEST_CASE("number different from 1,2,3,4") {
    CHECK_THROWS(snowman(55555555));
    CHECK_THROWS(snowman(66666666));
    CHECK_THROWS(snowman(77777777));
    CHECK_THROWS(snowman(88888888));
    CHECK_THROWS(snowman(99999999));
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(25424313));
    CHECK_THROWS(snowman(13283231));
    CHECK_THROWS(snowman(68534245));
}
