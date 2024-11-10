#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <raylib.h>
#include <algorithm>
#include <string>
#include "../include/doctest.h"
#include "../include/Window.hpp"

// Unit tests for property storage
TEST_SUITE("Window Properties") {
    TEST_CASE("Window default constructor property storage") {
        const bool test_mode = true;
        Window window(test_mode);
        CHECK_EQ(window.get_width(), 1280);
        CHECK_EQ(window.get_height(), 720);
        CHECK_EQ(window.get_title(), "Raylib Window");
        CHECK_EQ(window.get_flags(), 0);
    }

    TEST_CASE("Window constructor property storage") {
        const int test_width = 800;
        const int test_height = 600;
        const std::string test_title = "Test Window";
        const bool test_mode = true;

        Window window(test_width, test_height, test_title, test_mode);
        CHECK_EQ(window.get_width(), test_width);
        CHECK_EQ(window.get_height(), test_height);
        CHECK_EQ(window.get_title(), test_title);
        CHECK_EQ(window.get_flags(), 0);
    }

    TEST_CASE("Window flags property storage") {
        const int test_width = 800;
        const int test_height = 600;
        const std::string test_title = "Test Window";
        ConfigFlags test_flags = static_cast<ConfigFlags>(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
        const bool test_mode = true;

        Window window(test_width, test_height, test_flags, test_title, test_mode);
        CHECK_EQ(window.get_flags(), test_flags);

        auto enabled_flags = window.get_enabled_flags();
        CHECK_EQ(enabled_flags.size(), 2);
        CHECK((std::find(enabled_flags.begin(), enabled_flags.end(), "Resizable") != enabled_flags.end()));
        CHECK((std::find(enabled_flags.begin(), enabled_flags.end(), "V-Sync") != enabled_flags.end()));
    }
}
