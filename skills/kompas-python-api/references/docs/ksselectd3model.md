# ksSelectD3Model - Выбрать из списка открытых или из файла модели

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksselectd3modelw.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](getrightfilenamew.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksSelectD3Model](kompasobject_ksselectd3model.html).

Синтаксис:

int LIB_FUNC ksSelectD3Model( char *name,

unsigned int bufLen,

bool onlyDetail,

bool showAddNum );

Входные параметры:

bufLen | \- размер буфера name в символах,  
---|---  
onlyDetail | \- только детали,  
showAddNum | \- отображать комбобокс выбора дополнительного номера.  
  
Выходные параметры:

name | \- имя файла.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

В диалоге выбора файла могут быть выбраны также обозначение исполнения и дополнительный номер исполнения, если они были созданы в файле модели.

Получить выбранное обозначение исполнения можно с помощью функции [ksGetSelectedEmbodimentMarking](ksgetselectedembodimentmarking.html).

Получить выбранный дополнительный номер исполнения можно с помощью функции [ksGetSelectedEmbodimentAdditionalNumber](ksgetselectedembodimentadditionalnumber.html).

Подразделы:

(отсутствуют)
