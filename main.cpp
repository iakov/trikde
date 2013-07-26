/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "trikDEApplication.h"
#include "startWidget.h"

int main(int argc, char *argv[])
{
    TrikDEApplication a(argc, argv);
    StartWidget w;
    w.show();
    
    return a.exec();
}
