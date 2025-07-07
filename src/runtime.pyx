import glfw
import glfw.GLFW as GLFW_CONSTANTS

cdef class Runtime:
    cdef public object window
    cdef public int width
    cdef public int height

    def __init__(self, object window):
        self.window = window
        self.width = 640
        self.height = 480

    cpdef frame(self):
        pass