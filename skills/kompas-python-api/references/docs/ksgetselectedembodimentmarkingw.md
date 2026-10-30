# ksGetSelectedEmbodimentMarkingW - Возвращает обозначение исполнения, выбранное в диалоге выбора файла (ksSelectD3ModelW)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetselectedembodimentadditionalnumber.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetselectedembodimentmarking.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetSelectedEmbodimentMarking](kompasobject_ksgetselectedembodimentmarking.html).

Синтаксис:

int LIB_FUNC ksGetSelectedEmbodimentMarkingW( LPWSTR marking,

unsigned int bufLen );

Входные параметры:

bufLen | \- размер буфера marking в символах.  
---|---  
  
Выходные параметры:

marking | \- обозначение исполнения.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

В диалоге выбора файла [ksSelectD3ModelW](ksselectd3modelw.html) может быть выбран также дополнительный номера, если он был создан в файле модели.

Получить выбранный дополнительный номер исполнения можно с помощью функции [ksGetSelectedEmbodimentAdditionalNumberW](ksgetselectedembodimentadditionalnumberw.html).

Подразделы:

(отсутствуют)
