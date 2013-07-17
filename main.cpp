#include "trikDEApplication.h"
#include "startWidget.h"

int main(int argc, char *argv[])
{
    TrikDEApplication a(argc, argv);
    StartWidget w;
    w.show();
    
    return a.exec();
}
