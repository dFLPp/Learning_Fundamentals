#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "id.h"
#include "task.h"
#include "tasklist.h"
#include "workbook.h"
#include "consts.h"

void loadTasks();
void eventLoop();

#endif