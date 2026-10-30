# ksInsertRaster - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
RasterParam par; // параметры растрового обекта

par.place.xBase = 100; // точка привязки

par.place.yBase = 100;

par.place.ang = -20; // угол наклона

par.place.scale = 0.5; // масштаб

::strcpy (par.fileName, "C:\\\BROWNBEAR.jpg"); // имя файла растра

::ksInsertRaster (&par); // вставка растрового объекта

reference iter = ::CreateIterator (RASTER_OBJ, 0); // создать итератор по растровым объектам

if (iter) {

reference obj = ::MoveIterator (iter, 'F'); // смещаемся на первый объект

if (::ExistObj(obj)) { // если объект существует

Message("Меняем файл"); // сообщение

::GetObjParam(obj, &par, sizeof(RasterParam), ALLPARAM);

// считываем параметры объекта

::strcpy(par.fileName, "C:\\\WHITEBEAR.jpg"); // имя нового файла растра

par.place.ang = 0; // угол наклона

par.place.scale = 0; // масштаб

::SetObjParam (obj, &par, sizeof(RasterParam), ALLPARAM);

// изменяем параметры объекта

}

::DeleteIterator (iter); // удаляем итератор

}
