#include "mainwindow.h"

#include <QApplication>

#include <QDir>
#include <QFontDatabase>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString o = ":/fonts/";
    QStringList z;
    auto t = QDir(o).entryList({"*.ttf", "*.otf"}, QDir::Files | QDir::Readable);
    for (auto i = t.begin(); i != t.end(); ++i)
        z << QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(o + *i));

    if (z.empty()) {
        QMessageBox::critical(nullptr, "error", "failed to load font files");
        return a.exec();
    }

    QFont f;
    f.setFamilies(z);
    f.setPointSize(20);
    a.setFont(f);

    MainWindow w;
    w.show();

    return a.exec();
}
