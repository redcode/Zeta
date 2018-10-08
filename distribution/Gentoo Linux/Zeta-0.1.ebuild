# Copyright 1999-2018 Gentoo Foundation
# Distributed under the terms of the GNU General Public License v2

EAPI="6"

ETYPE="headers"
DESCRIPTION="Header-only multi-platform base library written in C/C++"
HOMEPAGE="https://zeta.st"
SRC_URI="https://zeta.st/downloads/Z-0.1.tar.xz"
SLOT="0"

S="${WORKDIR}/Z"

src_configure() { :; }
src_compile()	{ :; }
src_test()	{ :; }

src_install() {
	insinto /usr/include/Z
	doins -r API/Z/.
	dodoc AUTHORS COPYING.LESSER HISTORY INSTALL README
}
