// Update keymap.cpp
#include "keymap.h"
#include "RGB_LED.h"  // Include the RGB LED library

// Initialize matrix 
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
        KC_NO
    ));

// Custom function to control the LED when key is pressed
static void led_key_press_cb(uint16_t keycode) {
    // Set the LED to blue when pressed
    // RGB values are (RED, GREEN, BLUE)
    setRGBLED(0, 0, 0, 255); // Full blue color
}

// Custom function to turn off the LED when key is released
static void led_key_release_cb(uint16_t keycode) {
    // Turn off the LED on release
    setRGBLED(0, 0, 0, 0); // Off
}

void setupKeymap() {
    // Initialize RGB LED
    setupRGB();
    
    // Single keymap for single key
    uint32_t layer0[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        KC_SPACE  // You can change this to any key you want
    );
 
    // Activate the key in the matrix with callbacks for LED control
    for (int row = 0; row < MATRIX_ROWS; ++row) {
        for (int col = 0; col < MATRIX_COLS; ++col) {
            matrix[row][col].addActivation(_L0, Method::PRESS, layer0[row][col]);
            
            // Add callbacks to handle LED control
            matrix[row][col].setPress(led_key_press_cb);
            matrix[row][col].setRelease(led_key_release_cb);
        }
    }
}