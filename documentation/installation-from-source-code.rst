=============================
Installation from source code
=============================

.. only:: html

   .. |br| raw:: html

      <br />

.. only:: latex

   .. |nl| raw:: latex

      \newline

.. |cmake_option_install_component| replace:: ``--component``
.. _cmake_option_install_component: https://cmake.org/cmake/help/latest/manual/cmake.1.html#cmdoption-cmake-install-component

.. |cmake_option_build_config| replace:: ``--config``
.. _cmake_option_build_config: https://cmake.org/cmake/help/latest/manual/cmake.1.html#cmdoption-cmake-build-config

.. _config-file package: https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html#config-file-packages
.. _file: https://people.freedesktop.org/~dbn/pkg-config-guide.html
.. _pkg-config: https://www.freedesktop.org/wiki/Software/pkg-config

Prerequisites
=============

You will need `CMake <https://cmake.org>`_ v3.12 or later to install the package and, optionally, a recent version of `Sphinx <https://www.sphinx-doc.org>`_ to compile the documentation. Also, make sure that you have `LaTeX <https://www.latex-project.org>`_ with PDF support installed on your system if you want to generate the documentation in PDF format.

Configure
=========

Once the prerequisites are met, create a directory and run ``cmake`` from there to prepare the build system:

.. code-block:: sh

   mkdir build
   cd build
   cmake [options] <Zeta-project-directory>

The resulting build files can be configured by passing options to ``cmake``. To show a complete list of those available along with their current settings, type the following:

.. code-block:: sh

   cmake -LAH -N -B .

If in doubt, read the `CMake documentation <https://cmake.org/documentation/>`_ for more information on configuration options. The following two standard CMake options are relevant:

.. option:: -DCMAKE_BUILD_TYPE=(Debug|Release|RelWithDebInfo|MinSizeRel)

   Choose the type of build (configuration) to generate. |br| |nl|
   The default is ``Release``.

.. option:: -DCMAKE_INSTALL_PREFIX="<path>"

   Specify the installation prefix. |br| |nl|
   The default is ``"/usr/local"`` (on `UNIX <https://en.wikipedia.org/wiki/Unix>`_ and `UNIX-like <https://en.wikipedia.org/wiki/Unix-like>`_ operating systems).

.. _cmake_package_options:

Package-specific options are prefixed with ``Zeta_`` and are as follows:

.. option:: -DZeta_INSTALL_CMAKEDIR="<path>"

   Specify the directory in which to install the CMake `config-file package`_. |br| |nl|
   The default is ``"${CMAKE_INSTALL_DATAROOTDIR}/Zeta/cmake"``.

.. option:: -DZeta_INSTALL_PKGCONFIGDIR="<path>"

   Specify the directory in which to install the `pkg-config`_ `file`_. |br| |nl|
   The default is ``"${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig"``.

.. option:: -DZeta_SPHINX_HTML_THEME="[<name>]"

   Specify the Sphinx theme for the documentation in HTML format. |br| |nl|
   The default is ``""`` (use the default theme).

.. option:: -DZeta_WITH_CMAKE_SUPPORT=(YES|NO)

   Generate and install the CMake `config-file package`_. |br| |nl|
   The default is ``NO``.

.. option:: -DZeta_WITH_HTML_DOCUMENTATION=(YES|NO)

   Build and install the documentation in HTML format. |br| |nl|
   It requires Sphinx. |br| |nl|
   The default is ``NO``.

.. option:: -DZeta_WITH_PDF_DOCUMENTATION=(YES|NO)

   Build and install the documentation in PDF format. |br| |nl|
   It requires Sphinx and LaTeX with PDF support. |br| |nl|
   The default is ``NO``.

.. option:: -DZeta_WITH_PKGCONFIG_SUPPORT=(YES|NO)

   Generate and install the `pkg-config`_ `file`_. |br| |nl|
   The default is ``NO``.

.. option:: -DZeta_WITH_STANDARD_DOCUMENTS=(YES|NO)

   Install the standard text documents distributed with the package: :file:`AUTHORS`, :file:`COPYING`, :file:`COPYING.LESSER`, :file:`HISTORY` and :file:`README`. |br| |nl|
   The default is ``NO``.

Build and install
=================

Finally, once the build system is configured according to your needs, build and install the package:

.. code-block:: sh

   cmake --build . [--config (Debug|Release|RelWithDebInfo|MinSizeRel)]
   cmake --install . [--config <configuration>] [--component <component>]

The |cmake_option_build_config|_ option is only necessary for those `CMake generators <https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html>`_ that ignore :option:`CMAKE_BUILD_TYPE<-DCMAKE_BUILD_TYPE>` (e.g., Xcode and Visual Studio). To install only a specific component of the package, use the |cmake_option_install_component|_ option.

The project defines two components:

.. option:: Zeta_Development

   * Header-only library.
   * CMake config-file package.
   * pkg-config file.
   * Standard text documents.

.. option:: Zeta_Documentation

   * Documentation in HTML format.
   * Documentation in PDF format.
