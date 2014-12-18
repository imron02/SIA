#include <mainwindow/pagehome/pagehome.h>

PageHome::PageHome(QWidget* parent) : QWidget(parent)
{
    QString string = "<html><body>"
                     "<h3>Selamat Datang di Aplikasi Sistem Informasi Akademik</h3>"
                     "<br/><b>Mengenai aplikasi</b><br/>"
                     "<p>Aplikasi sistem informasi akademik adalah aplikasi yang ditunjukkan untuk"
                     "membantu sekolah dalam mengolah data-data akademik secara cepat dan mudah.</p>"
                     "<p><b>Fitur</b></p>"
                     "<p>Dengan aplikasi SIA, pihak sekolah dapat melakukan berbagai hal seperti:</p>"
                     "<ul>"
                     "<li>Mudah mengolah data-data guru</li>"
                     "<li>Mudah mengolah data-data siswa</li>"
                     "<li>Fitur pembayaran SPP</li>"
                     "<li>Fitur penjurusan siswa</li>"
                     "</ul>"
                     "<p>See README.txt for more information.</p>"
                     "</body></html>";
    QLabel* label = new QLabel(string);

    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->addWidget(label);
    vbox->addStretch(1);

    setLayout(vbox);
}

PageHome::~PageHome() {}
