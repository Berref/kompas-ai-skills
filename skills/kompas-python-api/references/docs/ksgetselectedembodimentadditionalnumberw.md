# ksGetSelectedEmbodimentAdditionalNumberW - Возвращает дополнительный номер исполнения, выбранного в диалоге выбора файла (ksSelectD3ModelW). Unicode

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](kschoicefile.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetselectedembodimentadditionalnumber.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetSelectedEmbodimentMarking](kompasobject_ksgetselectedembodimentmarking.html).

Синтаксис:

int LIB_FUNC ksGetSelectedEmbodimentAdditionalNumberW( LPWSTR additionalNumber,

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

В диалоге выбора файла [ksSelectD3ModelW](ksselectd3modelw.html) может быть выбрано также обозначение исполнения, если оно было создано в файле модели.

Получить выбранное обозначение исполнения можно с помощью функции [ksGetSelectedEmbodimentMarkingW](ksgetselectedembodimentmarkingw.html).

Подразделы:

(отсутствуют)
