# AddFromFile - Добавить существующий компонент из файла или из библиотеки моделей в документ и в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IParts7 ](iparts7.html) > [IParts7 - методы ](iparts7_methods.html) |  Scroll [ [ [ ](iparts7_copypart.html "К следующему разделу")](iparts7_methods.html "На уровень выше")](iparts7_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparts7.html)

Синтаксис Automation:

LPDISPATCH AddFromFile (LPCTSTR FileName, BOOL ExternalFile, BOOL Redraw);

Синтаксис COM:

HRESULT AddFromFile ([in] BSTR FileName, [in, defaultvalue(FALSE)] VARIANT_BOOL ExternalFile, [in, defaultvalue(TRUE)] VARIANT_BOOL Redraw, [out, retval] IPart7 ** Result);

Входные параметры:

FileName | \- имя файла, из которого будет вставлен компонент,  
---|---  
ExternalFile | \- признак сохранения связи с файлом-источником: TRUE - вставка со ссылкой на внешний файл, FALSE - вставка "телом", (без сохранения ссылки на источник),  
Redraw | \- признак перестроения документа после вставки компонента: TRUE - перестроить документ, FALSE - не перестраивать.  
  
Возвращаемое значение:

указатель на интерфейс [IPart7](ipart7.html) | \- в случае успешного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечания:

При вставке из файла указывается полный путь к файлу. При вставке из библиотеки моделей указывается полный путь к файлу библиотеки и путь внутри библиотеки моделей, например, "C:\\\standard.l3d|Крепежные элементы|Болты|Болт_1".

Подразделы:

(отсутствуют)
