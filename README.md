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

Next, install the package:

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

## License

Copyright © 2006-2024 Manuel Sainz de Baranda y Goñi.

<img src="https://zxe.io/software/Zeta/assets/images/lgplv3.svg" width="160" align="right">

This library is [free software](https://www.gnu.org/philosophy/free-sw.html): you can redistribute it and/or modify it under the terms of the [GNU Lesser General Public License](https://www.gnu.org/licenses/lgpl-3.0.html) as published by the [Free Software Foundation](https://www.fsf.org), either version 3 of the License, or (at your option) any later version.

**This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE**. See the GNU Lesser General Public License for more details.

You should have received a [copy](COPYING.LESSER) of the GNU Lesser General Public License along with this library. If not, see <https://www.gnu.org/licenses/>.
