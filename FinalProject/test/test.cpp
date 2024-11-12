#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <raylib.h>
#include <algorithm>
#include <string>
#include "../include/doctest.h"
#include "../include/Window.hpp"

// Shamelessly stolen from Claude.ai
// Turn off the TraceLog for testing
struct LogRedirect {
    LogRedirect() {
        SetTraceLogLevel(LOG_NONE);
    }
    ~LogRedirect() {
        SetTraceLogLevel(LOG_WARNING);
    }
};

LogRedirect log_redirect;


// Unit tests for property storage
TEST_SUITE("Window Properties") {
    TEST_CASE("Window default constructor property storage") {
        const bool test_mode = true;

        Window window(test_mode);
        CHECK_EQ(window.get_current_width(), 1280);
        CHECK_EQ(window.get_current_height(), 720);
        CHECK_EQ(window.get_minimum_width(), 100);
        CHECK_EQ(window.get_minimum_height(), 100);
        CHECK_EQ(window.get_maximum_width(), 7680);
        CHECK_EQ(window.get_maximum_height(), 4320);
        CHECK_EQ(window.get_title(), "Raylib Window");
        CHECK_EQ(window.get_flags(), 0);
    }

    TEST_CASE("Window constructor property storage") {
        const int test_width = 800;
        const int test_height = 600;
        const std::string test_title = "Test Window";
        const bool test_mode = true;

        Window window(test_width, test_height, test_title, test_mode);
        CHECK_EQ(window.get_current_width(), test_width);
        CHECK_EQ(window.get_current_height(), test_height);
        CHECK_EQ(window.get_minimum_width(), 100);
        CHECK_EQ(window.get_minimum_height(), 100);
        CHECK_EQ(window.get_maximum_width(), 7680);
        CHECK_EQ(window.get_maximum_height(), 4320);
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

    TEST_CASE("Window size setters") {
        const int test_width = 800;
        const int test_height = 600;
        const std::string test_title = "Test Window";
        ConfigFlags test_flags = static_cast<ConfigFlags>(FLAG_WINDOW_RESIZABLE);
        const bool test_mode = true;

        Window window(test_width, test_height, test_flags, test_title, test_mode);

        SUBCASE("Set current size - valid cases") {
            CHECK(window.set_size_current(1920, 1080));
            CHECK_EQ(window.get_current_width(), 1920);
            CHECK_EQ(window.get_current_height(), 1080);
        }

        SUBCASE("Set current size - invalid cases") {
            CHECK_FALSE(window.set_size_current(test_width, test_height));
            CHECK_FALSE(window.set_size_current(50, 50));
        }

        SUBCASE("Set minimum size - valid cases") {
            CHECK(window.set_size_minimum(200, 200));
            CHECK_EQ(window.get_minimum_width(), 200);
            CHECK_EQ(window.get_minimum_height(), 200);
        }

        SUBCASE("Set minimum size - invalid cases") {
            CHECK_FALSE(window.set_size_minimum(50, 50));
            // Default maximum size is 7680 x 4320
            // Test all combinations of going over the default maximum size
            CHECK_FALSE(window.set_size_minimum(3000, 8000));
            CHECK_FALSE(window.set_size_minimum(8000, 3000));
            CHECK_FALSE(window.set_size_minimum(8000, 8000));
        }

        SUBCASE("Set maximum size - valid cases") {
            CHECK(window.set_size_maximum(3440, 1440));
            CHECK_EQ(window.get_maximum_width(), 3440);
            CHECK_EQ(window.get_maximum_height(), 1440);
        }

        SUBCASE("Set maximum size - invalid cases") {
            // Minimum size is 100 x 100
            // Test all combinations of going under minimum size
            CHECK_FALSE(window.set_size_maximum(200, 50));
            CHECK_FALSE(window.set_size_maximum(50, 200));
            CHECK_FALSE(window.set_size_maximum(50, 50));
        }
    }
}
