# ksGetSelectedEmbodimentAdditionalNumber - Возвращает дополнительный номер исполнения, выбранного в диалоге выбора файла (ksSelectD3Model)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetselectedembodimentadditionalnumberw.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetselectedembodimentmarkingw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetSelectedEmbodimentMarking](kompasobject_ksgetselectedembodimentmarking.html).

Синтаксис:

int LIB_FUNC ksGetSelectedEmbodimentAdditionalNumber( char *additionalNumber,

unsigned int bufLen );

Входные параметры:

bufLen | \- размер буфера marking в символах.  
---|---  
  
Выходные параметры:

additionalNumber | \- дополнительный номер исполнения.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

В диалоге выбора файла [ksSelectD3Model](ksselectd3model.html) может быть выбрано также обозначение исполнения, если оно было создано в файле модели.

Получить выбранное обозначение исполнения можно с помощью функции [ksGetSelectedEmbodimentMarking](ksgetselectedembodimentmarking.html).

Подразделы:

(отсутствуют)
