from conan import ConanFile
from conan.tools.cmake import CMakeDeps
import os

class App(ConanFile):
	settings = "os", "arch", "compiler", "build_type"
	requires = (
        "gtest/1.10.0",
		"glfw/3.3.2",
		"glew/2.1.0",
        "eigen/3.3.9",
        "opencv/4.5.3",
		"imgui/1.77"
	)
	
	def generate(self):
		cmake = CMakeDeps(self)
		cmake.generate()

	def imports(self):
		self.copy("*.dll", os.path.join('..', 'bin', str(self.settings.build_type)), "bin")
		self.copy("imgui_impl_glfw.cpp", os.path.join('..', 'bin/bindings', str(self.settings.build_type)), "./misc/bindings")
		self.copy("imgui_impl_opengl2.cpp", os.path.join('..', 'bin/bindings', str(self.settings.build_type)), "./misc/bindings")
		self.copy("imgui_impl_glfw.h", os.path.join('..', 'bin/bindings', str(self.settings.build_type)), "./misc/bindings")
		self.copy("imgui_impl_opengl2.h", os.path.join('..', 'bin/bindings', str(self.settings.build_type)), "./misc/bindings")
