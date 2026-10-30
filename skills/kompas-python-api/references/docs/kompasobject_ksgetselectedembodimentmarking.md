# ksGetSelectedEmbodimentMarking - Вернуть обозначение исполнения, выбранное в диалоге выбора файла (ksSelectD3Model)

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetselectedembodimentadditionalnumber.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetdocumenttypebyname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSelectedEmbodimentMarking](ksgetselectedembodimentmarking.html).

Синтаксис Automation:

BSTR ksGetSelectedEmbodimentMarking();

Возвращаемое значение:

| \- обозначение исполнения.  
---|---  
  
Примечание:

1\. В диалоге выбора файла [KompasObject::ksSelectD3Model](kompasobject_ksselectd3model.html) могут быть выбраны также дополнительные номера, если они были созданы в файле модели.

2\. Получить выбранный дополнительный номер исполнения можно с помощью функции [KompasObject::ksGetSelectedEmbodimentAdditionalNumber](kompasobject_ksgetselectedembodimentadditionalnumber.html).

Подразделы:

(отсутствуют)
