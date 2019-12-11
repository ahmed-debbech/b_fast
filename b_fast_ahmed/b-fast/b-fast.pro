QT       += core gui sql network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#LIBS += -LC:\Users\ahmeddebbech\Desktop\b_fast_ahmed\b-fast\OpenSSL-Win64 -llibssl-1_1-x64
#OPENSSL_LIBS='-L/opt/ssl/lib -lssl -lcrypto' ./configure -openssl-linked
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    mailing/emailaddress.cpp \
    mailing/mimeattachment.cpp \
    mailing/mimecontentformatter.cpp \
    mailing/mimefile.cpp \
    mailing/mimehtml.cpp \
    mailing/mimeinlinefile.cpp \
    mailing/mimemessage.cpp \
    mailing/mimemultipart.cpp \
    mailing/mimepart.cpp \
    mailing/mimetext.cpp \
    mailing/quotedprintable.cpp \
    mailing/smtpclient.cpp \
    main.cpp \
    mainwindow.cpp \
    subscriber.cpp \
    subscription.cpp


HEADERS += \
    arduino.h \
    mailing/SmtpMime \
    mailing/emailaddress.h \
    mailing/mimeattachment.h \
    mailing/mimecontentformatter.h \
    mailing/mimefile.h \
    mailing/mimehtml.h \
    mailing/mimeinlinefile.h \
    mailing/mimemessage.h \
    mailing/mimemultipart.h \
    mailing/mimepart.h \
    mailing/mimetext.h \
    mailing/quotedprintable.h \
    mailing/smtpclient.h \
    mailing/smtpexports.h \
    mainwindow.h \
    subscriber.h \
    subscription.h

FORMS += \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    OpenSSL-Win64/acknowledgements.txt \
    OpenSSL-Win64/authors.txt \
    OpenSSL-Win64/bin/CA.pl \
    OpenSSL-Win64/bin/PEM/ca-cert.srl \
    OpenSSL-Win64/bin/PEM/ca-key.pem \
    OpenSSL-Win64/bin/PEM/ca-req.pem \
    OpenSSL-Win64/bin/PEM/cert.pem \
    OpenSSL-Win64/bin/PEM/client.pem \
    OpenSSL-Win64/bin/PEM/demoSRP/srp_verifier.txt \
    OpenSSL-Win64/bin/PEM/demoSRP/srp_verifier.txt.attr \
    OpenSSL-Win64/bin/PEM/dh1024.pem \
    OpenSSL-Win64/bin/PEM/dh2048.pem \
    OpenSSL-Win64/bin/PEM/dh4096.pem \
    OpenSSL-Win64/bin/PEM/dsa-ca.pem \
    OpenSSL-Win64/bin/PEM/dsa-pca.pem \
    OpenSSL-Win64/bin/PEM/dsa1024.pem \
    OpenSSL-Win64/bin/PEM/dsa512.pem \
    OpenSSL-Win64/bin/PEM/dsap.pem \
    OpenSSL-Win64/bin/PEM/pca-cert.srl \
    OpenSSL-Win64/bin/PEM/pca-key.pem \
    OpenSSL-Win64/bin/PEM/pca-req.pem \
    OpenSSL-Win64/bin/PEM/privkey.pem \
    OpenSSL-Win64/bin/PEM/req.pem \
    OpenSSL-Win64/bin/PEM/rsa8192.pem \
    OpenSSL-Win64/bin/PEM/s1024key.pem \
    OpenSSL-Win64/bin/PEM/s1024req.pem \
    OpenSSL-Win64/bin/PEM/s512-key.pem \
    OpenSSL-Win64/bin/PEM/s512-req.pem \
    OpenSSL-Win64/bin/PEM/server.pem \
    OpenSSL-Win64/bin/PEM/server.srl \
    OpenSSL-Win64/bin/PEM/server2.pem \
    OpenSSL-Win64/bin/PEM/testCA.pem \
    OpenSSL-Win64/bin/capi.dll \
    OpenSSL-Win64/bin/dasync.dll \
    OpenSSL-Win64/bin/libcrypto-1_1-x64.dll \
    OpenSSL-Win64/bin/libssl-1_1-x64.dll \
    OpenSSL-Win64/bin/openssl.exe \
    OpenSSL-Win64/bin/ossltest.dll \
    OpenSSL-Win64/bin/padlock.dll \
    OpenSSL-Win64/bin/progs.pl \
    OpenSSL-Win64/bin/tsget.pl \
    OpenSSL-Win64/c_rehash.pl \
    OpenSSL-Win64/changes.txt \
    OpenSSL-Win64/faq.txt \
    OpenSSL-Win64/libcrypto-1_1-x64.dll \
    OpenSSL-Win64/libssl-1_1-x64.dll \
    OpenSSL-Win64/license.txt \
    OpenSSL-Win64/news.txt \
    OpenSSL-Win64/readme.txt \
    OpenSSL-Win64/unins000.dat \
    OpenSSL-Win64/unins000.exe \
    imgs/but.png \
    imgs/graph.png \
    mailing.rar \
    re/Page de garde_nom_classe.docx \
    re/admin.png \
    re/aziz.jpg \
    re/back.png \
    re/back.psd \
    re/businessman.png \
    re/but.png \
    re/captain (1).png \
    re/captain (2).png \
    re/captain (3).png \
    re/captain.png \
    re/diag.jpg \
    re/gestion des abonnees et des abonnements.cdb \
    re/gestion des abonnees et des abonnements.cdm \
    re/gestion.mdj \
    re/graph.png \
    re/logo 100.png \
    re/logo 25.png \
    re/logo 300.png \
    re/logo 75.png \
    re/logo bfastpng.png \
    re/logo group.jpg \
    re/logo group.png \
    re/logo.ai \
    re/logobfast.ai \
    re/malik.jpg \
    re/presentation-projetcpptx.pptx \
    re/refresh.png \
    re/wassim.jpg \
    re/yasssine.jpg \
    re/zied.jpg \
    simple-mail-master.zip

RESOURCES += \
    res.qrc
