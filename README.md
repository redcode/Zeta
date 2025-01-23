# Zeta

## Installation

### <sub><img src="https://zxe.io/software/Zeta/assets/images/debian-icon.svg" height="24"></sub> Debian, <sub><img src="https://zxe.io/software/Zeta/assets/images/ubuntu-icon.svg" height="24"></sub> Ubuntu and other Debian-based Linux distributions

First, add the `zxe` repository and update the package index:

```shell
sudo mkdir -pm700 /root/.gnupg
sudo mkdir -pm755 /etc/apt/keyrings
sudo gpg --no-default-keyring --keyring /etc/apt/keyrings/zxe-archive-keyring.gpg --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys FE214A38D6A0C01D9AF514EE841EA3BD3A7E1487
echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/zxe-archive-keyring.gpg] https://zxe.io/repos/apt stable main" | sudo tee /etc/apt/sources.list.d/zxe.list
sudo apt update
```

Then install the package:

```shell
sudo apt install libzeta-dev
```

### <sub><img src="https://zxe.io/software/Zeta/assets/images/gentoo-icon.svg" height="24"></sub> Gentoo

First, add and sync the [`zxe`](https://github.com/redcode/zxe-gentoo-overlay) overlay:

```shell
eselect repository add zxe git https://github.com/redcode/zxe-gentoo-overlay.git
emaint sync --repo zxe
```

Then install the library:

```shell
emerge dev-libs/zeta
```

### <sub><img src="https://zxe.io/software/Zeta/assets/images/homebrew-icon.svg" height="24"></sub> Homebrew

```shell
brew install redcode/zxe/zeta
```

## Installation from source code

### Prerequisites

You will need [CMake](https://cmake.org) v3.12 or later to install the package and, optionally, a recent version of [Sphinx](https://www.sphinx-doc.org) to compile the documentation. Also, make sure that you have [LaTeX](https://www.latex-project.org) with PDF support installed on your system if you want to generate the documentation in PDF format.

### Configure

Once the prerequisites are met, create a directory and run `cmake` from there to prepare the build system:

```shell
mkdir build
cd build
cmake [options] <Zeta-project-directory>
```

The resulting build files can be configured by passing options to `cmake`. To show a complete list of those available along with their current settings, type the following:

```shell
cmake -LAH -N -B .
```

If in doubt, read the [CMake documentation](https://cmake.org/documentation/) for more information on configuration options. The following two standard CMake options are relevant:

* <span id="cmake_option_cmake_build_type">**<code>-D[CMAKE_BUILD_TYPE](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html)=(Debug|Release|RelWithDebInfo|MinSizeRel)</code>**</span>  
	Choose the type of build (configuration) to generate.  
	The default is `Release`.

* <span id="cmake_option_cmake_install_prefix">**<code>-D[CMAKE_INSTALL_PREFIX](https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html)="\<path\>"</code>**</span>  
	Specify the installation prefix.  
	The default is `"/usr/local"` (on [UNIX](https://en.wikipedia.org/wiki/Unix) and [UNIX-like](https://en.wikipedia.org/wiki/Unix-like) operating systems).

<span id="cmake_package_options">Package-specific options</span> are prefixed with `Zeta_` and are as follows:

* <span id="cmake_option_zeta_install_cmakedir">**`-DZeta_INSTALL_CMAKEDIR="<path>"`**</span>  
	Specify the directory in which to install the CMake [config-file package](https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html#config-file-packages).  
	The default is <code>"${[CMAKE_INSTALL_DATAROOTDIR](https://cmake.org/cmake/help/latest/module/GNUInstallDirs.html)}/Zeta/cmake"</code>.

* <span id="cmake_option_zeta_install_pkgconfigdir">**`-DZeta_INSTALL_PKGCONFIGDIR="<path>"`**</span>  
	Specify the directory in which to install the [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config) [file](https://people.freedesktop.org/~dbn/pkg-config-guide.html).  
	The default is <code>"${[CMAKE_INSTALL_DATAROOTDIR](https://cmake.org/cmake/help/latest/module/GNUInstallDirs.html)}/pkgconfig"</code>.

* <span id="cmake_option_zeta_sphinx_html_theme">**`-DZeta_SPHINX_HTML_THEME="[<name>]"`**</span>  
	Specify the Sphinx theme for the documentation in HTML format.  
	The default is `""` (use the default theme).

* <span id="cmake_option_zeta_with_cmake_support">**`-DZeta_WITH_CMAKE_SUPPORT=(YES|NO)`**</span>  
	Generate and install the CMake [config-file package](https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html#config-file-packages).  
	The default is `NO`.

* <span id="cmake_option_zeta_with_html_documentation">**`-DZeta_WITH_HTML_DOCUMENTATION=(YES|NO)`**</span>  
	Build and install the documentation in HTML format.  
	It requires Sphinx.  
	The default is `NO`.

* <span id="cmake_option_zeta_with_pdf_documentation">**`-DZeta_WITH_PDF_DOCUMENTATION=(YES|NO)`**</span>  
	Build and install the documentation in PDF format.
	It requires Sphinx and LaTeX with PDF support.
	The default is `NO`.

* <span id="cmake_option_zeta_with_pkgconfig_support">**`-DZeta_WITH_PKGCONFIG_SUPPORT=(YES|NO)`**</span>  
	Generate and install the [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config) [file](https://people.freedesktop.org/~dbn/pkg-config-guide.html).  
	The default is `NO`.

* <span id="cmake_option_zeta_with_standard_documents">**`-DZeta_WITH_STANDARD_DOCUMENTS=(YES|NO)`**</span>  
	Install the standard text documents distributed with the package: [`AUTHORS`](AUTHORS), [`COPYING`](COPYING), [`COPYING.LESSER`](COPYING.LESSER), [`HISTORY`](HISTORY) and [`README`](README).  
	The default is `NO`.

### Build and install

Finally, once the build system is configured according to your needs, build and install the package:

```shell
cmake --build . [--config (Debug|Release|RelWithDebInfo|MinSizeRel)]
cmake --install . [--config <configuration>]
```

The [`--config`](https://cmake.org/cmake/help/latest/manual/cmake.1.html#cmdoption-cmake-build-config) option is only necessary for those [CMake generators](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) that ignore [`CMAKE_BUILD_TYPE`](#cmake_option_cmake_build_type) (e.g., Xcode and Visual Studio).

## License

Copyright © 2006-2025 Manuel Sainz de Baranda y Goñi.

<img src="https://zxe.io/software/Zeta/assets/images/lgplv3.svg" width="160" align="right">

This library is [free software](https://www.gnu.org/philosophy/free-sw.html): you can redistribute it and/or modify it under the terms of the [GNU Lesser General Public License](https://www.gnu.org/licenses/lgpl-3.0.html) as published by the [Free Software Foundation](https://www.fsf.org), either version 3 of the License, or (at your option) any later version.

**This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE**. See the GNU Lesser General Public License for more details.

You should have received a [copy](COPYING.LESSER) of the GNU Lesser General Public License along with this library. If not, see <https://www.gnu.org/licenses/>.
