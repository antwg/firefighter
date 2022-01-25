#include <GLFW/glfw3.h>

class Window {
public:
    // The size of the window.
    int width, height;

    // Opens a window with the specified dimensions.
    Window(int width, int height, const char *windowName);
    // Closes the window.
    ~Window();
    // Polls for events and tests if the window should close.
    bool shouldClose();
    // Changes the color of the specified pixel.
    void put(int x, int y, unsigned char red, unsigned char green, unsigned char blue);
    // Redraws the window.
    void redraw();
private:
    GLFWwindow *window;
    unsigned char *buffer;
};
