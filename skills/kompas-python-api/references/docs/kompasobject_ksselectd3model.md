# ksSelectD3Model - Выбрать из списка открытых или из файла модели

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_kssetdocoptions.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_kssetdebugmessagesmode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksSelectD3Model](ksselectd3model.html).

Синтаксис Automation:

BSTR ksSelectD3Model( BOOL onlyDetail, BOOL showAddNum );

Возвращаемое значение:

| \- имя файла,  
---|---  
  
Входные параметры:

onlyDetail | \- только файлы деталей,  
---|---  
showAddNum | \- отображать комбобокс выбора дополнительного номера.  
  
Примечание:

1\. В диалоге выбора файла могут быть выбраны также обозначение исполнения и дополнительный номер исполнения, если они были созданы в файле модели.

2\. Получить выбранное обозначение исполнения можно с помощью метода [KompasObject::ksGetSelectedEmbodimentMarking](kompasobject_ksgetselectedembodimentmarking.html).

3\. Получить выбранный дополнительный номер исполнения можно с помощью метода [KompasObject::ksGetSelectedEmbodimentAdditionalNumber](kompasobject_ksgetselectedembodimentadditionalnumber.html).

Подразделы:

(отсутствуют)
