#include <QtGui>
#include <iostream>

using namespace std;

#if 0
int data()
{
    QString value = layout;
    return value;
}
#endif

int main(int argc, char * argv[])
{
     QApplication app(argc, argv);
     QTextCodec *codec = QTextCodec::codecForName("UTF-8");
     QWidget *window = new QWidget;
     window->setWindowTitle(codec->toUnicode("値を入力"));
                    
     QSpinBox *spinBox = new QSpinBox;
     QSlider *slider = new QSlider(Qt::Horizontal);
     spinBox->setRange(50, 250);
     slider->setRange(50, 250);
                                        
     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
        slider, SLOT(setValue(int)));
     QObject::connect(slider, SIGNAL(valueChanged(int)),
        spinBox, SLOT(setValue(int)));
     spinBox->setValue(150);
                                                       
     QHBoxLayout *layout = new QHBoxLayout;
     layout->addWidget(spinBox);
     layout->addWidget(slider);
     window->setLayout(layout);

     // cout << layout << endl;
        
     window->show();
     return app.exec();
}
