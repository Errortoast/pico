project(Pico VERSION 1.1.0 LANGUAGES CXX)

install(TARGETS Pico DESTINATION bin)

set(CPACK_PACKAGE_NAME "Pico")
set(CPACK_PACKAGE_VENDOR "errortoast")
set(CPACK_PACKAGE_CONTACT "daniel.vanmaarseveen@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A simple command-line text editor..")
set(CPACK_PACKAGE_VERSION "1.1.0")

set(CPACK_RPM_PACKAGE_LICENSE "GNU General Public License v3.0")
set(CPACK_RPM_PACKAGE_GROUP "Applications/Editors")

set(CPACK_GENERATOR "RPM;DEB;TGZ")

include(CPack)