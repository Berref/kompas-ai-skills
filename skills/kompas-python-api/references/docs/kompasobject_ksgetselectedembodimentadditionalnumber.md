# ksGetSelectedEmbodimentAdditionalNumber - Вернуть дополнительный номер исполнения, выбранный в диалоге выбора файла (ksSelectD3Model)

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetexternalinterface.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetselectedembodimentmarking.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSelectedEmbodimentAdditionalNumber](ksgetselectedembodimentadditionalnumber.html).

Синтаксис Automation:

BSTR ksGetSelectedEmbodimentAdditionalNumber();

Возвращаемое значение:

| \- дополнительный номер исполнения.  
---|---  
  
Примечание:

1\. В диалоге выбора файла [KompasObject::ksSelectD3Model](kompasobject_ksselectd3model.html) могут быть выбраны также обозначения исполнения, если они были созданы в файле модели.

2\. Получить выбранное обозначение исполнения можно с помощью функции [KompasObject::ksGetSelectedEmbodimentMarking](kompasobject_ksgetselectedembodimentmarking.html).

Подразделы:

(отсутствуют)
