# Maintainer: Brian Mercer <mail@brianmercer.com>

pkgname=wvkbd-git
pkgver=v0.12.r0.8bdd741
pkgrel=1
pkgdesc="On-screen keyboard for wlroots"
arch=(any)
url='https://git.sr.ht/~proycon/wvkbd'
license=('GPL3')
groups=()
depends=('wayland' 'pango')
makedepends=('git' 'fontconfig' 'libxkbcommon' 'cairo')
provides=("${pkgname%-git}")
conflicts=("${pkgname%-git}")
replaces=(wvkbd)
backup=()
options=()
install=
source=(${pkgname%-git}::git+${url})
noextract=()
md5sums=('SKIP')
layout=tabenus

pkgver() {
  cd "$srcdir/${pkgname%-git}"
  printf "%s" "$(git describe --long --tags | sed 's/\([^-]*-\)g/r\1/;s/-/./g')"
}

prepare() {
  cd "$srcdir/${pkgname%-git}"
  cp ../../mod/* .
  #patch -p1 -i "../../package.patch"
}

build() {
  cd "$srcdir/${pkgname%-git}"
  make LAYOUT=${layout}
}

package() {
  cd "$srcdir/${pkgname%-git}"
  make LAYOUT=${layout} PREFIX=/usr DESTDIR="${pkgdir}/" install
}
