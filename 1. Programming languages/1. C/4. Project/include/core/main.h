#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../id/id.h"
#include "../task/task.h"
#include "../tasklist/tasklist.h"
#include "../workbook/workbook.h"
#include "consts.h"

Boolean setup(WorkBook *workbook);
void eventLoop(WorkBook *workbook);

#endif