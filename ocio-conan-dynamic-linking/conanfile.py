from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMake, CMakeToolchain, CMakeDeps
import os


required_conan_version = '>=2.0.0'


class OiioLinkingDemo(ConanFile):
    name = 'dynamic-linking-example'
    version = '0.1'
    settings = "os", "compiler", "build_type", "arch"

    package_type = 'library'
    exports_sources = ['CMakeLists.txt', 'src/main.cpp']

    options = {
        'shared': [True, False],
        'fPIC': [True, False],
    }

    default_options = {
        'shared': True,
        'fPIC': True,

        # Default all third party libraries to shared
        '*:shared': True,

        # Fix minizip-ng as needed in OpenColorIO when building for macOS,
        # On other systems libcomp is anyway not active.
        'minizip-ng/*:with_libcomp': False,
        'minizip-ng/*:with_zlib': True,
    }

    def requirements(self):
        self.requires('fmt/10.2.1', force=True)

        # Enforce some versions, as some dependencies had mismatches
        self.requires('imath/3.1.11', override=True)
        self.requires('openexr/3.2.3', override=True)
        self.requires('opencolorio/2.3.2')

    def config_options(self):
        if self.settings.os == 'Windows':
            self.options.rm_safe('fPIC')

    def configure(self):
        if self.options.shared:
            self.options.rm_safe('fPIC')

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()

        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
