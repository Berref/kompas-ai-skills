# ksGetSysOptions, ksSetSysOptions - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
if (ksGetCurrentDocument(1)) {

SnapOptrions par;

char mes[700];

memset(&par, 0, sizeof(SnapOptrions));

//получим параметры привязок

ksGetSysOptions(SNAP_OPTIONS, &par, sizeof(SnapOptrions));

sprintf(mes , "Привязка 'Ближайшая точка '-%s\n", par.nearestPoint ? "включена" : "отключена");

sprintf(mes+strlen(mes), "Привязка 'Середина '-%s\n", par.nearestMiddle ? "включена" : "отключена");

sprintf(mes+strlen(mes), "Привязка 'Пересечение '-%s\n", par.intersect ? "включена" : "отключена");

sprintf(mes+strlen(mes), "Привязка 'Касание '-%s\n", par.tangentToCurve ? "включена" : "отключена");

sprintf(mes+strlen(mes), "Привязка 'Нормаль '-%s\n", par.normalToCurve ? "включена" : "отключена");

sprintf(mes+strlen(mes), "Привязка 'По сетке '-%s\n", par.grid ? "включена" : "отключена");

sprintf(mes+strlen(mes), "Привязка 'Выравнивание '-%s\n", par.xyAlign ? "включена" : "отключена");

sprintf(mes+strlen(mes), "Привязка 'Угловая привязка'-%s\n", par.angSnap ? "включена" : "отключена");

sprintf(mes+strlen(mes), "Привязка 'Точка на кривой '-%s\n", par.pointOnCurve ? "включена" : "отключена");

sprintf(mes+strlen(mes), "Общие настройки : динамически %sотслеживать\n", par.commonOpt & SN_DYNAMICALLY ? "" : "не ");

sprintf(mes+strlen(mes), " : %sотображать текст\n" , par.commonOpt & SN_ASSISTANT ? "" : "не ");

sprintf(mes+strlen(mes), " : %sучитывать фоновые слои и виды\n", par.commonOpt & SN_BACKGROUND_LAYER ? "" : "не ");

sprintf(mes+strlen(mes), " : %sподавить привязки\n", par.commonOpt & SN_SUSPENDED ? "" : "не ");

sprintf(mes+strlen(mes), " угловой шаг %f", par.angleStep);

sprintf(mes+strlen(mes), " локальная привязка = %d", par.localSnap);

Message(mes);

//очистим структуру привязок

memset(&par, 0, sizeof(SnapOptrions));

//включим привязку Касание

par.tangentToCurve = 1;

//включим привязку Точка на кривой

par.pointOnCurve = 1;

//текст отображать

par.commonOpt = par.commonOpt | SN_ASSISTANT;

par.angleStep = 10;

//локальная привязка

par.localSnap = SN_GRID;

// заменим привязки

ksSetSysOptions(SNAP_OPTIONS, &par, sizeof(SnapOptrions));

}
